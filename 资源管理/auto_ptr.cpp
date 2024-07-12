//auto_ptr
//在C++17中被废弃 (deprecated)

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;

void test0(){
    int * p = new int(10);
    auto_ptr<int> ap(p);
    cout << *ap << endl;
    /* delete p; */
}

void test1(){
    //智能指针通常在构造函数参数初始化时直接使用new表达式
    auto_ptr<int> ap(new int(20));
    cout << *ap << endl;
    
    auto_ptr<int> ap2(ap);
    //虽然调用了拷贝构造，但是底层的实现是移交管理权的操作
    //ap失去了对之前的资源空间的管理权,被置为空指针
    /* cout << *ap << endl; //再对ap进行解引用,会造成程序中断 */
    cout << *ap2 << endl;
}
int main(void){
    test1();
    return 0;
}
