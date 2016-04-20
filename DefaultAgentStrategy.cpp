//
// Created by Jose on 4/7/2016.
//



#include "DefaultAgentStrategy.h"

namespace Gaming {


    DefaultAgentStrategy::DefaultAgentStrategy() {

    }


    DefaultAgentStrategy::~DefaultAgentStrategy() {

    }


    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const {
        return S;
    }
}