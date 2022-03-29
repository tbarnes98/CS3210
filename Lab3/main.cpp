/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
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
	Matrix m1(rows,cols);
	// add more tests
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			m1[i][j] = 4.268394 + (i+7)*(j+7);
		}
		m1[0][0] = 4.20;
		m1[0][1] = 6.9;
		m1[0][2] = 1.337;
		m1[0][3] = 12.18;

	}
	cout << m1 << endl;
	m1*5;
	cout << m1 << endl;
	m1.clear();
	cout << m1;
	return 0;
}
