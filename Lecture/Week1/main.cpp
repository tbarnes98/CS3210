#include <iostream>
using namespace std;
/*
void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}
*/

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int A = 2;
    int B = 8;
    // Pass in addresses to be 
    swap(&A,&B);
    cout << "A: " << A << " B: " << B << endl;

    return 0;
}