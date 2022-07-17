//
// Created by jiangli on 2022/7/9.
//

#include <cstdio>
#include "ArrayList.h"

#include "iostream"

using namespace std;

ArrayList::ArrayList() {
    this->capacity = 0;
    this->size = 16;
    //new 和delete  malloc和free必须成对出现
    this->arr = new int[this->size];
}


ArrayList::ArrayList(int capacity) {
    this->capacity = 0;
    this->size = capacity;
    //new 和delete  malloc和free必须成对出现
    this->arr = new int[this->size];
}

ArrayList::~ArrayList() {
    if (this->arr != NULL) {
        delete[] this->arr;
        this->arr = NULL;
    }
}

void ArrayList::add(int val) {
    //添加到最后的位置
    add(val, actualSize);
}

void ArrayList::add(int val, int index) {
    if (index < 0 || index > size) {
        return;
    }
    //先判断，扩容
    if (this->actualSize >= size * 0.75) {
        resize();
    }

    //使用下标方式
    this->arr[index] = val;
    //或者使用地址方式
//    *(this->arr + index) = val;
    actualSize++;

}

/**
 * 扩容
 */
void ArrayList::resize() {
    int newLength = size * 2;
    int *p = new int[newLength];
    for (int i = 0; i < size; ++i) {
        *(p + i) = arr[i];
    }
    //删除arr的内存数据
    delete[]this->arr;
    this->arr = p;
    //改变size
    this->size=newLength;

    cout<<"call resize function"<<endl;
}

void ArrayList::remove(int index) {
    if (index < 0 || index > size) {
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    actualSize--;
}

int ArrayList::get(int pos) {
    return arr[pos];
}

int ArrayList::getLength() {
    return actualSize;
}

bool ArrayList::isEmpty() {
    return actualSize == 0;
}

void ArrayList::toString() {
    cout << "[";
    for (int i = 0; i < actualSize; ++i) {
        cout << arr[i]<<"，";
    }
    cout << "]" << endl;
}




