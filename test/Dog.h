#include<iostream>

class Dog
{
private:
    int age;
public:
    Dog(/* args */);
    Dog(int age);
    ~Dog();

    void bark();
};

Dog::Dog(/* args */)
{
}

Dog::Dog(int age)
{
    this->age = age;
}

Dog::~Dog()
{
}

void Dog::bark()
{
    std::cout << "wof" << std::endl;
}
