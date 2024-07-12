//电脑类
//数据成员有char*指针类型,需要new[strlen()+1](),再strcpy
//此时不能再采用默认的析构函数，要自定义析构函数释放数据成员申请的堆空间
//析构函数要安全回收(指针置空)

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

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

void test(){
    Computer pc("apple", 20000);
    pc.print();
    cout << endl;

    Computer pc2("ASUS", 8000);
    cout << endl;

    Computer pc3 = pc;
    cout << endl;
    
    pc3 = pc2;
    cout << endl;
}

int main()
{
    test();
    return 0;
}
