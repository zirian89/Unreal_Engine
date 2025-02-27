// Fill out your copyright notice in the Description page of Project Settings.


#include "erosion.h"

// Sets default values
Aerosion::Aerosion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aerosion::BeginPlay()
{
    initializeHeightmap();
    erode(NumberOfDroplets, MaxDropletSteps);
	Super::BeginPlay();
	
}

// Called every frame
void Aerosion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void Aerosion::initializeHeightmap()
{
    if (!TargetLandscape) return;

    ULandscapeInfo* LandscapeInfo = TargetLandscape->GetLandscapeInfo();
    if (!LandscapeInfo) return;

    // Get landscape dimensions
    LandscapeInfo->GetLandscapeExtent(MinX, MinY, MaxX, MaxY);
    GridSizeX = MaxX - MinX + 1;
    GridSizeY = MaxY - MinY + 1;

    // Initialize arrays
    Heightmap.SetNum(GridSizeX * GridSizeY);
    NormalizedHeightmap.SetNum(GridSizeX * GridSizeY);

    // Get height data using landscape tools
    FLandscapeEditDataInterface LandscapeEdit(LandscapeInfo);
    LandscapeEdit.GetHeightData(MinX, MinY, MaxX, MaxY, Heightmap.GetData(), 0);

    // Normalize the heightmap
    const float Scale = 1.0f / 65535.0f;
    for (int32 i = 0; i < Heightmap.Num(); ++i)
    {
        NormalizedHeightmap[i] = static_cast<float>(Heightmap[i]) * Scale;
    }
}

void Aerosion::applyHeightMapToLandscape()
{
    if (!TargetLandscape) return;

    ULandscapeInfo* LandscapeInfo = TargetLandscape->GetLandscapeInfo();
    if (!LandscapeInfo) return;

    // Create a transaction for undo/redo
    FScopedTransaction Transaction(FText::FromString(TEXT("Landscape Erosion")));
    TargetLandscape->Modify();

    // Convert normalized heights back to landscape height values
    TArray<uint16> HeightData;
    HeightData.SetNum(NormalizedHeightmap.Num());

    for (int32 i = 0; i < NormalizedHeightmap.Num(); ++i)
    {
        float ClampedHeight = FMath::Clamp(NormalizedHeightmap[i], 0.0f, 1.0f);
        HeightData[i] = static_cast<uint16>(ClampedHeight * 65535.0f);
    }

    // Apply height changes using landscape tools
    FLandscapeEditDataInterface LandscapeEdit(LandscapeInfo);
    LandscapeEdit.SetHeightData(MinX, MinY, MaxX, MaxY, HeightData.GetData(), 0, true);
    LandscapeEdit.Flush(); // Ensure texture updates are completed and locks are released

    // Mark landscape as needing update
    for (ULandscapeComponent* Component : TargetLandscape->LandscapeComponents)
    {
        if (Component)
        {
            Component->UpdateCachedBounds();
            Component->UpdateComponentToWorld();
            Component->MarkRenderStateDirty();

        }
    }

    // Update collision
    TargetLandscape->RequestLayersContentUpdate(ELandscapeLayerUpdateMode::Update_All);

}

float Aerosion::getHeightAt(float x, float y)
{
    int x0 = static_cast<int>(x);
    int y0 = static_cast<int>(y);
    int x1 = std::min(x0 + 1, GridSizeX - 1);
    int y1 = std::min(y0 + 1, GridSizeY - 1);

    float fx = x - x0;
    float fy = y - y0;

    // Clamp interpolation factors between 0 and 1
    fx = std::max(0.0f, std::min(fx, 1.0f));
    fy = std::max(0.0f, std::min(fy, 1.0f));

    checkf(y0 * GridSizeX + x0 <= Heightmap.Num() && y0 * GridSizeX + x0 >= 0, TEXT("Assertion failed y0 * GridSizeX + x0 = %d"), y0 * GridSizeX + x0);
    checkf(y0 * GridSizeX + x1 <= Heightmap.Num() && y0 * GridSizeX + x1 >= 0, TEXT("Assertion failed y0 * GridSizeX + x1 = %d"), y0 * GridSizeX + x1);
    checkf(y1 * GridSizeX + x0 <= Heightmap.Num() && y1 * GridSizeX + x0 >= 0, TEXT("Assertion failed y1 * GridSizeX + x0 = %d"), y1 * GridSizeX + x0);
    checkf(y1 * GridSizeX + x1 <= Heightmap.Num() && y1 * GridSizeX + x1 >= 0, TEXT("Assertion failed y1 * GridSizeX + x1 = %d"), y1 * GridSizeX + x1);
    float h00 = NormalizedHeightmap[y0 * GridSizeX + x0];
    float h10 = NormalizedHeightmap[y0 * GridSizeX + x1];
    float h01 = NormalizedHeightmap[y1 * GridSizeX + x0];
    float h11 = NormalizedHeightmap[y1 * GridSizeX + x1];

    return h00 * (1 - fx) * (1 - fy) +
        h10 * fx * (1 - fy) +
        h01 * (1 - fx) * fy +
        h11 * fx * fy;
}

void Aerosion::calculateGradient(float x, float y, float& gradX, float& gradY)
{
    float h = getHeightAt(x, y);
    float hL = getHeightAt(std::clamp((int)x - 1, 0, GridSizeX - 1), y);
    float hR = getHeightAt(std::clamp((int)x + 1, 0, GridSizeX - 1), y);
    float hT = getHeightAt(x, std::clamp((int)y - 1, 0, GridSizeY - 1));
    float hB = getHeightAt(x, std::clamp((int)y + 1, 0, GridSizeY - 1));

    gradX = (hR - hL) * 0.5f;
    gradY = (hB - hT) * 0.5f;
}

void Aerosion::modifyHeight(float x, float y, float amount)
{
    int x0 = static_cast<int>(x);
    int y0 = static_cast<int>(y);

    // Ensure we're within bounds
    if (x0 >= 0 && x0 < GridSizeX - 1 && y0 >= 0 && y0 < GridSizeY - 1) {
        float fx = x - x0;
        float fy = y - y0;

        NormalizedHeightmap[y0 * GridSizeX + x0] += amount * (1 - fx) * (1 - fy);
        NormalizedHeightmap[y0 * GridSizeX + x0 + 1] += amount * fx * (1 - fy);
        NormalizedHeightmap[(y0 + 1) * GridSizeX + x0] += amount * (1 - fx) * fy;
        NormalizedHeightmap[(y0 + 1) * GridSizeX + x0 + 1] += amount * fx * fy;
    }
}

void Aerosion::simulateParticle(Particle& particle)
{

    // Calculate gradient at current position
    float gradX, gradY;
    calculateGradient(particle.x, particle.y, gradX, gradY);

    // Update velocity based on gradient
    particle.dx += -gradX * Gravity * TimeStep;
    particle.dy += -gradY * Gravity * TimeStep;

    // Calculate speed
    particle.speed = FMath::Sqrt(particle.dx * particle.dx + particle.dy * particle.dy);

    // Update position
    particle.x += particle.dx * TimeStep;
    particle.y += particle.dy * TimeStep;

    // Calculate sediment capacity
    float slope = FMath::Sqrt(gradX * gradX + gradY * gradY);
    float sedimentCapacity = std::max(slope, minSlope) * particle.speed * particle.water * SedimentCapacityFactor;

    // Erode or deposit
    if (particle.sediment > sedimentCapacity) {
        // Deposit excess sediment
        float depositAmount = (particle.sediment - sedimentCapacity) * DepositionRate;
        particle.sediment -= depositAmount;
        modifyHeight(particle.x, particle.y, depositAmount);
    }
    else {
        // Erode surface
        float erosionAmount = (sedimentCapacity - particle.sediment) * ErosionRate;
        particle.sediment += erosionAmount;
        modifyHeight(particle.x, particle.y, -erosionAmount);
    }

    // Evaporate water
    particle.water *= (1.0f - EvaporationRate);
}

void Aerosion::erode(int numParticles, int stepsPerParticle)
{
 //   std::random_device rd;
 //   std::mt19937 gen(rd());
 //   std::uniform_real_distribution<float> disX(0, GridSizeX - 1);
 //   std::uniform_real_distribution<float> disY(0, GridSizeY - 1);
    if (!TargetLandscape) return;


    for (int i = 0; i < numParticles; i++) {
        //Initialize particle

        Particle particle;
        particle.x = FMath::RandRange(0.0f, (float)GridSizeX - 1.0f);
        particle.y = FMath::RandRange(0.0f, (float)GridSizeY - 1.0f);
        particle.dx = 0.0f;
        particle.dy = 0.0f;
        particle.speed = 0.0f;
        particle.water = 1.0f;
        particle.sediment = 0.0f;

        // Simulate particle movement
        for (int step = 0; step < stepsPerParticle; step++) {
            simulateParticle(particle);

            // Check if particle is still on the map
            if (particle.x < 0 || particle.x >= GridSizeX - 1 ||
                particle.y < 0 || particle.y >= GridSizeY - 1 ||
                particle.water < 0.01f) {
                break;
            }
        }

    }
    applyHeightMapToLandscape();

}

void Aerosion::logOutput(FString log)
{
    FString FilePath = "C:/Users/zryan.saeed/Desktop/log.txt";
   // FString FileContent = TEXT("This is a line of text to put in the file.");
    FFileHelper::SaveStringToFile(log, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}

