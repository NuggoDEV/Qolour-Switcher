#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "ModUI/MainSettingsViewController.hpp"
using namespace QolourSwitcher;

#include "questui/shared/QuestUI.hpp"
using namespace QuestUI;

#include "chroma/shared/CoreAPI.hpp"
using namespace Chroma;

DEFINE_CONFIG(ModConfig);

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
// other config tools such as config-utils don't use this config, so it can be removed if those are in use
Configuration& getConfig() {
    static Configuration config(modInfo);
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = MOD_ID;
    info.version = VERSION;
    modInfo = info;
	
    getConfig().Load();
    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Loading Qolour Switcher UI & Config");
    getModConfig().Init(modInfo);
    QuestUI::Init();
    QuestUI::Register::RegisterMainMenuModSettingsViewController<QolourSwitcher::Views::MainSettingsViewController *>(modInfo, "Qolour Switcher");
    getLogger().info("Successfully loaded Qolour Switcher UI & Config!");

    getLogger().info("Installing Qolour Switcher Hooks");

    auto &logger = getLogger();
    Hooks::InstallHooks(logger);

    CoreAPI::addForceEnableChromaHooks(modInfo);

    getLogger().info("Installed Qolour Switcher Hooks!");
}