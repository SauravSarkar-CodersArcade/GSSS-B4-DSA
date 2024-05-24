#include <iostream>
using namespace std;
class Demo {
    double d;
    int i;
    short s;
    char c;
};
int main() {
    Demo obj;
    cout << "Size of the class is: " << sizeof(obj) << " bytes." <<
    endl;
    cout << INT_MAX << endl;
    cout << INT_MIN << endl;
    cout << INT_MAX+1 << endl;
    cout << INT_MIN-1 << endl;
    int arr[5] = {1,2,3}; // 1,2,3,0,0
    cout << arr[4] << endl;
    // DMA & De-allocation
    int n;
    cin >> n;
    int * array = new int [n]; // 1D Array
    int ** myArrayMatrix = new int * [n]; // Allocation
    delete[] myArrayMatrix; // De-Allocation
    return 0;
}
