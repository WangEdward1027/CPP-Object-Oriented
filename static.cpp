//const成员函数里,可以修改static修饰的数据成员

#include <iostream>
using std::cout;

class A
{
public:
    void printNum() const{ //const 成员函数"不修改对象状态"
        _a = 30;
        cout << "_a = " << _a << "\n";
    }

private:
    /* int _a = 10; */
    static int _a;
};

int A::_a = 20;  //静态数据成员,在类外进行初始化

int main()
{
    A a;
    a.printNum();
    return 0;
}
