#include <iostream>
using namespace std;
class Node {
private:
    int data;
    int priority;
    Node* next;
public:
    Node(int d, int p){
        data = d;
        priority = p;
        next = nullptr;
    }
    // Getter for the data
    int getData(){
        return data;
    }
    // Getter for the priority
    int getPriority(){
        return priority;
    }
    // Getter for the next node
    Node* getNext(){
        return next;
    }
    // Setter for the next node
    void setNext(Node* node){
        next = node;
    }

};
// Function for a new node
Node* newNode(int d, int p){
    return new Node(d, p);
}
// Peek function to return the value at head
int peek(Node** head){
    return (*head)->getData();
}
// pop function to remove the highest priority element from the list
void pop(Node** head){
    Node* temp = *head;
    (*head) = (*head)->getNext();
    delete temp;
}
// Function to store/push/add an element
void push(Node** head, int d, int p){
    Node* start = *head;
    Node* temp = newNode(d, p);
    if ((*head)->getPriority() < p){
        temp->setNext(*head);
        (*head) = temp;
    }else{
        while (start->getNext() != nullptr &&
               start->getNext()->getPriority() > p){
            start = start->getNext();
        }
        temp->setNext(start->getNext());
        start->setNext(temp);
    }

}
bool isEmpty(Node** head){
    return (*head) == nullptr;
}
int main() {
    Node* pq = newNode(4,1);
    push(&pq, 5,2);
    push(&pq, 6,3);
    push(&pq, 7,0);
    while (!isEmpty(&pq)){
        cout << " " << peek(&pq);
        pop(&pq);
    }
    return 0;
}
