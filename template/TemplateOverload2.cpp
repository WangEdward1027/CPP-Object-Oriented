//函数模板重载2:函数模板与普通函数重载
//优先走普通函数，速度块

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//函数模板
template <class T>
T add(T t1, T t2){
    cout << "模板" << endl;
    return t1 + t2;
}


short add(short t1, short t2){
    cout << "普通函数" << endl;
    return t1 + t2;
}


void test0(){
    short s1 = 1, s2 = 2;
    int i1 = 3, i2 = 4;

    cout << "add(s1,s2): " << add(s1,s2) << endl;
    cout << "add(s1,s2): " << add<short>(s1,s2) << endl;
    cout << "add(i1,i2): " << add(i1,i2) << endl;

}

int main(void){
    test0();
    return 0;
}
