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
    Computer(const char * brand, double price)
    : _brand(new char[strlen(brand) + 1]())
    , _price(price)
    {
        strcpy(_brand, brand);
    }

    ~Computer(){
        cout << "~Computer()" << endl;
        if(_brand){
            delete [] _brand;
            _brand = nullptr; //安全回收
        }
    }

    void print(){
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
}

int main()
{
    test();   
    return 0;
}
