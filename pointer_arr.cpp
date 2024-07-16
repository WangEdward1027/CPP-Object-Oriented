//指针作为数组: int* p = arr;

#include <iostream> 
using std::cout;
using std::endl;

void test(){
    int arr[5] = {1,2,3,4,5};
    int* p = arr; //指针指向数组的第一个元素

    //使用指针像数组一样访问元素
    for(int i = 0; i < 5; ++i){
        cout << p[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();   
    return 0;
}
