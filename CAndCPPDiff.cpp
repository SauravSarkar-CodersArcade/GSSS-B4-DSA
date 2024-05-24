#include <iostream> // Continuous Stream Of Bytes 1's & 0's
using namespace std;
namespace student1 {
    int age = 20;
    void print(){
        cout << "Hi" << endl;
    }
}
namespace student2 {
    int age = 30;
    void print(){
        cout << "Hi" << endl;
    }
    class Demo{
    public:
        static void display(){
            cout << "This is class Demo" << endl;
        }
    };
}
int main() {
//    cout << "GSSS" << endl;
//    cout << student1::age << endl;
//    cout << student2::age << endl;
//    student1::print();
//    student2::print();
//    //namespace_name::className::method_name();
//    student2::Demo::display();
    // Format Specifiers
    int x = 20;
    auto y = 4.5f; // Iterator
    string name;
    getline(cin, name);
    cout << name << endl;
    printf("%d", x);
    // C + SIMULA = C++ Bjarne Stroustrup
    // C + C++ = Java James Gosling
    return 0;
}
