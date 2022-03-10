#include <iostream>
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
        ifstream inputfile(filename, ifstream::in);
        string line;
        string solidName;
        // Solid header line
        getline(inputfile, line);
        istringstream inputstream(line);
        // Iterate stream past "solid"

        // Retrieve name of solid
        inputstream >> solidName;
        // Process entire solid, looping through each facet
        getline(inputfile, line);
        while(1) {
            // Iterate stream past "facet"
            // Process entire facet,
            
        }
    }

};

int main(int argc, char** argv) {
    ReadSTL RF(argv[1]);

    return 0;
}