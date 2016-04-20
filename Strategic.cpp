//
// Created by Jose on 4/7/2016.
//
#include <sstream>
#include "Simple.h"
#include "Strategic.h"

namespace Gaming{
    const char Strategic::STRATEGIC_ID = 'T';

    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s) : Agent(g,p,energy) {
        __strategy = s;
    }

    //**************************************************

    Strategic::~Strategic() { }

    //**************************************************

    void Strategic::print(std::ostream &os) const {
        std::stringstream ss;

        ss << STRATEGIC_ID << Strategic::__id;        //Simple ID will print out and then the actual ID
        os << ss.str();
    }

    //**************************************************

    ActionType Strategic::takeTurn(const Surroundings &s) const {
        return (*__strategy)(s);
    }

}

