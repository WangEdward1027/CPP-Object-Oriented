//2.开放闭合原则：对扩展开放,对修改关闭

//代码风格:
//函数和类,左大括号{单独占一行
//函数内部的if、else、while的大括号,不会单独占行

#include <iostream> 
using std::cout;
using std::endl;

//1.所有功能做到一个类中
class Calculator0
{
public:
    int plus(int x, int y)
    {
        return x + y;
    }

    int minus(int x, int y)
    {
        return x - y;
    }

    int multiply(int x, int y)
    {
        return x * y;
    }

    int divide(int x, int y)
    {
        if(0 != y){
            return x/y;
        }else{
            cout << "除数不能为0" << endl;
            return 1 << 31;
        }
    }

    //若要添加新功能,则必须修改Calculator0类。
    //即要改动源代码,向其中添加新的成员函数。
    //若是一个庞大的继承体系,改动基类可能会出现意想不到的问题。
};

void test0()
{
    Calculator0 cal;
    cout << cal.plus(10,20) << endl;     //10+20
    cout << cal.minus(10,20) << endl;    //10-20
    cout << cal.multiply(10,20) << endl; //10*20
    cout << cal.divide(10,5) << endl;   //10/5
}


//2.遵循开闭原则
//版本升级，不改源代码，原来的功能就是可以使用的。
//计算器代码的实现：分别设计加减乘除，不如直接使用继承，实现虚方法。
class Calculator
{
public:
    virtual int getResult(int x, int y) = 0;
    virtual ~Calculator() {}
};

class PlusCalculator
: public Calculator
{
public:
    virtual int getResult(int x, int y)
    {
        return x + y;
    }

    ~PlusCalculator(){}
};

class MinusCalculator
: public Calculator
{
public:
    virtual int getResult(int x, int y)
    {
        return x - y;
    }
    ~MinusCalculator(){}
};

class MultiplyCalculator
: public Calculator
{
public:
    virtual int getResult(int x, int y)
    {
        return x * y;
    }

    ~MultiplyCalculator(){}
};

class DivideCalculator
: public Calculator
{
public:
    virtual int getResult(int x, int y)
    {
        if(0 != y){
            return x/y;
        }else{
            cout << "除数不能为0" << endl;
            return 1 << 31;
        }
    }
 
    ~DivideCalculator(){}
};

//新增一个求模的功能:只需要新增代码,而不需要对老代码进行改动
//即对扩展开放,对修改关闭
class ModulusCalculator : public Calculator
{
public:
    virtual int getResult(int x, int y)
    {
        if(0 != y){
            return x % y;
        }else{
            cout << "除数不能为0" << endl;
            return 1 << 31;
        }
    }

    ~ModulusCalculator(){}
};

void test()
{
    //基类的指针
    Calculator* cal;
    
    //指向派生类的对象
    cal = new PlusCalculator();
    cout << "10 + 20 = " << cal->getResult(10, 20) << endl;
    delete cal; //用完后及时释放

    cal = new MinusCalculator();
    cout << "10 - 20 = " << cal->getResult(10, 20) << endl;
    delete cal;

    cal = new MultiplyCalculator();
    cout << "10 * 20 = " << cal->getResult(10, 20) << endl;
    delete cal;

    cal = new DivideCalculator();
    cout << "10 / 5 = " << cal->getResult(10, 5) << endl;
    cout << "10 / 0 = " << cal->getResult(10, 0) << endl;
    delete cal;

    //新增的求模功能的测试代码
    cal = new ModulusCalculator();
    cout << "10 % 3 = " << cal->getResult(10, 3) << endl;
    delete cal;
}

int main()
{
    test0();   
    test();   
    return 0;
}
