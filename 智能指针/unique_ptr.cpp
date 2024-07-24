//独享指针：unique_ptr

#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

class Point
{
public:
    Point(int x, int y)
    : _ix(x)
    , _iy(y)
    {
        /* cout << "Point(int,int)" << endl; */
    }

    void print(){
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }

private:
   int  _ix;
   int  _iy;
};

void test(){
    unique_ptr<Point> up(new Point(1,2));
    unique_ptr<Point> up2(new Point(3,4));
    unique_ptr<Point> up3(new Point(5,6));
    
    vector<unique_ptr<Point>> vec;

    //unique_ptr作为容器元素,必须以右值的形式加入
    //使用移动构造创建出新的unique_ptr对象作为容器元素
    //移交了原本管理的资源管理权
    //vec.push_back(up); //error
    vec.push_back(unique_ptr<Point>(new Point(7,8)));
    vec[0]->print();

    vec.push_back(std::move(up));
    vec.push_back(std::move(up2));
    vec.push_back(std::move(up3));
    vec[1]->print();
    vec[2]->print();
    vec[3]->print();
}

int main(void){
    test();
}
