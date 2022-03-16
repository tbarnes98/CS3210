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
    int length;
    cout << "Enter desired length for row matrix:" << endl;
    cin >> length;
    Row row1(length);
    for(int i = 0; i < length; i++){
        cout << "before seg fault" << endl;
        // Will use access operator instead
        //cout << row1.row_data[i] << " ";
    }
    cout << endl;
    
    return 0;
}
