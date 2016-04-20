//
// Created by Jose on 4/7/2016.
//

#include "AggressiveAgentStrategy.h"

namespace Gaming {


    Gaming::AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy) : __agentEnergy(agentEnergy) {

    }


    AggressiveAgentStrategy::~AggressiveAgentStrategy() {

    }

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const {
        return S;
    }
}