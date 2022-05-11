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
#include <sstream>
#include <fstream>

Image::Image(){
    shapes.clear();
}

Image::Image(const Image& from){
    for(int i = 0; i < from.shapes.size(); i++){
        shapes.push_back(from.shapes[i]->clone());
    }
}

Image::~Image(){
    for(int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
    shapes.clear();
}

Image &Image::operator=(const Image& rhs){
    if(this != &rhs){
        for(int i = 0; i < shapes.size(); i++){
            delete shapes[i];
        }
        shapes.clear();
        for(int i = 0; i < rhs.shapes.size(); i++){
            shapes.push_back(rhs.shapes[i]->clone());
        }
    }
    return *this;
}

void Image::add(Shape* shape){
    shapes.push_back(shape->clone());
}
 
void Image::draw(GraphicsContext* gc, const ViewContext* vc){
    for(int i = 0; i < shapes.size(); i++){
        shapes[i]->draw(gc,vc);
    }
}

void Image::out(std::ostream& os){
    for(int i = 0; i < shapes.size(); i++){
        shapes[i]->out(os);
        os << endl;
    }
}

void Image::in(std::istream& is){
    string line;
    string token;
    int shapeCoords[3][3];
    getline(is, line);
    istringstream lineStream(line);
    do{
        lineStream >> token;
        switch(token[0]){
            case 'L':
                {
                    // Next Line
                    getline(is, line);
                    lineStream.str(line);
                    lineStream.clear();
                    // Iterate past "Color:"
                    lineStream >> token;
                    // Get actual color code
                    lineStream >> token;
                    stringstream hexColor(token);
                    // Convert hex code to unsigned int
                    uint32_t color;
                    hexColor >> hex >> color;
                    // hexColor >> color;
                    // Points
                    for(int i = 0; i < 2; i++){
                        getline(is, line);
                        lineStream.str(line);
                        lineStream.clear();
                        // Iterate past "P#:"
                        lineStream >> token;
                        // Get each coord
                        for(int j = 0; j < 3; j++){
                            lineStream >> token;
                            shapeCoords[i][j] = stoi(token);
                        }
                    }
                    shapes.push_back(
                        new Line(shapeCoords[0][0],shapeCoords[0][1],
                                 shapeCoords[1][0],shapeCoords[1][1],color)
                    );
                    break;
                }
            case 'T':
                {
                    // Next Line
                    getline(is, line);
                    lineStream.str(line);
                    lineStream.clear();
                    // Iterate past "Color:"
                    lineStream >> token;
                    // Get actual color code
                    lineStream >> token;
                    stringstream hexColor(token);
                    // Convert hex code to unsigned int
                    uint32_t color;
                    hexColor >> hex >> color;
                    // hexColor >> color;
                    // Points
                    for(int i = 0; i < 3; i++){
                        getline(is, line);
                        lineStream.str(line);
                        lineStream.clear();
                        // Iterate past "P#:"
                        lineStream >> token;
                        // Get each coord
                        for(int j = 0; j < 3; j++){
                            lineStream >> token;
                            shapeCoords[i][j] = stoi(token);
                        }
                    }
                    shapes.push_back(
                        new Triangle(shapeCoords[0][0],shapeCoords[0][1],
                                     shapeCoords[1][0],shapeCoords[1][1],
                                     shapeCoords[2][0],shapeCoords[2][1],color)
                    );
                    break;
                }
            default:
            {
                cout << "Invalid Shape";
            }
            
        }
        // Go to blank line
        getline(is, line);
        lineStream.str(line);
        lineStream.clear();
        // Get next line
        getline(is, line);
        lineStream.str(line);
        lineStream.clear();
        lineStream >> token;
    } while(!is.eof()); // Loop until end of file
}

void Image::erase(){
    for(int i = 0; i < shapes.size(); i++){
        delete shapes[i];
    }
    shapes.clear();
}