#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ReadSTL {
    private:
        int numFacet = 0;
        double Xmin = 0;
        double Xmax = 0;
        double Ymin = 0;
        double Ymax = 0;
        double Zmin = 0;
        double Zmax = 0;
    public:
    ReadSTL(string filename) {
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
                // Process facet
                // Facet header
                // Iterate past "normal"
                lineStream >> token;
                // Coord double value
                double coord;
                // Convert coord string to double
                // X Coord
                lineStream >> token;
                coord = stod(token);
                // X Min
                if((coord < Xmin) || numFacet == 0) {
                    Xmin = coord;
                }
                // X Max
                if((coord > Xmax) || numFacet == 0) {
                    Xmax = coord;
                }
                // Y Coord
                lineStream >> token;
                coord = stod(token);
                // Min
                if((coord < Ymin) || numFacet == 0) {
                    Ymin = coord;
                }
                // Max
                if((coord > Ymax) || numFacet == 0) {
                    Ymax = coord;
                }
                // Z Coord
                lineStream >> token;
                coord = stod(token);
                // Min
                if((coord < Zmin) || numFacet == 0) {
                    Zmin = coord;
                }
                // Max
                if((coord > Zmax) || numFacet == 0) {
                    Zmax = coord;
                }
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
                                //Process vertex
                                // No functionality needed
                                // Does nothing but iterate through each coord
                                // X coord
                                lineStream >> token;
                                // Y coord
                                lineStream >> token;
                                // Z coord
                                lineStream >> token;
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

    int getNumFacets(){
        return numFacet;
    }

    double getXmin() {
        return Xmin;
    }
    double getXmax() {
        return Xmax;
    }

    double getYmin() {
        return Ymin;
    }
    double getYmax() {
        return Ymax;
    }

    double getZmin() {
        return Zmin;
    }
    double getZmax() {
        return Zmax;
    }
};
