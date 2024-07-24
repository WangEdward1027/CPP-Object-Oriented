//虚析构函数
//如果派生类中有指针数据成员申请了堆空间,则基类的析构函数必须设为虚函数
//否则delete基类指针,无法调用派生类的析构函数,造成内存泄露

#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base()
    : _base(new int(6))
    { 
        cout << "Base()" << endl; 
    }

    virtual void display() const
    {
        cout << "*_base = " << *_base << endl << endl;;
    }

    /* ~Base() */
    virtual ~Base()
    {
        if(_base){
            delete _base;
            _base = nullptr;
        }
        cout << "~Base()" << endl;
    }
private:
    int * _base;
};

class Derived
: public Base
{
public:
    Derived()
    : Base() //创建派生类对象前,必须先创建基类子对象
    , _derived(new int(666))
    {
        cout << "Derived()" << endl;
    }

    virtual void display() const override
    {
        cout << "*_derived = " << *_derived << endl << endl;;
    }

    ~Derived()
    {
        if(_derived){
            delete _derived;
            _derived = nullptr;
        }
        cout << "~Derived()" << endl;
    }
private:
    int* _derived;
};

void test(){
    //基类中,一个int*,一个虚函数指针 = 16
    //派生类中,继承了基类的16，再新增一个int*  = 24
    cout << "sizeof(Base) = " << sizeof(Base) << endl;
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl << endl;

    //创建基类对象,并用基类指针指向基类的对象
    Base* pb = new Base();
    pb->display();
    delete pb;
    
    //创建派生类对象,并用基类指针指向派生类对象 
    Base * pbase = new Derived();//创建派生类对象,基类指针指向派生类对象
    pbase->display();            //基类指针调用虚函数,调用的是派生类重写的虚函数

    //
    delete pbase;
}

int main(void){
    test();
    return 0;
}
