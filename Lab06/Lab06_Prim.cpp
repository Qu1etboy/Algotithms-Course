// Thank you @ong22280 for the solution 🙏

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;

/*
Prim's algorithm function
s = starting village
n = number of villages
adj = adjacency list
*/
int prim(int s, int n, vector<pair<int, int> > adj[]) {
    int cost = 0;
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    // start at starting village
    pq.push(make_pair(0, s));
    key[s] = 0;
    // while there are still villages to visit
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        // if the village has already been visited, skip it
        if (mst[u]) continue;
        // otherwise, add the cost of the path to the total cost
        cost += key[u];
        // mark the village as visited
        mst[u] = true;
        // for each path from the current village
        for (auto x : adj[u]) {
            // if the path has not been visited and the path is shorter than the current shortest path
            if (!mst[x.first] && key[x.first] > x.second) {
                // update the shortest path
                key[x.first] = x.second;
                // add the path to the priority queue
                pq.push(make_pair(key[x.first], x.first));
            }
        }
    }
    return cost;
}

int main() {
    /*
    n = number of villages
    v = number of paths
    w = weight
    s = starting village
    */
    int n, v, w, s;
    cin >> n >> v;
    
    cin >> s;
    // catch invalid input
    if (n <= 0 || v < 0) {
        cout << "What did you expect?" << endl;
        return 0;
    }

    vector<pair<int, int> > adj[n+1]; // adjacency list
    // add edges and weights to adjacency list
    for (int i = 0; i < v; i++) {
        int a, b;
        cin >> a >> b >> w;
        // catch invalid input
        if (a < 1 || a > n || b < 1 || b > n || w < 0) {
            cout << "What did you expect?" << endl;
            return 0;
        }
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    cout << prim(s, n, adj) << endl;
    return 0;
}