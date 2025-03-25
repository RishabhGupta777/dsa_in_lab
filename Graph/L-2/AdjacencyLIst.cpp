#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<list<int>> graph;
int v; // Number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    
    if (bi_dir) {  //for bidirectional graph[0].push_back(1);-->0 -> {1}, 1 -> {0} ,2 -> {}, 3 -> {},4 -> {}, 5 -> {}
        graph[src].push_back(dest); //src naam ke index pe dest ko list me dal do 
        graph[dest].push_back(src);    
    }
    else{  //for directional graph[0].push_back(1);-->0 -> {1}, 1 -> {} ,2 -> {}, 3 -> {},4 -> {}, 5 -> {}
        graph[src].push_back(dest);
    }
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto el : graph[i]) {  //graph ke ith row ke list ke sare elwemet ko nikalo 
            cout << el << ", ";     //auto el automatically takes the type of elements inside graph[i]
        }
        cout << "\n";
    }
}

int main() {
    cin >> v;
    graph.resize(v, list<int>());  //graph is resize as this graph = { {}, {}, {}, {}, {}, {} }
    
    int e;
    cin >> e;

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    display();

    return 0;
}
 