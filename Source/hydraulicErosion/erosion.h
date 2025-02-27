// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <random>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Landscape.h"
#include "LandscapeComponent.h"
#include "LandscapeEdit.h"
#include "Editor.h"
#include "erosion.generated.h"


struct Particle {
    float x, y;           // Position
    float dx, dy;         // Direction vector
    float speed;          // Current speed
    float water;          // Water volume
    float sediment;       // Sediment content
};


UCLASS()
class HYDRAULICEROSION_API Aerosion : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	Aerosion();
    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    ALandscape* TargetLandscape;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    int32 NumberOfDroplets = 1000;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    int32 MaxDropletSteps = 100;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float TimeStep = 1.0f;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float minSlope = 0.01f;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float SedimentCapacityFactor = 4.0f;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float ErosionRate = 0.1f;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float DepositionRate = 0.1f;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float EvaporationRate = 0.01f;

    UPROPERTY(EditAnywhere, Category = "Erosion Parameters")
    float Gravity = 9.81f;


    // Get height at a specific position using bilinear interpolation
    float getHeightAt(float x, float y);
    // Calculate gradient at position
    void calculateGradient(float x, float y, float& gradX, float& gradY);
    // Modify height at a position
    void modifyHeight(float x, float y, float amount);

    void simulateParticle(Particle& particle);

    void erode(int numParticles, int stepsPerParticle);




private:
    // Internal representation of the terrain heightmap
    TArray<uint16> Heightmap;
    TArray<float> NormalizedHeightmap;


    // Size of the terrain grid
    int32 GridSizeX;
    int32 GridSizeY;

    int32 MinX, MinY, MaxX, MaxY;


    struct FTextureSettings
    {
        TextureCompressionSettings OriginalCompressionSettings;
        TextureMipGenSettings OriginalMipGenSettings;
        bool OriginalSRGB;
    };

    TArray<FTextureSettings> OriginalTextureSettings;


	void initializeHeightmap();
    void applyHeightMapToLandscape();
    void logOutput(FString);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
