/**
 * @file main.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief The main driver file used to demonstrate the functionality of the
 * ReadSTL class. The user enters the file location of the STL file as a 
 * command line arg and the console returns the min/max coords of the solid's
 * facets as well as the total number of facets.
 * @version 1.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>
#include "ReadSTL.cpp"
using namespace std;

//int main(int argc, char** argv) {
int main(){
    // Debug mode
    ReadSTL stl1("STLFiles/shape.stl");
    // End debug mode
    //ReadSTL stl1(argv[1]);
    cout << endl << "File read successfully!" << endl;  
    // Formatted file info output
    cout << "Facets in file: " << stl1.getNumFacets() << endl << endl;

    cout << "X Min: " << stl1.getXmin() << endl;
    cout << "X Max: " << stl1.getXmax() << endl << endl;    

    cout << "Y Min: " << stl1.getYmin() << endl;
    cout << "Y Max: " << stl1.getYmax() << endl << endl;    

    cout << "Z Min: " << stl1.getZmin() << endl;
    cout << "Z Max: " << stl1.getZmax() << endl << endl;

    return 0;
}
