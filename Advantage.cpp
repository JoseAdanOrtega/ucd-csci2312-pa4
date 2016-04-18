//
// Created by Jose on 4/7/2016.
//
#include <string>           //To output the stringstream
#include <sstream>          //Used to pass in ADVANTAGE_ID
#include "Advantage.h"

namespace Gaming{
    const char Advantage::ADVANTAGE_ID = 'D';   //From Readme
    const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

    //**************************************************

    Advantage::Advantage(const Game &g, const Position &p, double capacity) : Resource(g,p,capacity){
        __capacity = capacity * ADVANTAGE_MULT_FACTOR;
    }

    //**************************************************

    Advantage::~Advantage() { }

    //**************************************************

    void Advantage::print(std::ostream &os) const {
        std::stringstream ss;
        std::string temp;
        ss << ADVANTAGE_ID << __id;     //Passes ADVANTAGE_ID to a string stream
        getline(ss, temp);              //Passes the string stream in to the string
        os << temp;                     //Outputs it to the ostream
    }

    //**************************************************

    double Advantage::getCapacity() const {
        return Advantage::__capacity;   //Getter
    }

    //**************************************************

    double Advantage::consume() {
        double consume = getCapacity();     //Holds the capacity
        __capacity = 0;                     //Resets __capacity
        finish();
        return consume;
    }
}

