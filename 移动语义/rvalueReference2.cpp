//右值引用2
//1.非const左值引用:只能绑左值
//2.const左值引用:既可以绑左值,又可以绑右值
//3.右值引用:只能绑右值

#include <iostream> 
using std::cout;
using std::endl;

//1.非const左值引用:只能绑左值,不能绑右值
void test(){
    int a = 1, b = 2;

    int & ref = a;
    cout << ref << endl;

    //int & ref2 = a + b; //error, a+b是右值,绑不了

    //int & ref3 = std::move(a); //error,std::move(a)是右值,绑不了
}

//2.const左值引用:既可以绑右值,又可以绑左值
void test2(){
    int a = 1, b = 2;

    const int & ref = a; //a是左值
    cout << ref << endl;

    const int & ref2 = a + b; //a+b是右值
    cout << ref2 << endl;
}

//3.右值引用:只能绑右值,不能绑左值
void test3(){
    int a = 1, b = 2;
    
    //int && ref1 = a;  //error
    
    int && ref2 = a + b; //右值引用只能绑定右值,不能绑定左值
    cout << ref2 << endl;

    int && ref3 = std::move(a); //std::move(左值),能将左值的副本强转为右值
    cout << ref3 << endl;
}

int main()
{
    /* test(); */
    /* test2(); */
    test3();   
    return 0;
}
