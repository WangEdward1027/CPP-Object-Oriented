//基类和派生类的转换:
//直接向上转型(向基类转)都是可以的
//直接向下转型都是不可以的
//合理的向下转型可以通过dynamic_cast实现(如基类指针指向派生类对象)
#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

class Base{
public:
    Base(long x)
    : _base(x)
    {
        cout << "Base()" << endl;
    }
    
    //要使用dynamic_cast, Base类要求是多态的,故加上此虚函数
    virtual void print(){
        cout << "Base::print()" << endl;
    }

private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base,long derived)
    : Base(base)//创建基类子对象
    , _derived(derived)
    {
        cout << "Derived()" << endl;
    }
public:
    long _derived;
};

//直接向上转型(向基类)都是可以的
void test1(){
    Base base(1);
    Derived d1(2,3);

        //底层是base对象调用了Base类的赋值运算符函数
        //base.operator=(d1);
        //形参 const Base & rhs = d1
    base = d1; //ok  //1.派生类对象赋值给基类对象
    /* d1 = base; //error */

    Base * pbase = &d1; //ok //2.基类指针指向派生类对象
    /* Derived * pderived = &base //error */

    Base & rbase = d1; //ok  //3.基类引用绑定派生类对象
    /* Derived & rderived = base; //error */
}

//直接向下转型(向派生类)都会报错
//但是合理的向下转型可以通过dynamic_cast完成
void test2(){
    Base base(1);
    Derived d1(2,3);
    
    //基类指针指向派生类对象,向下转型是合理的,但是不能直接转型，会报错
    Base * pbase = &d1; 
    //Base * pbase = &base; //若基类指针绑定是基类对象,在向下转型,会转换失败,变为空指针
    /* Derived * pderived = pbase; //error,不能直接向下转型 */ 
    //这时,合理的向下转型可以通过dynamic_cast实现
    Derived * pd = dynamic_cast<Derived*>(pbase);
    if(pd != nullptr){
        cout << "转换成功" << endl;
        cout << pd->_derived << endl;
    }else{
        cout << "转换失败" << endl;
    }
}

int main()
{
    test2();   
    return 0;
}
