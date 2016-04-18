//
// Created by Jose on 4/7/2016.
//
#include <string>
#include <sstream>
#include "Food.h"

namespace Gaming{
    const char Food::FOOD_ID = 'F';

    //**************************************************

    Food::Food(const Game &g, const Position &p, double capacity) : Resource(g,p,capacity){
        __capacity = capacity;
    }

    //**************************************************

    Food::~Food() { }

    //**************************************************

    void Food::print(std::ostream &os) const {
        std::stringstream ss;

        ss << FOOD_ID << Food::__id;        //Food ID will print out and then the actual ID
        os << ss.str();
    }
}