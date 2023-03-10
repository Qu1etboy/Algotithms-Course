#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

int main() {
  int n;
  char c;

  cin >> n >> c;

  vector<pair<int, char > > adj[127];

  for (int i = 0; i < n; i++) {
    char c1, c2;
    int w;
    cin >> c1 >> w >> c2;

    adj[c1].push_back(make_pair(w, c2));
    adj[c2].push_back(make_pair(w, c1));

  }

  priority_queue<pair<int, char>, vector<pair<int, char> >, greater<pair<int, char> > > pq;
  int visited[127] = {};

  int key[127] = {};
  int parent[127] = {};

  for (int i = 0; i < 127; i++) {
    key[i] = INF;
  }

  pq.push(make_pair(0, c));

  while (!pq.empty()) {
    pair<int, char> u = pq.top();
    pq.pop();

    visited[u.second] = 1;

    for (auto v : adj[u.second]) {
      if (!visited[v.second] && v.first < key[v.second]) {
        pq.push(v);
        parent[v.second] = u.second;
        key[v.second] = v.first;
      }
    }

  }

  vector<pair<char, pair<char, int> > > out;

  for (char k = 'A'; k <= 'z'; k++) {
    if (parent[k]) {
      if (k < (char) parent[k]) {
        out.push_back(make_pair(k, make_pair(parent[k], key[k])));
        //  cout << k << " " <<  key[k] << " " << (char) parent[k] << endl;
      }
      else {
        out.push_back(make_pair(parent[k], make_pair(k, key[k])));
        // cout << (char) parent[k] << " " <<  key[k] << " " << k << endl;
      }
    }
  }

  sort(out.begin(), out.end());
 // " " << key[o.first] << " " <<

  int i = 0;
  for (auto o : out) {
    cout << o.first << " " << o.second.second << " " << o.second.first << endl;
  }

}

/*
10 a
a 3 b
b 1 c
c 6 d
c 4 A
A 4 b
a 5 A
e 6 a
A 2 e
d 8 e
d 5 A

*/