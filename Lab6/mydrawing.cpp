#include "mydrawing.h"

using namespace std;
MyDrawing::MyDrawing()
{
    cout << "COLORS: 'b' = blue, 'r' = red, 'g' = green \n";
    cout << "MODES: 'l' = lines, 'm' = mirror, 'd' = dotted, 'c' = connected\n";
    cout << "OTHER: 'Delete' = clear image\n";
}
void MyDrawing::keyDown(GraphicsContext *gc, unsigned int keycode)
{
    switch (keycode)
    {
    case 114: // 'r', change color to red
        color = GraphicsContext::RED;
        break;
    case 103: // 'g', change color to green
        color = GraphicsContext::GREEN;
        break;
    case 98: // 'b', change color to blues
        color = GraphicsContext::BLUE;
        break;
    case 65535: // 'delete', clear window
        gc->clear();
        break;
    case 108: // 'l', set mode to "lines"
        mode = "lines";
        break;
    case 109: // 'm', set mode to "mirror"
        mode = "mirror";
        break;
    case 99: // 'c', set mode to connected
        connected = true;
        break;
    case 100: // 'd', set mode to dotted
        connected = false;
        break;
    }
}
void MyDrawing::mouseButtonDown(GraphicsContext *gc, unsigned int button, int x,
                                int y)
{
    hold = true; // user is holding down mouse
}
void MyDrawing::mouseMove(GraphicsContext *gc, int x, int y)
{
    int dx = gc->getWindowWidth();
    int dy = gc->getWindowHeight();
    if (hold)
    { // only draw when user is holding down mouse
        if (mode == "lines")
        {
            gc->setColor(color);
            //. draw line from center of window to mouse location
            gc->drawLine(dx / 2, dy / 2, x, y);
        }
        else if (mode == "mirror")
        {
            gc->setColor(color);
            if (firstdraw)
            {
                xprev = x;
                yprev = y;
                firstdraw = false;
            }
            // mirror 8 times around center in dotted or connected mode
            if (!connected)
            {
                setLargePixel(gc, x, y);
                setLargePixel(gc, y + dx / 2 - dy / 2, -x + dx / 2 + dy / 2);
                setLargePixel(gc, -y + dx / 2 + dy / 2, x - dx / 2 + dy / 2);
                setLargePixel(gc, -x + dx, -y + dy);
                setLargePixel(gc, y + dx / 2 - dy / 2, x - dx / 2 + dy / 2);
                setLargePixel(gc, -y + dx / 2 + dy / 2, -x + dx / 2 + dy / 2);
                setLargePixel(gc, x, -y + dy);
                setLargePixel(gc, -x + dx, y);
            }
            else
            {
                drawLargeLine(gc, xprev, yprev, x, y);
                drawLargeLine(gc, yprev + dx / 2 - dy / 2, -xprev + dx / 2 + dy / 2,
                              y + dx / 2 - dy / 2, -x + dx / 2 + dy / 2);
                drawLargeLine(gc, -yprev + dx / 2 + dy / 2, xprev - dx / 2 + dy / 2,
                              -y + dx / 2 + dy / 2, x - dx / 2 + dy / 2);
                drawLargeLine(gc, -xprev + dx, -yprev + dy, -x + dx, -y + dy);
                drawLargeLine(gc, yprev + dx / 2 - dy / 2, xprev - dx / 2 + dy / 2,
                              y + dx / 2 - dy / 2, x - dx / 2 + dy / 2);
                drawLargeLine(gc, -yprev + dx / 2 + dy / 2, -xprev + dx / 2 + dy / 2,
                              -y + dx / 2 + dy / 2, -x + dx / 2 + dy / 2);
                drawLargeLine(gc, xprev, -yprev + dy, x, -y + dy);
                drawLargeLine(gc, -xprev + dx, yprev, -x + dx, y);
            }
            // draw line from previous mouse coordinate
            xprev = x;
            yprev = y;
        }
    }
}
void MyDrawing::mouseButtonUp(GraphicsContext *gc,
                              unsigned int button, int x, int y)
{
    // user has released mouse button
    hold = false;
    firstdraw = true;
}

void drawLargeLine(GraphicsContext *gc, int x0, int y0, int x1, int y1)
{
    // draw 3 pixel wide line
    gc->drawLine(x0, y0, x1, y1);
    gc->drawLine(x0 + 1, y0, x1 + 1, y1);
    gc->drawLine(x0 - 1, y0, x1 - 1, y1);
}
void setLargePixel(GraphicsContext *gc, int x, int y)
{
    // draw 9x9 square around pixel
    gc->setPixel(x, y);
    gc->setPixel(x + 1, y);
    gc->setPixel(x + 1, y + 1);
    gc->setPixel(x, y + 1);
    gc->setPixel(x - 1, y + 1);
    gc->setPixel(x - 1, y);
    gc->setPixel(x - 1, y - 1);
    gc->setPixel(x, y - 1);
    gc->setPixel(x + 1, y - 1);
}