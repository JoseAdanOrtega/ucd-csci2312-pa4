//
// Created by Jose on 4/7/2016.
//
#include <vector>
#include "DefaultAgentStrategy.h"
#include "Game.h"


namespace Gaming {


    DefaultAgentStrategy::DefaultAgentStrategy() { }

    //**************************************************

    DefaultAgentStrategy::~DefaultAgentStrategy() { }

    //**************************************************

    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const {
        PositionRandomizer random;
        std::vector<int> ways;
        Position p, middle(1,1);
        bool around[4] = {false, false, false, false};

        for (int i = 0; i < 8; ++i) {
            if (s.array[i] == ADVANTAGE )
                around[0] = true;
            else if (s.array[i] == FOOD)
                around[1] = true;
            else if (s.array[i] == EMPTY)
                around[2] = true;
            else if (s.array[i] == SIMPLE)
                around[3] = true;
        }

        if (around[0]){
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

        else if (around[1]){
            for (int i = 0; i < 8; ++i) {
                if (s.array[i] == SIMPLE){
                    ways.push_back(i);
                }
            }
            p = random(ways);
            return Game::reachSurroundings(middle,p);
        }

        return STAY;
    }
}