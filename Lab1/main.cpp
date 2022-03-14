#include "ReadSTL.cpp"
using namespace std;

int main(int argc, char** argv) {
    
    ReadSTL stl1(argv[1]);
    cout << "Facets in file:" << stl1.getNumFacets() << endl;
    cout << "X Min: " << stl1.getXmin() << endl;
    cout << "X Max: " << stl1.getXmax() << endl;

    cout << "Y Min: " << stl1.getYmin() << endl;
    cout << "Y Max: " << stl1.getYmax() << endl;

    cout << "Z Min: " << stl1.getZmin() << endl;
    cout << "Z Max: " << stl1.getZmax() << endl;

    return 0;
}