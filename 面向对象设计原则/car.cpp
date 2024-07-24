//未使用组合复用原则
//不太好的设计:让每一个驾驶者去继承他的车

#include <iostream> 
using std::cout;
using std::endl;

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

class PersonA
: public Tesla
{

};

class PersonB
: public BMW
{

};

class PersonC
: public Benz
{

};

void test()
{
    PersonA pa;
    pa.run();
    PersonB pb;
    pb.run();
    PersonC pc;
    pc.run();
}

int main()
{
    test();
    return 0;
}
