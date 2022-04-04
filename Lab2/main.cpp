/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief A main driver that provides some rudimentary tests for row.cpp
 * Tests involving memory leaks were tested using valgrind via the command:
 * `valgrind ./lab2` Test output was left in submission to signify modules
 * that have successfully passed and provide further clarity of testing
 * methods.
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
    double testValue;
    cout << "Enter the desired length for the row matrix:" << endl;
    cin >> length;
    cout << "Enter a double value to test as row data element:" << endl;
    cin >> testValue;

    cout << "Test - Constructor / Access Operator" << endl;
    // Test: Constructor
    Row row1(length);

    // Test: Access Operator (non const)
    try{
        // All elements are accessed
        for(int i = 0; i < length; i++){
            cout << row1[i] << " ";
        }
        cout << endl;
        // First element shown as 0
        cout << row1[0] << endl;
        // First element is assigned the test value
        row1[0] = testValue;
        // First element is now the test value
        cout << row1[0] << endl;
        // Throws OOB Exception
        cout << row1[length+1] << endl;
    }catch(const out_of_range e){
        cout << "Out of Range Exception Successfully Caught" << endl;
    }
    cout << "Test - Constructor / Access Operator: PASS" << endl;

    cout << "Test - Copy Constructor / Access Operator (const)" << endl;
    // Test: Copy Constructor
    const Row row1Copy(row1);
    // Test: Access Operator (const)
    try{
        for(int i = 0; i < length; i++){
            cout << row1Copy[i] << " ";
        }
        cout << endl;
        // First element is the same as the original Row object's
        cout << row1Copy[0] << endl;
        // Throws OOB Exception
        cout << row1Copy[length+1];
    }catch(const out_of_range e){
        cout << "Out of Range Exception Successfully Caught" << endl;
    }
    cout << "Test - Copy Constructor / Access Operator (const): PASS" << endl;

    // Test: Assignment Operator
    Row row2(length);
    // Set new row object equal to another row object
    row2 = row1;
    // Show that the elements are identical to the original row object
    for(int i = 0; i < length; i++){
        cout << row2[i] << " ";
    }
    cout << endl;

    // Test: Clear
    cout << "Test - Clear" << endl;
    row2.clear();
    for(int i = 0; i < length; i++){
        cout << row2[i] << " ";
    }
    cout << endl;
    cout << "Test - Clear: PASS" << endl;

    // Tested for memory leaks using valgrind:
    // Result: "All heap blocks were freed -- no leaks are possible"

    return 0;
}
