#include <iostream>

void cincoutTest();

void yinyongTest();

void constYinYongTest();

void functionYinYongTest();

using namespace std;

void myswap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void myswap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void myswap3(int &p1, int &p2) {
    //传引用和传指针的效果是一样的
    //传引用直接对实参进行操作，没有产生副本
    int p = p1;
    p1 = p2;
    p2 = p;
}

/**
 * 引用
 * @return
 */
int main() {

//    cincoutTest();
//    yinyongTest();
//    constYinYongTest();
    functionYinYongTest();
    return 0;
}
/**
 * 可以实现，但是会产生返回值副本
 * @param r
 * @return
 */
float fn1(float r) {
    float temp = (float) (r * r * 3.14);
    return temp;
}

/**
 * 局部变量会有问题
 * @param r
 * @return
 */
float &fn2(float r) {
    float temp = (float) (r * r * 3.14);
    float &p = temp;
    return p;
}
/**
 * 需要全局变量
 */
float temp;

float &fn3(float r) {
    temp = (float) (r * r * 3.14);
    //相当于 int & b=temp;
    //      return b;
    return temp;
}

void functionYinYongTest() {
    float a = fn1(10);
    cout << "a=" << a << endl;

    //报错
    //fn2返回值temp 会在函数结束后进行销毁，所以不能声明一个引用指向函数返回值
    float &b = fn2(10);
    cout << "b=" << b << endl;//b=-1.42767e-33

    //fn3返回值temp 是全局变量，不会销毁，所以可以声明一个引用指向函数的返回值
    float &c = fn3(10);
    float x=fn3(10);
    cout << "x=" << x << endl;
    cout << "c=" << c << endl;

    //总结：c++ 中的引用可以就理解为c语言中的指针！！！
}

void constYinYongTest() {
    int a = 1;
    int &b = a;
    b = 2;
    cout << "a=" << a << endl;
    int c = 1;
    //常量引用 和常量指针类似  指向常量的指针，指针的内容不能变
    const int &d = c;
    //下面写法不合法
//    d = 2;
    c = 2;
}

void yinyongTest() {
    int a = 10;
    //引用：就是某一个变量（目标）的别名，对引用的操作与对变量的直接操作完全一样
    //&b在=的左边，表示引用，&只是个标志，标志是引用，不是取在地址；
    /**
     * 1、&不是求址运算符，而是起标志作用
     * 2、声明引用时，必须同时对其进行初始化
     * 3、类型标志符是目标变量的类型
     * 4、引用声明完毕后，相当于变量有两个名称，目标原名称和引用名，且不能再不该引用名作为其他变量名
     * 5、声明一个引用不是定义新变量，它只表示该引用名是目标变量的一个别名。系统不会分配存储但愿
     * 6、不能建立数组的引用，因为数组是一个由若干个元素所组成的集合，所以无法建立一个数组的别名。
     */
    int &b = a;
    printf("a:%d\n", a);//a和b 的值和地址都是完全一样的
    printf("b:%d\n", b);
    printf("a:%p\n", &a);
    printf("b:%p\n", &b);
    int c = 11;
//    int &b=c;

    //一般作用在函数参数名声明中
    //引用的好处：1、纯指针，需要不断的取址 2、可以减少内存的分配
    int p11 = 10;
    int p22 = 20;
//    myswap1(p11, p22);
//    myswap2(&p11, &p22);
    myswap3(p11, p22);
    printf("%d,%d", p11, p22);

}


void cincoutTest() {
    //  std::cout << "Hello, World!" << std::endl;
    // std 可以使用using namespace 来声明命名空间
    // c++ 中没有包名的概念，可以是用命名空间的概念
    cout << "hello,"
         << "world"
         << endl;
    cout << "abc";

    //
    char a, b;
    int c;
    float d;
    cin >> a
        >> b
        >> c
        >> d;
    cout << a << b << c << d;


}
