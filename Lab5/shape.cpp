/**
 * @file shape.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "shape.h"

Shape::Shape(){
    this->color = (uint32_t) 0x00FFFFFF;
}
Shape::Shape(const Shape& from){
    this->color = from.color;
    this->coords = from.coords;
}

Shape::~Shape(){};

void Shape::draw(GraphicsContext *gc){}

void Shape::out(std::ostream& os, const Shape& rhs){}

Shape& Shape::operator=(const Shape& rhs){
    return *this;
}
