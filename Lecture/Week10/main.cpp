#include <iostream>
using namespace std;

class Row{
    public:
        int size = 0;
        double * data;

        // constructor
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

        // move copy constructor
        Row(Row&& from){
            cout << "move copy constructor" << endl;
            this->size = from.size;
            this->data = from.data;
            from.data = nullptr;
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


        Row& operator=(Row&& from){
            cout << "assignment operator" << endl;
            if(this != &from){
                delete[] data;
                //this-size = from.size; // gives error
                this->data = from.data;
                from.data = nullptr;
            }
            return *this;
        }

        ~Row(){
            delete[] data;
        }
        
};


void swap(Row& R1, Row& R2){
    Row temp = move(R1);
    R1 = std::move(R2);
    R2 = std::move(temp);
}

int main(){

    Row R1(2);
    Row R2(3);
    swap(R1,R2);
    return 0;
}