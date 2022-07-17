#include <iostream>

using namespace std;

class Parent {
public:
    int name;
    char *str;
protected:
    int bank;
private:
    int xifu;

public:
    Parent() {
        cout << "Parent(NULL)" << endl;
    }

    Parent(char *str) {
        if (str != NULL) {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        } else {
            this->str = NULL;
        }
        cout << "parent()" << endl;
    }

    ~Parent() {
        cout << "delete parent()" << endl;
    }

    void printC() {
        cout << "printC parent " << endl;
    }


};

class Parent2 {
public:
    //成员变量名称必须不一样
    int name2;
};

/**
 * 可以多继承
 *
 * public 继承
 */
class Child : public Parent, Parent2 {
    void test() {
        this->name;
        this->bank;
        //不能访问私有属性
        //this->xifu;
    }

public:

    Child() {
        cout << "Child(NULL)" << endl;
    }

    //C++中子类构造方法如何调用父类的构造方法
    //可以使用冒号然后调用父类的构造方法
    Child(char *str) : Parent(str) {
        if (str != NULL) {
            this->str = new char[strlen(str) + 1];
            strcpy(this->str, str);
        } else {
            this->str = NULL;
        }
        cout << "Child()" << endl;
    }

    ~Child() {
        cout << "delete child()" << endl;
    }


    void printC() {
        cout << "printC child " << endl;
    }

};

/**
 * private 继承
 */
class Child1 : private Parent {

    void test() {
        this->name;
        this->bank;
    }
};

/**
 * protected 继承
 */
class Child2 : protected Parent {
    void test() {
        this->name;
        this->bank;
    }

};


void demo1() {

    //public 继承，在类外部可以访问public属性，其他类型属性都不可以访问
    Child child;
    child.name;
    //不可以访问protect
//    child.bank;

    //private 继承，在类外部，所有属性都不可以访问
    Child1 child1;
    //name bank xifu 都不能访问
//    child1.name;



    //protected 继承，在类外部，所有属性都不可以访问
    Child2 child2;
    //name bank xifu 都不能访问
//    child2.name;
//    child2.bank;

    //大部分情况下都是使用public

}

void demo2() {
    //调用父类构造方法，调用子类构造方法，调用父类析构函数
    //parent()
    //Child()
    //delete parent()
    Child child3 = Child("xiaoming");
    cout << "-------------------" << endl;


    //parent()
    //Child()
    //delete parent()
    //delete parent()
    Parent child4 = Child("xiaoming");

    cout << "-------------------" << endl;
    //在父类中重写了系统默认方法，比如：无参的构造函数，待拷贝的构造函数，析构函数。
    //子类直接继承，无需重写。

    //生成时，先执行父类的构造函数，再执行子类的。
    //销毁时，先调用子类的析构函数，再调用父类的。
    Child child = Child();
}
//
//void howToPrint(Child *c) {
//    cout << "howToPrint(Child *c)" << endl;
//    c->printC();
//}
//
//void howToPrint(Child &c) {
//    cout << "howToPrint(Child &c)" << endl;
//    c.printC();
//}

void howToPrint(Parent *p) {
    cout << "howToPrint(Parent *p)" << endl;
    p->printC();
}

void howToPrint(Parent &p) {
    cout << "howToPrint(Parent &p)" << endl;
    p.printC();
}

void demo3() {
    Parent parent;
    //调用父类的printc
    parent.printC();
    cout << "-------------------" << endl;

    Child child;
    //调用子类的printc
    child.printC();
    cout << "-------------------" << endl;

    Parent child1 = Child();
    //只调用父类的printc
    //printC parent
    child1.printC();
    cout << "-------------------" << endl;

    Parent *p = NULL;
    p = &child;
    //只调用父类的printc
    //printC parent
    p->printC();

    cout << "-------------------" << endl;


    //howToPrint(Parent *p)
    //printC parent
    howToPrint(p);

    //howToPrint(Parent &p)
    //printC parent
    howToPrint(child);

}


class VirParent {
public:
    //虚函数，子类可以不重写
    virtual void speak() {
        cout << "speak parent " << endl;
    }

    //纯虚函数，子类必须重写
    virtual void listener() = 0;
};

class VirChild : VirParent {

public:
//    void speak() {
//        cout << "speak child" << endl;
//    }

    void listener() {
        cout << "listener child" << endl;
    }
};

void demo4() {
    //如何调用子类的方法？——使用虚函数
    VirChild child;
    child.listener();
//    child.speak();
}

int main() {

    //******************************** 类继承 *******************************//
//    demo1();

    //******************************** 构造函数 *******************************//
    demo2();

//    demo3();

//    demo4();
    return 0;
}



