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

Dog& Dog::operator=(const Dog& rhs){
    if(&rhs != this){
        // delete existing memory
        if(namelength > 0){
            delete[] this->name;
        }
        this->age = rhs.age;
        this->namelength = rhs.namelength;
        this->name = new char[namelength];
        for(int i = 0; i < namelength; i++){
            this->name[i] = rhs.name[i];
        }
    }
    return *this;
}

char Dog::operator[](int index) const{
    if(index >= namelength){
        // Use with try/catch when called in main do exception e.what()
        throw(out_of_range("index is larger than name length"));
    }
    return name[index];
}

char& Dog::operator[](int index){
    if(index >= namelength){
        // Use with try/catch when called in main do exception e.what()
        throw(out_of_range("index is larger than name length"));
    }
    return name[index];
}

Dog Dog::puppy(int namelength, char * name){
    Dog p(0, namelength, name);
    return p;
}

ostream& operator<<(ostream& os, const Dog& d){
    for(int i = 0; i< d.namelength; i++) {
        os << d[i];
    }
    return os;
}