//函数对象：让对象像函数一样被调用，以成员函数形式 重载函数调用运算符()
//优点：与面向对象相关，可以保存状态

#include <iostream> 
using std::cout;
using std::endl;

class FunctionObject{
public:
    void operator() (){
        cout << "void operator() ()" << endl;
        _cnt++;
    }
    
    int operator() (int x){
        cout << "int operator()(int x)" << endl;
        _cnt++;
        return x;
    }

    double operator() (double x, int y){
        cout << "double operator() (double x, int y)" << endl;
        _cnt++;
        return x + y;
    }
    
    int getCount(){
        return _cnt;
    }

private:
    int _cnt = 0;
};

void test(){
    FunctionObject fo;
    fo();  //ok
    fo.operator()(); //本质
    fo(3);
    fo(3.5,3);
    cout << "函数对象被调用的次数:" << fo.getCount() << endl;
}

int main()
{
    test();   
    return 0;
}
