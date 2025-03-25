#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v; // number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int end, vector<int> &path) {
    if (curr == end) {  //base condition
        path.push_back(curr); //current ko path me dal lo
        result.push_back(path);  //result me path ko dal to taki ek path store ho jaye
        path.pop_back();   //ab path ko result me store kara liya to ney path ke liye path ko pop kardo
        return;
    }

    visited.insert(curr); // mark visited
    path.push_back(curr); 

    for (auto neighbour : graph[curr]) {
        if (not visited.count(neighbour)) {
            cout << neighbour << "\n";  //not needed to print
            dfs(neighbour, end, path);
        }
    }

    path.pop_back();   //current node ko purane path se bhi hata do  taki naye path ka hissa ban sake 
    visited.erase(curr);  //current node lo visited se hata dete h ki wo kisi aur path ka baad me hissa ban paye
    return;
}

void allPath(int src, int dest) {
    vector<int> path;
    dfs(src, dest, path);
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
    allPath(x, y);

    for (auto path : result) {
        for (auto el : path) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}
