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
	//�˷���ֻ�ܻ�ȡ��ǰResDir�µ�����Obj�������ܻ�ȡ������Ŀ¼���Obj
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	TArray<FAssetData> AssetDatas;
	//������
	FARFilter Filter;
	//���͹���
	//Filter.Classes.Add(UStaticMesh::StaticClass());
	//����Ŀ��Ŀ¼
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
	AssetRegistryModule.Get().GetAllCachedPaths(Pathes); //�˷������������Ŀ¼���粻��Ҫ������ʹ��GetSubPaths
	TArray<FAssetData> AssetDatas;
	/*
	//���ܲ��ҵ�ǰָ��Ŀ¼�µ���Դ�����ܵ�������������Ŀ¼
	//������
	FARFilter Filter;
	//���͹���
	//Filter.Classes.Add(UStaticMesh::StaticClass());
	//����Ŀ��Ŀ¼
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