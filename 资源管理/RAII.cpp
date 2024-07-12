//使用类模板模拟RAII的思想,管理Point类资源
//Point类没有申请堆空间

#include <iostream>
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

int main(void){
    /* test0(); */
    test1();
    return 0;
}
