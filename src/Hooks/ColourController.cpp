#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
using namespace Chroma;

#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

using namespace UnityEngine;

MAKE_AUTO_HOOK_MATCH(GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
    GameplayCoreInstaller_InstallBindings(self);

    // Sets bomb colour on map start
    BombAPI::setGlobalBombColorSafe(getModConfig().BombColour.GetValue());
}


MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);

    int songTime = self->songTime;

    if (getModConfig().TimedToggle1.GetValue() && getModConfig().TimedActivation1.GetValue() == songTime)
        NoteAPI::setGlobalNoteColorSafe(getModConfig().LeftSaber1.GetValue(), getModConfig().RightSaber1.GetValue());
    
    else if (getModConfig().TimedToggle2.GetValue() && getModConfig().TimedActivation2.GetValue() == songTime)
        NoteAPI::setGlobalNoteColorSafe(getModConfig().LeftSaber2.GetValue(), getModConfig().RightSaber2.GetValue());
    
    else if (getModConfig().TimedToggle3.GetValue() && getModConfig().TimedActivation3.GetValue() == songTime)
        NoteAPI::setGlobalNoteColorSafe(getModConfig().LeftSaber3.GetValue(), getModConfig().RightSaber3.GetValue());
    
    else if (getModConfig().TimedToggle4.GetValue() && getModConfig().TimedActivation4.GetValue() == songTime)
        NoteAPI::setGlobalNoteColorSafe(getModConfig().LeftSaber4.GetValue(), getModConfig().RightSaber4.GetValue());
}