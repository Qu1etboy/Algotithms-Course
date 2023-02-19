#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main() {
  int n, e, s;
  cin >> n >> e >> s;

  if (n <= 0 || e < 0 || s <= 0 || s > n) {
    cout << "What did you expect?" << endl;
    return 0;
  }

  // w, v
  vector<pair<int, int> > G[n];

  for (int i = 0; i < e; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u <= 0 || v <= 0 || v > n || u > n || w < 0) {
      cout << "What did you expect?" << endl;
      return 0;
    }
    if (u == v) {
      continue;
    }
    G[u - 1].push_back(make_pair(w, v - 1));
    G[v - 1].push_back(make_pair(w, u - 1));
  }

  priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  vector<int> visited(n);
  vector<int> dist(n, 1e8);
  // dist[s - 1] = 0;
  // for (auto v: G[s - 1]) {
  //   dist[v.second] = v.first;
  //   pq.push(v);
  // }  

  pq.push(make_pair(0, s - 1));
  dist[s - 1] = 0;

  while (!pq.empty()) {
    pair<int, int> u = pq.top();
    pq.pop();

    if (visited[u.second]) continue;
    // cout << u.second + 1 << endl;
    // dist += u.first;
    visited[u.second] = 1;
    for (auto v : G[u.second]) {
      // cout << v.second + 1 << endl;
      // dist[v.second] = min(v.first, dist[v.second]);
      if (!visited[v.second] && v.first < dist[v.second]) {
        // cout << u.second + 1 << " -> " << v.second + 1  << ", weight = " << v.first << endl;
        pq.push(v);
        dist[v.second] = v.first;
      }
    }
  }

  int total = 0;
  for (int i = 0; i < n; i++) {
    // cout << i+1 << ": " << dist[i] << endl;
    total += dist[i];
  }

  cout << total << endl;

}

// 1 2 6 3 8 
/*
6 8
1
1 3 4
1 2 4
2 3 2
3 4 3
3 6 4
4 6 3
5 3 2
5 6 3

9 12
1
1 2 7
1 9 15
2 3 5
3 5 2
3 4 4
3 7 3
5 4 1
4 6 9
6 7 5
6 8 12
7 9 6
9 8 10

4 5
2
1 2 1
1 3 2
2 3 3
2 4 4
3 4 5

6 10
2
1 2 3
2 3 1
3 4 6
4 5 8
5 1 6
1 6 5
2 6 4
3 6 4
4 6 5
5 6 2
*/