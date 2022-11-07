#include "ModUI/TimedSettingsViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;


DEFINE_TYPE(QolourSwitcher::UI, TimedSettingsViewController);

void QolourSwitcher::UI::TimedSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        auto container = BeatSaberUI::CreateScrollView(get_transform());
        TextMeshProUGUI *title = BeatSaberUI::CreateText(container->get_transform(), "Timed Settings");
        title->set_fontSize(6.0f);
        title->set_alignment(TextAlignmentOptions::Center);


    }
}