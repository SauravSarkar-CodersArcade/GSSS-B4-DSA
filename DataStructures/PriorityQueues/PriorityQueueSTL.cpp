#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    // Deletion Complexity -> Constant O(1)
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    cout << "Max-Heap: ";
    while (!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // MinHeap using the greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(5);

    cout << "Min-Heap: ";
    while (!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
    return 0;
}
