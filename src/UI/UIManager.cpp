#include "UI/UIManager.hpp"
#include "ModConfig.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

DEFINE_TYPE(QolourSwitcher::UI, UIManager);

namespace QolourSwitcher::UI
{
    SafePtr<UIManager> UIManager::instance;
    UIManager *UIManager::get_instance()
    {
        if (!instance)
            instance = UIManager::New_ctor();
        return instance.ptr();
    }
    void UIManager::ctor()
    {

    }


    Color UIManager::get_LeftSaber() { return getModConfig().LeftSaber.GetValue(); }
    void UIManager::set_LeftSaber(Color value) { getModConfig().LeftSaber.SetValue(value); }

    Color UIManager::get_RightSaber() { return getModConfig().RightSaber.GetValue(); }
    void UIManager::set_RightSaber(Color value) { getModConfig().RightSaber.SetValue(value); }

    Color UIManager::get_BombColour() { return getModConfig().BombColour.GetValue(); }
    void UIManager::set_BombColour(Color value) { return getModConfig().BombColour.SetValue(value); }

    Color UIManager::get_WallColour() { return getModConfig().WallColour.GetValue(); }
    void UIManager::set_WallColour(Color value) { getModConfig().WallColour.SetValue(value); }



    bool UIManager::get_TimedToggle1() { return getModConfig().TimedToggle1.GetValue(); }
    void UIManager::set_TimedToggle1(bool value) { getModConfig().TimedToggle1.SetValue(value); }

    float UIManager::get_TimedActivation1() { return getModConfig().TimedActivation1.GetValue(); }
    void UIManager::set_TimedActivation1(float value) { getModConfig().TimedActivation1.SetValue(value); }

    Color UIManager::get_LeftColour1() { return getModConfig().LeftSaber1.GetValue(); }
    void UIManager::set_LeftColour1(Color value) { getModConfig().LeftSaber1.SetValue(value); }

    Color UIManager::get_RightColour1() { return getModConfig().LeftSaber1.GetValue(); }
    void UIManager::set_RightColour1(Color value) { getModConfig().LeftSaber1.SetValue(value); }

    Color UIManager::get_BombColour1() { return getModConfig().BombColour1.GetValue(); }
    void UIManager::set_BombColour1(Color value) { getModConfig().BombColour1.SetValue(value); }

    Color UIManager::get_WallColour1() { return getModConfig().WallColour1.GetValue(); }
    void UIManager::set_WallColour1(Color value) { getModConfig().WallColour1.SetValue(value); }



    bool UIManager::get_TimedToggle2() { return getModConfig().TimedToggle2.GetValue(); }
    void UIManager::set_TimedToggle2(bool value) { getModConfig().TimedToggle2.SetValue(value); }

    float UIManager::get_TimedActivation2() { return getModConfig().TimedActivation2.GetValue(); }
    void UIManager::set_TimedActivation2(float value) { getModConfig().TimedActivation2.SetValue(value); }

    Color UIManager::get_LeftColour2() { return getModConfig().LeftSaber2.GetValue(); }
    void UIManager::set_LeftColour2(Color value) { getModConfig().LeftSaber2.SetValue(value); }

    Color UIManager::get_RightColour2() { return getModConfig().RightSaber2.GetValue(); }
    void UIManager::set_RightColour2(Color value) { getModConfig().RightSaber2.SetValue(value); }

    Color UIManager::get_BombColour2() { return getModConfig().BombColour2.GetValue(); }
    void UIManager::set_BombColour2(Color value) { getModConfig().BombColour2.SetValue(value); }

    Color UIManager::get_WallColour2() { return getModConfig().WallColour2.GetValue(); }
    void UIManager::set_WallColour2(Color value) { getModConfig().WallColour2.SetValue(value); }



    bool UIManager::get_TimedToggle3() { return getModConfig().TimedToggle3.GetValue(); }
    void UIManager::set_TimedToggle3(bool value) { getModConfig().TimedToggle3.SetValue(value); }

    float UIManager::get_TimedActivation3() { return getModConfig().TimedActivation3.GetValue(); }
    void UIManager::set_TimedActivation3(float value) { getModConfig().TimedActivation3.SetValue(value); }

    Color UIManager::get_LeftColour3() { return getModConfig().LeftSaber3.GetValue(); }
    void UIManager::set_LeftColour3(Color value) { getModConfig().LeftSaber3.SetValue(value); }

    Color UIManager::get_RightColour3() { return getModConfig().RightSaber3.GetValue(); }
    void UIManager::set_RightColour3(Color value) { getModConfig().RightSaber3.SetValue(value); }

    Color UIManager::get_BombColour3() { return getModConfig().BombColour3.GetValue(); }
    void UIManager::set_BombColour3(Color value) { getModConfig().BombColour3.SetValue(value); }

    Color UIManager::get_WallColour3() { return getModConfig().WallColour3.GetValue(); }
    void UIManager::set_WallColour3(Color value) { getModConfig().WallColour3.SetValue(value); }



    bool UIManager::get_TimedToggle4() { return getModConfig().TimedToggle4.GetValue(); }
    void UIManager::set_TimedToggle4(bool value) { getModConfig().TimedToggle4.SetValue(value); }

    float UIManager::get_TimedActivation4() { return getModConfig().TimedActivation4.GetValue(); }
    void UIManager::set_TimedActivation4(float value) { getModConfig().TimedActivation4.SetValue(value); }

    Color UIManager::get_LeftColour4() { return getModConfig().LeftSaber4.GetValue(); }
    void UIManager::set_LeftColour4(Color value) { getModConfig().LeftSaber4.SetValue(value); }

    Color UIManager::get_RightColour4() { return getModConfig().RightSaber4.GetValue(); }
    void UIManager::set_RightColour4(Color value) { getModConfig().RightSaber4.SetValue(value); }

    Color UIManager::get_BombColour4() { return getModConfig().BombColour4.GetValue(); }
    void UIManager::set_BombColour4(Color value) { getModConfig().BombColour4.SetValue(value); }

    Color UIManager::get_WallColour4() { return getModConfig().WallColour4.GetValue(); }
    void UIManager::set_WallColour4(Color value) { getModConfig().WallColour4.SetValue(value); }

}