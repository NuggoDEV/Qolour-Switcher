#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"

#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
using namespace Chroma;

#include "GlobalNamespace/SaberModelController.hpp"
#include "GlobalNamespace/SaberManager.hpp"
#include "GlobalNamespace/Saber.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "System/Collections/Generic/Dictionary_2.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"

#include "UnityEngine/Object.hpp"
using namespace UnityEngine;
using namespace GlobalNamespace;


MAKE_AUTO_HOOK_MATCH(BeatEffectSpawner_Update, &BeatEffectSpawner::Update, void, BeatEffectSpawner *self)
{
    if (!getModConfig().ModToggle.GetValue())
    {
        getLogger().info("Colours Updated");
        auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
        auto playerData = playerDataModel->playerData;
        auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

        auto colourA = colourScheme->saberAColor;
        auto colourB = colourScheme->saberBColor;

        NoteAPI::setGlobalNoteColorSafe(std::make_optional(colourA), std::make_optional(colourB));
        getModConfig().ColoursChanged.SetValue(false);
    }
}