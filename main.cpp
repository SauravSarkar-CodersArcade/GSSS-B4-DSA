#include <iostream>
using namespace std;
// 8822185799
int main() {
    int arr[] =
            {3,6,12,15,18,21,24,27,30};
    int n = sizeof(arr) / sizeof(arr[0]) + 1; // 36 / 4 = 9
    int sum =  3 * n * (n+1) / 2;
    for (int i=0; i<n-1; i++){
        sum -= arr[i];
    }
    cout << "The missing element is: " << sum << endl;
    return 0;
}
