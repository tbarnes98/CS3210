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
#include <stdexcept>
#include <iomanip>
#include "matrix.h"

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
 }
 
// Copy constructor
Matrix::Matrix(const Matrix& from){
	// New matrix gets row amount from "from" matrix
	this->rows = from.rows;
	// New matrix gets row amount from "from" matrix
	this->cols = from.cols;
	// Create the row pointer with new row amount
	this->the_matrix = new Row*[rows];
	for(int i = 0; i < this->rows; i++){
		// Set the pointer to each copied row
		the_matrix[i] = new Row(from[i]);
	}
}

// Destructor
Matrix::~Matrix(){
	// Explicitly calls the destructor for each row in the matrix
	for(int i = 0; i < rows; i++) {
		the_matrix[i]->~Row();
	}
	// Deletes the matrix itself
	delete[] the_matrix;
}
 
// Assignment operator - TODO
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
	size--;
	// Create square matrix
	Matrix result(size, size);
	for(int i = 0; i < size; i++){
		// Fill each diagonal value with 1
		result[i][i] = 1;
	}
	return result;
}	
		
// Matrix addition - TODO
Matrix Matrix::operator+(const Matrix& rhs) const{
	Matrix result(this->rows, this->cols);
	// finish
	return result;
}
 
// Matrix multiplication  - TODO
Matrix Matrix::operator*(const Matrix& rhs) const{
	if(rows != rhs.cols){
		throw(invalid_argument("1st matrix rows must equal 2nd matrix cols"));
	}
	//for(int i = 0; i < cols; i++)
	Matrix result(this->rows, rhs.cols);
	// finish
	return result;
}
 
// Scalar multiplication - TODO
Matrix Matrix::operator*(const double scale) const{
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			double temp = (*the_matrix[i])[j]*scale;
			(*the_matrix[i])[j] = temp;
		}
	}
	Matrix result(this->rows, this->cols);
	// finish
	return result;
}

// Transpose of a Matrix - TODO
Matrix Matrix::operator~() const{
	Matrix result(this->cols, this->rows);
	// finish
	return result;
}
 
// Clear Matrix
void Matrix::clear(){
	for(int i = 0; i < rows ; i++) {
		the_matrix[i]->clear();
	}
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
 
// print to output stream - TODO
void Matrix::out(std::ostream& os) const{
	os << setprecision(4);
	os << setw(10);	
	// finish
}

// global insertion operator - TODO
std::ostream& operator<<(std::ostream& os, const Matrix& rhs){
	rhs.out(os);
	return os;
}	

// global scalar multiplication - TODO
Matrix operator*(const double scale, const Matrix& rhs){
	return rhs*scale;
}