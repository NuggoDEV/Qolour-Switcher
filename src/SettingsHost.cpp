#include "SettingsHost.hpp"
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
            instance = new SettingsHost::New_ctor();
        }
        return instance.ptr();
    }


    bool SettingsHost::get_toggleSwitch1() {    return config.toggleSwitch1;    }
    void SettingsHost::set_toggleSwitch1(bool value) {    config.toggleSwitch1 = value;    SaveConfig();    }

    bool SettingsHost::get_toggleSwitch2() {    return config.toggleSwitch2;    }
    void SettingsHost::set_toggleSwitch2(bool value) {    config.toggleSwitch2 = value;    SaveConfig();    }

    bool SettingsHost::get_toggleSwitch3() {    return config.toggleSwitch3;    }
    void SettingsHost::set_toggleSwitch3(bool value) {    config.toggleSwitch3 = value;    SaveConfig();    }

    bool SettingsHost::get_toggleSwitch4() {    return config.toggleSwitch4;    }
    void SettingsHost::set_toggleSwitch4(bool value) {    config.toggleSwitch4 = value;    SaveConfig();    }
}