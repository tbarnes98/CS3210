#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ReadSTL {
    private:
        int numFacet;
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
        string solidName;
        // Solid header line
        getline(inputfile, line);
        // Input string stream for each line
        istringstream lineStream(line);
        string token;
        // Iterate stream past "solid"
        lineStream >> token; // Might not be a valid way of iterating stream
        // Get solid name
        lineStream >> token;
        solidName = token; // Might not work
        do {
            // Process entire solid, looping through each facet
            getline(inputfile, line);
            istringstream lineStream(line);
            lineStream >> token;
            if(!token.compare("facet")) {
                // Process facet
                do {
                    // Process facet header
                    // "normal"
                    lineStream >> token;
                    // Coord double value
                    double coord;
                    // Convert coord string to double
                    // X Coord
                    lineStream >> token;
                    coord = stod(token);
                    // Min
                    if(coord < Xmin) {
                        Xmin = coord;
                    }
                    // Max
                    if(coord > Xmax) {
                        Xmax = coord;
                    }
                    // Y Coord
                    lineStream >> token;
                    coord = stod(token);
                    // Min
                    if(coord < Ymin) {
                        Ymin = coord;
                    }
                    // Max
                    if(coord > Ymax) {
                        Ymax = coord;
                    }
                    // Z Coord
                    lineStream >> token;
                    coord = stod(token);
                    // Min
                    if(coord < Zmin) {
                        Zmin = coord;
                    }
                    // Max
                    if(coord > Zmax) {
                        Zmax = coord;
                    }
                    // End facet header
                    do {
                        getline(inputfile, line);
                        istringstream lineStream(line);
                        lineStream >> token;
                        if(token.compare("vertex")) {
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
                    } while(line.compare("endloop")); // Endloop
                } while(line.compare("endfacet")); // Endfacet
                // Iterate facet counter
                numFacet++;
            }
        } while (token.compare("endsolid"));
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
