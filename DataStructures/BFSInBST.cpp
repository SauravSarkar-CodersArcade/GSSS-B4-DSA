#include <iostream>
#include <queue>
using namespace std;
class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k){
        key = k;
        left = nullptr;
        right = nullptr;
    }
};
class BinarySearchTree {
private:
    TreeNode* root;
public:
    BinarySearchTree(){
        root = nullptr;
    }
    void insert(int key){
        root = insertNode(root, key);
    }
    TreeNode* insertNode(TreeNode* node, int key){
        if (node == nullptr){
            return new TreeNode(key);
        }
        if (key < node->key){
            node->left = insertNode(node->left, key);
        }else if (key > node->key){
            node->right = insertNode(node->right, key);
        }
        return node;
    }
    void bfsTraversal(){
        if (root == nullptr){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        cout << "BFS Traversal (BST): ";
        while (!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->left != nullptr){
                q.push(current->left);
            }
            if (current->right != nullptr){
                q.push(current->right);
            }
        }
        cout << endl;
    }
};
int main() {
    BinarySearchTree binarySearchTree;
    binarySearchTree.insert(50);
    binarySearchTree.insert(30);
    binarySearchTree.insert(70);
    binarySearchTree.insert(20);
    binarySearchTree.insert(40);
    binarySearchTree.insert(60);
    binarySearchTree.insert(80);
    binarySearchTree.bfsTraversal();
    return 0;
}
