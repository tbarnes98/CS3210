/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief 
 * @version 1.0
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>
#include "row.h"
using namespace std;

int main() {
    // Test Setup
    int length;
    cout << "Enter the desired length for the matrix constructor test:" << endl;
    cin >> length;

    cout << "Test - Constructor / Access Operator" << endl;
    // Test: Constructor
    Row row1(length);

    // Test: Access Operator (non const)
    try{
        for(int i = 0; i < length; i++){
            cout << row1[i] << " ";
        }
        cout << endl;
        cout << row1[1] << endl;
        //row1[1] = 12.18;
        cout << row1[1] << endl;
        cout << row1[length+1] << endl; // Might change
    }catch(out_of_range){
        cout << "Out of Range Exception Successfully Caught" << endl;
    }
    cout << "Test - Constructor/AccessOperator: PASS" << endl;

    cout << "Test - Copy Constructor/AccessOperator(const)" << endl;
    // Test: Copy Constructor
    const Row row1Copy(row1);
    cout << "before seg";
    // Test: Access Operator (const)
    try{
        for(int i = 0; i < length; i++){
            cout << row1Copy[i] << " ";
        }
        cout << row1Copy[1];
        cout << row1Copy[length+1]; // Might change
    }catch(out_of_range){
        cout << "Out of Range Exception Successfully Caught" << endl;
    }
    cout << "Test - Copy Constructor / Access Operator (const): PASS" << endl;

    // Test: Assignment Operator
    Row row2(length*2);
    row2 = row1;
    for(int i = 0; i < length*2; i++){
        cout << row2[i] << " ";
    }
    cout << endl;

    // Test: Clear
    row2.clear();
    for(int i = 0; i < length*2; i++){
        cout << row2[i] << " ";
    }
    cout << endl;

    return 0;
}
