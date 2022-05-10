#ifndef image_h
#define image_h
/**
 * @file image.h
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "shape.h"
#include "line.h"
#include "triangle.h"
#include "x11context.h"
#include <vector>
using namespace std;

class Image{
    public:
        // Image constructor
        Image();

        // Image copy constructor
        Image(const Image& from);

        // Image destructor
        ~Image();

        // Image assignment operator
        Image& operator=(const Image& rhs);

        // Adds a passed in shape to the image
        void add(Shape* shape);

        // Draws all the shapes in the image
        void draw(GraphicsContext* gc);

        // Outputs all of the shape data to an output stream
        void out(std::ostream& os);

        // Inputs all the shape data from a given input stream
        void in(std::istream& is);

        // Erases all the shapes in the image
        void erase();
        
    private:
        vector<Shape*> shapes;
};

#endif