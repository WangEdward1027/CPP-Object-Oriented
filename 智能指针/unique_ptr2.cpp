//独享指针:unique_ptr的用法

#include <iostream> 
#include <memory>
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;

//1.自定义类型
void test()
{
    //1.new: 只能用括号,不能用等号
    unique_ptr<int> up(new int(666));   
    
    //2.make_unique
    unique_ptr<int> up2 = make_unique<int>(888);
    cout << "*up2 = " << *up2 << endl;
    
    //3.get()
    cout << "up的原生指针: " << up.get() << endl;
    
    //*up和*up.get()是等价的
    cout << "*up = " << *up << endl;
    cout << "*up.get() = " << *up.get() << endl;
    
    //4.unique_ptr删除了拷贝构造和拷贝赋值,但支持移动构造和移动赋值
    /* unique_ptr<int> up3(up2); //不支持拷贝构造 */
    /* up2 = up; //不支持拷贝赋值 */
    
    unique_ptr<int> up3(std::move(up2)); //支持移动构造
    cout << "*up3 = " << *up3 << endl;
    
    up2 = std::move(up); //支持移动赋值
    cout << "*up2 = " << *up2 << endl;
    
    if(up){
        cout << "up还在" << endl;
    }else{
        cout << "up为空指针" << endl; //被移动后,为空指针
    }
}

int main()
{
    test();   
    return 0;
}
