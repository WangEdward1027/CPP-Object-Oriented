//类模板
//使用类模板定义出可以存放各种类型元素的栈
//存放 int、double、char、vector<string>

#include <iostream> 
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

template <class T = int, int kCapacity = 3>
class Stack
{
public:
    Stack()
    : _top(-1)
    , _data(new T[kCapacity])
    {
        cout << "Stack()" << endl;
    }

    ~Stack(){
        if(_data){
            delete [] _data;
            _data = nullptr;
        }
        cout << "~Stack()" << endl;
    }

    bool empty() const{
        return _top == -1;
    }

    bool full() const{
        return _top == kCapacity - 1;
    }

    void push(const T & t){
        if(!full()){
            _data[++_top] = t;
        }else{
            cout << "栈已满!" << endl;
        }
    }

    void pop(){
        if(!empty()){
            --_top;
        }else{
            cout << "栈已空!" << endl;
        }
    }

    T top();
private:
    int _top;
    T * _data;
};

//类模板的成员函数在类外实现,需要加上完整的模板声明
template <class T, int kCapacity>
T Stack<T,kCapacity>::top(){
    if(!empty()){
        return _data[_top];
    }else{
        throw "栈已空";
    }
}

// 重载 << 运算符用于打印 vector<string>
std::ostream& operator<<(std::ostream& os, const vector<string>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) {
            os << " ";
        }
    }
    return os;
}

void test0(){
    Stack<int,2> s1;
    Stack<double> s2;
    Stack<> s3;
    Stack<char,5> s4;
    Stack<vector<string>> s5;

    //1.存放int类型的栈
    s1.push(1);
    s1.push(2);
    cout << "s1 top: " << s1.top() << endl;
    s1.pop();
    cout << "s1 top after pop: " << s1.top() << endl;
    
    //2.存放double类型的栈。没指定容量,默认为3
    s2.push(3.14);
    s2.push(2.718);
    cout << "s2 top: " << s2.top() << endl;
    s2.pop();
    cout << "s2 top after pop: " << s2.top() << endl;

    //3.没指定类型的栈,默认类型为int
    s3.push(1.9);
    s3.push(2.9);
    cout << "s3 top: " << s3.top() << endl;
    s3.pop();
    cout << "s3 top after pop: " << s3.top() << endl;

    //4.存放char类型的栈
    s4.push('h');
    s4.push('e');
    s4.push('l');
    s4.push('l');
    s4.push('o');
    cout << s4.full() << endl;
    cout << "s4 top: " << s4.top() << endl;

    //5.存放vector<string>类型的栈
    vector<string> vec1{"hello,","world"};
    s5.push(vec1);
    cout << "s5 top: " << s5.top() << endl;
}

int main()
{
    test0();   
    return 0;
}
