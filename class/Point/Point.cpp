//Point类
//C++可以用小括号进行赋值

#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

class Point{
public:
    //无参构造
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout << "Point()" << endl;
    }

    //有参构造
    //explicit //禁止隐式转换
    Point(int x, int y = 0) //默认参数
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int x, int y)" << " ("<< _ix << "," << _iy << ")" << endl;
    }

    //拷贝构造
    Point(const Point & rhs)
    :_ix(rhs._ix) //只有构造函数才有初始化列表
    ,_iy(rhs._iy) //无参构造、有参构造、拷贝构造
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
    Point pt1;
    pt1.print();

    Point pt2(3,4);
    pt2.print();

    Point pt3 = pt2;
    pt3.print();

    pt2 = pt1;
    pt2.print();
}

void test2(){
    Point pt1 = {5,6}; //隐式转换。有参构造,右边当作初始化列表,右边不调用构造函数
    pt1.print();

    Point pt2 = 7;
    pt2.print();

    pt1 = 9;     //隐式转换。赋值运算符函数.右边调用有参构造函数,生成一个临时匿名对象
    pt1.print(); //赋值完成,该临时匿名对象直接析构销毁。
}

int main()
{
    /* test(); */      
    test2();      
    return 0;
}
