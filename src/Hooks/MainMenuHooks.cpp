#include "main.hpp"
#include "ModConfig.hpp"
#include "Hooks.hpp"


#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "GlobalNamespace/MainMenuViewController.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Resources.hpp"
using namespace UnityEngine;



//#define STATIC_AUTO(name, definition) 
//static auto& name = ResettableStaticPtr::registerPointer(definition); 
//if(!name) name = definition;
//
//template<class T>
//T FindComponent() {
//    STATIC_AUTO(cachedComponent, UnityEngine::Resources::FindObjectsOfTypeAll<T>().FirstOrDefault());
//    if(!cachedComponent) SAFE_ABORT();
//    return cachedComponent;
//}


MAKE_AUTO_HOOK_MATCH(MainMenuViewController_DidActivate, &MainMenuViewController::DidActivate, void, MainMenuViewController *self, bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    MainMenuViewController_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);
    auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
    auto playerData = playerDataModel->playerData;
    auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);
    bool customColours = playerData->colorSchemesSettings->overrideDefaultColors;

    if (!customColours)
    {
        customColours = true;
    }
    
    if (getModConfig().DidUserCrash.GetValue())
    {
        //auto parent = FindComponent<MainMenuViewController *>()->get_transform();
        //auto modal = BeatSaberUI::CreateModal(parent, {65, 41}, nullptr, false);
//
        //TMPro::TextMeshProUGUI *modalTitle = BeatSaberUI::CreateText(modal->get_transform(), "Qolour Switcher");
        //modalTitle->set_fontSize(8.0f);
        //
//
        //TMPro::TextMeshProUGUI *modalText = BeatSaberUI::CreateText(modal->get_transform(), "It appears your game has crashed or closed before returning to the songs list.\nWould you like to restore your original colours?");
        //modalText->set_fontSize(6.0f);
//
        //auto restoreColours = BeatSaberUI::CreateUIButton(modal->get_transform(), "Yes", "ActionButton", {-16, -14}, [modal, colourScheme]() {
        //    modal->Hide(true, nullptr);
        //    colourScheme->saberAColor = getModConfig().LeftStart.GetValue();
        //    colourScheme->saberBColor = getModConfig().RightStart.GetValue();
        //    colourScheme->obstaclesColor = getModConfig().WallStart.GetValue();
        //    getModConfig().BombColour.SetValue(getModConfig().BombStart.GetValue());
//
        //    getModConfig().DidUserCrash.SetValue(false);
        //});
        //Object::Destroy(restoreColours->get_transform()->Find("Content")->GetComponent<UI::LayoutElement*>());
//
        //auto dontRestore = BeatSaberUI::CreateUIButton(modal->get_transform(), "No", "ActionButton", {16, -14}, [modal] {
        //    modal->Hide(true, nullptr);
//
        //    getModConfig().DidUserCrash.SetValue(false);
        //});
        //Object::Destroy(dontRestore->get_transform()->Find("Content")->GetComponent<UI::LayoutElement*>());
    }
}

