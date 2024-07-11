//要求：使用函数模板实现两个整数类型数据相加、两个double型数据相加、两个存放int型元素的set融合

#include <iostream> 
#include <set>
using std::cout;
using std::endl;
using std::set;

template <class T>
T add(T t1, T t2){
    return t1 + t2;
}

//set<int>的特化模板
template <>
set<int> add(set<int> t1, set<int> t2){
    set<int> t3 = t1;
    t3.insert(t2.begin(), t2.end());
    return t3;
}

void test(){
    //1.两个整数类型数据相加
    int i1 = 10, i2 = 20;
    cout << add(i1,i2) << endl;
    
    //2.两个double型数据相加
    double d1 = 1.5, d2 = 2.5;
    cout << add(d1,d2) << endl;
    
    //3.两个存放int型元素的set融合
    //由于set<int>没有定义operator+操作,需要使用特化模板
    set<int> s1,s2;
    s1.insert({1,2,3,4});
    s2.insert({5,6,7,8});
    set<int> s3 = add(s1,s2);
    //遍历融合的set
    for(auto & ele: s3){
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}
