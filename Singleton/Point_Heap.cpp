//单例模式, 在堆上申请空间创建Point类的单例对象

#include <iostream> 
using std::cout;
using std::endl;

class Point
{
public:
    static Point * getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Point(1,2);
        }
        return _pInstance;
    }
    
    void init(int x, int y){
        _ix = x;
        _iy = y;
    }

    //定义为静态成员函数,则不需要创建对象也能通过类名调用
    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr; //安全回收
            cout << " delete heap" << endl;
        }
    }

    void print() const{
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
    Point(int x, int y = 0) //默认参数
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int,int)" << endl;
    }
    
    ~Point(){
        cout << "~Point()" << endl;
    }
 
    //严格禁止复制和赋值:
    //直接从本类中删除拷贝构造函数和赋值运算符函数
    Point(const Point & rhs) = delete;
    Point & operator=(const Point & rhs) = delete;

private:
    int _ix = 10;
    int _iy = 10;
    static Point * _pInstance;
};
Point * Point::_pInstance = nullptr;

void test0(){
    Point * p1 = Point::getInstance();
    Point * p2 = Point::getInstance();
    cout << p1 << endl;
    cout << p2 << endl; //地址一样,说明确实是单例
    p1->print();
    p2->print();
    //delete p1; //析构被私有,无法delete
    p1 = nullptr; //为什么置空了,还能调用destroy()??这不是对空指针解引用了吗？
    //海豹老师补充:自定义类的空指针,可以访问与对象无关的普通函数和静态成员
    p1->destroy();
    p2->destroy();
}

void test1(){
    Point::getInstance()->print();
    Point::getInstance()->init(3,4);
    Point::getInstance()->print();
    Point::getInstance()->init(5,6);
    Point::getInstance()->print();
    Point::destroy();
    Point::destroy();
    Point::destroy();
    Point::getInstance()->print();
    Point::destroy();
}

int main()
{
    /* test0(); */         
    test1();
    return 0;
}
