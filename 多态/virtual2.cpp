#include <iostream>
using std::cout;
using std::endl;

class Animal
{
public: 
    virtual void makeSound() const {
        cout << "Animal makes a sound." << endl;
    }
};

class Dog :public Animal
{
public:
    virtual void makeSound() const override{
        cout << "Dog barks." << endl;
    }
};

class Cat :public Animal
{
public:
    virtual void makeSound() const override{
        cout << "Cat meows." << endl;
    }
};

int main()
{
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    animal1->makeSound();
    animal2->makeSound();

    return 0;
}
