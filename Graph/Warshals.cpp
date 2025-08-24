#include <iostream>
using namespace std;

const int V = 4; // Number of vertices

void warshall(bool graph[V][V]) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                //this line also can be written 
                //if (graph[i][k] && graph[k][j]) { -->graph[i][k]==1 ya true && graph[k][j]==1 ya true ha to
                        // graph[i][j] = 1;
                //}
            }
        }
    }
}

void printGraph(bool graph[V][V]) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    bool graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };  

    warshall(graph);

    cout << "Transitive closure (reachability matrix):\n";
    printGraph(graph);

    return 0;
}