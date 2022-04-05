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
#include "x11context.h"
#include <unistd.h>
#include <iostream>
using namespace std;

int main(void)
{
	GraphicsContext* gc = new X11Context(800,600,GraphicsContext::BLACK);
 
	

	sleep(10);
 
	delete gc;
 
	return 0;
}