using namespace std;

class Dog {
    public:
    Dog(int age, int namelength, char * name);
    // has to be dog object, not reference
    static Dog Dog::puppy(int namelength, char *name);
    Dog(const Dog& from);
    ~Dog();
    Dog& operator=(const Dog& rhs);
    char operator[](int index) const;
    char& operator[](int index);
    friend ostream& operator<<(ostream& os, const Dog& d);
    private:
    int age;
    int namelength;
    char * name;
};