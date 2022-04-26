#ifndef shape_h
#define shape_h
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
        virtual void draw(GraphicsContext *gc);
        // Print to output stream
        virtual void out(std::ostream& os, const Shape& rhs);
        // Virtual Constructor 
        virtual Shape* clone() = 0; // Pure virtual "=0"
    protected:
        // Matrix containing the coords of each point in the shape
        Matrix* coords;
        // RGB color
        uint32_t color;
        // Assignment Operator
        Shape& operator=(const Shape& rhs);
};

#endif