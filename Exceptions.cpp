//
// Created by Jose on 4/7/2016.
//
#include <string>
#include "Exceptions.h"

namespace Gaming
{


    void GamingException::setName(std::string name) {
        __name = name;
    }

    //**************************************************

    std::ostream &operator<<(std::ostream &os, const GamingException &ex) {
        os << ex.__name << "\n";
        ex.__print_args(os);
        return os;
    }

    //**************************************************

    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height) {
        __exp_width = expWidth;
        __exp_height = expHeight;
        __width =  width;
        __height = height;
        setName("DimensionsEX");
    }

    //**************************************************

    unsigned DimensionEx::getExpWidth() const {
        return __exp_width;
    }

    //**************************************************

    unsigned DimensionEx::getExpHeight() const {
        return __exp_height;
    }

    //**************************************************

    unsigned DimensionEx::getWidth() const {
        return __width;
    }

    //**************************************************

    unsigned DimensionEx::getHeight() const {
        return __height;
    }

    //**************************************************

    void InsufficientDimensionsEx::__print_args(std::ostream &os) const {
        os << "expWidth: " << getExpWidth() << " expHieght: " << getExpHeight() << '\n';
        os << "Width: " << getWidth() << "Height: " << getHeight() << '\n';
    }

    //**************************************************

    InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width, unsigned height) : DimensionEx(minWidth, minHeight, width, height) {
        setName("InsufficientDimensionsEX");
    }

    //**************************************************

    void OutOfBoundsEx::__print_args(std::ostream &os) const {
        os << "expWidth: " << getExpWidth() << " expHieght: " << getExpHeight() << '\n';
        os << "Width: " << getWidth() << "Height: " << getHeight() << '\n';
    }

    //**************************************************

    OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height) : DimensionEx(maxWidth, maxHeight, width, height){
        setName("OutOfBoundsEX");
    }

    //**************************************************

    void PositionEx::__print_args(std::ostream &os) const {
        os << "x: " << __x << " y: " << __y << "\n";
    }

    //**************************************************

    PositionEx::PositionEx(unsigned x, unsigned y) {
        __x = x;
        __y = y;
        setName("PositionEX");
    }

    //**************************************************

    PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y) : PositionEx(x, y) {
        setName("PositionNoneEX");
    }

    //**************************************************

    PositionEmptyEx::PositionEmptyEx(unsigned x, unsigned y) : PositionEx(x, y){
        setName("PositionEmptyEX");
    }

    //**************************************************

    void PosVectorEmptyEx::__print_args(std::ostream &os) const { }

    //**************************************************

    PosVectorEmptyEx::PosVectorEmptyEx() {
        setName("PosVectorEmptyEx");
    }
}