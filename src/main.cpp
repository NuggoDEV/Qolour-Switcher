#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"
#include "config.hpp"
#include "ModUI/SettingsHost.hpp"
#include "assets.hpp"

#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSMLDataCache.hpp"

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
    config.Load();
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

    if (!LoadConfig())
    {
        SaveConfig();
    }
    il2cpp_functions::Init();

    LoggerContextObject logger = getLogger().WithContext("Load");

    getLogger().info("Loading Qolour Switcher UI & Config");

    getModConfig().Init(modInfo);

    QuestUI::Init();
    BSML::Register::RegisterSettingsMenu("Qolour Switcher", MOD_ID "_settings", QolourSwitcher::SettingsHost::get_instance(), true);

    getLogger().info("Successfully loaded Qolour Switcher UI & Config!");

    getLogger().info("Installing Qolour Switcher Hooks");

    auto &hookLogger = getLogger();
    Hooks::InstallHooks(hookLogger);

    CoreAPI::addForceEnableChromaHooks(modInfo);

    getLogger().info("Installed Qolour Switcher Hooks!");
}

BSML_DATACACHE(settings)
{
    return IncludedAssets::ToggleSettings_bsml;
}