//用C语言链表实现栈类

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

struct Node {
public:
    Node(int val) 
    : _val(val)
    , _next(nullptr) 
    {}

    int _val;
    Node* _next;
};

class Stack {
public:
    Stack(int capa) 
    : _head(nullptr)
    , _rail(nullptr)
    , _size(0) 
    , _capcaity(capa)
    {}

    bool full() const{
        return _size == _capcaity;
    }

    bool empty() const{
        return _size == 0;
    }

    void push(int val) {
        if(!full()){
            Node* node = new Node(val);
            if(empty()) {
                _head = _rail = node;
            } else {
                _rail->_next = node;
                _rail = node;
            }
            ++_size;
        }else{
            cout << "The Stack is full!!!" << endl;
            return;
        }
    }

    void pop() {
        if(!empty()) {
            if(_size == 1) {
                delete _rail;
                _head = _rail = nullptr;
            } else {
                Node* curr = _head;
                while (curr->_next != _rail) {
                    curr = curr->_next;
                }
                delete _rail;
                _rail = curr;
                _rail->_next = nullptr;
            }
            --_size;
        }else{
            cout << "The stack is empty!!!" << endl;           
            return;
        }
    }

    int top() const {
        if (_rail){
            return _rail->_val;
        } else {
            throw "stack is empty!!!";
        }
    }

    ~Stack() {
        while(_head != nullptr) {
            Node* temp = _head;
            _head = _head->_next;
            delete temp;
        }
        cout << "~Stack()" << endl;
    }

private:
    Node* _head;//头指针，指向栈底（链表头）
    Node* _rail;//尾指针，指向栈顶（链表尾）
    int _size;
    int _capcaity;
};

void test0() {
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

int main() {
    test0();
    return 0;
}
