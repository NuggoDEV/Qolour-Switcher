#include "ModUI/ToggleSettingsViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

DEFINE_TYPE(QolourSwitcher::UI, ToggleSettingsViewController);

void QolourSwitcher::UI::ToggleSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        auto container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        container->set_spacing(0.5f);

        TextMeshProUGUI *title = BeatSaberUI::CreateText(container->get_transform(), "Toggle Settings");
        title->set_fontSize(6.0f);
        title->set_alignment(TextAlignmentOptions::Center);


        BeatSaberUI::CreateToggle(container->get_transform(), "Enable First Timed Switch", getModConfig().TimedSwitch1.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch1.SetValue(value);
        });

        BeatSaberUI::CreateToggle(container->get_transform(), "Enable Second Timed Switch", getModConfig().TimedSwitch2.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch2.SetValue(value);
        });

        BeatSaberUI::CreateToggle(container->get_transform(), "Enable Third Timed Switch", getModConfig().TimedSwitch3.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch3.SetValue(value);
        });

        BeatSaberUI::CreateToggle(container->get_transform(), "Enable Fourth Timed Switch", getModConfig().TimedSwitch4.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch4.SetValue(value);
        });
    }
}