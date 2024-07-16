//可变参数模板

#include <iostream>
using std::cout;
using std::endl;

template <class ...Args>//Args 模板参数包
void display(Args ...args)//args 函数参数包
{
    //输出模板参数包中类型参数个数
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    //输出函数参数包中参数的个数
    cout << "sizeof...(args) = " << sizeof...(args) << endl;
}

//普通函数作为递归出口
void print(){
    cout << endl;
}

template <class T,class ...Args>
void print(T x, Args ...args){
    cout << x << " ";
    print(args...); //省略号在包的右边表示解包
}

void test0(){
    display();
    display(1,"hello",3.3,true);
    display(1,"hello",3.3,true,'a',2);
}

void test1(){
    print(1,"hello",3.4,true,false,200);
}

int main(void){
    test1();
   
