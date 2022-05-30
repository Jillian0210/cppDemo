#include <iostream>

namespace namespaceA {
    int a;

    void fun();

    namespace namespaceB {
        int a;

        void fun();

        namespace namespaceC {
            int a;
        }
    }
}
namespace namespaceAA {
    int a;
}

using namespace namespaceA;
using namespace namespaceAA;

using namespace std;

int main() {
//    std::cout << "Hello, World!" << std::endl;

//endl 是换行
cout<<"hello,world"<<endl;
//cin>>


    int x = namespaceA::a;
    int y = namespaceA::namespaceB::namespaceC::a;
    int z = namespaceAA::a;
    a;

    a;

    return 0;
}
