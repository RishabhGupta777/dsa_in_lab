#include<bits/stdc++.h>

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

void topoBFS(){ //kahn algo
    vector<int> indegree(v, 0);
    for(int i=0;i<v;i++){
        for(auto neighbor:graph[i]){
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    unordered_set<int> visited; //-->no need of this visited set due to 
//A node is pushed only when its indegree becomes 0
//Indegree is decremented exactly once per incoming edge
//Once indegree reaches 0, it cannot reach 0 again
//So the node will be pushed only once naturally

    for(int i=0;i<v;i++){
          if(indegree[i]==0){
            q.push(i);
          }
        }

        while(!q.empty()){
            int node=q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbor:graph[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
             q.push(neighbor);
        }

        }
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
        add_edge(s, d,false);
    }
    topoBFS();
    return 0;
}


//input 
// 8
// 11
// 0 2
// 1 2
// 1 3
// 2 3
// 2 4
// 2 6
// 2 5
// 3 5
// 4 6
// 5 6
// 6 7