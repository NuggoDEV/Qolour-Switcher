#pragma once

#include "bsml/shared/Helpers/creation.hpp"
#include "bsml/shared/BSML.hpp"
#include "HMUI/FlowCoordinator.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"
#include "UI/FlowCoordinators/QolourSwitcherFlowCoordinator.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

namespace QolourSwitcher::UI
{
    class Manager
    {
        HMUI::FlowCoordinator *parentFlow;
        SafePtrUnity<QolourSwitcher::UI::FlowCoordinators::QolourSwitcherFlowCoordinator> flow;
        BSML::MenuButton *menuButton;

        public:
            Manager(Manager const&) = delete;
            Manager() = default;

            void Init();

            void ShowFlow(bool immediately);

    };

    inline static Manager manager;
}