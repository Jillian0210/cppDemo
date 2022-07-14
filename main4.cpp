
#include <iostream>
#include <unistd.h>

using namespace std;

class Person {
public:

    //1、常量 const在类型前面或者后面
    const int a = 10;
    int const a1 = 20;


    //普通变量
    int b = 8;


    //可变变量
    mutable int c = 100;
    int mutable c1 = 200;


    //2、常函数
    void show() const {
        //长函数的目的，不让其它人修改内部的变量
        //修改 a，b都会报错
//        a=10;
//        b=20;
        //修改c 不会报错，用mutable声明的
        c = 16;
    }
};

void constDemo() {
    //普通变量
    Person person;
    //不能修改常量属性
//    person.a=1;
    person.b = 2;
    person.c = 3;

    //3、常对象
    Person const person1;
    //既不能修改常量属性，也不能修改普通变量，只能修改mutable修饰的变量。
//    person1.a=1;
//    person1.b=2;
    person1.c = 3;

}

/**************************************************************************/
//可以不要{}，声明一个空类
//class Instance1;

class Instance {
    //声明对象
private:
    static Instance *instance;

    //对外提供一个获取对象的方法
public:
    static Instance *getInstance() {
        //初始化在类外进行
//        if (instance == nullptr) {
//            instance = new Instance();
//        }
        return instance;
    }

private:
    //私有化构造函数
    Instance() {};

    //私有化构造拷贝函数
    Instance(const Instance &) {};
};

//初始化在此进行
Instance *Instance::instance = Instance::getInstance();

void instanceDemo() {


    //和java一样，使用对外提供的方法获取单例实例对象.
    //  不能使用默认构造函数  new Instance() 获取对象
    Instance *c1 = Instance::getInstance();
    Instance *c2 = Instance::getInstance();
    if (c1 == c2) {
        //结果：一样的
        cout << "c1==c2" << endl;
    } else {
        cout << "c1!=c2" << endl;
    }

//    //和java不一样的是，c有默认的构造拷贝函数——》c需要把构造拷贝函数也私有化
//    Instance *c3 = new Instance(*c1);
//    if (c1 == c3) {
//        cout << "c1==c3" << endl;
//    } else {
//        //结果：不一样
//        cout << "c1!=c3" << endl;
//    }



}

/**************************************************************************/
class Student {
public:

    double score;
    int age;
    static int a;

public:
    void test() {}
};

struct Teacher {
    int age;
    static int a;

    void test() {}

    Student student;
};


void sizeDemo() {

    Student *student;
    //指针的长度是8个字节
    cout << "student point size " << sizeof(student) << endl;

    //studen1是对象，对象的大小要看成员变量。
    //如果没有成员变量，为1个字节
    //如果有成员变量，成员变量之和，并且进行对齐。是字节数最多的成员变量的整数倍。
    //如：    int age;  ——》4个字节
    //如：    int age;   char name;——》8个字节
    //如果有静态成员变量，不计入它的字节数；
    //如果有成员方法，也不计入它的字节数；
    Student student1;
    cout << "student1 object size " << sizeof(student1) << endl;


    //结构体和对象计算方式类似。
    Teacher teacher;
    cout << "teacher struct size " << sizeof(teacher) << endl;
}

/**************************************************************************/

class Box {
private:
    int width;

    void testPrivateMethod() {
        cout << "testPrivateMethod" << endl;
    }

public:
    double length;

    //printWidth 就是友元函数
    friend void printWidth(Box box);

    friend class Printer;

    void setWidth(int width);
};


class Printer {
public:
    void print(int width, Box box) {
        box.setWidth(width);
        cout << "Printer excute print Width of box " << box.width << endl;
        box.testPrivateMethod();
    }
};

//成员函数定义
void Box::setWidth(int d) {
    this->width = d;
}

//printWidth 不是任何类的成员函数
void printWidth(Box box) {
    //因为printWidth时Box的友元函数，所以可以直接访问该类的任何成员
    cout << "Width of box " << box.width << endl;
    box.testPrivateMethod();
}


void friendDemo() {
    Box box;
    box.setWidth(10);
    printWidth(box);

    Printer printer;
    printer.print(12, box);
}

/**
 * 知识点如下：
 * 1、常量
 * 2、单例
 * 3、对象模型
 * 4、友元函数
 */
int main() {

//    constDemo();

//    instanceDemo();

    //c++中分为栈区、堆区；没有方法区
    //c++中的静态成员变量放在全局数据区，方法（也就是代码）放在代码段里面
//    sizeDemo();


    friendDemo();
    return 0;
}


