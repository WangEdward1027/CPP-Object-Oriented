//友元的第三种形式 —— 友元类:将某个类声明为本类的友元类
//则那个类的所有成员函数都可以访问本类的私有成员

#include <math.h>
#include <iostream> 
using std::cout;
using std::endl;

class Point
{
public:
    Point(int x, int y = 0) //默认参数
    :_ix(x)
    ,_iy(y)
    {}

    void print(){
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
 
    //声明为友元类 :    //将Line类声明为Point的友元类，那么Line中所有的成员函数都可以访问Point的私有成员
    friend class Line;

private:
    int _ix = 10;
    int _iy = 10;
};

class Line{
public:
    float distance(const Point & lhs, const Point & rhs){
        return sqrt(pow((rhs._ix - lhs._ix),2) + pow( rhs._iy - lhs._iy,2));
    }
    
    void setX(Point & rhs, int x){
        rhs._ix = x;
    }
};

void test(){
    Point pt(0,0);
    pt.print();
    Point pt2(3,4);
    Line line;
    cout << line.distance(pt, pt2) << endl;

    line.setX(pt,5);
    pt.print();
}

int main()
{
    test();         
    return 0;
}
