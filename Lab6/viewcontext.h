#ifndef viewcontext_h
#define viewcontext_h

#include "matrix.h"


class ViewContext{
        ViewContext();
        void model_to_device();

        // Rotation - Around center of screen
        // Scaling - Around center of screen
        // Translation
        // Reset
        // Invert Colors
        Matrix* compMatrix;
};

#endif