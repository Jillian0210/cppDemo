//
// Created by jiangli on 2021/1/17.
//
#include <iostream>
#include <unistd.h>

using namespace std;

class Child{

};
class Person {


    //protect private
public:
    int a;
    int b;
    Child child;
    //
    Person() {
        //默认构造函数
        cout << "0 param new person" << endl;
    }

    Person(int a) {
        this->a=a;
        cout << "1 param new person" << endl;
    }

    Person(int a, int b) {
        this->a=a;
        this->b=b;
        cout << "2 params new person" << endl;
    }

    //默认拷贝函数 常量引用  指向常量的引用，即person的内容不可以改变；
    // 因为如果person的内容改变了，那么main函数的person对象就会被改变。
    // 常量引用作为拷贝参数时，只能读，不能修改
    Person(const Person &person) {
        //person.a的写法编译报错
//        person.a=10;

        cout << "new person const Person &person" << endl;

        //实际上拷贝执行的代码如下：
        //注意是浅拷贝
        this->a=person.a;
        this->b=person.b;
        this->child=person.child;
    }

    Person(Person &person) {
        cout << "new person  Person &person" << endl;

        //实际上拷贝执行的代码如下：
        //注意是浅拷贝
        this->a=person.a;
        this->b=person.b;
        this->child=person.child;
    }


    ~Person() {
        //析构函数，没有重载，必须是无参
        //相当于activity 的onDestroy

        cout << "delete person" << endl;
    }
};

void test1();

void test2();

void test3();

void test4();

void test5();

void test6(Person person);


/**
 * 构造函数
 * 析构函数
 *
 * c++ 中的内存管理是手动的，java中的内存管理是系统来自动管理的
 * @return
 */
int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();


//0 param new person
//delete person test6的方法结束了
//delete person main方法结束了
    Person person=10;
    test6(person);
    cout<<"person a ="<<person.a<<endl;
    return 0;
}

//传递是地址
void test6(Person person) {
}

void test5() {
    //声明数组也进行了实例化 调用了四次构造函数
    Person person6[4];

}

void test4() {
    //隐式法 实例化对象 只能调用只有一个参数的构造函数，用的少，容易有歧议
    //explicit 关键字
    //   explicit Person(int a) {} 如果用 explicit 对Person一个参数的构造函数进行修饰，则表示不可以用隐式调用，必须明确的调用
    Person person5 = 10;
}

void test3() {
    //显示法 实例化对象
    Person person3 = Person(10, 20);
    Person person4 = Person();
}

void test2() {
    //括号法 实例化对象
    Person person2(1, 2);
}

void test1() {
    //声明就初始化了（实例化）
    //内存开辟在栈区（只有new 和 malloc 是开辟在堆区，其他方式的声明都是在堆区开辟的）
    Person person;
    //如果调用了暂停，那么不会打印delete，即不会执行析构函数
//    pause();
}

