#include <iostream>
using namespace std;

void primMST(int graph[3][3]) {
    int parent[3];  // Stores MST edges
    int key[3];     // Stores minimum edge weights
    bool mstSet[3]; // Tracks selected vertices

    // Initialize keys to a high value and mstSet to false
    for (int i = 0; i < 3; i++) {
        key[i] = 10000;
        mstSet[i] = false;
    }

    key[0] = 0;      // Start from the first node
    parent[0] = -1;  // Root node

    for (int count = 0; count < 2; count++) {  // Loop runs V-1 times
        int minIndex = -1;
        for (int v = 0; v < 3; v++) {
            if (!mstSet[v] && (minIndex == -1 || key[v] < key[minIndex])) {
                minIndex = v;
            }
        }
       
        mstSet[minIndex] = true;

        for (int v = 0; v < 3; v++) {
            if (graph[minIndex][v] != 0 && !mstSet[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < 3; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int graph[3][3] = {
        {0, 2, 3},
        {2, 0, 1},
        {3, 1, 0}
    };

    primMST(graph);
    return 0;
}
