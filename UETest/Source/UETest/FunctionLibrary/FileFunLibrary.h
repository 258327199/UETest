// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AssetData.h"
#include "AssetRegistryModule.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileFunLibrary.generated.h"

/**
 * 
 */
class FAssetData;
UCLASS()
class UETEST_API UFileFunLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	//遍历文件夹，加载所有的uasset
	UFUNCTION(BlueprintCallable, Category = "FileFunLibrary")
		static TArray<UObject*> LoadAllUAsset(const FString&  ResDir);
	

	//获取指定目录下的所有文件名
	/*
	ResDir:获取资源的目录，如/Game/Meshes
	*/
	UFUNCTION(BlueprintCallable, Category = "FileFunLibrary")
		static TArray<FString> GetAllFilePathes(const FString& ResDir);


	//获取当前目录所有资源，不会迭代到它的子件夹里
	/*
	ResDir:获取资源的目录，如/Game/Meshes
	*/
		static TArray<FAssetData> GetAssetsByDir(FString ResDir);

};
