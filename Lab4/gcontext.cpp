/* This is an abstract base class representing a generic graphics
 * context.  Most implementation specifics will need to be provided by
 * a concrete implementation.  See header file for specifics. */

#define _USE_MATH_DEFINES	// for M_PI
#include <cmath>	// for trig functions
#include "gcontext.h"	

/*
 * Destructor - does nothing
 */
GraphicsContext::~GraphicsContext()
{
	// nothing to do
	// here to insure subclasses handle destruction properly
}

//does nothing
void GraphicsContext::drawLine(int x0, int y0, int x1, int y1){}
void GraphicsContext::drawCircle(int x0, int y0, unsigned int radius){}


void GraphicsContext::endLoop()
{
	run = false;
}