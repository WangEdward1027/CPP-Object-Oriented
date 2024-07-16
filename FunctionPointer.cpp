//函数指针

#include <iostream> 
using std::cout;
using std::endl;

void display(int x){
    cout << "display:" << x << endl;
}

void show(){
    cout << "show()" << endl;
}

int add(int a, int b){
    return a + b;
}

void test(){
    //函数指针的省略形式
    void (*p1)(int) = display;
    p1(6);
    
    int (*p3)(int,int) = add;
    cout << p3(2,3) << endl;

    //函数指针的完整形式
    void (*p2)() = &show;
    (*p2)();
}

int main(void)
{
    test();   
    return 0;
}
