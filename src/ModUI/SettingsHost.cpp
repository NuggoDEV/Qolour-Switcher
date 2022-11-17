#include "main.hpp"
#include "ModConfig.hpp"

#include "ModUI/SettingsHost.hpp"
#include "config.hpp"

#include "bsml/shared/BSML.hpp"

extern ModInfo modInfo;
extern config_t config;

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


    int SettingsHost::set_timedSwitch1(int value) { getModConfig().TimedSwitch1.SetValue(value);}

    bool SettingsHost::get_toggleSwitch1() {    return config.toggleSwitch1; getLogger().info("get_toggleSwitch1");    }
    void SettingsHost::set_toggleSwitch1(bool value) {    config.toggleSwitch1 = value;    SaveConfig(); getLogger().info("set_toggleSwitch1");    }

    bool SettingsHost::get_toggleSwitch2() {    return config.toggleSwitch2; getLogger().info("get_toggleSwitch2");    }
    void SettingsHost::set_toggleSwitch2(bool value) {    config.toggleSwitch2 = value;    SaveConfig(); getLogger().info("set_toggleSwitch2");    }

    bool SettingsHost::get_toggleSwitch3() {    return config.toggleSwitch3; getLogger().info("get_toggleSwitch3");    }
    void SettingsHost::set_toggleSwitch3(bool value) {    config.toggleSwitch3 = value;    SaveConfig(); getLogger().info("set_toggleSwitch3");    }

    bool SettingsHost::get_toggleSwitch4() {    return config.toggleSwitch4; getLogger().info("get_toggleSwitch4");    }
    void SettingsHost::set_toggleSwitch4(bool value) {    config.toggleSwitch4 = value;    SaveConfig(); getLogger().info("set_toggleSwitch4");    }


    int SettingsHost::get_timedSwitch1() {    return config.timedSwitch1; getLogger().info("get_timedSwitch1");    }
    void SettingsHost::set_timedSwitch1(int value) {    config.timedSwitch1 = value;    SaveConfig(); getLogger().info("set_timedSwitch1");    }

    int SettingsHost::get_timedSwitch2() {    return config.timedSwitch2; getLogger().info("get_timedSwitch2");    }
    void SettingsHost::set_timedSwitch2(int value) {    config.timedSwitch2 = value;    SaveConfig(); getLogger().info("set_timedSwitch2");    }

    int SettingsHost::get_timedSwitch3() {    return config.timedSwitch3; getLogger().info("get_timedSwitch3");    }
    void SettingsHost::set_timedSwitch3(int value) {    config.timedSwitch3 = value;    SaveConfig(); getLogger().info("set_timedSwitch3");    }

    int SettingsHost::get_timedSwitch4() {    return config.timedSwitch4; getLogger().info("get_timedSwitch4");    }
    void SettingsHost::set_timedSwitch4(int value) {    config.timedSwitch4 = value;    SaveConfig(); getLogger().info("set_timedSwitch4");    }
}