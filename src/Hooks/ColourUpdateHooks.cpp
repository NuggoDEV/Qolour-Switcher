#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"

#include "GlobalNamespace/PauseMenuManager.hpp"
#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
using namespace GlobalNamespace;

#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
using namespace Chroma;


MAKE_AUTO_HOOK_MATCH(GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
    GameplayCoreInstaller_InstallBindings(self);

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    BombAPI::setGlobalBombColorSafe(getModConfig().BombColour.GetValue());

    getModConfig().BombStart.SetValue(getModConfig().BombColour.GetValue());
    getModConfig().LeftStart.SetValue(colourScheme->get_saberAColor());
    getModConfig().RightStart.SetValue(colourScheme->get_saberBColor());
    getModConfig().WallStart.SetValue(colourScheme->get_obstaclesColor());

    getModConfig().DidUserCrash.SetValue(true);
}

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);

    int songTime = self->songTime;

    if (getModConfig().TimedSwitch1.GetValue() && songTime == getModConfig().TimedSwitch1Int.GetValue() )
        NoteAPI::setGlobalNoteColorSafe(getModConfig().TimedSwitch1LNColour.GetValue(), getModConfig().TimedSwitch1RNColour.GetValue());

    else if (getModConfig().TimedSwitch2.GetValue() && songTime == getModConfig().TimedSwitch2Int.GetValue())
        NoteAPI::setGlobalNoteColorSafe(getModConfig().TimedSwitch2LNColour.GetValue(), getModConfig().TimedSwitch2RNColour.GetValue());
    
    else if (getModConfig().TimedSwitch3.GetValue() && songTime == getModConfig().TimedSwitch3Int.GetValue())
        NoteAPI::setGlobalNoteColorSafe(getModConfig().TimedSwitch3LNColour.GetValue(), getModConfig().TimedSwitch3RNColour.GetValue());
    
    else if (getModConfig().TimedSwitch4.GetValue() && songTime == getModConfig().TimedSwitch4Int.GetValue() )
        NoteAPI::setGlobalNoteColorSafe(getModConfig().TimedSwitch4LNColour.GetValue(), getModConfig().TimedSwitch4RNColour.GetValue());

}