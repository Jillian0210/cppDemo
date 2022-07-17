//
// Created by jiangli on 2022/7/9.
//

#ifndef CPPDEMO_ARRAYLIST_H
#define CPPDEMO_ARRAYLIST_H

/**
 * 自定义arraylist
 */
class ArrayList {

public:
    ArrayList();

    explicit ArrayList(int capacity);

    ~ArrayList();

    //为什么要实现拷贝构造函数？
    //防止重复释放；因为默认拷贝构造函数是浅拷贝，只拷贝地址，这个地址会释放两次。
    //什么时候会调用拷贝函数？
    //作为参数，赋值，返回值；
    void add(int val);
    void add(int val,int size);
    int get(int pos);
    void remove(int index);
    int getLength();
    bool isEmpty();

    void resize();
    void toString();



private:
    //数组的容量
    int capacity;
    int size;
    //实际的数据长度
    int actualSize;
    //暂时定义成int类型的数组，后面可以改成范性
    //定义成指针，这样可以重写赋值，进行扩容，
    int *arr;


};


#endif //CPPDEMO_ARRAYLIST_H
