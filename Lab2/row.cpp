#include<iostream>
#include "row.h"
using namespace std;

// parameterized constructor
Row::Row(unsigned int length){
	// Set matrix length private variable to passed in length
	this->length = length;
	// Create new array in heap for row_data
	this->row_data = new double[length];
	// Clear all values in new array to 0
	clear();
	// finish
}

// copy constructor
Row::Row(const Row& from){
	// New row matrix gets length from previous matrix
	this->length = from.length;
	// Create new array in heap with new length
	this->row_data - new double[this->length];
	// Copy all row_data values over to new array
	for(int i = 0; i < this->length; i++) {
		cout << "before seg fault" << endl;
		cout << this->row_data[i] << endl;
		this->row_data[i] = from[i];
	}
	// finish
}

// destructor
Row::~Row(){
	cout << "-Row Destructor-" << endl; // TODO: temp
	// Check for valid length then free the heap memory
	if(this->length > 0 ) {
		delete[] row_data;
	}
}

// access operator (const)
double Row::operator[](unsigned int column) const{
	if (column >= length) {
		throw(out_of_range("Column is out of range"));
	}
	return row_data[column];
}

// access operator (non-const)
double& Row::operator[](unsigned int column){
	if (column >= length) {
		throw(out_of_range("Column is out of range"));
	}
	return row_data[column];
}

// assignment operator
Row& Row::operator= (const Row& rhs){
	if(&rhs != this){
		// Delete the current row matrix
		if(length > 0){
			delete[] this->row_data;
		}
		// New row matrix gets length from previous matrix
		this->length = rhs.length;
		// Create new array in heap with new length
		this->row_data - new double[this->length];
		// Copy all row_data values over to new array
		for(int i = 0; i < this->length; i ++) {
			this->row_data[i] = rhs.row_data[i];
		}
	}
	// Return address of the Row
	return *this;
}

// clear row data
void Row::clear(){
	for(int i = 0; i < length; i++) {
		this->row_data[i] = 0;
	}
}