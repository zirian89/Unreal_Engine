// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "hydraulicErosion/erosion.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeerosion() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
HYDRAULICEROSION_API UClass* Z_Construct_UClass_Aerosion();
HYDRAULICEROSION_API UClass* Z_Construct_UClass_Aerosion_NoRegister();
LANDSCAPE_API UClass* Z_Construct_UClass_ALandscape_NoRegister();
UPackage* Z_Construct_UPackage__Script_hydraulicErosion();
// End Cross Module References

// Begin Class Aerosion
void Aerosion::StaticRegisterNativesAerosion()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(Aerosion);
UClass* Z_Construct_UClass_Aerosion_NoRegister()
{
	return Aerosion::StaticClass();
}
struct Z_Construct_UClass_Aerosion_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "erosion.h" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetLandscape_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfDroplets_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDropletSteps_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeStep_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_minSlope_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SedimentCapacityFactor_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErosionRate_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DepositionRate_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EvaporationRate_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[] = {
		{ "Category", "Erosion Parameters" },
		{ "ModuleRelativePath", "erosion.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetLandscape;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfDroplets;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDropletSteps;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeStep;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_minSlope;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SedimentCapacityFactor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ErosionRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DepositionRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EvaporationRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Aerosion>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_TargetLandscape = { "TargetLandscape", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, TargetLandscape), Z_Construct_UClass_ALandscape_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetLandscape_MetaData), NewProp_TargetLandscape_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_NumberOfDroplets = { "NumberOfDroplets", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, NumberOfDroplets), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NumberOfDroplets_MetaData), NewProp_NumberOfDroplets_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_MaxDropletSteps = { "MaxDropletSteps", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, MaxDropletSteps), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDropletSteps_MetaData), NewProp_MaxDropletSteps_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_TimeStep = { "TimeStep", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, TimeStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeStep_MetaData), NewProp_TimeStep_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_minSlope = { "minSlope", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, minSlope), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_minSlope_MetaData), NewProp_minSlope_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_SedimentCapacityFactor = { "SedimentCapacityFactor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, SedimentCapacityFactor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SedimentCapacityFactor_MetaData), NewProp_SedimentCapacityFactor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_ErosionRate = { "ErosionRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, ErosionRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErosionRate_MetaData), NewProp_ErosionRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_DepositionRate = { "DepositionRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, DepositionRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DepositionRate_MetaData), NewProp_DepositionRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_EvaporationRate = { "EvaporationRate", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, EvaporationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EvaporationRate_MetaData), NewProp_EvaporationRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_Aerosion_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Aerosion, Gravity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gravity_MetaData), NewProp_Gravity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_Aerosion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_TargetLandscape,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_NumberOfDroplets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_MaxDropletSteps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_TimeStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_minSlope,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_SedimentCapacityFactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_ErosionRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_DepositionRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_EvaporationRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_Aerosion_Statics::NewProp_Gravity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Aerosion_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_Aerosion_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_hydraulicErosion,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_Aerosion_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_Aerosion_Statics::ClassParams = {
	&Aerosion::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_Aerosion_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_Aerosion_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_Aerosion_Statics::Class_MetaDataParams), Z_Construct_UClass_Aerosion_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_Aerosion()
{
	if (!Z_Registration_Info_UClass_Aerosion.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_Aerosion.OuterSingleton, Z_Construct_UClass_Aerosion_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_Aerosion.OuterSingleton;
}
template<> HYDRAULICEROSION_API UClass* StaticClass<Aerosion>()
{
	return Aerosion::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(Aerosion);
Aerosion::~Aerosion() {}
// End Class Aerosion

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_zryan_saeed_Documents_Unreal_Projects_hydraulicErosion_Source_hydraulicErosion_erosion_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_Aerosion, Aerosion::StaticClass, TEXT("Aerosion"), &Z_Registration_Info_UClass_Aerosion, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(Aerosion), 2615507593U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_zryan_saeed_Documents_Unreal_Projects_hydraulicErosion_Source_hydraulicErosion_erosion_h_3403732257(TEXT("/Script/hydraulicErosion"),
	Z_CompiledInDeferFile_FID_Users_zryan_saeed_Documents_Unreal_Projects_hydraulicErosion_Source_hydraulicErosion_erosion_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_zryan_saeed_Documents_Unreal_Projects_hydraulicErosion_Source_hydraulicErosion_erosion_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
