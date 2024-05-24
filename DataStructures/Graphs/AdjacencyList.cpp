#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected
        // direction = 1 -> directed

        adjList[u].push_back(v);
        if (direction == 0){ // It's undirected
            adjList[v].push_back(u);
        }
    }
    void printAdjList(){
        for (auto i : adjList){
            cout << i.first << "->";
            for (auto j : i.second){
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    int n;
    cout << "Enter the number of Nodes:" << endl;
    cin >> n;
    int m;
    cout << "Enter the number of Edges:" << endl;
    cin >> m;

    Graph g;
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        // Create the undirected graph
        g.addEdge(u,v,false);
    }
    // Print the graph
    g.printAdjList();
    return 0;
}