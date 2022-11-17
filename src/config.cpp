#include "config.hpp"
#include "main.hpp"

extern Logger& getLogger();
extern ModInfo modInfo;
config_t config;


void SaveConfig()
{
    getConfig().config.RemoveAllMembers();
    getConfig().config.SetObject();
    rapidjson::Document::AllocatorType& allocator = getConfig().config.GetAllocator();

    getConfig().config.AddMember("toggleSwitch1", config.toggleSwitch1, allocator);
    getConfig().config.AddMember("toggleSwitch2", config.toggleSwitch2, allocator);
    getConfig().config.AddMember("toggleSwitch3", config.toggleSwitch3, allocator);
    getConfig().config.AddMember("toggleSwitch4", config.toggleSwitch4, allocator);

    getConfig().Write();
}

bool LoadConfig()
{
    LoggerContextObject logger = getLogger().WithContext("Config Load");
    logger.info("Loading Config");
    getConfig().Load();
    bool foundEverything = true;

    if (getConfig().config.HasMember("toggleSwitch1") && getConfig().config["toggleSwitch1"].IsBool())
    {
        config.toggleSwitch1 = getConfig().config["toggleSwitch1"].GetBool();
    }
    else
    {
        foundEverything = false;
    }


    if (getConfig().config.HasMember("toggleSwitch2") && getConfig().config["toggleSwitch2"].IsBool())
    {
        config.toggleSwitch2 = getConfig().config["toggleSwitch2"].GetBool();
    }
    else
    {
        foundEverything = false;
    }


    if (getConfig().config.HasMember("toggleSwitch3") && getConfig().config["toggleSwitch3"].IsBool())
    {
        config.toggleSwitch3 = getConfig().config["toggleSwitch3"].GetBool();
    }
    else
    {
        foundEverything = false;
    }


    if (getConfig().config.HasMember("toggleSwitch4") && getConfig().config["toggleSwitch4"].IsBool())
    {
        config.toggleSwitch4 = getConfig().config["toggleSwitch4"].GetBool();
    }
    else
    {
        foundEverything = false;
    }



    if (getConfig().config.HasMember("timedSwitch1") && getConfig().config["timedSwitch1"].IsInt())
    {
        config.timedSwitch1 = getConfig().config["timedSwitch1"].GetInt();
    }
    else
    {
        foundEverything = false;
    }


    if (getConfig().config.HasMember("timedSwitch2") && getConfig().config["timedSwitch2"].IsInt())
    {
        config.timedSwitch2 = getConfig().config["timedSwitch2"].GetInt();
    }
    else
    {
        foundEverything = false;
    }


    if (getConfig().config.HasMember("timedSwitch3") && getConfig().config["timedSwitch3"].IsInt())
    {
        config.timedSwitch3 = getConfig().config["timedSwitch3"].GetInt();
    }
    else
    {
        foundEverything = false;
    }


    if (getConfig().config.HasMember("timedSwitch4") && getConfig().config["timedSwitch4"].IsInt())
    {
        config.timedSwitch4 = getConfig().config["timedSwitch4"].GetInt();
    }
    else
    {
        foundEverything = false;
    }

    

    if (foundEverything) getLogger().info("Config loaded!");
        return foundEverything;
}