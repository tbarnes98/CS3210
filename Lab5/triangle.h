#ifndef triangle_h
#define triangle_h
/**
 * @file triangle.h
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
#include "x11context.h"

class Triangle: public Shape{
    public:
        // Triangle constructor
        Triangle(int x0, int y0, int x1, int y1, int x2, int y2, 
                 uint32_t color);

        // Triangle copy constructor
        Triangle(const Triangle& from);

        // Triangle destructor
        ~Triangle();

        // Triangle assignment operator
        Triangle& operator=(const Triangle& rhs);

        // Draw function
        void draw(GraphicsContext *gc);

        // Outputs line data to os
        void out(std::ostream& os) const;

        // Clones a triangle
        Shape* clone();

};
#endif