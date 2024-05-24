#include <iostream>
#include <map>
#include <list>
using namespace std;
class Graph {
public:
    map<int, bool> visited; // Nodes visited
    map<int, list<int>> adj; // Storing the adj list

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // Function for the DFS traversal
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    // Add w to the adj -> list of v
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
    // Recursive call for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for ( i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            DFS(*i);
        }
    }
}
int main() {
    // Create a graph
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);


    cout << "Following is the Depth First Traversal"
            "(starting from vertex/node 0):\n";
    g.DFS(0);
    return 0;
}
