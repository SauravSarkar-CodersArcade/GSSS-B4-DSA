#include <iostream>
using namespace std;
// We use a structure to store the elements of the Priority Queue
struct item {
    int value;
    int priority;
};
// Store the elements of the Priority Queue in an Array
item pr[100000];
// Pointer to the last index
int queueSize = -1; // Nothing is available in the PQueue

void enqueue(int key, int priority){
    // Increase the size of the PQueue
    queueSize++;
    pr[queueSize].value = key;
    pr[queueSize].priority = priority;
}
int peek(){ // View the element with the highest priority
    int highestPriority = INT_MIN;
    int ind = -1;
    // Checking for the element with the highest priority
    for (int i=0; i<=queueSize; i++){
        if (highestPriority == pr[i].priority && ind > -1
        && pr[ind].value < pr[i].value){
            highestPriority = pr[i].priority;
            ind = i;
        }
        if (highestPriority < pr[i].priority){
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
    return ind;
}
void dequeue(){ // Remove the element with highest/lowest priority
    int ind = peek();
    // Shift the elements to one index ahead
    for (int i=ind; i<queueSize; i++){
        pr[i] = pr[i+1];
    }
    // Decrease the size of the priority queue by 1 index
    queueSize--;
}
int main() {
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);

    // Store the top element
    int ind = peek();
    cout << pr[ind].value << endl;

    dequeue();

    ind = peek();
    cout << pr[ind].value << endl;
    return 0;
}
