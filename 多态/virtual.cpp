//虚函数与多态

#include <iostream>
using std::cout;
using std::endl;

//基类
class Animal
{
public:
    virtual void makeSound() const{
        cout << "Animal makes a sound." << endl;
    }
};

//派生类:Dog
class Dog :public Animal
{
public:
    virtual void makeSound() const override{
        cout << "Dog barks." << endl;
    }
};

//派生类:Cat
class Cat :public Animal
{
public:
    virtual void makeSound() const override{
        cout << "Cat meows." << endl; 
    }
};

int main()
{
    //基类指针指向派生类对象
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    //通过基类指针调用派生类的虚函数
    animal1->makeSound();
    animal2->makeSound();

    return 0;
}
