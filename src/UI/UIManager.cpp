#include "UI/UIManager.hpp"

void QolourSwitcher::UI::Manager::Init()
{
    BSML::Register::RegisterMenuButton("Qolour Switcher", "Allows for full customization of the saber, bomb and wall colours!", [this]() {
        ShowFlow(false);
    });
}

void QolourSwitcher::UI::Manager::ShowFlow(bool immediately)
{
    if (!flow)
        flow = BSML::Helpers::CreateFlowCoordinator<QolourSwitcher::UI::FlowCoordinators::QolourSwitcherFlowCoordinator *>();
    parentFlow = QuestUI::BeatSaberUI::GetMainFlowCoordinator()->YoungestChildFlowCoordinatorOrSelf();
    parentFlow->PresentFlowCoordinator(flow.ptr(), nullptr, HMUI::ViewController::AnimationDirection::Horizontal, false, false);
}