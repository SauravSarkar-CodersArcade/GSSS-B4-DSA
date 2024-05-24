#include <iostream>
using namespace std;
class Stack {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(int data) {
        Node* newNode = new Node(data, top);
        if (newNode == nullptr){
            cout << "Stack Overflow..!!" << endl;
            exit(1);
        }
        top = newNode;
    }
    void print(){
        if (isEmpty()){
            cout << "Stack Underflow..!!" << endl;
            return;
        }
        Node* temp = top;
        cout << "The elements in the stack are: ";
        while (temp != nullptr){
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
    int pop(){
        if (isEmpty()){
            cout << "Stack Underflow..!!" << endl;
            exit(1);
        }
        int value = top->data;
        Node* del = top;
        top = top->next;
        delete del;
        return value;
    }
    bool isEmpty(){
//        if (top == nullptr){
//            return true;
//        }else{
//            return false;
//        }
        return top == nullptr;
    }
    int peek(){
        if (isEmpty()){
            cout << "Stack Underflow..!!" << endl;
            exit(1);
        }
        return top->data;
    }
};
int main() {
    Stack stack;
    int choice, data;
    while (true){
        cout << "\n1. Push:\n2.Pop:\n3.Print the top:\n4.Print all elements:\n5.Quit!!\n";
        cout << "Please enter the choice:" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the element to be pushed:";
                cin >> data;
                stack.push(data);
                break;
            case 2:
                cout << "The deleted element is " << stack.pop() << endl;
                break;
            case 3:
                cout << "The top element is " << stack.peek() << endl;
            case 4:
                stack.print();
                break;
            default:
                return 0;
        }
    }
}

