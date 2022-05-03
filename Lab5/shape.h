#ifndef shape_h
#define shape_h
/**
 * @file shape.h
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "x11context.h"
#include "matrix.h"

using namespace std;

class Shape{
    public:
        // Constructor
        Shape();
        // Copy Constructor
        Shape(const Shape& from);
        // Destructor
        virtual ~Shape();
        // Draw shape
        virtual void draw(GraphicsContext *gc) = 0;
        // Print to output stream
        virtual void out(std::ostream& os)const = 0;
        // Virtual Constructor 
        virtual Shape* clone() = 0; // Pure virtual "=0"
    protected:
        // Matrix containing the coords of each point in the shape
        Matrix* coords;
        // RGB color
        uint32_t color;
        // Assignment Operator
        virtual Shape& operator=(const Shape& rhs);
};

#endif