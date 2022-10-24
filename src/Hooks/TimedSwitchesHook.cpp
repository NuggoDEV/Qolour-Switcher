#include "main.hpp"
#include "QolourSwitcherHooks.hpp"
#include "QolourSwitcherConfig.hpp"

#include "GlobalNamespace/AudioTimeSyncController.hpp"

#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Object.hpp"
#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
using namespace Chroma;

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);
    int timeData = self->songTime;

    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    auto colourA = colourScheme->saberAColor;
    auto colourB = colourScheme->saberBColor;

    if (timeData == 10)
    {
        NoteAPI::setGlobalNoteColorSafe(Color(0.1, 0.1, 0.1, 0.5), Color(0.5, 0.5, 0.5, 0.1));
    } else if (timeData == 15)
    {
        NoteAPI::setGlobalNoteColorSafe(colourA, colourB);
    }
}