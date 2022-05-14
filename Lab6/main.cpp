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

Image boatScene;

void buildBoat(){

	cout << "Build Boat" << endl;

	// Boat
	boatScene.add(new Line(250,500,550,500,GraphicsContext::YELLOW));
	boatScene.add(new Line(250,500,150,400,GraphicsContext::YELLOW));
	boatScene.add(new Line(150,400,650,400,GraphicsContext::YELLOW));
	boatScene.add(new Line(650,400,550,500,GraphicsContext::YELLOW));
	boatScene.add(new Line(400,400,400,100,GraphicsContext::YELLOW));
	
	// Sail
	boatScene.add(new Triangle(400,100,300,150,400,200,GraphicsContext::YELLOW));
	
	// Waves
	boatScene.add(new Line(0,550,100,450,GraphicsContext::BLUE));
	boatScene.add(new Line(100,450,100,550,GraphicsContext::BLUE));
	boatScene.add(new Line(100,550,200,450,GraphicsContext::BLUE));
	boatScene.add(new Line(200,450,200,550,GraphicsContext::BLUE));
	boatScene.add(new Line(200,550,300,450,GraphicsContext::BLUE));
	boatScene.add(new Line(300,450,300,550,GraphicsContext::BLUE));
	boatScene.add(new Line(300,550,400,450,GraphicsContext::BLUE));
	boatScene.add(new Line(400,450,400,550,GraphicsContext::BLUE));
	boatScene.add(new Line(400,550,500,450,GraphicsContext::BLUE));
	boatScene.add(new Line(500,450,500,550,GraphicsContext::BLUE));
	boatScene.add(new Line(500,550,600,450,GraphicsContext::BLUE));
	boatScene.add(new Line(600,450,600,550,GraphicsContext::BLUE));
	boatScene.add(new Line(600,550,700,450,GraphicsContext::BLUE));
	boatScene.add(new Line(700,450,700,550,GraphicsContext::BLUE));
	boatScene.add(new Line(700,550,800,450,GraphicsContext::BLUE));
}

int main(void){

    GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
    gc->setColor(GraphicsContext::GREEN);

    MyDrawing md;
    md.paint(gc);

    gc->runLoop(&md);
    
    return 0;
}