/**
 * @file image.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "image.h"


// TODO
Image::Image(){
    shapes.clear();
}

// TODO
Image::Image(const Image& from){
    for(int i = 0; i < from.shapes.size(); i++){
        shapes.push_back(from.shapes[i]->clone());
    }
}

// TODO
Image::~Image(){
    for(int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
    shapes.clear();
}

// TODO
Image &Image::operator=(const Image& rhs){
    for(int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
    shapes.clear();
    for(int i = 0; i < rhs.shapes.size(); i++){
        shapes.push_back(rhs.shapes[i]->clone());
    }
    return *this;
}

// TODO
void Image::add(Shape* shape){
    shapes.push_back(shape);
}

// TODO
void Image::draw(GraphicsContext* gc){
    for(int i = 0; i < shapes.size(); i++){
        shapes[i]->draw(gc);
    }
}

// TODO
void Image::out(std::ostream& os){
    for(int i = 0; i < shapes.size(); i++){
        shapes[i]->out(os);
        os << endl;
    }
}

// TODO
void Image::in(std::istream& is){
    
}

// TODO
void Image::erase(){
    for(int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
    shapes.clear();
}