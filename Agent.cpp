//
// Created by Jose on 4/7/2016.
//
#include "Agent.h"
#include "Advantage.h"
#include "Food.h"

namespace Gaming{
    const double Agent::AGENT_FATIGUE_RATE = 0.3;   //From Readme

    //**************************************************

    Agent::Agent(const Game &g, const Position &p, double energy) : Piece(g,p) {
        __energy = energy;
    }

    //**************************************************

    Agent::~Agent() { }

    //**************************************************

    void Agent::age() {
        __energy -= AGENT_FATIGUE_RATE;     //Sets __energy to __energy - AGENT_FATIGUE_RATE
    }

    //**************************************************

    Piece& Agent::operator*(Piece &other) {
        return other.interact(this);
    }

    //**************************************************

    Piece& Agent::interact(Agent *a) {     //How two agents will act with one another
        if(__energy > a->getEnergy()){     //Agent will terminate other agent if his energy is higher
            __energy -= a->getEnergy();//Energy is subtracted
            a ->finish();
        }

        else if(__energy < a->getEnergy()){//Other agent will terminate agent if his energy is higher
            a->__energy -= __energy;       //Other agent has its energy subtracted
            a->finish();
        }

        else{                              //Both agents are terminated
            this->finish();
            a->finish();
        }
    }

    //**************************************************

    Piece& Agent::interact(Resource *r) {
        this->addEnergy(r->consume());      //Calls function to add energy to agent

        return *this;
    }
}