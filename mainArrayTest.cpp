//
// Created by jiangli on 2022/7/9.
//


#include "ArrayList.h"
#include "iostream"
using namespace std;
int main() {
    ArrayList *arrayList = new ArrayList(1);
    arrayList->add(4);
    arrayList->add(6);
    arrayList->add(8);
    arrayList->add(9);
    arrayList->add(10);
    arrayList->add(2);
    arrayList->add(7);
    arrayList->toString();

    cout<< arrayList->getLength();


    cout<<arrayList->get(1)<<endl;
    cout<<arrayList->isEmpty()<<endl;

    arrayList->remove(1);
    arrayList->toString();

   cout<< arrayList->getLength();

}