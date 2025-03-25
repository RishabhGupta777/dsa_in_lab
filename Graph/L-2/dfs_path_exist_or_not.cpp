#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v; // no of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

bool dfs(int curr, int end) {
    if (curr == end) return true;
    visited.insert(curr); // mark visited
    for (auto neighbour : graph[curr]) {
        if (not visited.count(neighbour)) {  //agar current ka jo neighbour visited na ho to uss
            bool result = dfs(neighbour, end);  //neighbour ko recurssion me call karawo
            if (result) return true;   //and jo dfs call lagaye the waha se true aa raha h to age bhi true return kar do jaga se call laga tha ye dfs function
        }
    }
    return false;  //agar current ka koi bhi neighbour aisa nahi mila jo visited na ho to false return kar do
}                  //that means cuurent ka sara neighbour vsited ho gya h to false return ka do

bool anyPath(int src, int dest) {
    return dfs(src, dest);
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());
    int e;
    cin >> e;
    visited.clear();
    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d, false);
    }
    int x, y;
    cin >> x >> y;
    cout << anyPath(x, y) << "\n";
    return 0; 
}
