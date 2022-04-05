/**
 * @file matrix.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief Contains the main functionality for matrices of double values
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
	// New matrix gets col amount from "from" matrix
	this->cols = from.cols;
	// Create the row pointer with new row amount
	this->the_matrix = new Row*[rows];
	for(int i = 0; i < rows; i++){
		// Set the pointer to each copied row
		this->the_matrix[i] = new Row(from[i]);
	}
}

// Destructor
Matrix::~Matrix(){
	// Iterates through the pointer array and deletes each row's array
	for(int i = 0; i < rows; i++) {
		delete this->the_matrix[i];
	}
	// Deletes the matrix itself
	delete[] the_matrix;
}
 
// Assignment operator
Matrix& Matrix::operator=(const Matrix& rhs){
	if(&rhs != this){
		if(rows > 0 && cols > 0){
			// Iterates through the pointer array and deletes each row's array
			for(int i = 0; i < rows; i++) {
				delete this->the_matrix[i];
			}
			// Deletes the matrix itself
			delete[] the_matrix;
		}
		this->rows = rhs.rows;
		this->cols = rhs.cols;
		this->the_matrix = new Row*[rows];
		for(int i = 0; i < rows; i++){
			// Set the pointer to each copied row
			the_matrix[i] = new Row(rhs[i]);
		}
	}
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
}	
		
// Matrix addition
Matrix Matrix::operator+(const Matrix& rhs) const{
	if(rows != rhs.rows || cols != rhs.cols){
		throw(out_of_range("Matrices must be the same size"));
	}
	Matrix result(this->rows, this->cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result[i][j] = (*the_matrix[i])[j] + rhs[i][j];
		}
	}
	return result;
}
 
// Matrix multiplication
Matrix Matrix::operator*(const Matrix& rhs) const{
	if(cols != rhs.rows){
		throw(out_of_range("1st matrix rows must equal 2nd matrix cols"));
	}
	Matrix result(this->rows, rhs.cols);
	for(int i = 0; i < this->rows; i++){
		for(int j = 0; j < rhs.cols; j++){
			result[i][j] = 0.0;
			for(int k = 0; k < rhs.rows; k++){
				result[i][j] += (*the_matrix[i])[k]*rhs[k][j];
			}
		}
	}
	return result;
}
 
// Scalar multiplication
Matrix Matrix::operator*(const double scale) const{
	Matrix result(this->rows, this->cols);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result[i][j] = (*the_matrix[i])[j]*scale;
		}
	}
	return result;
}

// Transpose of a Matrix
Matrix Matrix::operator~() const{
	Matrix result(this->cols, this->rows);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			result[j][i] = (*the_matrix[i])[j];
		}
	}
	return result;
}
 
// Clear Matrix
void Matrix::clear(){
	for(int i = 0; i < rows; i++) {
		the_matrix[i]->clear();
	}
}
  
// Access Operators - non-const
Row& Matrix::operator[](unsigned int row){
	// Ensure the row is in range
	if(row > rows){
		throw(out_of_range("Row is out of range"));
	}
	return *(the_matrix[row]);
}
 
// Access Operators - const
const Row& Matrix::operator[](unsigned int row) const{
	// Ensure the row is in range
	if(row > rows){
		throw(out_of_range("Row is out of range"));
	}
	return *(the_matrix[row]);
}
 
// print to output stream
void Matrix::out(std::ostream& os) const{
	os << setprecision(4);
	os << "[";
	for(int i = 0; i < rows; i++) {
		if(i != 0){
			cout << " ";
		}
		os << "[ ";
		for(int j = 0; j < cols; j++) {
			os << (*the_matrix[i])[j];
			if(j != cols-1){
				os << ", ";
			}
		}
		os << " ]";
		if(i != rows-1){
			os << endl;
		}
	}
	os << "]" << endl;
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