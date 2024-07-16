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

//1.利用函数指针进行函数调用
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

//2.函数指针作为参数传递
void execute(int (*func)(int,int), int x, int y){ //此处是实参add赋值给形参func
    int result = func(x,y);
    printf("Result: %d\n", result);
}

//3.typedef
void test2(){
    //利用typedef将 void (* )(int)类型定义为Function
    typedef void (*Function)(int);
    Function f1 = display;
    f1(8);
    //f1 = show; //error,类型不匹配
}

int main(void)
{
    /* test(); */
    execute(add, 6, 5);
    /* test2(); */   
    return 0;
}
