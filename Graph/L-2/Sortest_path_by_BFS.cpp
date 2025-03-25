#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v; // Number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void bfs(int src, int dest, vector<int> &dist) {
    queue<int> qu;  //queue bana lo
    visited.clear();
    dist.resize(v, INT_MAX);   //distance naam ke vector ke harek element me infinte bhar do
    dist[src] = 0;    // pahle element jo source h distance vector ka usko 0 rakh do
    visited.insert(src);  //yha dfs ki tarah element bharne ke baad nahi,queue me element bharne se pahle hi visited me store kara do source ko 
    qu.push(src);    //now source ko queue me dalo

    while (!qu.empty()) {   //jab tak queue khali na ho
        int curr = qu.front();  //queue ke front me jo uper src dale the use 
        qu.pop();   //ab usko nikal do queue me se aur uske neighbour ko queue me dalo dekho niche for() se

        for (auto neighbour : graph[curr]) {
            if (!visited.count(neighbour)) {  
                qu.push(neighbour);    //jo neighbour visited nahi usko dalo queue me 
                visited.insert(neighbour);  //visited me bhi dalo
                dist[neighbour] = dist[curr] + 1; //dist vector ke neigbour naam ke index pe distance[of curr] se 1 jyada dist hoga na
            }
        }
    }
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
        add_edge(s, d);
    }

    int x, y;
    cin >> x >> y;
    vector<int> dist;
    bfs(x, y, dist);

    for (int i = 0; i < dist.size(); i++) {
        cout<<"distance of "<< i<<" from 0:" << dist[i] << endl;
    }

    return 0;
}
