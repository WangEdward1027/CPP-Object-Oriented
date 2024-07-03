//要求只能创建堆对象,不能创建栈对象:
//将构造函数设为私有

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
        cout << "Computer(const char * brand, double price)"  << endl;
    }
    
    void print() const{
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

    void destroy(){
        delete this;
    }

private:
    ~Computer(){
        cout << "~Computer()" << endl;
        if(_brand){
            delete [] _brand;
            _brand = nullptr; //安全回收
        }
    }

private:
    char * _brand;
    double _price;
};

void test(){
    //创建栈对象失败,因为析构函数是私有的
    //Computer pc("apple", 20000);
    //pc.print();
    
    //创建堆对象
    Computer * pc  = new Computer("ASUS", 8000);
    pc->print();
    pc->destroy();
    pc = nullptr; //安全回收
}

int main()
{
    test();   
    return 0;
}
