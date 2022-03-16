/**
 * @file ReadSTL.cpp
 * @author Trevor Barnes (barnestr@msoe.edu)
 * @brief A C++ file containing the functionality need to read in a .stl file.
 * The ReadSTL class allows the min/max coordinates and total count of the STL
 * facets be stored. The appropriate getters are also included.
 * @version 1.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ReadSTL {
    private:
        int numFacet;
        double Xmin;
        double Xmax;
        double Ymin;
        double Ymax;
        double Zmin;
        double Zmax;
    public:
        ReadSTL(string filename) {
            // Instantiate variables
            numFacet = 0;
            // Input Stream setup
            ifstream inputfile(filename, ifstream::in);
            string line;
            string token;
            string solidName;
            // Solid header line
            getline(inputfile, line);
            // Input string stream for each line
            istringstream lineStream(line);
            // Iterate stream past "solid"
            lineStream >> token;
            // Get solid name
            lineStream >> solidName;
            do {
                // Process entire solid, looping through each facet
                // Get next line
                getline(inputfile, line);
                // Set string stream to new line
                lineStream.str(line);
                // Clear sstream error state
                lineStream.clear();
                // Get first word in line
                lineStream >> token;
                if(!token.compare("facet")) {
                    // Facet header
                    // Iterate past "normal"
                    lineStream >> token;
                    // No additional functionality required for facet normal vectors
                    // Normal X
                    lineStream >> token;
                    // Normal Y
                    lineStream >> token;
                    // Z Normal
                    lineStream >> token;
                    // End facet header
                    do {
                        // Get next line
                        getline(inputfile, line);
                        // Set string stream to new line
                        lineStream.str(line);
                        // Clear sstream error state
                        lineStream.clear();
                        lineStream >> token;
                        if (!token.compare("outer")) {
                            do {
                                // Get next line
                                getline(inputfile, line);
                                // Set string stream to new line
                                lineStream.str(line);
                                // Clear sstream error state
                                lineStream.clear();
                                lineStream >> token;
                                if(!token.compare("vertex")) {
                                    // Process vertex
                                    // Coord double value
                                    double coord;
                                    // X Coord
                                    lineStream >> token;
                                    coord = stod(token);
                                    if((coord < Xmin) || numFacet == 0) {
                                        Xmin = coord;
                                    }
                                    if((coord > Xmax) || numFacet == 0) {
                                        Xmax = coord;
                                    }
                                    // Y Coord
                                    lineStream >> token;
                                    coord = stod(token);
                                    if((coord < Ymin) || numFacet == 0) {
                                        Ymin = coord;
                                    }
                                    if((coord > Ymax) || numFacet == 0) {
                                        Ymax = coord;
                                    }
                                    // Z Coord
                                    lineStream >> token;
                                    coord = stod(token);
                                    if((coord < Zmin) || numFacet == 0) {
                                        Zmin = coord;
                                    }
                                    if((coord > Zmax) || numFacet == 0) {
                                        Zmax = coord;
                                    }
                                } // End vertex line
                            } while(token.compare("endloop")); // Endloop
                        } 
                    }while(token.compare("endfacet")); // Endfacet
                    // Iterate facet counter
                    numFacet++;
                }
            }while(token.compare("endsolid"));
            // Close file
            inputfile.close();
        }

    /**
     * @brief Getter for the number of facets
     * 
     * @return int 
     */
    int getNumFacets(){
        return numFacet;
    }
    
    /**
     * @brief Getter for Xmin
     * 
     * @return double 
     */
    double getXmin() {
        return Xmin;
    }

    /**
     * @brief Getter for Xmax
     * 
     * @return double 
     */
    double getXmax() {
        return Xmax;
    }

    /**
     * @brief Getter for Ymin
     * 
     * @return double 
     */
    double getYmin() {
        return Ymin;
    }
    
    /**
     * @brief Getter for Ymax
     * 
     * @return double 
     */
    double getYmax() {
        return Ymax;
    }

    /**
     * @brief Getter for Zmin
     * 
     * @return double 
     */
    double getZmin() {
        return Zmin;
    }

    /**
     * @brief Getter for Zmax
     * 
     * @return double 
     */
    double getZmax() {
        return Zmax;
    }
};
