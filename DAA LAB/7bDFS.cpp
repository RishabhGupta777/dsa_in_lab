#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v; // Number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

// DFS traversal
void dfs(int node) {
    visited.insert(node);
    for (auto neighbor : graph[node]) {
        if (!visited.count(neighbor)) {
            dfs(neighbor);
        }
    }
}

// Function to check if the graph is connectedi
bool isConnected() {
    visited.clear();
    
    // Start DFS from the first node (node 0)
    dfs(0);

    // If all vertices are visited, the graph is connected
    return (visited.size() == v);
}

int main() {
    cin >> v;
    graph.assign(v, list<int>());  // Initialize adjacency list

    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);  // Default is an undirected graph
    }

    if (isConnected()) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is NOT connected.\n";
    }

    return 0;
}
