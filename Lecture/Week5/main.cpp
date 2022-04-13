#include <iostream>
#include <deque>
using namespace std;
class Pet{
    public:
        string name;
        void set_data(int data){}
};

class Cat: public Pet{
    public:
        int fish;
        void set_data(int data){fish = data;}
    private:
        Cat operator+(const Cat& rhs) const{

        }
};

class Bird: public Pet{
    public:
        int seed;
        void set_data(int data){seed = data;}

};

template<typename T>
T doubler(T in){
    T result;
    result = in + in;
    return result;
}

int main(){
    // Pet* C1 = new Cat;
    // Pet* C2 = new Cat;
    // C1->name = "Cat1";
    // C1->set_data(1);
    // int result = doubler(3);
    // cout << "result: " << result << endl;
    deque<double> Q;
    cout << "size :" << Q.size() << endl;

    return 0;
}