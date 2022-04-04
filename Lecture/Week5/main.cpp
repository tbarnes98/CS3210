#include <iostream>
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
};

class Bird: public Pet{
    public:
        int seed;
        void set_data(int data){seed = data;}

};

int main(){
    Pet* C1 = new Cat;
    Pet* C2 = new Cat;
    C1->name = "Cat1";
    C1->set_data(1);

}