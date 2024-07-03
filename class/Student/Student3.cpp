#include <string.h>
#include <iostream> 
using std::cout;
using std::endl;

//自定义类
class Student{
public:
    Student():_id(1),_height(180),_name(new char[100]),_score(100)
    {
        cout << "Student()" << endl;
        strcpy(_name, "Ed");
    }

    Student(int id, double height, const char * name, double score)
    :_id(id),_height(height), _name(new char[strlen(name) + 1]), _score(score)
    {
        cout << "Student(int id, double height, const char * name, double score)"  << endl;
        strcpy(_name, name);
    }

    //析构函数：释放new出来的指针成员
    ~Student(){
        if(_name){
            delete [] _name;
            _name = nullptr; //设为空指针,安全回收
        }
        cout << "~Student()" << endl;
    }

    int getId(){
        return _id;
    }

    double getHeight(){
        return _height;
    }

    char * getName(){
        return _name;
    }

    double getScore(){
        return _score;
    }

private:
    int _id;
    double _height;
    //char _name[20];
    char * _name;     //动态创建数组大小
    double _score;
};

int main()
{
    Student stu;
    
    int id = stu.getId();
    cout << "id = " << id << endl;

    double height = stu.getHeight();
    cout << "height = " << height << endl;

    char * name = stu.getName();
    cout << "name = " << name << endl;

    double score = stu.getScore();
    cout << "score = " << score << endl;
    
    cout << "----------------------" << endl;

    Student stu2(2, 182.0, "Edward", 140.5);
    int id2 = stu2.getId();
    cout << "id2 = " << id2 << endl;

    double height2 = stu2.getHeight();
    cout << "height2 = " << height2 << endl;

    char * name2 = stu2.getName();
    cout << "name2 = " << name2 << endl;

    double score2 = stu2.getScore();
    cout << "score2 = " << score2 << endl;
    
    return 0;
}
