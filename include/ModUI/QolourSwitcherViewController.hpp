#pragma once

#include "main.hpp"
#include "custom-types/shared/macros.hpp"
#include "custom-types/shared/register.hpp"

#include "HMUI/ViewController.hpp"
#include "HMUI/FlowCoordinator.hpp"

#include "UnityEngine/UI/Button.hpp"


DECLARE_CLASS_CODEGEN(QolourSwitcher::UI, QolourSwitcherViewController, HMUI::ViewController,
    DECLARE_INSTANCE_FIELD(HMUI::FlowCoordinator*, flowCoordinator);

    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, mainSettingsButton);
    DECLARE_INSTANCE_FIELD(UnityEngine::UI::Button*, timedSettingsButton);

    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);

public:
    UnityEngine::UI::Button *CreateUIViewControllerButton(UnityEngine::Transform *parent, std::string title, std::string description, HMUI::ViewController *viewController);
)