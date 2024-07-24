//用new在堆上申请自定义类型的对象

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Point{
public:
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout << "Point()" << endl;
    }

    //有参构造
    Point(int x, int y = 0) 
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int x, int y)" << " ("<< _ix << "," << _iy << ")" << endl;
    }

    //拷贝构造
    Point(const Point & rhs)
    :_ix(rhs._ix) 
    ,_iy(rhs._iy) 
    {
        cout << "Point(const Point & pt)" << endl;
    }

    //赋值运算符函数
    Point& operator=(const Point & rhs)
    {
        cout << "Point& operator=(const Point & pt)" << endl;
        _ix = rhs._ix;
        _iy = rhs._iy;
        return *this;
    }

    //析构函数
    ~Point(){
        cout << "~Point()" << endl;
    }

    void print() const{
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};

void test(){
    //在堆上创建无参构造的Point对象
    Point* p1 = new Point();
    p1->print();
    delete p1; //释放内存

    //在堆上创建有参构造的Point对象
    Point* p2 = new Point(3,4);
    p2->print();
    delete p2; //释放内存

    //在堆上创建单参数的Point对象:缺省参数,另一个参数用默认值
    Point* p3 = new Point(5);
    p3->print();
    delete p3; //释放内存
    cout << endl;

    //拷贝构造
    Point pt;
    pt.print();
    Point* p4 = new Point(pt);
    p4->print();
}

int main()
{
    test();
    return 0;
}
