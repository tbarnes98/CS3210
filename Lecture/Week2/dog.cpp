#include <iostream>
#include "dog.h"
using namespace std;

Dog::Dog(int age, int namelength, char * name) {
    this->age = age;
    this->namelength = namelength;
    this->name = new char[namelength];
    for(int i = 0; i < namelength; i++){
        this->name[i] = name[i];
    }
}

Dog::~Dog(){
    if(this->namelength > 0){
        delete[] this->name;
    }
}

Dog::Dog(const Dog& from){
    this->age = from.age;
    this->namelength = from.namelength;
    this->name = new char[this->namelength];
    for(int i = 0; i< this->namelength; i++){
        this->name[i] = from.name[i];
    }
}