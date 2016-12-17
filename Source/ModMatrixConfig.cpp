/*
 ==============================================================================
 
 ModMatrixConfig.cpp
 Created: 12 Dec 2016 6:45:42pm
 Author:  Matthias Pueski
 
 ==============================================================================
 */

#include "ModMatrixConfig.h"

ModMatrixConfig::ModMatrixConfig()
{
    // this->config = new ValueTree(Identifier("modMatrix"));
}

ModMatrixConfig::~ModMatrixConfig()
{
}

void ModMatrixConfig::addConfig(ModSlotConfig * config)
{
    this->slotConfigs.push_back(config);
}

/*
ValueTree * ModMatrixConfig::getConfiguation()
{
    config->removeAllChildren(nullptr);
    
    for (int i = 0; i < slotConfigs.size(); i++) {
        
        ScopedPointer<ValueTree> slotConfig = new ValueTree(Identifier("slotConfig"));
        
        slotConfig->setProperty("sourceId", slotConfigs.at(i)->sourceId, nullptr);
        slotConfig->setProperty("targetId1", slotConfigs.at(i)->targetId1, nullptr);
        slotConfig->setProperty("targetId2", slotConfigs.at(i)->targetId2, nullptr);
        slotConfig->setProperty("amount1", slotConfigs.at(i)->amount1, nullptr);
        slotConfig->setProperty("amount2", slotConfigs.at(i)->amount2, nullptr);
        slotConfig->setProperty("enabled", slotConfigs.at(i)->enabled, nullptr);
        
        config->addChild(*slotConfig, -1, nullptr);
    }
    
    return this->config;
}
 */

ModSlotConfig * ModMatrixConfig::getSlotConfig(int i)
{
    return slotConfigs.at(i);
}

void ModMatrixConfig::clearSlots()
{
    for(std::vector<ModSlotConfig*>::iterator it = slotConfigs.begin(); it != slotConfigs.end(); ++it) {
        if (*it != NULL)
            delete *it;
    }
    this->slotConfigs.clear();
}

int ModMatrixConfig::getNumConfigs()
{
    return slotConfigs.size();
}
