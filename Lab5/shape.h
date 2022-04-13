#include <iostream>
#include "x11context.h"

using namespace std;

class Shape{
    public:
        // Constructor
        Shape();
        // Copy Constructor
        Shape(const Shape& from);
        // Destructor
        virtual ~Shape();
        // Virtual Constructor
        virtual Shape* clone();
        // Draw shape
        virtual void draw(GraphicsContext gc);
        // Print to output stream
        virtual void out(std::ostream& os, const Shape& rhs);


    protected:
        // Assignment Operator
        Shape& operator=(const Shape& rhs);
    private:
        uint32_t RGB;
};



