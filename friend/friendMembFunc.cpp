//友元的第二种方式：其他类的成员函数 声明为友元函数 (较为繁琐，不推荐)
//1.需要将本类前向声明
//2.然后其他类的成员函数声明
//3.本类的具体实现，并将其他类的成员函数声明为友元函数 (记得加 类名 作用域限定符)
//4.其他类的成员函数的具体实现 (记得加 类名 作用域限定符)

#include <math.h>
#include <iostream> 
using std::cout;
using std::endl;

//类的前向声明
class Point;

class Line{
public:
    float distance(const Point & lhs, const Point & rhs);
    void setX(Point & rhs, int x);
};

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
 
    friend float Line::distance(const Point & lhs, const Point & rhs);
    friend void  Line::setX(Point & rhs, int x);

private:
    int _ix = 10;
    int _iy = 10;
};

float Line::distance(const Point & lhs, const Point & rhs){
    return sqrt(pow((rhs._ix - lhs._ix),2) + pow( rhs._iy - lhs._iy,2));
}

void Line::setX(Point & rhs, int x){
    rhs._ix = x;
}

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
