#include <iostream>
using namespace std;
struct Node{

};
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
void preOrder(TreeNode* root){ // DLR
    if (root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(TreeNode* root){ // LDR
    if (root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(TreeNode* root){ // LRD
    if (root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
TreeNode* mirrorTree(TreeNode* root){
    // Base case 1: If root is null, no mirror is possible. Return null
    if (root == nullptr){
        return nullptr;
    }
    // take a temporary node and swap the left and right subtree
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Check for individual subtrees & recursively swap them
    if (root->left){
        mirrorTree(root->left);
    }
    if (root->right){
        mirrorTree(root->right);
    }
    return root;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
//    root->left->left->left = new TreeNode(8);
//    root->left->right->right = new TreeNode(9);
//    root->right->right->right = new TreeNode(10);
//    cout << "PreOrder: " << endl;
//    preOrder(root);
//    cout << endl;
//    cout << "InOrder: " << endl;
//    inOrder(root);
//    cout << endl;
//    cout << "PostOrder: " << endl;
//    postOrder(root);
//    cout << endl;
    cout << "InOrder of Original Tree: " << endl;
    inOrder(root);
    cout << endl;
    root = mirrorTree(root);
    cout << "InOrder of Mirror Tree: " << endl;
    inOrder(root);
    return 0;
}
