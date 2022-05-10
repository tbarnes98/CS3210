#ifndef line_h
#define line_h
/**
 * @file line.h
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

class Line: public Shape{
    public:
        // Line constructor
        Line(int x0, int y0, int x1, int y1, uint32_t color);

        // Line copy constructor
        Line(const Line& from);

        // Line destructor
        ~Line();

        // Line assignment operator
        Line& operator=(const Line& rhs);

        // Draw function
        void draw(GraphicsContext *gc);

        // Outputs line data to os
        void out(std::ostream& os) const;

        // Clones a line
        Shape* clone();

};

#endif