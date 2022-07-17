#include <iostream>

using namespace std;


class VirParent {
public:
    //虚函数，子类可以不重写
    virtual void speak() {
        cout << "speak parent " << endl;
    }

    //纯虚函数，子类必须重写
    virtual void listener() = 0;

    void test() {
        cout << "test parent " << endl;
    }
};

class VirChild : public VirParent {
public:
    void speak() {
        cout << "speak child" << endl;
    }

    void listener() {
        cout << "listener child" << endl;
    }
};

void demo4() {
    //如何调用子类的方法？——使用虚函数
    VirChild child;
//    child.listener();
//    child.speak();

//variable type 'VirParent' is an abstract class
//    VirParent parent = VirChild();
//    parent.speak();

    VirParent *child1 = new VirChild();
    //调用的子类的方法
    child1->speak();
    child1->listener();


}

/**
 * 虚函数
 * @return
 */
int main() {
    demo4();
    return 0;
}



