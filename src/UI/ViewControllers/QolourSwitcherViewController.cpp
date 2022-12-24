#include "UI/ViewControllers/QolourSwitcherViewController.hpp"
using namespace QolourSwitcher::UI::ViewControllers;
using namespace QolourSwitcher::UI;

#include "ModConfig.hpp"
#include "bsml/shared/BSML.hpp"
#include "assets.hpp"

#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"
using namespace GlobalNamespace;

DEFINE_TYPE(QolourSwitcher::UI::ViewControllers, QolourSwitcherUI);

namespace QolourSwitcher::UI
{
    bool defaultsChanged = false;

    void QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if (!firstActivation)
            return;

        BSML::parse_and_construct(IncludedAssets::settings_bsml, this->get_transform(), this);

        std::function<std::string(float)> TimeFormatFunction = [](float value)
        {
            int minutes = value / 60;
            int seconds = value - minutes * 60;
            std::string minuteStr = std::to_string(minutes);
            std::string secondStr = std::to_string(seconds);
            if (minutes == 0)
                return secondStr + "s";
            else if (minutes > 0 && seconds == 0)
                return minuteStr + "m";
            else
                return minuteStr + "m : " + secondStr + "s"; 
        };
        TimeSlider1->formatter = TimeFormatFunction;
        TimeSlider2->formatter = TimeFormatFunction;
        TimeSlider3->formatter = TimeFormatFunction;
        TimeSlider4->formatter = TimeFormatFunction;
    }

    void QolourSwitcherUI::Update()
    {
        auto playerDataModal = UnityEngine::Object::FindObjectOfType<PlayerDataModel *>();
        auto playerData = playerDataModal->playerData;
        auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

        if (defaultsChanged)
        {
            colourScheme->saberAColor = getModConfig().LeftSaber.GetValue();
            colourScheme->saberBColor = getModConfig().RightSaber.GetValue();
            colourScheme->obstaclesColor = getModConfig().WallColour.GetValue();

            defaultsChanged = false;
        }
    }
    
    Color QolourSwitcherUI::get_LeftSaber() { return getModConfig().LeftSaber.GetValue(); }
    void QolourSwitcherUI::set_LeftSaber(Color value) { getModConfig().LeftSaber.SetValue(value); defaultsChanged = true; }

    Color QolourSwitcherUI::get_RightSaber() { return getModConfig().RightSaber.GetValue(); }
    void QolourSwitcherUI::set_RightSaber(Color value) { getModConfig().RightSaber.SetValue(value); defaultsChanged = true; }

    Color QolourSwitcherUI::get_BombColour() { return getModConfig().BombColour.GetValue(); }
    void QolourSwitcherUI::set_BombColour(Color value) { getModConfig().BombColour.SetValue(value); }

    Color QolourSwitcherUI::get_WallColour() { return getModConfig().WallColour.GetValue(); }
    void QolourSwitcherUI::set_WallColour(Color value) { getModConfig().WallColour.SetValue(value); defaultsChanged = true; }



    bool QolourSwitcherUI::get_TimedToggle1() { return getModConfig().TimedToggle1.GetValue(); }
    void QolourSwitcherUI::set_TimedToggle1(bool value) { getModConfig().TimedToggle1.SetValue(value); }

    float QolourSwitcherUI::get_TimedActivation1() { return getModConfig().TimedActivation1.GetValue(); }
    void QolourSwitcherUI::set_TimedActivation1(float value) { getModConfig().TimedActivation1.SetValue(value); }

    Color QolourSwitcherUI::get_LeftSaber1() { return getModConfig().LeftSaber1.GetValue(); }
    void QolourSwitcherUI::set_LeftSaber1(Color value) { getModConfig().LeftSaber1.SetValue(value); }

    Color QolourSwitcherUI::get_RightSaber1() { return getModConfig().RightSaber1.GetValue(); }
    void QolourSwitcherUI::set_RightSaber1(Color value) { getModConfig().RightSaber1.SetValue(value); }

    Color QolourSwitcherUI::get_BombColour1() { return getModConfig().BombColour1.GetValue(); }
    void QolourSwitcherUI::set_BombColour1(Color value) { getModConfig().BombColour1.SetValue(value); }

    Color QolourSwitcherUI::get_WallColour1() { return getModConfig().WallColour1.GetValue(); }
    void QolourSwitcherUI::set_WallColour1(Color value) { getModConfig().WallColour1.SetValue(value); }



    bool QolourSwitcherUI::get_TimedToggle2() { return getModConfig().TimedToggle2.GetValue(); }
    void QolourSwitcherUI::set_TimedToggle2(bool value) { getModConfig().TimedToggle2.SetValue(value); }

    float QolourSwitcherUI::get_TimedActivation2() { return getModConfig().TimedActivation2.GetValue(); }
    void QolourSwitcherUI::set_TimedActivation2(float value) { getModConfig().TimedActivation2.SetValue(value); }

    Color QolourSwitcherUI::get_LeftSaber2() { return getModConfig().LeftSaber2.GetValue(); }
    void QolourSwitcherUI::set_LeftSaber2(Color value) { getModConfig().LeftSaber2.SetValue(value); }

    Color QolourSwitcherUI::get_RightSaber2() { return getModConfig().RightSaber2.GetValue(); }
    void QolourSwitcherUI::set_RightSaber2(Color value) { getModConfig().RightSaber2.SetValue(value); }

    Color QolourSwitcherUI::get_BombColour2() { return getModConfig().BombColour2.GetValue(); }
    void QolourSwitcherUI::set_BombColour2(Color value) { getModConfig().BombColour2.SetValue(value); }

    Color QolourSwitcherUI::get_WallColour2() { return getModConfig().WallColour2.GetValue(); }
    void QolourSwitcherUI::set_WallColour2(Color value) { getModConfig().WallColour2.SetValue(value); }



    bool QolourSwitcherUI::get_TimedToggle3() { return getModConfig().TimedToggle3.GetValue(); }
    void QolourSwitcherUI::set_TimedToggle3(bool value) { getModConfig().TimedToggle3.SetValue(value); }

    float QolourSwitcherUI::get_TimedActivation3() { return getModConfig().TimedActivation3.GetValue(); }
    void QolourSwitcherUI::set_TimedActivation3(float value) { getModConfig().TimedActivation3.SetValue(value); }

    Color QolourSwitcherUI::get_LeftSaber3() { return getModConfig().LeftSaber3.GetValue(); }
    void QolourSwitcherUI::set_LeftSaber3(Color value) { getModConfig().LeftSaber3.SetValue(value); }

    Color QolourSwitcherUI::get_RightSaber3() { return getModConfig().RightSaber3.GetValue(); }
    void QolourSwitcherUI::set_RightSaber3(Color value) { getModConfig().RightSaber3.SetValue(value); }

    Color QolourSwitcherUI::get_BombColour3() { return getModConfig().BombColour3.GetValue(); }
    void QolourSwitcherUI::set_BombColour3(Color value) { getModConfig().BombColour3.SetValue(value); }

    Color QolourSwitcherUI::get_WallColour3() { return getModConfig().WallColour3.GetValue(); }
    void QolourSwitcherUI::set_WallColour3(Color value) { getModConfig().WallColour3.SetValue(value); }



    bool QolourSwitcherUI::get_TimedToggle4() { return getModConfig().TimedToggle4.GetValue(); }
    void QolourSwitcherUI::set_TimedToggle4(bool value) { getModConfig().TimedToggle4.SetValue(value); }

    float QolourSwitcherUI::get_TimedActivation4() { return getModConfig().TimedActivation4.GetValue(); }
    void QolourSwitcherUI::set_TimedActivation4(float value) { getModConfig().TimedActivation4.SetValue(value); }

    Color QolourSwitcherUI::get_LeftSaber4() { return getModConfig().LeftSaber4.GetValue(); }
    void QolourSwitcherUI::set_LeftSaber4(Color value) { getModConfig().LeftSaber4.SetValue(value); }

    Color QolourSwitcherUI::get_RightSaber4() { return getModConfig().RightSaber4.GetValue(); }
    void QolourSwitcherUI::set_RightSaber4(Color value) { getModConfig().RightSaber4.SetValue(value); }

    Color QolourSwitcherUI::get_BombColour4() { return getModConfig().BombColour4.GetValue(); }
    void QolourSwitcherUI::set_BombColour4(Color value) { getModConfig().BombColour4.SetValue(value); }

    Color QolourSwitcherUI::get_WallColour4() { return getModConfig().WallColour4.GetValue(); }
    void QolourSwitcherUI::set_WallColour4(Color value) { getModConfig().WallColour4.SetValue(value); }
}