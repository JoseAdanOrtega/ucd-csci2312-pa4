//
// Created by Jose on 4/7/2016.
//
#include "Resource.h"

namespace Gaming{
    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2; //From Readme

    //**************************************************

    Resource::Resource(const Game &g, const Position &p, double capacity) : Piece(g,p) { }

    //**************************************************

    Resource::~Resource() { }

    //**************************************************

    double Resource::consume() {
        double temp = __capacity;
        __capacity = 0;
        finish();
        return temp;
    }

    //**************************************************

    void Resource::age() {
        __capacity /= RESOURCE_SPOIL_FACTOR;
        if(__capacity < 1)
            finish();
    }

    //**************************************************

    ActionType Resource::takeTurn(const Surroundings &s) const {
        return ActionType::STAY;
    }

    //**************************************************

    Piece &Resource::operator*(Piece& other) { }

    //**************************************************

    Piece &Resource::interact(Agent *agent) { return *this; }

    //**************************************************

    Piece &Resource::interact(Resource *resource) { return *this; }
}