#include "ModUI/ToggleSettingsViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

DEFINE_TYPE(QolourSwitcher::UI, ToggleSettingsViewController);



std::string SecondsToString(float value)
{
    int minutes = value / 60;
    int seconds = value - minutes * 60;
    std::string minuteStr = std::to_string(minutes);
    std::string secondStr = std::to_string(seconds);

    if (minutes == 0)
    {
        return secondStr + "s";
    }
    else
    {
        return minuteStr + "m :" + secondStr + "s";
    }
}



void QolourSwitcher::UI::ToggleSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {        
        auto container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        //container->

        TextMeshProUGUI *title = BeatSaberUI::CreateText(container->get_transform(), "Toggle + Time Settings");
        title->set_fontSize(6.0f);
        title->set_alignment(TextAlignmentOptions::Center);


        auto text1 = BeatSaberUI::CreateText(container->get_transform(), "First Timed Setting");
        text1->set_fontSize(4.0f);
        text1->set_alignment(TextAlignmentOptions::Center);

        BeatSaberUI::CreateToggle(container->get_transform(), "Enable First Timed Switch", getModConfig().TimedSwitch1.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch1.SetValue(value);
        });

        auto slider1 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "First Timed Switch", 1, getModConfig().TimedSwitch1Int.GetValue(), 1, 120, [&](int value)
        {   
            getModConfig().TimedSwitch1Int.SetValue(value);
        });
        slider1->FormatString = SecondsToString;

        auto text2 = BeatSaberUI::CreateText(container->get_transform(), "Second Timed Setting");
        text2->set_fontSize(4.0f);
        text2->set_alignment(TextAlignmentOptions::Center);


        BeatSaberUI::CreateToggle(container->get_transform(), "Enable Second Timed Switch", getModConfig().TimedSwitch2.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch2.SetValue(value);
        });

        auto slider2 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "Second Timed Switch", 1, getModConfig().TimedSwitch2Int.GetValue(), getModConfig().TimedSwitch1Int.GetValue(), 240, [&](int value)
        {   getModConfig().TimedSwitch2Int.SetValue(value);   });
        slider2->FormatString = SecondsToString;

        auto text3 = BeatSaberUI::CreateText(container->get_transform(), "Third Timed Setting");
        text3->set_fontSize(4.0f);
        text3->set_alignment(TextAlignmentOptions::Center);


        BeatSaberUI::CreateToggle(container->get_transform(), "Enable Third Timed Switch", getModConfig().TimedSwitch3.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch3.SetValue(value);
        });

        auto slider3 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "Third Timed Switch", 1, getModConfig().TimedSwitch3Int.GetValue(), getModConfig().TimedSwitch2Int.GetValue(), 360, [&](int value)
        {   getModConfig().TimedSwitch3Int.SetValue(value);   });
        slider3->FormatString = SecondsToString;


        auto text4 = BeatSaberUI::CreateText(container->get_transform(), "Fourth Timed Setting");
        text4->set_fontSize(4.0f);
        text4->set_alignment(TextAlignmentOptions::Center);

        BeatSaberUI::CreateToggle(container->get_transform(), "Enable Fourth Timed Switch", getModConfig().TimedSwitch4.GetValue(), [](bool value)
        {
            getModConfig().TimedSwitch4.SetValue(value);
        });

        auto slider4 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "Fourth Timed Switch", 1, getModConfig().TimedSwitch4Int.GetValue(), getModConfig().TimedSwitch3Int.GetValue(), 480, [&](int value)
        {   getModConfig().TimedSwitch4Int.SetValue(value);   });
        slider4->FormatString = SecondsToString;
    }
}