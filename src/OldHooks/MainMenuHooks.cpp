#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "QolourSwitcherHooks.hpp"


#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/MainMenuViewController.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Object.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
using namespace UnityEngine::UI;
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
#include "TMPro/TextAlignmentOptions.hpp"
using namespace TMPro;


GameObject *textScreen;
GameObject *doRestore;
GameObject *dontRestore;
TextMeshProUGUI *text;

MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    //auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);
    
    // Enables Custom Colours if it isn't already set to active
    bool customColours = playerData->colorSchemesSettings->overrideDefaultColors;
    if (!customColours)
    {
        playerData->colorSchemesSettings->overrideDefaultColors = true;
    }

    // Enables HUD if game crashed before returning to the songs list
    //if (getModConfig().DidUserCrash.GetValue())
    //{
    //    textScreen = BeatSaberUI::CreateFloatingScreen(Vector2(50.0f, 30.0f), Vector3(0.0f, 1.0f, 2.0f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
    //    doRestore = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(-0.3f, 0.675f, 1.95f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
    //    dontRestore = BeatSaberUI::CreateFloatingScreen(Vector2(1.0f, 1.0f), Vector3(0.3f, 0.675f, 1.95f), Vector3(0.0f, 0.0f, 0.0f), 0.0f, false, false);
//
    //    // Stuff to make a canvas work, don't know what any of this means
    //    auto test = BeatSaberUI::CreateCanvas();
    //    test->AddComponent<HMUI::Screen *>();
    //    auto canvasTransform = reinterpret_cast<RectTransform *>(test->get_transform());
    //    canvasTransform->set_localPosition({0.0f, 1.0f, 2.0f});
    //    auto modalSize = BeatSaberUI::CreateModal(test->get_transform(), [test](auto modal)
    //    {
    //        Object::Destroy(test);
    //    }, true);
//
    //    Vector2 sizeDelta(50.0f, 30.0f);
    //    reinterpret_cast<RectTransform *>(modalSize->get_transform())->set_sizeDelta(sizeDelta);
    //    auto horizontal = BeatSaberUI::CreateHorizontalLayoutGroup(modalSize->get_transform());
    //    auto vertical = BeatSaberUI::CreateVerticalLayoutGroup(modalSize->get_transform());
//
    //    auto layout = vertical;
    //    auto button1 = horizontal;
    //    auto button2 = horizontal;
//
    //    auto *layoutElem = layout->get_gameObject()->AddComponent<LayoutElement *>();
    //    auto *button1Elem = button1->get_gameObject()->AddComponent<LayoutElement *>();
    //    auto *button2Elem = button2->get_gameObject()->AddComponent<LayoutElement *>();
    //    layoutElem->set_preferredHeight(sizeDelta.x);
    //    layoutElem->set_preferredWidth(sizeDelta.y);
//
    //    layout->set_childAlignment(TextAnchor::MiddleCenter);
    //    button1->set_childAlignment(TextAnchor::LowerLeft);
    //    button2->set_childAlignment(TextAnchor::LowerRight);
//
    //    layout->set_childControlHeight(true);
    //    layout->set_childForceExpandHeight(true);
    //    layout->set_childControlWidth(true);
    //    layout->set_childForceExpandWidth(true);
    //    
//
    //    modalSize->Show(true, true, nullptr);
//
//
    //    text = BeatSaberUI::CreateText(layout->get_transform(), "It appears your game has crashed or has been closed before returning\nto the song selection screen.\n\nWould you like to restore the colours used at the start of the level?");
    //    text->set_alignment(TextAlignmentOptions::Center);
    //    text->set_fontSize(2.0f);
    //    
//
    //    auto restore = BeatSaberUI::CreateUIButton(button1->get_transform(), "Yes", "ActionButton",  {-10, 0}, [colourScheme]() 
    //    {
    //        
    //        colourScheme->saberAColor = getModConfig().LeftStart.GetValue();
    //        colourScheme->saberBColor = getModConfig().RightStart.GetValue();
    //        getModConfig().BombColour.SetValue(getModConfig().BombStart.GetValue());
    //        colourScheme->obstaclesColor = getModConfig().WallStart.GetValue();
    //    });
    //    Object::Destroy(restore->get_transform()->Find("Content")->GetComponent<LayoutElement *>());
//
    //    auto noRestore = BeatSaberUI::CreateUIButton(button2->get_transform(), "No", "ActionButton", {-10, 0}, []() 
    //    {
//
    //    });
    //    Object::Destroy(noRestore->get_transform()->Find("Content")->GetComponent<LayoutElement *>());
    //}

    if (getModConfig().ColourPickerLocation.GetValue() == "Top")
    {
        getModConfig().LeftNotePosition.SetValue({ -0.4f, 2.85f, 2.4f });
        getModConfig().LeftNoteRotation.SetValue({ -30.0f, 0.0f, 0.0f });

        getModConfig().RightNotePosition.SetValue({ 0.4f, 2.85f, 2.4f });
        getModConfig().RightNoteRotation.SetValue({ -30.0f, 0.0f, 0.0f });

        getModConfig().BombPosition.SetValue({ -1.2f, 2.85f, 2.4f });
        getModConfig().BombRotation.SetValue({ -30.0f, 0.0f, 0.0f });

        getModConfig().WallPosition.SetValue({ 1.2f, 2.85f, 2.4f });
        getModConfig().WallRotation.SetValue({ -30.0f, 0.0f, 0.0f });
    }
    else if (getModConfig().ColourPickerLocation.GetValue() == "Left Side")
    {
        getModConfig().LeftNotePosition.SetValue({ -2.0f, 1.9f, 0.2f });
        getModConfig().LeftNoteRotation.SetValue({ 0.0f, -89.0f, 0.0f });

        getModConfig().RightNotePosition.SetValue({ -1.985f, 1.9f, 1.1f });
        getModConfig().RightNoteRotation.SetValue({ 0.0f, -89.0f, 0.0f  });

        getModConfig().BombPosition.SetValue({ -2.0f, 1.5f, 0.2f });
        getModConfig().BombRotation.SetValue({ 0.0f, -89.0f, 0.0f });

        getModConfig().WallPosition.SetValue({ -1.985f, 1.5f, 1.1f });
        getModConfig().WallRotation.SetValue({ 0.0f, -89.0f, 0.0f });
    }
    else if (getModConfig().ColourPickerLocation.GetValue() == "Right Side")
    {
        getModConfig().LeftNotePosition.SetValue({ 2.0f, 1.9f, 0.2f });
        getModConfig().LeftNoteRotation.SetValue({ 0.0f, 89.0f, 0.0f });

        getModConfig().RightNotePosition.SetValue({ 1.985f, 1.9f, 1.1f });
        getModConfig().RightNoteRotation.SetValue({ 0.0f, 89.0f, 0.0f  });

        getModConfig().BombPosition.SetValue({ 2.0f, 1.5f, 0.2f });
        getModConfig().BombRotation.SetValue({ 0.0f, 89.0f, 0.0f });

        getModConfig().WallPosition.SetValue({ 1.985f, 1.5f, 1.1f });
        getModConfig().WallRotation.SetValue({ 0.0f, 89.0f, 0.0f });
    }
}


