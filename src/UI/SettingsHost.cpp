#include "ModUI/SettingsHost.hpp"
#include "test.hpp"

#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DEFINE_TYPE(QolourSwitcher, SettingsHost);

namespace QolourSwitcher
{
    SafePtr<SettingsHost> SettingsHost::instance;
    SettingsHost *SettingsHost::get_instance()
    {
        if (!instance) 
        {
            instance = SettingsHost::New_ctor();
        }
        return instance.ptr();
    }

    void SettingsHost::ctor()
    {

    }

    bool SettingsHost::get_toggleSwitch1() {return getModConfig().toggleSwitch1.GetValue();}
    void SettingsHost::set_toggleSwitch1(bool value) {getModConfig().toggleSwitch1.SetValue(value);}

    bool SettingsHost::get_toggleSwitch2() {return getModConfig().toggleSwitch2.GetValue();}
    void SettingsHost::set_toggleSwitch2(bool value) {getModConfig().toggleSwitch2.SetValue(value);}

    bool SettingsHost::get_toggleSwitch3() {return getModConfig().toggleSwitch3.GetValue();}
    void SettingsHost::set_toggleSwitch3(bool value) {getModConfig().toggleSwitch3.SetValue(value);}

    bool SettingsHost::get_toggleSwitch4() {return getModConfig().toggleSwitch4.GetValue();}
    void SettingsHost::set_toggleSwitch4(bool value) {getModConfig().toggleSwitch4.SetValue(value);}

    float SettingsHost::get_timedSwitch1() {return getModConfig().timedSwitch1.GetValue();}
    void SettingsHost::set_timedSwitch1(float value) {getModConfig().timedSwitch1.SetValue(value);}

    float SettingsHost::get_timedSwitch2() {return getModConfig().timedSwitch2.GetValue();}
    void SettingsHost::set_timedSwitch2(float value) {getModConfig().timedSwitch2.SetValue(value);}

    float SettingsHost::get_timedSwitch3() {return getModConfig().timedSwitch3.GetValue();}
    void SettingsHost::set_timedSwitch3(float value) {getModConfig().timedSwitch3.SetValue(value);}

    float SettingsHost::get_timedSwitch4() {return getModConfig().timedSwitch4.GetValue();}
    void SettingsHost::set_timedSwitch4(float value) {getModConfig().timedSwitch4.SetValue(value);}


    // Timed Switch 1
    Color SettingsHost::get_timedSwitch1LeftColour() {return getModConfig().timedSwitch1LeftColour.GetValue();}
    void SettingsHost::set_timedSwitch1LeftColour(Color value) {getModConfig().timedSwitch1LeftColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch1RightColour() {return getModConfig().timedSwitch1RightColour.GetValue();}
    void SettingsHost::set_timedSwitch1RightColour(Color value) {getModConfig().timedSwitch1RightColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch1BombColour() {return getModConfig().timedSwitch1BombColour.GetValue();}
    void SettingsHost::set_timedSwitch1BombColour(Color value) {getModConfig().timedSwitch1BombColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch1WallColour() {return getModConfig().timedSwitch1WallColour.GetValue();}
    void SettingsHost::set_timedSwitch1WallColour(Color value) {getModConfig().timedSwitch1WallColour.SetValue(value);}


    // Timed Switch 2
    Color SettingsHost::get_timedSwitch2LeftColour() {return getModConfig().timedSwitch2LeftColour.GetValue();}
    void SettingsHost::set_timedSwitch2LeftColour(Color value) {getModConfig().timedSwitch2LeftColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch2RightColour() {return getModConfig().timedSwitch2RightColour.GetValue();}
    void SettingsHost::set_timedSwitch2RightColour(Color value) {getModConfig().timedSwitch2RightColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch2BombColour() {return getModConfig().timedSwitch2BombColour.GetValue();}
    void SettingsHost::set_timedSwitch2BombColour(Color value) {getModConfig().timedSwitch2BombColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch2WallColour() {return getModConfig().timedSwitch2WallColour.GetValue();}
    void SettingsHost::set_timedSwitch2WallColour(Color value) {getModConfig().timedSwitch2WallColour.SetValue(value);}


    // Timed Switch 3
    Color SettingsHost::get_timedSwitch3LeftColour() {return getModConfig().timedSwitch3LeftColour.GetValue();}
    void SettingsHost::set_timedSwitch3LeftColour(Color value) {getModConfig().timedSwitch3LeftColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch3RightColour() {return getModConfig().timedSwitch3RightColour.GetValue();}
    void SettingsHost::set_timedSwitch3RightColour(Color value) {getModConfig().timedSwitch3RightColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch3BombColour() {return getModConfig().timedSwitch3BombColour.GetValue();}
    void SettingsHost::set_timedSwitch3BombColour(Color value) {getModConfig().timedSwitch3BombColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch3WallColour() {return getModConfig().timedSwitch3WallColour.GetValue();}
    void SettingsHost::set_timedSwitch3WallColour(Color value) {getModConfig().timedSwitch3WallColour.SetValue(value);}


    // Timed Switch 4
    Color SettingsHost::get_timedSwitch4LeftColour() {return getModConfig().timedSwitch4LeftColour.GetValue();}
    void SettingsHost::set_timedSwitch4LeftColour(Color value) {getModConfig().timedSwitch4LeftColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch4RightColour() {return getModConfig().timedSwitch4RightColour.GetValue();}
    void SettingsHost::set_timedSwitch4RightColour(Color value) {getModConfig().timedSwitch4RightColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch4BombColour() {return getModConfig().timedSwitch4BombColour.GetValue();}
    void SettingsHost::set_timedSwitch4BombColour(Color value) {getModConfig().timedSwitch4BombColour.SetValue(value);}

    Color SettingsHost::get_timedSwitch4WallColour() {return getModConfig().timedSwitch4WallColour.GetValue();}
    void SettingsHost::set_timedSwitch4WallColour(Color value) {getModConfig().timedSwitch4WallColour.SetValue(value);}
}