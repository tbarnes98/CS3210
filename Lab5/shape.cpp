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
Shape::Shape(const Shape& from){};

Shape::~Shape(){};

Shape& Shape::operator=(const Shape& rhs){
    return *this;
}
