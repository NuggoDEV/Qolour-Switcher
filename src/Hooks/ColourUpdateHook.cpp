#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
using namespace Chroma;

#include "GlobalNamespace/AudioTimeSyncController.hpp"

#include "GlobalNamespace/SaberModelController.hpp"
#include "GlobalNamespace/SaberManager.hpp"
#include "GlobalNamespace/Saber.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "System/Collections/Generic/Dictionary_2.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/PauseMenuManager.hpp"

#include "UnityEngine/Object.hpp"
using namespace UnityEngine;
using namespace GlobalNamespace;


MAKE_AUTO_HOOK_MATCH(CUH_PauseMenuManager_ContinueButtonPressed, &PauseMenuManager::ContinueButtonPressed, void, PauseMenuManager *self)
{
    CUH_PauseMenuManager_ContinueButtonPressed(self);
    
    getLogger().info("Finding All Colours.");

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    auto colourA = colourScheme->saberAColor;
    auto colourB = colourScheme->saberBColor;
    Color wallColour = colourScheme->obstaclesColor;
    Color bombColour = getModConfig().BombColour.GetValue();

    getLogger().info("All Colours Found!");

    if (getModConfig().ColoursChanged.GetValue())
    {
        getLogger().info("Updating Colours!");

        NoteAPI::setGlobalNoteColorSafe(std::make_optional(colourA), std::make_optional(colourB));
        BombAPI::setGlobalBombColorSafe(bombColour);
        ObstacleAPI::setAllObstacleColorSafe(wallColour);
        
        getModConfig().ColoursChanged.SetValue(false);

        getLogger().info("Colours Updated");
    }
}

//#include "GlobalNamespace/AudioTimeSyncController.hpp"
//
//MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
//{
//    AudioTimeSyncController_Update(self);
//    int timeData = self->songTime;
//
//    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
//    auto playerData = playerDataModel->playerData;
//    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);
//
//    auto colourA = colourScheme->saberAColor;
//    auto colourB = colourScheme->saberBColor;
//
//    if (timeData == 10)
//    {
//        NoteAPI::setGlobalNoteColorSafe(Color(0.1, 0.1, 0.1, 0.5), Color(0.5, 0.5, 0.5, 0.1));
//    } else if (timeData == 15)
//    {
//        NoteAPI::setGlobalNoteColorSafe(colourA, colourB);
//    }
//    
//}

//MAKE_AUTO_HOOK_MATCH(a, &AudioTimeSyncController::Awake, void, AudioTimeSyncController *self)
//{
//    a(self);
//
//    auto SongTimeModel = Object::FindObjectOfType<AudioTimeSyncController *>();
//    float SongTime = SongTimeModel->songTime;
//
//    if (SongTime == 10.0f)
//    {
//        NoteAPI::setGlobalNoteColorSafe(Color(1, 0, 0, 1), Color(0, 1, 0, 1));
//    }
//}