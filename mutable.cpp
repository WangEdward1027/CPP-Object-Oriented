#include <iostream> 
#include <string>
using std::cout;
using std::string;

class Log
{
public:
    void print(const string & str) const
    {
        cout << str << "\n";
        printNums++;
        cout << printNums << "\n";
    }
private:  //被mutable修饰的成员变量,可以在const成员函数中被修改
    mutable int printNums = 0; 
};

int main()
{
    Log log;
    log.print("666");
    log.print("hello world");
    return 0;
}
