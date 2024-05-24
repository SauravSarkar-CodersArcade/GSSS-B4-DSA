#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
//    Node(int data){
//        this->data = data;
//        next = nullptr;
//    }
//    Node(int val) : data(val) , next(nullptr){}
};

void printListElements(Node* node){
    while (node != nullptr){
        cout << node->data << "->";
        node = node->next;
    }
    cout << "null" << endl;
}

void insertAtFront(Node** head, int newValue){
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    // Set the newNode next pointer to point to the head
    newNode->next = *head;
    // Move the head to the new node
    *head = newNode;
}

void insertAtEnd(Node** head, int newValue){
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = nullptr; // tail always points to null
    // If the linked list is empty, set the new node as the head
    // node starting node of the list
    if (*head == nullptr){
        *head = newNode;
        return;
    }
    Node* last = *head;
    // Traverse the list to reach the last node
    while (last->next != nullptr){
        last = last->next;
    }
    // Add the new node at the end of last node
    last->next = newNode;
}

void insertAfterSpecificNode(Node* previous, int newValue){
    // Check if the previous node is null
    if (previous == nullptr){
        cout << "Previous node cannot be a null pointer." << endl;
        return;
    }
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    // Insert the newNode after the previous node
    // Connect the previous node to the new node
    newNode->next = previous->next;
    previous->next = newNode;
}

void deleteFrontNode(Node** head){
    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the head...!!!" << endl;
        return;
    }
    // Temporary var to store the head
    Node* temp = *head;
    // Shift the head to the next node in the list
    *head = (*head)->next;
    // Delete the temporary var
    delete temp;
}

void deleteEndNode(Node** head){

    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the tail...!!!" << endl;
        return;
    }

    // Single Node
    if ((*head)->next == nullptr){
        delete *head;
        *head = nullptr;
        return;
    }

    // Multiple nodes
    // traverse to the end of the list & find the last node

    Node* last = *head;
    Node* secondLast = nullptr;

    while (last->next != nullptr){
        secondLast = last;
        last = last->next;
    }

    delete last;
    secondLast->next = nullptr;

}

void deleteSpecificNodeWithTargetValue(Node** head, int targetValue){

    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the node...!!!" << endl;
        return;
    }

    // Check if the target value is in the head node

    if ((*head)->data == targetValue){
        Node* temp = *head;
        (*head) = (*head)->next;
        delete temp;
        return;
    }

    // Two pointer approach
    Node* curr = *head;
    Node* prev = nullptr;

    while (curr != nullptr && curr->data != targetValue){
        prev = curr;
        curr = curr->next;
    }

    // Check if the target value is available in the list

    if (curr == nullptr){
        cout << "The target value was not found in the list." << endl;
        return;
    }

    // Delete the current node with the target value

    prev->next = curr->next;
    delete curr;
}

int main() {
    // Enter the elements o
    //
    // f the Linked List manually
//    Node* head = new Node();
//    head->data = 1;
//    Node* second = new Node();
//    second->data = 2;
//    head->next = second;
//    Node* third = new Node();
//    third->data = 3;
//    second->next = third;
//    third->next = nullptr; // 1->2->3->null

    Node* head = nullptr;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    int arr[] = {5,6,7};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i=0; i<size; i++){
        insertAtEnd(&head, arr[i]);
    }

    insertAfterSpecificNode(head, 2);
    insertAfterSpecificNode(nullptr, 3);

    cout << "List before deletion of head:" << endl;
    printListElements(head);

    deleteFrontNode(&head);

    cout << "List after deletion of head:" << endl;
    printListElements(head);

    cout << "List before deletion of tail:" << endl;
    printListElements(head);

    deleteEndNode(&head);

    cout << "List after deletion of tail:" << endl;
    printListElements(head);

    // Delete a target value from the list
    int targetValue;

    cout << "Enter a targetValue node to be deleted:" << endl;

    cin >> targetValue;

    cout << "After the deletion of the targetValue " <<
    targetValue << " from the list, new list: " << endl;

    deleteSpecificNodeWithTargetValue(&head, targetValue);

    printListElements(head);
    return 0;

}
