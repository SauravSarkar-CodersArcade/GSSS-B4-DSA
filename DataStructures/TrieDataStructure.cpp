#include <iostream>
#include <vector>
using namespace std;
class TrieNode {
public:
    TrieNode* childNode[26];
    bool wordEnd;
    TrieNode(){
        // Make the wordEnd variable by default false
        // If we insert a word, then this will become true
        wordEnd = false;
        // Initialize all the child nodes to nullptr
        for (int i=0; i<26; i++){
            childNode[i] = nullptr;
        }
    }
};
void insert_Key(TrieNode* root, string& key){
    // Initialize the currentNode to the root node
    TrieNode* currentNode = root;
    for (auto c : key){
        if (currentNode->childNode[c-'a'] == nullptr){
            // It doesn't exist, create a new node
            TrieNode* newNode = new TrieNode();
            // Add the new node as a new child
            currentNode->childNode[c-'a'] = newNode;
        }
        // Now, mode the current node pointer to the newly
        // created node
        currentNode = currentNode->childNode[c-'a'];
        // Go to the next index in the word
        // Finally, we insert a string as a new key into the trie
        // Update the wordEnd to true
        currentNode->wordEnd = 1;
    }
}
bool search_key(TrieNode* root, string& key){
    TrieNode* currentNode = root;
    for (auto c : key){
        if (currentNode->childNode[c-'a'] == nullptr){
            // Given word doesn't exist in the Trie
            return false;
        }
        // Traverse to the next childNode
        currentNode = currentNode->childNode[c-'a'];
    }
    return currentNode->wordEnd;
}
int main() {
    TrieNode* root = new TrieNode();
    vector<string> inputData
    = {"arm", "arena", "aryan", "arjun"};
    int n = inputData.size();

    for (int i=0; i<n; i++){
        insert_Key(root, inputData[i]);
    }
    vector<string> searchData
    = {"arm", "gsss", "python","arena", "aryan", "java", "arjun"};

    for (int i=0; i<searchData.size(); i++){
        if (search_key(root, searchData[i])){
            cout << searchData[i] << " is available in the Trie." << endl;
        }
        else{
            cout << searchData[i] << " is not available in the Trie." << endl;
        }
    }
    cout << endl;
    return 0;
}
