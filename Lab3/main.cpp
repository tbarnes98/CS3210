/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief The main driver for the matrix implementation. This driver provides
 * test for matrix.cpp. Memory leak test were performed using valgrind
 * @version 1.0
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	int rows, cols;
	cout << "Enter the number of rows in the test matrix: " << endl;
	cin >> rows;
	cout << "Enter the number of columns in the test matrix: " << endl;
	cin >> cols;
	// Constructor Test
	Matrix m1(rows,cols);
	Matrix m2(rows,cols);
	// Assign various arbitrary values
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			m1[i][j] = 12.181998*(1+(i*j));
			m2[i][j] = 1.0 + i;
		}
	}
	// IO Test
	cout << "m1:" << endl << m1; 
	// Copy Constructor Test with const
	const Matrix m1copy(m1);
	cout << "m1copy:" << endl << m1copy;
	cout << "m2:" << endl << m2;
	// Assignment Operator Test
	m1 = m2;
	cout << "m1 = m2:" << endl << m1;
	// Transpose Test
	m1 = ~m1;
	cout << "~m1:" << endl << m1;
	// Named Contructor Test
	Matrix ident = Matrix::identity(4);
	cout << "Identity matrix of size: " << rows << endl << ident;
	Matrix m3(3,4);
	Matrix m4(4,3);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			m3[i][j] = 1 + i*j;
		}
	}
	cout << "m3:" << endl << m3; 
	// Scalar Multiplication Test
	m3 = 2.0*m3;
	cout << "m3 = 2.0*m3" << endl << m3;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			m4[i][j] = 2 + i*j;
		}
	}
	cout << "m4:" << endl << m4;
	Matrix m5(3,3);
	// Matrix Multiplication Test
	m5 = m3*m4;
	cout << "m5 = m3*m4" << endl << m5;
	// Clear Test
	m5.clear();
	cout << "m5.clear()" << endl << m5;

    // Tested for memory leaks using valgrind:
    // Result: "All heap blocks were freed -- no leaks are possible"

	return 0;
}
