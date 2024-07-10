//用new来申请int、char、int[]、char[]
//注意delete,避免内存泄露

#include <iostream> 
#include <string.h>
using std::cout;
using std::endl;

//1.申请一个int类型
void test(){
    int* p = new int; //不建议这样写,不写小括号,无法在所有平台确保能初始化为0
    cout << *p << endl;
    delete p;

    int* ptr = new int();      //在堆上申请一个int型数据,默认初始化为0
    int* ptr2 = new int(1027); //在堆上申请一个int型数据,初始化为1027
    cout << *ptr  << endl<< *ptr2 << endl;
    delete ptr;     //释放分配的内存,防止内存泄露
    ptr = nullptr;  //将悬空指针置为nullptr,避免double free
    delete ptr2;
    ptr = nullptr;
    
    int * ptr3 = new int(2204);
    delete ptr3;
    cout << *ptr3 << endl; //访问悬空指针,得到的结果会出乎意料
                           //潜在造成程序错误或崩溃,难以debug
    ptr3 = nullptr;
    //cout << *ptr3 << endl; //访问空指针,则会直接造成【段错误】
}

//2.申请char型类型
void test2(){
    char* pc = new char();
    char* pc2 = new char('a');
    cout << *pc << endl << *pc2 << endl;
    delete pc;
    delete pc2;
}

//3.申请一个int型数组
void test3(){
    int* A = new int[10]();
    //指针数组只能用普通下标访问for循环,增强for循环只能用于STL容器
    for(int i = 0; i < 10; ++i){
        cout << A[i] << " ";
    }
    cout << endl;
    delete [] A;

    int* B = new int[5]{1,2,3,4,5};
    for(int i = 0; i < 5; ++i){
        cout << B[i] << " ";
    }
    cout << endl;
    delete [] B;
}

//4.申请一个char型数组
void test4(){
    const char* p = "hello";
    int len = strlen(p);
    for(int i = 0; i < len; ++i){
        cout << p[i];
    }
    cout << endl;
    
    char* pstr = new char[strlen(p) + 1]{'w','o','r','l','d'};
    //输出流运算符对char*有默认重载效果，会自动访问指针保存的地址上的内容
    cout << pstr << endl;
    delete [] pstr;
}

int main()
{
    /* test(); */
    /* test2(); */
    /* test3(); */
    test4();
    return 0;
}
