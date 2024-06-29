//在静态区创建单例对象

#include <iostream> 
using std::cout;
using std::endl;

class Point
{
public:
    //当静态函数多次被调用,静态的局部对象只会被初始化一次
    //第一次调用getInstance(),静态对象会被初始化为一个对象实例
    //在后续的调用中,静态局部对象已经存在,不会再初始化
    //而是直接返回已经初始化的对象实例
    static Point & getInstance(){
        static Point pt(1,2);
        return pt;
    }
  
    ~Point(){
        cout << "~Point()" << endl;
    }

    Point & operator=(const Point & rhs){
        _ix = rhs._ix;
        _iy = rhs._iy;
        return *this;
    }

    //const成员函数:
    //this 指针原本是 Point * const this
    //const成员函数的this指针变成了const Point * const this
    void print () const {
        //_ix = 100;  //改为const成员函数后,无法在其内部修改数据成员的值
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    //1.为了只能创建一个对象,将构造函数和拷贝构造函数私有化
    Point(int x, int y = 0) //默认参数
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    Point(const Point & rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

private:
    int _ix = 10;
    int _iy = 10;
};

void test1(){
    Point & pt1 = Point::getInstance();
    Point & pt2 = Point::getInstance();
    cout << &pt1 << endl;
    cout << &pt2 << endl;
}

int main()
{
    test1();         
    return 0;
}
