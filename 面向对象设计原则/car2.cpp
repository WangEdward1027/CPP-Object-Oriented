//组合复用原则:车辆类、人类为两个基类
//单向关联:Person类中拥有Vehicle类的指针作为数据成员。
//Person类的派生类对象可以与Vehicle类的派生类对象任意组合

#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

class Vehicle
{
public:
    virtual void run() = 0;
    virtual ~Vehicle() {}
};

class Tesla
: public Vehicle
{
public:
    void run() override
    {
        cout << "Tesla Model X start..." << endl;
    }
};

class BMW
: public Vehicle
{
public:
    void run() override
    {
        cout << "BMW X5 start..." << endl;
    }
};

class Benz
: public Vehicle
{
public:
    void run() override
    {
        cout << "Benz S-class start..." << endl;
    }
};

//Person类中持有一个Vehicle的指针，并通过成员函数进行动态设置。
//这种设计方式增强了灵活性，Person类可以与不同的Vehicle实例进行组合，减少了类之间的耦合
class Person
{
public:
    void getVehicle(Vehicle* vehicle)
    {
        _vehicle = vehicle;
    }

    void drive()
    {
        _vehicle->run();
    }
private:
    Vehicle *_vehicle;
};

void test()
{
    Person person;
    unique_ptr<Vehicle> ModelX(new Tesla());
    unique_ptr<Vehicle> X5(new BMW());
    unique_ptr<Vehicle> S(new Benz());

    person.getVehicle(ModelX.get());
    person.drive();

    person.getVehicle(X5.get());
    person.drive();

    person.getVehicle(S.get());
    person.drive();
}

int main()
{
    test();
    return 0;
}
