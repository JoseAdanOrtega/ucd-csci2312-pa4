//
// Created by Jose on 4/7/2016.
//
#include <vector>
#include "Game.h"
#include "AggressiveAgentStrategy.h"

namespace Gaming {

    const double AggressiveAgentStrategy::DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;

    AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy) : __agentEnergy(agentEnergy) {

    }

    //**************************************************

    AggressiveAgentStrategy::~AggressiveAgentStrategy() { }

    //**************************************************

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const {
        PositionRandomizer random;
        std::vector<int> ways;
        Position p, middle(1,1);
        bool around[4] = {false, false, false, false};

        for (int i = 0; i < 8; ++i) {
            if ((s.array[i] == SIMPLE || s.array[i] == STRATEGIC) && __agentEnergy >= DEFAULT_AGGRESSION_THRESHOLD )
                around[0] = true;
            else if (s.array[i] == ADVANTAGE)
                around[1] = true;
            else if (s.array[i] == FOOD)
                around[2] = true;
            else if (s.array[i] == EMPTY)
                around[3] = true;
        }

        if (around[0]){
            for (int i = 0; i < 8; ++i) {
                if (s.array[i] == SIMPLE || s.array[i] == STRATEGIC){
                    ways.push_back(i);
                }
            }
            p = random(ways);
            return Game::reachSurroundings(middle,p);
        }

        else if (around[1]){
            for (int i = 0; i < 8; ++i) {
                if (s.array[i] == ADVANTAGE){
                    ways.push_back(i);
                }
            }
            p = random(ways);
            return Game::reachSurroundings(middle,p);
        }

        else if (around[1]){
            for (int i = 0; i < 8; ++i) {
                if (s.array[i] == FOOD){
                    ways.push_back(i);
                }
            }
            p = random(ways);
            return Game::reachSurroundings(middle,p);
        }

        else if (around[1]){
            for (int i = 0; i < 8; ++i) {
                if (s.array[i] == EMPTY){
                    ways.push_back(i);
                }
            }
            p = random(ways);
            return Game::reachSurroundings(middle,p);
        }

        return STAY;
    }
}