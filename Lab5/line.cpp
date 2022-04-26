/**
 * @file line.cpp
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
#include "line.h"

Line::Line(int x0, int y0, int x1, int y1, uint32_t color){
    coords = new Matrix(3, 3);

    // Point 1
    (*coords)[0][0] = x0;
    (*coords)[0][1] = y0;
    (*coords)[0][2] = 0.0;

    // Point 2
    (*coords)[1][0] = x1;
    (*coords)[1][1] = y1;
    (*coords)[1][2] = 0.0;

    // Ones
    (*coords)[2][0] = 1.0;
    (*coords)[2][1] = 1.0;
    (*coords)[2][2] = 1.0;

    this->color = color;
}

Line::Line(const Line &from){
    this->color = from.color;
    this->coords = new Matrix(4,3);
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         // Needs a look
    //         this->coords[i][j] = from.coords[i][j];
    //         //(*coords)[i][j] = (*from.coords)[i][j];
    //     }
    // }
    this->coords[0][0] = from.coords[0][0];
    this->coords[0][1] = from.coords[0][1];
    this->coords[0][2] = from.coords[0][2];

    this->coords[1][0] = from.coords[1][0];
    this->coords[1][1] = from.coords[1][1];
    this->coords[1][2] = from.coords[1][2];

    this->coords[2][0] = from.coords[2][0];
    this->coords[2][1] = from.coords[2][1];
    this->coords[2][2] = from.coords[2][2];

}

Line::~Line(){
    delete coords;
}

Line &Line::operator=(const Line &rhs){
    if (&rhs != this)
    {
        this->color = rhs.color;
        delete coords;
        coords = new Matrix(3, 3);
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                this->coords[i][j] = rhs.coords[i][j];
            }
        }
    }
    return *this;
}

void Line::draw(GraphicsContext *gc){
    gc->setColor(color);
    gc->drawLine((*coords)[0][0], (*coords)[0][1],
                 (*coords)[1][0], (*coords)[1][1]);
}

Shape *Line::clone(){
    return new Line(*this);
}