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
	//�����ļ��У��������е�uasset
	UFUNCTION(BlueprintCallable, Category = "FileFunLibrary")
		static TArray<UObject*> LoadAllUAsset(const FString&  ResDir);
	

	//��ȡָ��Ŀ¼�µ������ļ���
	/*
	ResDir:��ȡ��Դ��Ŀ¼����/Game/Meshes
	*/
	UFUNCTION(BlueprintCallable, Category = "FileFunLibrary")
		static TArray<FString> GetAllFilePathes(const FString& ResDir);


	//��ȡ��ǰĿ¼������Դ����������������Ӽ�����
	/*
	ResDir:��ȡ��Դ��Ŀ¼����/Game/Meshes
	*/
		static TArray<FAssetData> GetAssetsByDir(FString ResDir);

};
