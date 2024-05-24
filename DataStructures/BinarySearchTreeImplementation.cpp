#include <iostream>
using namespace std;
class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }
};
class BST {
private:
    Node* root;
    // Insert Function
    Node* insertRec(Node* root, int key){
        // Root is null, make the key as the root
        if (root == nullptr){
            root = new Node(key);
            return root;
        }
        // Compare with the value of root & either traverse
        // left or right depending on the condition & use recursion
        if (key < root->key){
            root->left = insertRec(root->left, key);
        }else if (key > root->key){
            root->right = insertRec(root->right, key);
        }
        return root;
    }
    bool searchRec(Node* root, int key){
        if (root == nullptr){
            return false;
        }
        if (root->key == key){
            return true;
        }else if (key < root->key){
            return searchRec(root->left, key);
        }else{
            return searchRec(root->right, key);
        }
        return false;
    }
    void inOrderRec(Node* root){ // LDR
        if (root != nullptr){
            inOrderRec(root->left);
            cout << root->key << " ";
            inOrderRec(root->right);
        }
    }
    Node* findMin(Node* node){
        Node* current = node;
        while (current && current->left != nullptr){
            current = current->left;
        }
        return current;
    }
    Node* deleteRec(Node* root, int key){
        if (root == nullptr){
            return root;
        }
        if (key < root->key){
            root->left = deleteRec(root->left, key);
        }else if (key > root->key){
            root->right = deleteRec(root->right, key);
        }else{
            // Node to be deleted has been found
            // Case 1: No child or 1 child
            if (root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }else if (root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 2: Node with 2 children
            // Finding inOrder successor to maintain BST properties
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteRec(root->right, temp->key);
        }
        return root;
    }
public:
    BST(){
        root = nullptr;
    }
    void insert(int key){
        root = insertRec(root, key);
    }
    bool search(int key){
        return searchRec(root, key);
    }
    void remove(int key){
        root = deleteRec(root, key);
    }
    void inOrderTraversal(){
        inOrderRec(root);
        cout << endl;
    }
};
int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    cout << "InOrder Traversal of the given BST:" << endl;
    bst.inOrderTraversal();

    int key1 = 60;
    if (bst.search(key1)){
        cout << key1 << " is found in the BST." << endl;
    }else{
        cout << key1 << " is not found in the BST." << endl;
    }
    int key2 = 90;
    if (bst.search(key2)){
        cout << key2 << " is found in the BST." << endl;
    }else{
        cout << key2 << " is not found in the BST." << endl;
    }
    int key3 = 30;
    bst.remove(key3);
    cout << "InOrder traversal after removing " << key3 << endl;
    bst.inOrderTraversal();
    return 0;
}
