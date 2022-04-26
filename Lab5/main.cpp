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
using namespace std;

int main(void)
{	
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
	Shape* L1 = new Line(200, 150, 200, 300, GraphicsContext::GREEN);
	Shape* T1 = new Triangle(250, 100, 50, 320, 125, 200, GraphicsContext::RED);
	Shape* L2 = L1->clone();
	Shape* T2 = T1->clone();
	Shape* L3(L1);
	Shape* T3(T1);
	delete L1;
	delete T1;
	(*L3).draw(gc);
	(*T3).draw(gc);


	sleep(5);
 
	delete gc;
 
	return 0;
}