/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <unistd.h>
#include <iostream>
#include "x11context.h"
#include "shape.h"
#include "line.h"
#include "triangle.h"
#include "image.h"
using namespace std;

GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);

void part1Test(){

	// Boat
	Shape* LT1 = new Line(250,500,550,500,GraphicsContext::YELLOW);
	Shape* LT2 = new Line(250,500,150,400,GraphicsContext::YELLOW);
	Shape* LT3 = new Line(150,400,650,400,GraphicsContext::YELLOW);
	Shape* LT4 = new Line(650,400,550,500,GraphicsContext::YELLOW);
	Shape* LT5 = new Line(400,400,400,100,GraphicsContext::YELLOW);
	
	// Sail
	Shape* TT1 = new Triangle(400,100,300,150,400,200,GraphicsContext::YELLOW);
	

	// Waves
	Shape* LT8 = new Line(0,550,100,450,GraphicsContext::BLUE);
	Shape* LT9 = new Line(100,450,100,550,GraphicsContext::BLUE);
	Shape* LT10 = new Line(100,550,200,450,GraphicsContext::BLUE);
	Shape* LT11 = new Line(200,450,200,550,GraphicsContext::BLUE);
	Shape* LT12 = new Line(200,550,300,450,GraphicsContext::BLUE);
	Shape* LT13 = new Line(300,450,300,550,GraphicsContext::BLUE);
	Shape* LT14 = new Line(300,550,400,450,GraphicsContext::BLUE);
	Shape* LT15 = new Line(400,450,400,550,GraphicsContext::BLUE);
	Shape* LT16 = new Line(400,550,500,450,GraphicsContext::BLUE);
	Shape* LT17 = new Line(500,450,500,550,GraphicsContext::BLUE);
	Shape* LT18 = new Line(500,550,600,450,GraphicsContext::BLUE);
	Shape* LT19 = new Line(600,450,600,550,GraphicsContext::BLUE);
	Shape* LT20 = new Line(600,550,700,450,GraphicsContext::BLUE);
	Shape* LT21 = new Line(700,450,700,550,GraphicsContext::BLUE);
	Shape* LT22 = new Line(700,550,800,450,GraphicsContext::BLUE);
	
	(*LT1).draw(gc);
	(*LT2).draw(gc);
	(*LT3).draw(gc);
	(*LT4).draw(gc);
	(*LT5).draw(gc);
	(*TT1).draw(gc);
	(*LT8).draw(gc);
	(*LT9).draw(gc);
	(*LT10).draw(gc);
	(*LT11).draw(gc);
	(*LT12).draw(gc);
	(*LT13).draw(gc);
	(*LT14).draw(gc);
	(*LT15).draw(gc);
	(*LT16).draw(gc);
	(*LT17).draw(gc);
	(*LT18).draw(gc);
	(*LT19).draw(gc);
	(*LT20).draw(gc);
	(*LT21).draw(gc);
	(*LT22).draw(gc);
}

void part2Test(){
	Image image1;
	for(int i = 0; i < 10; i++){
		image1.add(new Line(rand()%800,rand()%600,rand()%800,rand()%600,rand()));
	}
	for(int i = 0; i < 10; i++){
		image1.add(new Triangle(rand()%800,rand()%600,rand()%800,rand()%600,rand()%800,rand()%600,rand()));
	}
	image1.draw(gc);
}

int main(void)
{	
	part1Test();
	sleep(5);
	gc->clear();

	part2Test();
	sleep(5);
	gc->clear();

	sleep(20);
	
	delete gc;
 
	return 0;
}

