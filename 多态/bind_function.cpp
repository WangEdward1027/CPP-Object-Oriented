//bind + function ： 实现静态多态

#include <math.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;
using std::function;

//面向对象的方式 :继承 + 虚函数(纯虚函数)，可以体现多态，动态多态
//基于对象的方式: std::bind + std::function，也可以实现多态，静态多态

class Figure
{
public:
    using DisplayCallback = function<void()>;
    using AreaCallback = function<double()>;

    DisplayCallback _displayCallback;
    AreaCallback _areaCallback;
    
#if 0
    //用构造函数的初始化列表进行初始化.或用下文的set函数进行赋值
    Figure(DisplayCallback &&cb1, AreaCallback &&cb2)
    : _displayCallback(std::move(cb1))
    , _areaCallback(std::move(cb2))
    {
    
    }
#endif

    //const & : 既可以接右值,也可以接左值
    /* void setDisplayCallback(const DisplayCallback & cb){} */     
    
    //cb是右值引用,可以接收/绑定/识别右值,但是本身在此处是一个左值
    //赋值:也可以用构造函数的初始化列表 进行初始化
    void setDisplayCallback(DisplayCallback && cb){
        /* &cb; //可以取地址,cb是左值 */
        _displayCallback = std::move(cb);
    }

    void setAreaCallback(AreaCallback && cb){
        _areaCallback = std::move(cb); //回调函数的注册
    }
 
    //调用
    void handleDisplayCallback() const{
        if(_displayCallback){
            _displayCallback(); //回调函数的执行
        }
    }

    double handleAreaCallback() const{
        if(_areaCallback){
            return _areaCallback();
        }else{
            return 0.0;
        }
    }

    /* //纯虚函数 */
    /* virtual void display() const = 0; */
    /* virtual double area() const = 0; */
};

class Rectangle
{
public:
    Rectangle(double length = 0, double width = 0)
    : _length(length)
    , _width(width)
    {
        cout << "Rectangle(double = 0, double = 0)" << endl;
    }

    void display(int x) const 
    {
        cout << "x = " << x << endl;
        cout << "Rectangle";
    }

    double area() const 
    {
        return _length * _width;
    }

    ~Rectangle()
    {
        cout << "~Rectangle()" << endl;
    }
private:
    double _length;
    double _width;
};

class Circle
{
public:
    Circle(double radius = 0)
    : _radius(radius)
    {
        cout << "Circle(double = 0)" << endl;
    }

    void print() const 
    {
        cout << "Circle";
    }

    double printArea() const 
    {
        return 3.14 * _radius *_radius;;
    }

    ~Circle()
    {
        cout << "~Circle()" << endl;
    }

private:
    double _radius;
};

class Triangle
{
public:
    Triangle(double a = 0, double b = 0, double c = 0)
    : _a(a)
    , _b(b)
    , _c(c)
    {
        cout << "Triangle(double = 0, double = 0, double = 0)" << endl;
    }

    void show() const 
    {
        cout << "Triangle";
    }

    double showArea() const 
    {
        //海伦公式
        double tmp = (_a + _b + _c)/2;

        return sqrt(tmp * (tmp - _a) * (tmp - _b) * (tmp - _c));
    }

    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
private:
    double _a;
    double _b;
    double _c;
};

void func(const Figure &fig)
{
    fig.handleDisplayCallback();
    cout << "的面积 : " << fig.handleAreaCallback() << endl;
}

int main()
{
    Rectangle rectangle(10, 20);
    Circle circle(10);
    Triangle triangle(3, 4, 5);
    cout << endl;
    
    Figure fig;

    /* function<void()> f = bind(&Rectangle::display, &rectangle, 100); */
    /* fig.setDisplayCallback(std::move(f)); */
    fig.setDisplayCallback(bind(&Rectangle::display, &rectangle, 100));
    fig.setAreaCallback(bind(&Rectangle::area, &rectangle));
    func(fig);
    
    fig.setDisplayCallback(bind(&Circle::print, &circle));
    fig.setAreaCallback(bind(&Circle::printArea, &circle));
    func(fig);
    
    fig.setDisplayCallback(bind(&Triangle::show, &triangle));
    fig.setAreaCallback(bind(&Triangle::showArea, &triangle));
    func(fig);
    cout << endl;

    /* func(fig); */

    /* func(rectangle); */
    /* func(circle); */
    /* func(triangle); */

    return 0;
}
