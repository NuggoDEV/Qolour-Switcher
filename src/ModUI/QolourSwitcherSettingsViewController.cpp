#include "ModUI/QolourSwitcherViewController.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

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
        auto a = BeatSaberUI::CreateScrollView(get_transform());
        BeatSaberUI::CreateText(a->get_transform(), "JFEUSROIJHGFDKULHGFDKGHFKDSJGHFSDLKJGHSL");
    }
}