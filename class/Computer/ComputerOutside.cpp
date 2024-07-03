//电脑类
//成员函数:在类内声明(并加注释解释作用)，在类外实现

#include <string.h>
#include <iostream> 
using std::cout;
using std::endl;

class Computer
{
public:
    //设置品牌
    void setBrand(const char * brand);
    
    //设置价格
    void setPrice(double price);
    
    //打印信息
    void print();

private:
    char _brand[20];
    double _price;
};

void Computer::setBrand(const char * brand){
    strcpy(_brand, brand);
}   

void Computer::setPrice(double price){
    _price = price;
}

void Computer::print(){
    cout << "brand:" << _brand << endl;
    cout << "price:" << _price << endl;
}

void test(){
    cout << "sizeof(Computer):" << sizeof(Computer) << endl;
    Computer pc;
    pc.setBrand("ASUS");
    pc.setPrice(20000);
    pc.print();
}

int main()
{
    test();
    return 0;
}
