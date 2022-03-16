#include<iostream>
#include "row.h"
using namespace std;

// parameterized constructor
Row::Row(unsigned int length){
	cout << "-Row Constructor-" << endl; // TODO: temp
	// Set matrix length private variable to passed in length
	this->length = length;
	// Create new array in heap for row_data
	this->row_data = new double[length];
	// Clear all values in new array to 0
	for(int i = 0; i < length; i++) {
		cout << "-Row Constructor-" << endl; // TODO: temp
		this->row_data[i] = 0.0;
	}
	// finish
}

// copy constructor
Row::Row(const Row& from){
	cout << "-Row Copy Constructor-" << endl; // TODO: temp
	// New row matrix gets length from previous matrix
	this->length = from.length;
	// Create new array in heap with new length
	this->row_data - new double[this->length];
	// Copy all row_data values over to new array
	for(int i = 0; i < this->length; i ++) {
		this->row_data[i] = from.row_data[i];
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
	//finish
}

// access operator (const)
double Row::operator[](unsigned int column) const{
	//finish
	double result;
	return result;
}

// access operator (non-const)
double& Row::operator[](unsigned int column){
	//finish
	double result;
	return result;
}

// assignment operator
Row& Row::operator= (const Row& rhs){
	//finish
	Row result(1);
	return result;
}

// clear row data
void Row::clear(){
	//finish
}