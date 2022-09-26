#include "main.hpp"
#include "QolourSwitcherConfig.hpp"
#include "ModUI/QolourSwitcherUI.hpp"
using namespace QolourSwitcher;


#include "questui/shared/BeatSaberUI.hpp"
#include "questui/shared/QuestUI.hpp"

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

DEFINE_TYPE(QolourSwitcher, QolourSwitcherUI);



GameObject *leftScreen;

void QolourSwitcher::QolourSwitcherUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{

   leftScreen = QuestUI::BeatSaberUI::CreateFloatingScreen(Vector2(20.0f, 60.0f), Vector3(-1.8f, 1.0f, -2.0f), Vector3(-35.0f, 0.0f, 0.0f), 0.0f, true, false);

}