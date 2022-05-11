/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "x11context.h"
#include "mydrawing.h"
using namespace std;

int main(void){

    GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
    gc->setColor(GraphicsContext::GREEN);

    MyDrawing md;

    gc->runLoop(&md);
    
    return 0;
}