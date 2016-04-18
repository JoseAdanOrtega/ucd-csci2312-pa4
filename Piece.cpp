//
// Created by Jose on 4/7/2016.
//
#include "Piece.h"

namespace Gaming{
    unsigned int Piece::__idGen = 1000;

    //**************************************************

    Piece::Piece(const Game &g, const Position &p) : __game(g), __position(p) {
        __finished = false;
        __turned = false;
        __id = __idGen++;
    }

    //**************************************************

    Piece::~Piece() { }

    //**************************************************

    std::ostream& operator<<(std::ostream& os, const Piece& p){
        p.print(os);

        return os;
    }
}