//函数模板的重载
//1.函数模板与函数模板重载

#include <iostream> 
using std::cout;
using std::endl;

//函数模板一:接受两个相同类型的参数T,并返回类型T
template <class T>
T add(T t1, T t2){
    cout << "模板一: return ";
    return t1 + t2;
}

#if 1
//函数模板二:接受两个不同类型的参数T1和T2,并返回类型T1
template <class T1, class T2>
T1 add(T1 t1, T2 t2){
    cout << "模板二: t1 + t2 = " << t1 + t2 << ", return ";
    return t1 + t2;
}
#endif

//只有模板一的情况
void test0(){
    int i1 = 1;
    double d1 = 1.5;
    
    //模板一冲突
    /* cout << add(i1,d1) << endl; */ 
    //显式实例化,会强制类型转换,就不冲突了。但选择类型不当，可能造成精度丢失。
    cout << add<int>(i1,d1) << endl; 
    //正确显式实例化,选择好类型
    cout << add<double>(i1,d1) << endl; 
}

//加入模板二
void test1(){
    int i1 = 1;
    double d1 = 1.5, d2 = 2.5;
    
    //1.隐式实例化:模板一冲突,考虑加入模板二
    cout << add(i1,d1) << endl; 
    //2.显式实例化:先进行类型转换
    //(1)缺省一个模板参数
    //在两个模板都走得通时,编译优先选类型转换少的
    cout << add<int>(i1,d1) << endl; 
    //显式实例化,相当于先进行强转
    //相当于 add<double>(static_cast<double>(i1), static_cast<double>(d1))
    cout << add<double>(i1,d1) << endl; 
    //(2)两个参数,一定只能走模板二,因为模板二是两个类型参数(模板参数)
    //显式实例化,先强转,d2被转为int。再调用模板
    cout << add<double,int>(d1,d2) << endl;
}

int main()
{
    /* test0(); */      
    test1();      
    return 0;
}
