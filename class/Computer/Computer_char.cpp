//手撕电脑类
//数据成员有char*指针类型,需要new[strlen()+1](),再strcpy
//此时不能再采用默认的析构函数，要自定义析构函数释放数据成员申请的堆空间
//析构函数要安全回收(指针置空)

#include <iostream> 
#include <string.h>
using std::cout;
using std::endl;

class Computer{
public:
    //无参构造
    Computer()
    : _brand(new char[1]())
    {
        cout << "Computer()" << endl;
    }    

    //有参构造
    Computer(const char * brand, double price)
    : _brand(new char[strlen(brand)+1]())
    , _price(price)
    {
        strcpy(_brand,brand);
        cout << "Computer(char * brand, double price)" << endl;
    }

    //拷贝构造
    Computer(const Computer & rhs)
    : _brand(new char[strlen(rhs._brand) + 1]())
    , _price(rhs._price)
    {
        cout << "Computer(const Computer & rhs)" << endl;
        strcpy(_brand,rhs._brand);
    }

    //赋值运算符函数
    Computer & operator=(const Computer & rhs){
        cout << "operator=(const Computer & rhs)" << endl;
        if(this != &rhs){   //1.判断是否是自复制
            delete [] _brand;  //2.回收左操作数的数据成员原本管理的堆空间
            _brand = new char[strlen(rhs._brand) + 1](); //3.深拷贝
            strcpy(_brand,rhs._brand);
            _price = rhs._price;
        }
        return *this; //4.返回本对象
    }

    //析构函数
    ~Computer(){
        if(_brand){ //先判空:避免手动调用~Computer造成double free
            cout << "~Computer()" << endl;
            delete [] _brand;
            _brand = nullptr; //安全回收,悬空指针置空
        }
    }

    void print(){
        cout << "brand: " << _brand << endl;
        cout << "price: " << _price << endl;
    }

private:
    char * _brand;
    double _price = 5000;
};

//栈对象
void test(){
    Computer pc;
    pc.print();   
    cout << endl;

    Computer pc2("ASUS", 8000); 
    pc2.print(); 
    cout << endl;

    Computer pc3("Apple", 20000);
    pc3.print();
    cout << endl;

    Computer pc4 = pc3;
    pc4.print();
    cout << endl;

    pc4 = pc2;
    pc4.print();
    
    //仅为了演示错误,正常情况下不要手动调用析构函数。
    //为了避免double free,析构函数里要先判空
    pc4.~Computer();
}

//堆对象
void test2(){
    //Computer类的大小为16字节,对象的大小就是所属类的大小
    cout << sizeof(Computer) << endl;

    //申请了堆上的Computer类对象
    Computer* pPC1 = new Computer("HP", 7000);
    pPC1->print();
    //若没有delete,则直接泄露16字节,间接泄露_brand申请的字节数
    delete pPC1;
}

int main()
{
    /* test(); */
    test2();
    return 0;
}
