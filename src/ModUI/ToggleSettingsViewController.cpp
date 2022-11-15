#include "ModUI/ToggleSettingsViewController.hpp"
#include "ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "assets.hpp"
#include "bsml/shared/BSML.hpp"
using namespace BSML;

#include "TMPro/TextMeshProUGUI.hpp"
using namespace TMPro;

DEFINE_TYPE(QolourSwitcher::UI, ToggleSettingsViewController);



std::string SecondsToString(float value)
{
    int minutes = value / 60;
    int seconds = value - minutes * 60;
    std::string minuteStr = std::to_string(minutes);
    std::string secondStr = std::to_string(seconds);

    if (minutes == 0)
    {
        return secondStr + "s";
    }
    else
    {
        return minuteStr + "m :" + secondStr + "s";
    }
}



void QolourSwitcher::UI::ToggleSettingsViewController::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {        
        auto parser = BSMLParser::parse(IncludedAssets::ToggleSettings_bsml);
        parser->Construct(get_transform(), this);
    }
}