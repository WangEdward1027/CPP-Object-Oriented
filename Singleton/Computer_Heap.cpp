//在堆区创建Computer类的单例对象
//仿照Singleton_Point_Heap.cpp，照葫芦画瓢。
//单例对象的数据成员申请堆空间。要妥善处理char * _brand。

#include <string.h>
#include <iostream> 
using std::cout;
using std::endl;

class Computer
{
public:
    static Computer * getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Computer("ASUS", 8000);
        }
        return _pInstance;
    }

    void init(const char * brand, int price){
        strcpy(_brand, brand);
        _price = price;
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr; //安全回收
            cout << "delete heap" << endl;
        }
    }

    void print() const{
        cout << "brand:" << _brand << endl;
        cout << "price:" << _price << endl;
    }

private:
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

    Computer(const Computer & rhs) = delete;
    Computer & operator=(const Computer & rhs) = delete;

private:
    char * _brand;
    double _price;
    static Computer * _pInstance;
};
Computer * Computer::_pInstance = nullptr;

void test(){
    /* Computer pc("apple", 20000); */ //不能调用私有的构造函数
    /* pc.print(); */
    Computer * pc1 = Computer::getInstance();
    Computer * pc2 = Computer::getInstance();
    cout << pc1 << endl;
    cout << pc2 << endl;    //地址相同,证明是单例
    
    pc1->print();
    pc2->print();
    
    pc1->init("apple", 20000);
    pc1->print();

    pc2->init("HuaWei", 210000);
    pc2->print();
    
    pc1->destroy();
    pc2->destroy();

}

int main()
{
    test();   
    return 0;
}
