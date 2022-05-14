#ifndef mydrawing_h
#define mydrawing_h

#include <iostream>
#include "drawbase.h"
#include "image.h"
using namespace std;

class MyDrawing: public DrawingBase{

    public:
        MyDrawing();
        void keyDown(GraphicsContext* gc, unsigned int keycode);
        void mouseMove(GraphicsContext* gc, int x, int y);
        void mouseButtonDown(GraphicsContext* gc, 
                             unsigned int button, int x, int y);
        void mouseButtonUp(GraphicsContext* gc,
                           unsigned int button, int x, int y);

    private:
        // default is red
        unsigned int color = GraphicsContext::RED;
        // indicates whether user is holding down the mouse
        bool hold = false;
        // "lines" mode - lines from center
        // "mirror" mode - mirror 8 times around center
        string mode = "lines";

        // start of line drawn in mirror mode
        int xprev;
        int yprev;
        // first pixel drawn in mirror mode
        bool firstdraw = true;
        // dotted or connected mode
        bool connected = true;
        Image image;

};

void setLargePixel(GraphicsContext* gc, int x, int y);
void drawLargeLine(GraphicsContext* gc, int x0, int y0, int x1, int y1);

#endif