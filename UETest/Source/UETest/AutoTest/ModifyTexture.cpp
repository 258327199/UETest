
//use to test FileFunLibrary functions
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AutomationTest.h"
#include "FileHelpers.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

DEFINE_LOG_CATEGORY_STATIC(ModifyTextureLog, Log, All);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FModifyTexture, "AssetData.ModifyTextureData", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FModifyTexture::RunTest(const FString& Parameters)
{
	//注意，此处路径不能直接放/Game
	FString FilePath = TEXT("/Game/StarterContent/Textures/T_Brick_Clay_Beveled_D");
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/StarterContent/Textures/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'"));
	if (Texture != nullptr)
	{
		Texture->MaxTextureSize = 512;
		//Texture->MarkPackageDirty();
		TArray<UPackage*> PackagesToSave;
		check((Texture != nullptr) && (Texture->IsAsset()));
		PackagesToSave.Add(Texture->GetOutermost());
		FEditorFileUtils::EPromptReturnCode ret = FEditorFileUtils::PromptForCheckoutAndSave(PackagesToSave, false, false);
	}
	return true;
}