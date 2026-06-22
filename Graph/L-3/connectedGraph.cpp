#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

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

void dfs(int node,unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbor:graph[node]){
         if(!(visited.count(neighbor))){
        dfs(neighbor,visited);
       }
    }
}

int connectedComponent(){
    int result=0;
    unordered_set<int> visited;
    for(int node=0;node<v;node++){   //node=0 is indexing of 1st node
       if(!(visited.count(node))){  //-->visited.find(node) == visited.end()
        result++;
        dfs(node,visited);
       }
    }
    return result;
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
    cout<<connectedComponent()<<"\n";
    return 0;
}
 
