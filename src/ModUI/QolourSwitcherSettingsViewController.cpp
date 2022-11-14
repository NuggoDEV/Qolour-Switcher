#include "ModUI/QolourSwitcherViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
using namespace BSML;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;


DEFINE_TYPE(QolourSwitcher::UI, QolourSwitcherSettingsViewController);

void QolourSwitcher::UI::QolourSwitcherSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (firstActivation)
    {
        auto parser = BSMLParser::parse(IncludedAssets::MainSettings_bsml);
        parser->Construct(get_transform(), this);

        
    }
}