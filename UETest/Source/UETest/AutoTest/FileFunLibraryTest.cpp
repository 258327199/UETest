
//use to test FileFunLibrary functions
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "FunctionLibrary/FileFunLibrary.h"
#include "AutomationTest.h"

DEFINE_LOG_CATEGORY_STATIC(FileFunLibraryLog, Log, All);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAssetTest, "AssetData.GetAllAssetData", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FAssetTest::RunTest(const FString& Parameters)
{
	//注意，此处路径不能直接放/Game
	FString ResDir = TEXT("/Game/BP");
	//FString ResDir1 = TEXT("/Game/Maps");
	UFileFunLibrary::GetAssetsByDir(ResDir);
	//UFileFunLibrary::GetAssetsByDir(ResDir1);
	UFileFunLibrary::GetAllFilePathes(TEXT("/Game"));
	UFileFunLibrary::LoadAllUAsset(ResDir);
	return true;
}