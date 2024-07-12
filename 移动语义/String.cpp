//为深拷贝的String类，添加：
//1.移动构造函数  (优先于拷贝构造函数，只移交管理权，不需要new)
//2.移动赋值运算符函数  (优先于赋值运算符函数,只移交管理权,不需要new)
//编译时需要添加禁止优化参数：g++ String.cpp -fno-elide-constructors

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
public:
    String()
    : _pstr(new char[1]())
    {
        cout << "String()" << endl;
    }

    String(const char *pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "String(const char *)" << endl;
        strcpy(_pstr, pstr);
    }
    
    //移动构造: String s1 = String("hello");
    String(String && rhs)
    : _pstr(rhs._pstr) //浅拷贝
    {
        cout << "移动构造" << endl;
        rhs._pstr = nullptr; //移交管理权 
    }
    
    //拷贝构造: String s2 = s1;
    String(const String & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        cout << "String(const String &)" << endl;
        strcpy(_pstr, rhs._pstr);
    }

    //移动赋值运算符函数
    String & operator=(String && rhs){
        cout << "移动赋值函数" << endl;
        if(this != &rhs){
            delete [] _pstr;
            _pstr = rhs._pstr;   //浅拷贝
            rhs._pstr = nullptr; //移交管理权
        }
        return *this;
    }

    //赋值运算符函数
    String & operator=(const String & rhs)
    {
        cout << "String &operator=(const String &)" << endl;
        if(this != &rhs)
        {
            if(_pstr)
            {
                delete [] _pstr;
            }
            _pstr = new char[strlen(rhs._pstr) + 1]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }

    size_t length() const
    {
        size_t len = 0;
        if(_pstr){
            len = strlen(_pstr);
        }
        return len;
    }

    const char * c_str() const
    {
        if(_pstr){
            return _pstr;
        }else{
            return nullptr;
        }
    }


    ~String()
    {
        cout << "~String()" << endl;
        if(_pstr)
        {
            delete [] _pstr;
            _pstr = nullptr;
        }
    }

    void print() const
    {
        if(_pstr)
        {
            cout << "_pstr = " << _pstr << endl;
        }else{
            cout << endl;
        }
    }

private:
    char * _pstr;
};

void test0(){
    //1.有参构造
    String s1("hello");
    cout << endl;

    //2.拷贝构造
    String s2 = s1;
    cout << endl;
    
    //3.先有参构造,再拷贝构造
    //利用"hello"这个字符串创建了一个临时对象,再复制给了s3。这一步实际上new了两次
    //若加入移动构造,则是 有参构造 + 移动构造, new的次数为 1 + 0 = 1次
    String s3 = "hello";
    cout << endl;

    //4.赋值:优先移动赋值。没有移动赋值,才调用赋值运算符函数。
    s2 = std::move(s3);
}

int main(void){
    test0();
    return 0;
}
