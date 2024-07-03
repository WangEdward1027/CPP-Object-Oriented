//友元的第一种方式：普通函数声明为友元函数

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
    
    //友元的第一种方式:普通函数声明为类的友元函数
    //则该普通函数可以访问类的私有成员
    friend
    float distance(const Point & lhs, const Point & rhs);

private:
    int _ix = 10;
    int _iy = 10;
};

float distance(const Point & lhs, const Point & rhs){
    return sqrt(pow((rhs._ix - lhs._ix),2) + pow( rhs._iy - lhs._iy,2));
}

void test(){
    Point pt(0,0);
    Point pt2(3,4);
    cout << distance(pt, pt2) << endl;
}

int main()
{
    test();         
    return 0;
}
