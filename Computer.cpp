#include <string.h>
#include <iostream> 
using std::cout;
using std::endl;

class Computer
{
public:
    void setBrand(const char * brand){
        strcpy(_brand, brand);
    }   

    void setPrice(double price){
        _price = price;
    }

    void print(){
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }
private:
    char _brand[20];
    double _price;
};

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
