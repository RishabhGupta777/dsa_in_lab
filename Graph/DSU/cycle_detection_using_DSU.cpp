#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent, parent[x]);
}

bool Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a==b) return true;
    if (rank[a] < rank[b]) {
        rank[b]++;
        parent[a] = b;
    } else {
        rank[a]++;
        parent[b] = a;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // n -> elements
    //m represents the number of operations / edges (pairs) you are going to process that means number of pairs (x, y) you will input
    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    while (m--) {
            int x, y;
            cin >> x >> y;
        bool b=Union(parent, rank, x, y);
        if(b==true) cout << "cycle Detected";
    }
    return 0;
}

