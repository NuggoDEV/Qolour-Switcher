#include "ModUI/QolourSwitcherViewController.hpp"
#include "ModConfig.hpp"

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
        auto container = BeatSaberUI::CreateScrollView(get_transform());
        
        BeatSaberUI::CreateColorPicker(container->get_transform(), "Left Saber Colour", colourScheme->get_saberAColor(), [colourScheme](UnityEngine::Color value)
        {
            colourScheme->saberAColor = value;
        });

        BeatSaberUI::CreateColorPicker(container->get_transform(), "Right Saber Colour", colourScheme->get_saberBColor(), [colourScheme](UnityEngine::Color value)
        {
            colourScheme->saberBColor = value;
        });

        BeatSaberUI::CreateColorPicker(container->get_transform(), "Bomb Colour", getModConfig().BombColour.GetValue(), [colourScheme](UnityEngine::Color value)
        {
            getModConfig().BombColour.SetValue(value);
        });

        BeatSaberUI::CreateColorPicker(container->get_transform(), "Wall Colour", colourScheme->get_obstaclesColor(), [colourScheme](UnityEngine::Color value)
        {
            colourScheme->obstaclesColor = value;
        });
    }
}