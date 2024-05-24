#include <iostream>
using namespace std;
int fixedPoint(int arr[], int size){
    for (int i=0; i<size; i++){
        if (arr[i] == i)
            return i;
    }
    return -1;
}
int main() {
    int arr[] = {10,20,30,40,41,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int fPoint = fixedPoint(arr, size);
    if (fPoint != -1){
        cout << "The fixed point is: " << fPoint << endl;
    }else{
        cout << "Fixed point doesn't exist in the array." << endl;
    }
    return 0;
}
