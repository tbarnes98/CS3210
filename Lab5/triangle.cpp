/**
 * @file triangle.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "shape.h"
#include "matrix.h"
#include "triangle.h"

Triangle::Triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color){
    coords = new Matrix(4,3);

    // Point 1
    (*coords)[0][0] = x0;
    (*coords)[0][1] = y0;
    (*coords)[0][2] = 0.0;

    // Point 2
    (*coords)[1][0] = x1;
    (*coords)[1][1] = y1;
    (*coords)[1][2] = 0.0;

    // Point 3
    (*coords)[2][0] = x2;
    (*coords)[2][1] = y2;
    (*coords)[2][2] = 0.0;

    // Ones
    (*coords)[3][0] = 1.0;
    (*coords)[3][1] = 1.0;
    (*coords)[3][2] = 1.0;

    this->color = color;
}

Triangle::Triangle(const Triangle &from){
    this->coords = new Matrix(4,3);
    (*this).color = from.color;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            (*coords)[i][j] = (*from.coords)[i][j];
        }
    }
}

Triangle::~Triangle(){
    delete coords;
}

Triangle& Triangle::operator=(const Triangle& rhs){
    if(&rhs != this){
        this->color = rhs.color;
        delete coords;
        coords = new Matrix(4,3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                this->coords[i][j] = rhs.coords[i][j];
            }
        }
    }
    return *this;
}

void Triangle::out(std::ostream& os) const{
    os << "-Triangle-" << endl;
    os << "Color: " << color << endl;

    os << "Point 1 - X: " << (*coords)[0][0];
    os << " Y: " << (*coords)[0][1];
    os << " Z: " << (*coords)[0][2] << endl;


    os << "Point 2 - X: " << (*coords)[1][0];
    os << " Y: " << (*coords)[1][1];
    os << " Z: " << (*coords)[1][2] << endl;


    os << "Point 3 - X: " << (*coords)[2][0];
    os << " Y: " << (*coords)[2][1];
    os << " Z: " << (*coords)[2][2] << endl;
}


Shape* Triangle::clone(){
    return new Triangle(*this);
}

void Triangle::draw(GraphicsContext *gc){
    gc->setColor(color);
    gc->drawLine((*coords)[0][0], (*coords)[0][1],
                 (*coords)[1][0], (*coords)[1][1]);
    gc->drawLine((*coords)[1][0], (*coords)[1][1],
                 (*coords)[2][0], (*coords)[2][1]);
    gc->drawLine((*coords)[2][0], (*coords)[2][1],
                 (*coords)[0][0], (*coords)[0][1]);
}