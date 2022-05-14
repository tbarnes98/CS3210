// - ViewContext Class - 

#include <cmath>
#include "viewcontext.h"

ViewContext::ViewContext(int width, int height){
    compMatrix = new Matrix(4,4);
    prevTransform = new Matrix(4,4);
}

void ViewContext::model_to_device(Matrix* coord){
    (*coord) = (*compMatrix)*(*coord);
}

void ViewContext::rotate(int deg){
    // Store previous transform
    *prevTransform = *compMatrix;
    Matrix temp = Matrix::identity(4);
    // Input transformation
    temp[0][0] = cos(deg*M_PI/180);
    temp[0][1] = sin(deg*M_PI/180);
    temp[1][0] = -sin(deg*M_PI/180);
    temp[1][0] = cos(deg*M_PI/180);
    // Add transformation to comp matrix
    *compMatrix = temp*(*compMatrix);
}
    
    // Scaling - Around center of screen
void ViewContext::scale(int mult){
    // Store previous transform
    *prevTransform = *compMatrix;
    // Create identity matrix
    Matrix temp = Matrix::identity(4);
    // Input transformation
    temp[0][0] = mult;
    temp[1][1] = mult;
    temp[2][2] = mult;
    // Add transformation to comp matrix
    *compMatrix = temp*(*compMatrix);
}

// Translation
void ViewContext::translate(int dx, int dy, int dz){
    // Store previous transform
    *prevTransform = *compMatrix;
    Matrix temp = Matrix::identity(4);
    // Input transformation
    temp[0][3] = dx;
    temp[1][3] = dy;
    temp[2][3] = dz;
    // Add transformation to comp matrix
    *compMatrix = temp*(*compMatrix);
}
// Reset
void ViewContext::reset(){
    *compMatrix = (Matrix::identity(4))*(*compMatrix);
}

// Undo
void ViewContext::undo(Matrix* coord){
    // Use temp to store current trans
    Matrix temp = Matrix::identity(4);
    
    (*coord) = (*prevTransform)*(*coord);
    *prevTransform = temp;

}

// Invert Colors
// void ViewContext::invert(){

// }