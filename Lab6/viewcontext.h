#ifndef viewcontext_h
#define viewcontext_h

#include "matrix.h"


class ViewContext{
    public:
    // Contructor - takes in current window width and height to account for origin
    ViewContext(int width, int height);
    // Destructor
    ~ViewContext();
    
    void model_to_device(Matrix* coord);
    // Rotation - Around center of screen
    void rotate(int deg);
    
    // Scaling - Around center of screen
    void scale(int mult);
    
    // Translation
    void translate(int dx, int dy, int dz);

    // Reset
    void reset();

    // Undo previous transform
    void undo(Matrix* coord);

    // Invert Colors
    //void invert();

    private:
    // Window pixel width
    int width;
    // Window pixel height
    int height;
    // Matrix containing the composite of all current transformations
    Matrix* compMatrix;
    // Matrix containing the previous transformation
    Matrix* prevTransform;
    
};

#endif