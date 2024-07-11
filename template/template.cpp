//模板
//隐式实例化、显式实例化

#include <iostream> 
#include <string>
using std::cout;
using std::endl;
using std::string;

//以往只能使用函数重载
#if 0
int add(int x, int y){
 return x + y;
}

double add(double x, double y){
 return x + y;
}

long add(long x, long y){
 return x + y;
}

string add(string x, string y){
 return x + y;
}
#endif

//函数重载减少了函数名,在调用时名字统一
//而使用模板的好处:在定义函数时也大大方便了,不需要去手动写一堆函数重载
//现在希望将类型参数化，使用class关键字或typename关键字都可以
template <class T>
T add(T t1, T t2){
    return t1 + t2;
}

//在调用时，实例化出相应的模板函数。编译时生成这段代码，不用手动定义
/* short add(short t1, short t2){ */
/*     return t1 + t2; */
/* } */

void test0(){
	cout << add(1,2) << endl;
	cout << add(1.2,3.4) << endl;
}

void test1(){
    short s1 = 1, s2 = 2;
    int i1 = 3, i2 = 4;
    long l1 = 5, l2 = 6;
    double d1 = 1.5, d2 = 2.5;
    string str1("hello,");
    string str2("world");

    //隐式实例化:像调用普通函数一样
    cout << "add(s1,s2): " << add(s1,s2) << endl;
    cout << "add(i1,i2): " << add(i1,i2) << endl;
    cout << "add(l1,l2): " << add(l1,l2) << endl;
    cout << "add(d1,d2): " << add(d1,d2) << endl;  
    cout << "add(str1,str2): " << add(str1,str2) << endl;  
    cout << endl;

    //显式实例化：带< >
    cout << "add(d1,d2): " << add<int>(d1,d2) << endl;  
}

int main(void){
	test0();
    cout << endl;
	test1();
    return 0;
}
