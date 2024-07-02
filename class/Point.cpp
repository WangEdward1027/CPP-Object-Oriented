//Point类
//C++可以用小括号进行赋值

#include <iostream> 
using std::cout;
using std::endl;

class Point
{
public:
    //explicit  //禁止隐式转换
    Point(int x = 0, int y = 0) //默认参数
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }

    ~Point(){
        cout << "~Point()" << endl;
    }

    Point(const Point & rhs)
    :_ix(rhs._ix)
    ,_iy(rhs._iy)
    {
        cout << "Point(const Point &)" << endl;
    }

    void print() const{
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
private:
    int _ix = 10;
    int _iy = 10;
};

void test(){
    int x = 1;
    int y = x;  
    int z(x);   //C++除了可以用=进行赋值,还可以用()进行赋值
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
}

void test1(){
    Point pt(3,4);
    pt.print();
    
    Point pt2 = pt;
    pt2.print();

    Point pt3(pt);
    pt3.print();

    Point pt4(2);
    pt4.print();

    pt = {1,2}; //隐式转换
    pt.print();

    pt2 = 7;    //隐式转换
    pt2.print();
}


int main()
{
    /* test(); */         
    test1();
    return 0;
}
