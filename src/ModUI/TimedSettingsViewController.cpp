#include "ModUI/TimedSettingsViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

DEFINE_TYPE(QolourSwitcher::UI, TimedSettingsViewController);


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

void QolourSwitcher::UI::TimedSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        auto container = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        container->set_spacing(0.2f);

        TextMeshProUGUI *title = BeatSaberUI::CreateText(container->get_transform(), "Timed Settings");
        title->set_fontSize(6.0f);
        title->set_alignment(TextAlignmentOptions::Center);


        TextMeshProUGUI *text1 = BeatSaberUI::CreateText(container->get_transform(), "First Timed Switch");
        text1->set_fontSize(4.0f);
        text1->set_alignment(TextAlignmentOptions::Center);

        auto slider1 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "", 1, getModConfig().TimedSwitch1Int.GetValue(), 1, 120, [&](int value)
        {   getModConfig().TimedSwitch1Int.SetValue(value);   });
        slider1->FormatString = std::move(SecondsToString);


        TextMeshProUGUI *text2 = BeatSaberUI::CreateText(container->get_transform(), "Second Timed Switch");
        text2->set_fontSize(4.0f);
        text2->set_alignment(TextAlignmentOptions::Center);

        auto slider2 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "", 1, getModConfig().TimedSwitch2Int.GetValue(), getModConfig().TimedSwitch1Int.GetValue(), 240, [&](int value)
        {   getModConfig().TimedSwitch2Int.SetValue(value);   });
        slider2->FormatString = std::move(SecondsToString);


        TextMeshProUGUI *text3 = BeatSaberUI::CreateText(container->get_transform(), "Third Timed Switch");
        text3->set_fontSize(4.0f);
        text3->set_alignment(TextAlignmentOptions::Center);

        auto slider3 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "", 1, getModConfig().TimedSwitch3Int.GetValue(), getModConfig().TimedSwitch2Int.GetValue(), 360, [&](int value)
        {   getModConfig().TimedSwitch3Int.SetValue(value);   });
        slider3->FormatString = std::move(SecondsToString);


        TextMeshProUGUI *text4 = BeatSaberUI::CreateText(container->get_transform(), "Fourth Timed Switch");
        text4->set_fontSize(4.0f);
        text4->set_alignment(TextAlignmentOptions::Center);

        auto slider4 = BeatSaberUI::CreateSliderSetting(container->get_transform(), "", 1, getModConfig().TimedSwitch4Int.GetValue(), getModConfig().TimedSwitch3Int.GetValue(), 480, [&](int value)
        {   getModConfig().TimedSwitch4Int.SetValue(value);   });
        slider4->FormatString = std::move(SecondsToString);

    }
}