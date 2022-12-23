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
    class UIManager
    {
        HMUI::FlowCoordinator *parentFlow;
        QolourSwitcher::UI::FlowCoordinators::QolourSwitcherFlowCoordinator *flow;
        public:
            void Init()
            {
                BSML::Register::RegisterMenuButton("Qolour Switcher", "Allows for full customization of the saber, bomb and wall colours!", [this]()
                {
                    ShowFlow(false);
                });
            }

            void ShowFlow(bool immediately)
            {
                if (flow == nullptr || flow->m_CachedPtr.m_value == nullptr)
                    flow = BSML::Helpers::CreateFlowCoordinator<QolourSwitcher::UI::FlowCoordinators::QolourSwitcherFlowCoordinator *>();
                
                parentFlow = QuestUI::BeatSaberUI::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
                parentFlow->PresentFlowCoordinator(flow, nullptr, HMUI::ViewController::AnimationDirection::Horizontal, HMUI::ViewController::AnimationType::Out, false);
            }
    };

    inline static UIManager manager;
}