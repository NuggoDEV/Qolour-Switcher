#include "ModUI/TimedSettingsViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

DEFINE_TYPE(QolourSwitcher::UI, TimedSettingsViewController);



//SliderSetting *testSlider(auto parent, float min, float max, float current, float increment, auto onChange)
//{
//    auto sliderCreated = BeatSaberUI::CreateSliderSetting(parent, "", 0, 0, 0, 0);
//    SliderSetting *slider = sliderCreated->slider->get_gameObject()->template AddComponent<SliderSetting *>();
//    slider->slider = sliderCreated->slider;
//    //slider->FormatString = std::move(format);
//    slider->Setup(min, max, current, increment, 0, onChange);
//    auto transform = (RectTransform *) slider->slider->get_transform();
//    auto obj = transform->GetParent()->get_gameObject();
//    transform->SetParent(parent->get_transform(), false);
//    transform->set_anchorMin({0.5, 0.5});
//    transform->set_anchorMax({0.5, 0.5});
//    transform->set_pivot({0.5, 0.5});
//    UnityEngine::Object::Destroy(obj);
//
//    return slider;    
//}

void SetTransform(auto obj, Vector2 anchoredPos, Vector2 sizeDelta) {
    auto transform = (UnityEngine::RectTransform*) obj->get_transform();
    transform->set_anchoredPosition(anchoredPos);
    transform->set_sizeDelta(sizeDelta);
}


void QolourSwitcher::UI::TimedSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{

    auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModal->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

    if (firstActivation)
    {
        //auto vContainer = BeatSaberUI::CreateScrollableSettingsContainer(get_transform());
        //vContainer->AddComponent<UnityEngine::UI::VerticalLayoutGroup *>();
        auto vContainer = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());
        vContainer->set_spacing(0.1f);

        //SetTransform(vContainer, {0, 0}, {70, 10});

        auto hContainer = BeatSaberUI::CreateHorizontalLayoutGroup(vContainer->get_transform());
        hContainer->set_childAlignment(TextAlignmentOptions::Center);

        TextMeshProUGUI *title = BeatSaberUI::CreateText(vContainer->get_transform(), "Timed Switches Settings");
        title->set_fontSize(6.0f);
        title->set_alignment(TextAlignmentOptions::Center);

        
        // First Timed Switch
        TextMeshProUGUI *text1 = BeatSaberUI::CreateText(vContainer->get_transform(), "First Timed Switch");
        text1->set_fontSize(4.0f);
        text1->set_alignment(TextAlignmentOptions::Center);

        //auto slider1 = BeatSaberUI::CreateSliderSetting(vContainer->get_transform(), "First Switch", 1, getModConfig().TimedSwitch1Int.GetValue(), 1, 120, [&](int value)
        //{   
        //    getModConfig().TimedSwitch1Int.SetValue(value);
        //});
        //slider1->FormatString = SecondsToString;

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Left Saber Colour", getModConfig().TimedSwitch1LNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch1LNColour.SetValue(value);
        });

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Right Saber Colour", getModConfig().TimedSwitch1RNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch1RNColour.SetValue(value);
        });


        // Second Timed Switch
        TextMeshProUGUI *text2 = BeatSaberUI::CreateText(vContainer->get_transform(), "Second Timed Switch");
        text2->set_fontSize(4.0f);
        text2->set_alignment(TextAlignmentOptions::Center);

        //auto slider2 = BeatSaberUI::CreateSliderSetting(vContainer->get_transform(), "Second Switch", 1, getModConfig().TimedSwitch2Int.GetValue(), getModConfig().TimedSwitch1Int.GetValue(), 240, [&](int value)
        //{   getModConfig().TimedSwitch2Int.SetValue(value);   });
        //slider2->FormatString = SecondsToString;



        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Left Saber Colour", getModConfig().TimedSwitch2LNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch2LNColour.SetValue(value);
        });

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Right Saber Colour", getModConfig().TimedSwitch2RNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch2RNColour.SetValue(value);
        });


        // Third Timed Switch
        TextMeshProUGUI *text3 = BeatSaberUI::CreateText(vContainer->get_transform(), "Third Timed Switch");
        text3->set_fontSize(4.0f);
        text3->set_alignment(TextAlignmentOptions::Center);

        //auto slider3 = BeatSaberUI::CreateSliderSetting(vContainer->get_transform(), "Third Switch", 1, getModConfig().TimedSwitch3Int.GetValue(), getModConfig().TimedSwitch2Int.GetValue(), 360, [&](int value)
        //{   getModConfig().TimedSwitch3Int.SetValue(value);   });
        //slider3->FormatString = SecondsToString;

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Left Saber Colour", getModConfig().TimedSwitch3LNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch3LNColour.SetValue(value);
        });

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Right Saber Colour", getModConfig().TimedSwitch3RNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch3RNColour.SetValue(value);
        });


        // Fourth Timed Switch
        TextMeshProUGUI *text4 = BeatSaberUI::CreateText(vContainer->get_transform(), "Fourth Timed Switch");
        text4->set_fontSize(4.0f);
        text4->set_alignment(TextAlignmentOptions::Center);

        //auto slider4 = BeatSaberUI::CreateSliderSetting(vContainer->get_transform(), "Fourth Switch", 1, getModConfig().TimedSwitch4Int.GetValue(), getModConfig().TimedSwitch3Int.GetValue(), 480, [&](int value)
        //{   getModConfig().TimedSwitch4Int.SetValue(value);   });
        //slider4->FormatString = SecondsToString;

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Left Saber Colour", getModConfig().TimedSwitch4LNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch4LNColour.SetValue(value);
        });

        BeatSaberUI::CreateColorPicker(vContainer->get_transform(), "Right Saber Colour", getModConfig().TimedSwitch4RNColour.GetValue(), [](Color value)
        {
            getModConfig().TimedSwitch4RNColour.SetValue(value);
        });
    }
}