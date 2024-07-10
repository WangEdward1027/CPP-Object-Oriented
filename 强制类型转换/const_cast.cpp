#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

//2.const_cast
void test2(){
    //0.只有指针或引用才可以使用const_cast
    const int num0 = 100;
    /* const_cast<int>(num0);  //error */
    
    //1.引用去除const属性
    int num1 = 10;
    const int & ref = num1; //引用绑定num1
    int & ref1 = const_cast<int&>(ref); //移除引用的const属性
    ref1 = 20;  //修改成功
    cout << num1 << endl;
    
    //2.指针去除const属性
    int num2 = 30;
    const int * p = &num2; //指针指向num1
    int * p2 = const_cast<int*>(p); //移除指针的const属性
    *p2 = 40;  //修改成功
    cout << num2 << endl;
}

int main()
{
    test2();   
    return 0;
}
