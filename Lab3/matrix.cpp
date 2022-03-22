/**
 * @file matrix.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "matrix.h"
#include <iomanip>
using namespace std;

// constructor
Matrix::Matrix(unsigned int rows, unsigned int cols){
	// Ensure size is valid
	if(rows < 1 || cols < 1){ 
		throw(out_of_range("rows and cols must be greater than 0"));
	}
	// Assign given row and col size to matrix
	this->rows = rows;
	this->cols = cols;
	// Create the row pointer
	this->the_matrix = new Row*[rows];
	for(int i = 0; i < rows; i++){
		// Assign the rows of the matrix to new memory
		this->the_matrix[i] = new Row(cols);
	}
	// finish
 }
 
// Copy constructor
Matrix::Matrix(const Matrix& from){
	this->rows = from.rows;
	this->cols = from.cols;
	for(int i = 0; i < this->rows; i++){
		
	}
}

// Destructor
Matrix::~Matrix(){
	// finish
}
 
// Assignment operator
Matrix& Matrix::operator=(const Matrix& rhs){
	// finish
	return *this;
}	
 
// Named Constructor 
Matrix Matrix::identity(unsigned int size){
	// Ensure size is valid
	if(size < 1){ 
		throw(out_of_range("rows and cols must be greater than 0"));
	}
	// Create square matrix
	Matrix result(size, size);
	for(int i = 0; i < size; i++){
		// Fill each diagonal value with 1
		result[i][i] = 1;
	}
	return result;
	// finish
}	
		
// Matrix addition
Matrix Matrix::operator+(const Matrix& rhs) const{
	Matrix result(this->rows, this->cols);
	// finish
	return result;
}
 
// Matrix multiplication 
Matrix Matrix::operator*(const Matrix& rhs) const{
	Matrix result(this->rows, rhs.cols);
	// finish
	return result;
}
 
// Scalar multiplication
Matrix Matrix::operator*(const double scale) const{
	Matrix result(this->rows, this->cols);
	// finish
	return result;
}

// Transpose of a Matrix
Matrix Matrix::operator~() const{
	Matrix result(this->cols, this->rows);
	// finish
	return result;
}
 
// Clear Matrix
void Matrix::clear(){
	// finish
}
  
// Access Operators - non-const
Row& Matrix::operator[](unsigned int row){
	// Ensure the row is in range
	if(row >= rows){
		throw(out_of_range("Row is out of range"));
	}
	return *(the_matrix[row]);
}
 
// Access Operators - const
const Row& Matrix::operator[](unsigned int row) const{
	// Ensure the row is in range
	if(row >= rows){
		throw(out_of_range("Row is out of range"));
	}
	return *(the_matrix[row]);
}
 
// print to output stream
void Matrix::out(std::ostream& os) const{
	os << setprecision(4);
	os << setw(10);	
	// finish
}

// global insertion operator
std::ostream& operator<<(std::ostream& os, const Matrix& rhs){
	rhs.out(os);
	return os;
}	

// global scalar multiplication
Matrix operator*(const double scale, const Matrix& rhs){
	return rhs*scale;
}