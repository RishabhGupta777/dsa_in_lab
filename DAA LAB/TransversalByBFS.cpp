#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;
int v; // Number of vertices

void add_edge(int src, int dest) {
    graph[src].push_back(dest); // Directed edge
}

void bfs(int start) {
    queue<int> qu;
    unordered_set<int> visited;
    
    visited.insert(start);
    qu.push(start);
    
    cout << "Nodes reachable from " << start << ": ";
    
    while (!qu.empty()) {
        int curr = qu.front();
        qu.pop();
        cout << curr << " ";
        
        for (auto neighbour : graph[curr]) {
            if (!visited.count(neighbour)) {
                qu.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
    cout << endl;
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());
    
    int e;
    cin >> e;
    
    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }
    
    int start;
    cin >> start;
    bfs(start);
    
    return 0;
}
