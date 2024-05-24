#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int vertices){
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    void addEdge(int u, int v){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    void printAdjMatrix(){
        cout << "Adjacency Matrix: " << endl;
        for (int i=0; i<V; i++){
            for (int j=0; j<V; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    // Create the graph with 5 vertices
    Graph graph(5);
    // Add the edges
    graph.addEdge(0,2);
    graph.addEdge(0,1);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    graph.printAdjMatrix();
    return 0;
}
