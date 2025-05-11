#include <iostream>
using namespace std;

class Graph {
    public:
        int adj[10][10];  // Adjacency matrix for storing graph (for up to 10 nodes)
        int visited[10];   // Array to track visited nodes

        // DFS function
        void DFS(int node, int n) {
            visited[node] = 1;  // Mark the node as visited
            cout << node << " ";    // Print the node (or process it)

            // Explore all adjacent nodes
            for (int i = 0; i < n; i++) {
                if (adj[node][i] == 1 && !visited[i]) {  // Check if there's an edge and if the node is not visited
                    DFS(i, n);  // Recursively visit unvisited neighbors
                }
            }
        }

        // Function to add edges to the graph
        void addEdge(int u, int v) {
            adj[u][v] = 1;
            adj[v][u] = 1;  // Assuming undirected graph
        }

        // Initialize visited array (not visited yet)
        void initVisited(int n) {
            for (int i = 0; i < n; i++) {
                visited[i] = 0;  // Mark all nodes as not visited
            }
        }
};

int main() {
    Graph g;

    int n = 5;  // Number of nodes in the graph

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.initVisited(n);

    cout << "DFS Traversal: ";
    g.DFS(0, n);  // Start DFS from node 0
    cout << endl;

    return 0;
}