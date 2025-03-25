#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;

vector<list<pp>> gr;

void add_edge(int u, int v, int wt, bool bidir=true) {
    gr[u].push_back({v, wt});
    if (bidir) {
        gr[v].push_back({u, wt});  //gr-> graph
    }
}

unordered_map<int, int> dijkstra(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq; // {wt, node}
    unordered_set<int> visited;
    vector<int> via(n+1);
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        mp[i] = INT_MAX;               //map me sare jagah infinity bharne ke liye
    }
    
    pq.push({0, src});        //initially priority queue me (0,0) ko push kar do
    mp[src] = 0;              //map me src[0] ka khud se distance=0 so key value pair stores in map is(0,0)
    
    while (!pq.empty()) {
        pp curr = pq.top();  
        if (visited.count(curr.second)) {    //curr.second represents the current node extracted from the priority queue; queue me ye (dist,node) store hota tha na to usme se node ko dekho ki wo viste ho to ye karo
            pq.pop();    //If the node has already been visited, it is removed from the priority queue (pq.pop()) and skipped (continue;).
            continue;
        }             //The continue statement skips the remaining code in the current iteration of the while loop.
                      //Control jumps directly to the next iteration of the while (!pq.empty()) loop.
        
        
        pq.pop();    //priority me se pop karne time visited mark karenge ; bur priority queue me salte samay visited mark nahi karna h
        visited.insert(curr.second);  //iss line ko pq.pop ke uper bhi likh sakte h baat to wahi rahega ki priority queue se pop karte time visited mark kar diye
        
        for (auto neighbour : gr[curr.second]) {    //jo queue se nikale h let(7,6) then 6 ke sare neighbour jo visite nahi h, ko ek ek karke dekhenge
            if (!visited.count(neighbour.first) && mp[curr.second] + neighbour.second < mp[neighbour.first]) {   //mp[neighbour.first-->means source se pahle neighbour ka ditance in map
                //pahle neighbour jo visited nahi h && second=distance ; mp.(curr.second)-->source se current ka kya distance h + neighbour.second--> current node se uske neighbour ka distance
                pq.push({mp[curr.second] + neighbour.second, neighbour.first}); //queue me push karo ( (source se currnt ka distance + current node se uske neighbour ka distance) )
                via[neighbour.first] = curr.second;    
                mp[neighbour.first] = mp[curr.second] + neighbour.second;   //map me uss neighbour ke row me abhi ka distance store kara do
            }
        }
    }
    
    return mp;
}

int main() {
    int n, m;   //n-->no . of vertex , m-->no. of Edges 
    cin >> n >> m;    
    gr.resize(n, list<pp>());
    while (m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        add_edge(u, v, wt);
    }
    int src;
    cin >> src;
    unordered_map<int, int> sp = dijkstra(src, n);
    
    for (auto p : sp) {
        cout << p.first << " " << p.second << "\n";
    }
    int dest;
    cin >> dest;
    cout << sp[dest] << "\n";
    return 0;
}
 