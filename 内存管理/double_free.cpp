//内存回收问题:【不回收】会造成【内存泄露】,【多次回收】会造成【double free】
//1.delete悬空指针会造成double free 
//2.安全回收(悬空指针置空) + 下次delete前先判空
//3.智能指针会自动回收，无需手动回收

#include <iostream>
#include <memory>  //智能指针的头文件
using std::cout;
using std::endl;
using std::unique_ptr;

//不做任何处理,可能会delete悬空指针,造成double free问题
void test(){
    int * ptr = new int(10);
    delete ptr; //第一次释放
    delete ptr; //第二次释放,导致double free问题
    //补充:除了delete同一个指针两次。
    //浅拷贝造成两个指针指向同一片内存空间,也容易造成double free问题。
    //其中一个指针进行delete，另一个指针就成了悬空指针
}

//每次delete后将悬空指针置为空指针(安全回收),并在下次回收前先判空
void test2(){
    int * ptr = new int(10);
    delete ptr;     //第一次释放
    ptr = nullptr;  //1.安全回收:将悬空指针置空

    if(ptr != nullptr){ //2.检查ptr是否为nullptr,避免double free
        delete ptr;   
    }else{
        cout << "已经是空指针了" << endl;
    }
}

//使用智能指针
void test3(){
    unique_ptr<int> ptr(new int(10));   
    //不需要手动delete,智能指针会在超出作用域时自动释放内存
    //memcheck发现没有内存泄露
}

int main(){
    /* test(); */
    /* test2(); */
    test3();
    return 0;
}
