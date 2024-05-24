#include <iostream>
using namespace std;
int KadaneAlgo(int arr[], int size){ // Time Complexity -> O(N)
    int currentMax = arr[0];
    int globalMax = arr[0];
    for (int i=1; i<size; i++){
        currentMax = max(arr[i], currentMax + arr[i]);
        globalMax = max(globalMax, currentMax);
    }
    return globalMax;
}
int main() {
//    int arr[] = {5,-8,1,2,-1,4};
    int arr[] = {-1,-2,-3,-4,-5,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maximumSubarraySum = KadaneAlgo(arr, size);
    cout << "The max subarray sum is: " << maximumSubarraySum << endl;
    return 0;
}
