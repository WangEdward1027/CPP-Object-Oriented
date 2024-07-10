#include <iostream> 
using std::cout;
using std::cin;
using std::endl;

//1.static_cast
void test1(){
    //变量之间类型转换
    double a = 3.14;
    int b = static_cast<int>(a);
    cout << a << endl << b << endl;
    
    //指针之间类型转换:void* -> int*
    void * pVoid = malloc(sizeof(int));
    int * pInt = static_cast<int*>(pVoid); //pVoid->pInt,接管刚才申请的堆空间
    *pInt = 2204;
    cout << *pInt << endl;
    free(pInt);

    //char* -> int *不被允许
    char* pstr = new char('H');
    int* pInt2 = (int*)pstr; //C风格强转,即使不合理也能成功
    cout << *pInt2 << endl; //H的ASCII值是72,按int型输出
    //int pInt3 = static_cast<int*>(pstr); //error
    
    //const cahr*->char*不被允许
    const char * pstr2 = "HELLO";
    //char * pstr3 = static_cast<char*>(pstr2);  //error
}

int main()
{
    test1();   
    return 0;
}
