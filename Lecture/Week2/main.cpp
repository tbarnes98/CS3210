#include <iostream>
using namespace std;

int & multiply(int A, int B) {
    int i = A*B;
    return i;
}

int main() {
    int A = 5;
    int B = 3;
    int C = multiply(A,B);
    cout << "A: " << A << " B: " << B << " C: " << C << endl;

    return 0;
}