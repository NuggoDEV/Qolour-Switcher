#include "ModConfig.hpp"
#include "ModUI/QolourSwitcherFlowCoordinator.hpp"
#include "ModUI/QolourSwitcherViewController.hpp"
#include "ModUI/TimedSettingsViewController.hpp"

#include "questui/shared/CustomTypes/Components/Backgroundable.hpp"
#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/UI/VerticalLayoutGroup.hpp"
using namespace UnityEngine;
using namespace UnityEngine::UI;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(QolourSwitcher::UI, QolourSwitcherViewController);

void QolourSwitcher::UI::QolourSwitcherViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        VerticalLayoutGroup *verticalLayoutGroup = BeatSaberUI::CreateVerticalLayoutGroup(get_transform());

        GameObject *scrollView = BeatSaberUI::CreateScrollView(verticalLayoutGroup->get_transform());
        LayoutElement * scrollViewLayoutElement = scrollView->GetComponentInParent<LayoutElement *>();
        scrollViewLayoutElement->set_preferredWidth(120);
        scrollViewLayoutElement->set_preferredHeight(65);

        timedSettingsButton = CreateUIViewControllerButton(scrollView->get_transform(), "Timed Switches", "Allows for four separate timed switches during the song.", BeatSaberUI::CreateViewController<QolourSwitcher::UI::TimedSettingsViewController *>());

    }
}