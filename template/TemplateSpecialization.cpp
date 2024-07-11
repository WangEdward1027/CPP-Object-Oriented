//特化模板: template <>

#include <iostream> 
#include <string>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

//普通函数模板
template <class T>
T add(T t1, T t2){
    return t1 + t2;
}

#if 1
//特化模板
template <>
const char * add<const char *>(const char * p1, const char * p2){
    char * ptemp = new char[strlen(p1) + strlen(p2) + 1]();
    strcpy(ptemp,p1);
    strcat(ptemp,p2);
    return ptemp;
}
#endif

void test1(){
    const char * pstr1 = "hello,";
    const char * pstr2 = "world";
 
    //1.语法能通过,编译时调用模板无法通过
    cout << add(pstr1,pstr2) << endl; //将两个const char *相加,编译失败
    
    //2.考虑先显式实例化,强转为string类型
    cout << add<string>(pstr1,pstr2) << endl; //ok
}

void test2(){
    const char * pstr1 = "hello,";
    const char * pstr2 = "world";

    //3.考虑只想隐式实例化,需要使用 特化模板
    cout << add(pstr1,pstr2) << endl; //还是test1中第一句,但是调用了特化模板,就能编译通过了
}

int main()
{
    /* test1(); */
    test2();
    return 0;
}
