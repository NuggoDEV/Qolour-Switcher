#pragma once
#include "HMUI/ViewController.hpp"

#include "custom-types/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

DECLARE_CLASS_CODEGEN(QolourSwitcher, SettingsHost, Il2CppObject,

    DECLARE_BSML_PROPERTY(bool, toggleSwitch1);
    DECLARE_BSML_PROPERTY(bool, toggleSwitch2);
    DECLARE_BSML_PROPERTY(bool, toggleSwitch3);
    DECLARE_BSML_PROPERTY(bool, toggleSwitch4);

    DECLARE_CTOR(ctor);

    public:
        static SettingsHost *get_instance();
    private:
        static SafePtr<SettingsHost> instance;
)