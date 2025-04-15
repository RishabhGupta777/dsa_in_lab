#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const int INF = 1e9;

// Distance matrix (change this to test different graphs)
vector<vector<int>> dist = {
    {0, 29, 20, 21},
    {29, 0, 15, 17},
    {20, 15, 0, 28},
    {21, 17, 28, 0}
};

int n = dist.size(); // Number of cities

// OPTIMAL SOLUTION (Brute Force using permutations) 
int tspBruteForce() {
    vector<int> nodes;
    for (int i = 1; i < n; i++) 
        nodes.push_back(i);

    int min_path = INF;
    do {
        int current_cost = 0;
        int k = 0;
        for (int i = 0; i < nodes.size(); i++) {
            current_cost += dist[k][nodes[i]];
            k = nodes[i];
        }
        current_cost += dist[k][0]; // return to start
        min_path = min(min_path, current_cost);
    } while (next_permutation(nodes.begin(), nodes.end()));

    return min_path;
}

//  APPROXIMATE SOLUTION (Nearest Neighbor)
int tspNearestNeighbor() {
    vector<bool> visited(n, false);
    int cost = 0;
    int current = 0;
    visited[current] = true;

    for (int i = 0; i < n - 1; i++) {
        int next = -1;
        int min_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current][j] < min_dist) {
                min_dist = dist[current][j];
                next = j;
            }
        }

        visited[next] = true;
        cost += min_dist;
        current = next;
    }

    cost += dist[current][0]; // return to start
    return cost;
}


int main() {
    int optimal = tspBruteForce();
    int approx = tspNearestNeighbor();

    cout << "Optimal TSP cost (Brute Force): " << optimal << endl;
    cout << "Approximate TSP cost (Nearest Neighbor): " << approx << endl;

    double error = ((double)(approx - optimal) / optimal) * 100.0;
    cout << "Approximation Error: " << error << "%" << endl;

    return 0;
}
