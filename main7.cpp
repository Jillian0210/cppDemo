#include <iostream>

using namespace std;



template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
    cout<<a<<endl;
}

template <typename T>
void mySwap2(){
    T t;
    cout<<t<<endl;
}

int main() {
    int a=10;
    int b=20;
    char c='c';
    char d='d';
    mySwap(a,b);
    mySwap<int>(a,b);

    mySwap<char>(c,d);
    mySwap(c,d);
//    mySwap(a,c);
//    mySwap<int>(a,c);

  mySwap2<int>();
}



