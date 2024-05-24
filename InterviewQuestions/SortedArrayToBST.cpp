#include <iostream>
using namespace std;
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* newNode(int data){
    TreeNode* node = new TreeNode();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
TreeNode* sortedArrayToBinarySearchTree(int arr[], int start, int end){
    if (start > end){
        return nullptr;
    }
    int mid = (start + end)/2;
    TreeNode* root = newNode(arr[mid]);
    root->left = sortedArrayToBinarySearchTree(arr, start, mid-1);
    root->right = sortedArrayToBinarySearchTree(arr, mid+1, end);
    return root;
}

void preOrderTraversal(TreeNode* node){
    if (node == nullptr){
        return;
    }
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    TreeNode* root = sortedArrayToBinarySearchTree(
            arr, 0, size-1);
    cout << "PreOrderTraversal Of Sorted Array To Binary Search Tree: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}
