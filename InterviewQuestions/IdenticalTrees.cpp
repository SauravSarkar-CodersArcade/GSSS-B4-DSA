#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val) , left(nullptr) , right(nullptr) {}
};
bool areIdentical(Node* tree1, Node* tree2){
    // If they are identical
    // 1. Both are empty
    if (tree1 == nullptr && tree2 == nullptr){
        return true;
    }
    // Any one of them is null
    if (tree1 == nullptr || tree2 == nullptr){
        return false;
    }
    // Compare the root data
    if (tree1->value != tree2->value){
        return false;
    }
    return (areIdentical(tree1->left, tree2->left)
         && areIdentical(tree1->right, tree2->right));

}
void identifyAndCutDownTrees(Node* tree1, Node* tree2){
    if (areIdentical(tree1, tree2)){
        cout << "Trees are identical, cut them down." << endl;
    }else{
        cout << "Trees are not identical, continue searching." << endl;
    }
}
int main() {
    Node* t1 = new Node(5);
    t1->left = new Node(6);
    t1->right = new Node(7);

    Node* t2 = new Node(5);
    t2->left = new Node(8);
    t2->right = new Node(7);

    identifyAndCutDownTrees(t1, t2);
    return 0;
}
