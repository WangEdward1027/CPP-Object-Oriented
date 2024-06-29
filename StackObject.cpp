//要求: 只能创建栈对象,不能创建堆对象的Computer类
//公有的构造函数和析构函数,私有的 operator new 和 operator delete 函数

#include <string.h>
#include <error.h>
#include <errno.h>
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
        cout << "Computer(const char * brand, double price)" << endl;
    }

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
    void * operator new(size_t size){
        cout << "operator new" << endl;
        void * ptr = malloc(size);
        if(ptr == nullptr)  error(1, 0, "operator new malloc");
        return ptr;
    }

    void operator delete(void * pointer){
        cout << "operator delete" << endl;
        free(pointer);
    }

private:
    char * _brand;
    double _price;
};

void test(){
    //创建栈对象
    Computer pc("apple", 20000);
    pc.print();

    //创建堆对象
    //Computer * p = new Computer("ASUS", 18000); //失败,operator new is private

}

int main()
{
    test();   
    return 0;
}
