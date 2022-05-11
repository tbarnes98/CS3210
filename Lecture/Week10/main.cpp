#include <iostream>
using namespace std;

class Row{
    public:
        int size = 0;
        double * data;

        Row(int size){
            cout << "constructor" << endl;
            this->size = size;
            data = new double[size];
            // call clear
        }

        // copy constructor
        Row(const Row& from){
            this->size = from.size;
            data = new double[size];
            for(int i = 0; i < size; i++){
                this->data[i] = from.data[i];
            }
        }

        // assignment operator (non-move)
        Row operator=(const Row& rhs){
            if(this != &rhs){
                delete[] data;
                this->size = rhs.size;
                data = new double[size];
                for(int i = 0; i < size; i++){
                    this->data[i] = rhs.data[i];
                }
            }
            return *this;
        }

        ~Row(){
            delete[] data;
        }
        
};

int main(){

    Row R1(2);
    Row R2(R1);
    return 0;
}