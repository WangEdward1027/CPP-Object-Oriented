//右值引用
//有名字的右值引用是左值,可以取地址
//没名字的右值引用是右值,不能取地址

#include <iostream> 
#include <string>
using std::cout;
using std::endl;
using std::string;

int func(){
    return 1;
}

void test(){
    /* &func(); //没有名字的右值引用,是右值。不能取地址 */
   int && ref = func(); //有名字的右值引用,是左值。可以取地址
   cout << &ref << endl;
}

string func2(){
    string str1("wd");
    return str1;
}

void test2(){
    /* &func2(); //编译错误,右值不能取地址 */
    string && ref = func2();
    cout << &ref << endl; //有名字的右值引用为左值,可以取地址
}

int globalNumber = 10;

int && func3(){
    return std::move(globalNumber);
}

void test3(){
    /* &func3(); //没有名字的右值引用是右值,不能取地址 */
    int && ref = func3();
    cout << & ref << endl; //有名字的右值引用是左值,可以取地址
    cout << ref << endl;
}

int main()
{
    test();       
    test2();       
    test3();       
    return 0;
}
