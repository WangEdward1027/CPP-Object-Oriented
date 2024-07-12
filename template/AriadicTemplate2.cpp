//利用可变模板参数实现一个函数模板，用来计算多个整型、浮点型数据的加法

#include <iostream>
using std::cout;
using std::endl;

//普通函数,作为递归出口
double add(){
    return 0;
}

//可变参数模板函数，用于递归调用
template<class T, class ...Args> //省略号写在参数包的左边,代表打包
/*T*/double add(T x, Args ...args) {
    return x + add(args...); //省略号写在参数包的右边,代表解包
}

int main() {
    // 测试 add 函数
    cout << add(1, 2, 3, 4, 5) << endl;          // 整数相加
    cout << add(1.1, 2.2, 3.3, 4.4, 5.5) << endl; // 浮点数相加
    cout << add(1, 2.2, 3, 4.4) << endl;          // 混合类型相加
    return 0;
}
