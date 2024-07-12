//使用类模板模拟RAII的思想,管理Point类资源
//使用类模板模拟RAII的思想,管理Computer类资源

#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Point
{
public:
    Point(int x,int y)
    : _ix(x)
    , _iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    void print(){
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;
    }
private:
    int _ix;
    int _iy;
};

//电脑类
class Computer
{
public:
    //有参构造函数
    Computer(const char * brand, double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        cout << "有参构造" << endl;
        strcpy(_brand, brand);
    }
    
    //拷贝构造函数
    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        cout << "Computer(const Computer &)" << endl;
        strcpy(_brand,rhs._brand);
    }

    //赋值运算符函数 (类中有指针成员动态申请堆空间的情况)
    Computer & operator= (const Computer & rhs){
	    cout << "赋值运算符函数" << endl;
	    if(this != &rhs){	    //1.判断是否是自复制
		    delete [] _brand;   //2.回收左操作数的数据成员原本管理的堆空间
		    _brand = new char[strlen(rhs._brand) + 1]();  //3.深拷贝
		    strcpy(_brand, rhs._brand);
		    _price = rhs._price;   //以及其他的数据成员完成简单赋值
	    }
	    return *this;   //4.返回本对象
    }

    //析构函数
    ~Computer(){
        cout << "~Computer()" << endl;
        if(_brand){
            delete [] _brand;
            _brand = nullptr; //安全回收
        }
    }

    void print() const{
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
private:
    char * _brand;
    double _price;
};

//类模板
template <class T>
class RAII
{
public:
    RAII(T * data)
    : _data(data)
    {
        cout << "RAII(T*)" << endl; 
    }

    ~RAII(){
        cout << "~RAII()" << endl;
        if(_data){
            delete _data;
            _data = nullptr;
        }
    }

    T * operator->(){
        return _data;
    }

    T & operator*(){
        return *_data;
    }

    //获取底层的指针
    T * get() const{
        return _data;
    }

    //重新管理一片资源
    void reset(T * data){
        if(_data){
            delete _data;
            _data = nullptr;
        }
        _data = data;
    }

    RAII(const RAII & rhs) = delete;
    RAII & operator=(const RAII & rhs) = delete;
private:
    T * _data;
    //int * _data;
    //char * _data;
    //Point * _data;
};

void test0(){
    int * p = new int(10);
    RAII<int> raii(p);
    /* RAII<int> raii(new int(10)); */

    cout << p << endl;
    cout << raii.get() << endl;
    cout << *raii << endl;
    cout << raii.operator*() << endl;
    /* delete p; */
}

void test1(){
    RAII<Point> raii(new Point(1,2));
    raii->print();
    (*raii).print();
    cout << raii.get() << endl;
    raii.reset(new Point(10,9));
    raii->print();
}

void test2(){
    RAII<Computer> raii(new Computer("ASUS", 8000));
    raii->print();
    cout << raii.get() << endl;
    cout << endl;

    raii.reset(new Computer("Apple", 20000));
    (*raii).print();
}

int main(void){
    /* test0(); */
    /* test1(); */
    test2();
    return 0;
}
