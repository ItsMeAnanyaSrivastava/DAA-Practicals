#include <iostream>
#include <queue>
using namespace std;

class Graph {
    public:
        int adj[10][10];  // Adjacency matrix for storing graph (for up to 10 nodes)
        int visited[10];   // Array to track visited nodes

        // BFS function
        void BFS(int start, int n) {
            queue<int> q;  // Queue for BFS
            visited[start] = 1;  // Mark the start node as visited
            q.push(start);  // Enqueue the start node

            while (!q.empty()) {
                int node = q.front();  // Get the front element
                cout << node << " ";    // Print the node (or process it)
                q.pop();  // Dequeue the node

                // Enqueue all unvisited adjacent nodes
                for (int i = 0; i < n; i++) {
                    if (adj[node][i] == 1 && !visited[i]) {
                        visited[i] = 1;
                        q.push(i);  // Enqueue the unvisited neighbor 
                    }
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

    cout << "BFS Traversal: ";
    g.BFS(0, n);  // Start BFS from node 0
    cout << endl;

    return 0;
}
