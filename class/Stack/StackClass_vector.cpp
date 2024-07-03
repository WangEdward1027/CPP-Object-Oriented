//使用C++的vector实现栈类

#include <iostream> 
#include <vector>
#include <error.h>
#include <errno.h>
using std::cout;
using std::endl;
using std::vector;

class Stack{
public:
    Stack(int size)
    :_maxsize(size)
    {
        cout << "Stack(size)" << endl;
    }

    bool empty(){   //判断栈是否为空
        return _vec.empty();
    }

    bool full(){    //判断栈是否已满
        return _vec.size() == _maxsize;
    }
    
    void push(int value){ //元素入栈
        if(full()){
            error(1, 0 , "stack is full, push failed.");
        }
        _vec.push_back(value);
    }
    
    void pop(){     //元素出栈
        if(empty()){
            error(1, 0 ,"stack is empty, pop failed.");
        }
        _vec.pop_back();
    }
    
    int top(){      //获取栈顶元素
        if(empty()){
            error(1, 0, "stack is empty, top failed.");
        }
        return _vec.back();
    }

    size_t size(){
        return _vec.size();
    }

private:
    vector<int> _vec;
    size_t _maxsize;
};

int main()
{
    Stack s(3);

    cout << "if Stack is empty: " << s.empty() << endl;
    cout << "if Stack is full: " << s.full() << endl;
    
    s.push(10);
    cout << "top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;

    s.push(20);
    cout << "top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    s.push(30);
    cout << "top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    cout << "if Stack is empty: " << s.empty() << endl;
    cout << "if Stack is full: " << s.full() << endl;
    
    s.pop();
    cout << "top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    s.pop();
    cout << "top: " << s.top() << endl;
    cout << "Stack size: " << s.size() << endl;
    
    s.pop();
    cout << "Stack size: " << s.size() << endl;
    cout << "if Stack is empty: " << s.empty() << endl;

    return 0;
}
