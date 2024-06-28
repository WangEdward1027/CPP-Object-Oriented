//自定义学生类：包含学号（int _id）、身高（double _height）、姓名（char _name[20]）、成绩（double _score）信息，能够利用这个自定义类创建对象，并输出该对象的信息。
//注意数据成员的声明顺序，考虑内存对齐

#include <string.h>
#include <iostream> 
using std::cout;
using std::endl;

//自定义类
class Student{
public:
    Student():_height(180),_name("Ed"),_id(1),_score(100)
    {
        cout << "Student()" << endl;
    }

    Student(double height, const char * name, int id, double score)
    :_height(height), _id(id),_score(score)
    {
        cout << "Student(int id, double height, const char * name, double score)"  << endl;
        strcpy(_name, name);
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
    //注意数据成员的声明顺序，考虑内存对齐
    double _height;
    char _name[20]; //有可能不够,有可能浪费
    int _id;
    double _score;
};

void test0(){
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

    Student stu2(182.0, "Edward", 2,140.5);
    int id2 = stu2.getId();
    cout << "id2 = " << id2 << endl;

    double height2 = stu2.getHeight();
    cout << "height2 = " << height2 << endl;

    char * name2 = stu2.getName();
    cout << "name2 = " << name2 << endl;

    double score2 = stu2.getScore();
    cout << "score2 = " << score2 << endl;
}

void test1(){
    Student stu;
    cout << sizeof(stu) << endl;
    /* cout << stu._id << endl; */
}

int main()
{
    /* test0(); */
    test1();
    return 0;
}
