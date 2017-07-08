// Fill out your copyright notice in the Description page of Project Settings.


#include "FileFunLibrary.h"
#include "EngineUtils.h"
#include "ARFilter.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "UETest.h"

#pragma optimize("", off)

TArray<UObject*> UFileFunLibrary::LoadAllUAsset(const FString&  ResDir)
{
	if(ResDir.IsEmpty())
	{
		UETEST_ERROR(TEXT("ResDir is Empty!"));
	}
	TArray<UObject*> LoadedObjects;
	/*
	//此方法只能获取当前ResDir下的所有Obj，而不能获取它的子目录里的Obj
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetDatas;
	//过滤器
	FARFilter Filter;
	//类型过滤
	//Filter.Classes.Add(UStaticMesh::StaticClass());
	//查找目标目录
	Filter.PackagePaths.Add(FName(*ResDir));
	AssetRegistryModule.Get().GetAssets(Filter, AssetDatas);
	for (FAssetData item : AssetDatas)
	{
		UObject* itemobj = item.GetAsset();
		LoadedObjects.Add(itemobj);
	}*/
	EngineUtils::FindOrLoadAssetsByPath(ResDir, LoadedObjects, EngineUtils::ATL_Regular);
	return LoadedObjects;
}


TArray<FString> UFileFunLibrary::GetAllFilePathes(const FString& ResDir)
{
	// Gather the package files in that directory and subdirectories
	TArray<FString> Filenames;
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetRegistryModule.Get().GetSubPaths(ResDir, Filenames, true);
	for (FString names : Filenames)
	{
		UETEST_INFO(TEXT("FileName[%s]"), *names);
	}
	return Filenames;
}

TArray<FAssetData> UFileFunLibrary::GetAssetsByDir(FString ResDir)
{
	TArray<FString> Pathes;
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetRegistryModule.Get().GetAllCachedPaths(Pathes); //此方法会包含引擎目录，如不需要，可以使用GetSubPaths
	TArray<FAssetData> AssetDatas;
	/*
	//仅能查找当前指定目录下的资源，不能迭代查找它的子目录
	//过滤器
	FARFilter Filter;
	//类型过滤
	//Filter.Classes.Add(UStaticMesh::StaticClass());
	//查找目标目录
	Filter.PackagePaths.Add(FName(*ResDir));
	AssetRegistryModule.Get().GetAllAssets(Filter, AssetDatas);
	*/
	AssetRegistryModule.Get().GetAssetsByPath(*ResDir, AssetDatas, true);
	for (FAssetData item : AssetDatas)
	{
		UETEST_INFO(TEXT("ObjectPath[%s]"), *(item.ObjectPath.ToString()));
		UETEST_INFO(TEXT("PackageName[%s]"), *(item.PackageName.ToString()));
		UETEST_INFO(TEXT("PackagePath[%s]"), *(item.PackagePath.ToString()));
		UETEST_INFO(TEXT("AssetName[%s]"), *(item.AssetName.ToString()));
		UETEST_INFO(TEXT("AssetClass[%s]"), *(item.AssetClass.ToString()));
		//UObject* Obj = item.GetAsset();
	}
	TArray<UObject*> LoadedObjects;
	EngineUtils::FindOrLoadAssetsByPath(ResDir, LoadedObjects, EngineUtils::ATL_Regular);
	return AssetDatas;
}

#pragma optimize("", on)