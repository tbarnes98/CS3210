/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief Driver for testing the changes made to x11context.cpp
 * 5000 Lines Test Results:
 * - X11 Default Implementation: 0.83 Seconds
 * - Bresenham Implementation: 29.71 Seconds
 * @version 1.0
 * @date 2022-04-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "x11context.h"
#include <unistd.h>
#include <iostream>
using namespace std;

int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
 
 
	// draw some lines
	gc->setColor(GraphicsContext::GREEN);
	gc->setPixel(10,10);
	gc->setPixel(30,30);
	gc->drawLine(100,100,100,500);
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(100,500,500,500);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(500,500,500,100);
	gc->setColor(GraphicsContext::YELLOW);
	gc->drawLine(500,100,100,100);
	gc->setColor(GraphicsContext::MAGENTA);
	gc->drawCircle(300,300,200);
	sleep(2);
	gc->clear();

	// Random/Negatives Test
	gc-> setColor(rand());
	gc->drawLine(-100, 5000, 200, -590);
	gc-> setColor(rand());
	gc->drawLine(rand()%800,rand()%600,rand()%800,rand()%600);
	gc-> setColor(rand());
	gc->drawLine(rand()%800,rand()%600,rand()%800,rand()%600);
	gc-> setColor(rand());
	gc->drawLine(rand()%800,rand()%600,rand()%800,rand()%600);
	sleep(5);
	gc->clear();
	// End Random/Negatives Test

	// 5000 lines test
	// gc->setColor(GraphicsContext::GREEN);
	// int total = 0;
	// while(total < 5000){
	// 	for(int i = 0; (i < 800) && (total < 5000); i++){
	// 		gc->drawLine(i,0,i,600);
	// 		total++;
	// 	}
	// 	gc-> setColor(rand());
	// 	cout << total << endl;
	// }
	// cout << total << endl;
	// gc->clear();
	// End 5000 lines test

	// Draw boat
	gc->setColor(GraphicsContext::YELLOW);
	gc->drawLine(250,500,550,500);
	gc->drawLine(250,500,150,400);
	gc->drawLine(150,400,650,400);
	gc->drawLine(650,400,550,500);
	gc->drawLine(400,400,400,100);

	gc->drawLine(400,100,300,150);
	gc->drawLine(300,150,400,200);

	// Draw waves
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(0,550,100,450);
	gc->drawLine(100,450,100,550);
	gc->drawLine(100,550,200,450);
	gc->drawLine(200,450,200,550);
	gc->drawLine(200,550,300,450);
	gc->drawLine(300,450,300,550);
	gc->drawLine(300,550,400,450);
	gc->drawLine(400,450,400,550);
	gc->drawLine(400,550,500,450);
	gc->drawLine(500,450,500,550);
	gc->drawLine(500,550,600,450);
	gc->drawLine(600,450,600,550);
	gc->drawLine(600,550,700,450);
	gc->drawLine(700,450,700,550);
	gc->drawLine(700,550,800,450);

	sleep(5);
 
	delete gc;
 
	return 0;
}