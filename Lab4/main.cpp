#include "x11context.h"
#include <unistd.h>
#include <iostream>
 
int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
 
 
	// draw some lines
	gc->setColor(GraphicsContext::GREEN);
	gc->setPixel(10,10);
	gc->setPixel(30,30);
	gc->drawLine(100,100,500,500);
	gc->setColor(GraphicsContext::RED);
	gc->drawLine(100,500,500,500);
	gc->setColor(GraphicsContext::BLUE);
	gc->drawLine(500,500,500,100);
	gc->setColor(GraphicsContext::YELLOW);
	gc->drawLine(500,100,100,100);
	gc->setColor(GraphicsContext::MAGENTA);
	gc->drawCircle(300,300,200);
	sleep(10);
 
	delete gc;
 
	return 0;
}