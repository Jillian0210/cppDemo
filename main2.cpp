#include <iostream>

using namespace std;
#define AddTest1(x, y) x+y

//用inline 来标志内联函数
inline int AddTest2(int x, int y) {
    return x + y;
}

//------------------------------------------------
//可以在形参声明的时候定义默认值，那么在调用的时候可以不传递该形参对应的实参数
void paramsTest1(int x, int y = 10) {
    cout << "x=" << x << ",y=" << y << endl;
}

//没有默认参数的写在前面，有默认参数写在后面,需要分为两组
void paramsTest2(int a, int b, int c = 1, int d = 2) {
    cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << endl;
}

//占位参数 没参数名，函数体中不会去使用该参数
//存在的意义是兼容c可能出现的不规范
void paramsTest3(int a, int b, int= 0) {
    cout << "a=" << a << ",b=" << b << endl;
}

//------------------------------------------------
//1、名字相同
//2、参数不同,参数长度不同或者参数的类型不同
//3、和返回值没有关系，不做要求
//常量指针和指针常量算重载
//指针和引用也算重载
//引用和常量引用算重载
//普通变量和同类型的引用不算重载
//重载函数  void test(int a)和void test(int &a) 不是重载函数
void test(int a) {
    cout << "a=" << a << endl;
}

//void test(int &a) {
//    cout << "&a=" << a << endl;
//}

void test(int *a) {
    cout << "*a=" << a << endl;
}

void test(int a, int b) {
    cout << "a=" << a << ",b=" << b << endl;
}
//------------------------------------------------

void (*myfuncPoint)(int a);

typedef void myFuncTest1(int a);

typedef void myFuncTest2(int a, int b);

void realTest1(int a) {
    cout << "a=" << a << endl;
}

void realTest2(int a, int b = 10) {
    cout << "a=" << a << ",b=" << b << endl;
}
//------------------------------------------------
/**
 * 内联函数
 * 函数重载
 * @return
 */
int main() {
//------------------------------------------------
    int result = AddTest1(1, 2) * 10;
    cout << "宏定义函数 result=" << result << endl;//21

    int result2 = AddTest2(1, 2) * 10;
    cout << "内联函数 result=" << result2 << endl;//30

//------------------------------------------------
    paramsTest1(1, 2);
    paramsTest1(1);

    paramsTest2(11, 22);
    paramsTest2(11, 22, 33);
    paramsTest2(11, 22, 33, 44);

    paramsTest3(111, 222);
//------------------------------------------------

    test(1);
    test(1, 2);

//    int a = 10;
//    int &b = a;
//    test(b);

    int a = 10;
    int *p = &a;
    test(p);
//------------------------------------------------
//为了解决二义性：
    //func 为函数指针 指向test2
    //myFuncTest 函数类型
    myFuncTest1 *func = realTest1;
    func(3);

    //myfuncPoint函数指针
    myfuncPoint = realTest1;
    myfuncPoint(8);

    myFuncTest2 *funcTest2=realTest2;
    funcTest2(4,1);

//------------------------------------------------
}