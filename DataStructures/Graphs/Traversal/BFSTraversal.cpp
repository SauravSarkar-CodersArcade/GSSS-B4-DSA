#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Function for BFS Traversal
vector<int> bfsTraversal(int n, const vector<vector<int>>&
adjacencyList) {
    // Vector to keep track of the visited nodes
    vector<bool> visited(n, false);
    // Vector to store the output
    vector<int> traversalOrder; // answer_vector
    // Queue for the push & pop operations
    queue<int> q;

    // Start from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()){
        int curr = q.front();
        q.pop();
        traversalOrder.push_back(curr);

        // Traverse all the neighbours of the current front node
        for (int neighbor : adjacencyList[curr]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return traversalOrder;
}
int main() {
    int n, m;
    cin >> n >> m; // Number of vertices (n) & edges (m)

    vector<vector<int>> adjacencyList(n);
    // Read the edges and construct the adjacency list
    for (int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adjacencyList[u].push_back(v); // Directed
        adjacencyList[v].push_back(u); // Undirected
    }
    // Perform the BFS traversal starting from vertex 0
    vector<int> result = bfsTraversal(n, adjacencyList);

    for (int node : result){
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
