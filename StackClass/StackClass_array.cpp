//用C语言动态数组实现栈类

#include <iostream>

using std::cout;
using std::endl;

class Stack
{
public:
    Stack(int size = 10)
    : _size(size)
    , _top(-1)
    , _data(new int[_size]())
    {
        cout << "Stack(int)" << endl;
    }

    ~Stack()
    {
        cout << "~Satck()" << endl;
        if(_data)
        {
            delete [] _data;
            _data = nullptr;
        }
    }

    bool full() const
    {
        return _top == _size - 1;
    }

    bool empty() const
    {
        return -1 == _top;
    }

    void push(const int &value)
    {
        if(!full())
        {
            _data[++_top] = value;
        }
        else
        {
            cout << "The stack is full!!!" << endl;
            return;
        }
    }

    void pop()
    {
        if(!empty())
        {
            --_top;
        }
        else
        {
            cout << "The stack is empty!!!" << endl;
            return;
        }
    }

    int top() const
    {
        if(!empty()){
            return _data[_top];
        }else{
            throw "stack is empty!!!";
        }
    }
private:
    int _size;
    int _top;
    int *_data;
};

void test0()
{
    Stack st(12);
    cout << "栈是不是空的？" << st.empty() << endl;
    st.push(1);
    cout << "栈是不是满的？" << st.full() << endl;

    for(int idx = 2; idx != 15; ++idx)
    {
        st.push(idx);
    }

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << "栈是不是空的？" << st.empty() << endl;
}

int main(void){
    test0();
    return 0;
}
