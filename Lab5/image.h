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
#include "x11context.h"
#include <vector>
using namespace std;

class Image{
    public:
        Image();
        Image(const Image& from);
        ~Image();
        Image& operator=(const Image& rhs);
        void add(Shape* shape);
        void draw(GraphicsContext* gc);
        void out(std::ostream& os);
        void in(std::istream& is);
        void erase();
    private:
        vector<Shape*> shapes;

};

#endif