//类模板、类模板的特化

#include <iostream> 
#include <string>
using std::cout;
using std::endl;
using std::string;

//通用的类模板
template<typename T>
class Box
{
public:
    Box(T value = 65)
    :_value(value)
    {}

    T getValue() const{
        return _value;   
    }
private:
    T _value;
};


class Point
{
public:
    Point(int x = 0, int y =0)
    : _ix(x)
    , _iy(y)
    {

    }

    void print() const{
        cout << "(" <<_ix << "," << _iy << ")" << endl;
    }

private:
    int _ix;
    int _iy;
};


//类模板的特化:string类型
template<>
class Box<string>
{
public:
    Box(string value = "hello")
    :_value(value)
    {}

    string getValue() const{
        return _value;   
    }
private:
    string _value;
};


void test(){
    Box<float> b1;
    cout << b1.getValue() << endl;

    Box<char> b2;
    cout << b2.getValue() << endl;
    
    Box<Point> b3;
    b3.getValue().print(); 

    //string插不了Box,需要类模板的特化
    Box<string> b4;
    cout << b4.getValue() << endl;
}

int main()
{
    test();   
    return 0;
}
