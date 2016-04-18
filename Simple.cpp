//
// Created by Jose on 4/7/2016.
//
#include <random>
#include <iomanip>
#include <random>
#include <sstream>
#include "Simple.h"

namespace Gaming{
    const char Simple::SIMPLE_ID = 'S';

    //**************************************************

    Simple::Simple(const Game &g, const Position &p, double energy) : Agent(g,p,energy) { }

    //**************************************************

    Simple::~Simple() { }

    //**************************************************

    void Simple::print(std::ostream &os) const {
        std::stringstream ss;

        ss << SIMPLE_ID << Simple::__id;        //Simple ID will print out and then the actual ID
        os << ss.str();
    }

    ActionType Simple::takeTurn(const Surroundings &s) const {
        ActionType ac;
        std::vector<int> position;
        std::random_device randall;
        std::mt19937 gen(randall());

        //**************************************************

        for (int i = 0; i < s.array.size(); ++i) {
            if(s.array[i] == ADVANTAGE || s.array[i] == FOOD)
                position.push_back(i);
        }

        //**************************************************

        if(position.size() == 0){
            for (int i = 0; i < s.array.size(); ++i) {
                if(s.array[i] == EMPTY)
                    position.push_back(i);
            }
        }
        //**************************************************

        if(position.size() > 0){
            int posIndex = position[rand() % position.size()];

            if (position.size() == 1) posIndex = position[0];

            switch (posIndex){
                case 0:
                    ac = NW; break;
                case 1:
                    ac = N; break;
                case 2:
                    ac = NE; break;
                case 3:
                    ac = W; break;
                case 4:
                    ac = STAY; break;
                case 5:
                    ac = E; break;
                case 6:
                    ac = SW; break;
                case 7:
                    ac = S; break;
                case 8:
                    ac = SE; break;
                default:
                    ac = STAY;
            }
            return ac;
        }
        return STAY;
    }
}
