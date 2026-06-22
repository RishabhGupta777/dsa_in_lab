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

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (auto el : graph[i]) {  //graph ke ith row ke list ke sare elwemet ko nikalo 
            cout << el << ", ";     //auto el automatically takes the type of elements inside graph[i]
        }
        cout << "\n";
    }
}

unordered_set<int> vis;
bool bfs(int source){
    queue<int>q;
    vector<int>parent(v,-1);
    vis.insert(source);
    q.push(source);
    while(!q.empty()){
        int curr=q.front();
        vis.insert(curr);
        q.pop();
        for(auto neighbor:graph[curr]){
       if(vis.count(neighbor) && parent[curr] != neighbor){ //<-- means cycle detected
        return true; 
       }
       if(!vis.count(neighbor)){
        vis.insert(source);
        q.push(neighbor);
        parent[neighbor]=curr;
       }
    }    
    }
    return false;
}
bool cycleDetection(){
    bool result=false;
    for(int i=0;i<v;i++){
        if(!vis.count(i)){
            result = bfs(i);
            if(result) return true;
        } 
    }
    return false;
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

    bool result=cycleDetection();
    cout<<result;
    if(result) cout<<"cycle Detected";
    else cout<<"cycle not Detected";

    return 0;
}
 