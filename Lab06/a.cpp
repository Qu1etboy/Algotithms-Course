#include <iostream>
#include <cctype>
#include <map>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Compare {
public:
    bool operator()(pair<int, vector<char> > below, pair<int, vector<char> > above)
    {
        if (below.first > above.first) {
            return true;
        }

        return false;
    }
};

void insert(vector<char> c1, vector<char> c2, map<char, string> &out) {
  for (char c : c1) {
    cout << c << " ";
    out[c] += "0";
  }
  cout << " | ";
  for (char c : c2) {
    cout << c << " ";
    out[c] += "1";
  }
    cout << endl;
}

int main() {
  string s;
  getline(cin, s);

  map<char, int> freq;
  map<char, string> out;
  priority_queue<pair<int, vector<char> >, vector<pair<int, vector<char> > >, Compare> pq;
  queue<vector<char> > q;

  for (int i = 0; i < s.size(); i++) {
    freq[tolower(s[i])]++;
  }

  // insert to priority queue
  for (auto x : s) {
    if (!freq[tolower(x)]) {
      continue;
    }

    vector<char> c;
    c.push_back(tolower(x));
    pq.push(make_pair(freq[tolower(x)], c));
    q.push(c);
    cout << x << " : " << freq[tolower(x)] << endl;
    freq.erase(tolower(x));
  }

  // while (!pq.empty()) {
  //   pair<int, vector<char> > c1 = pq.top();
  //   cout << c1.second[0] << " : " << c1.first << endl;
  //   pq.pop();
  // }

  while (!pq.empty()) {
    pair<int, vector<char> > c1 = pq.top();
    // vector<char> lc1 = q.front();
    pq.pop();
    // q.pop();
    
    if (pq.empty()) {
      break;
    }

    pair<int, vector<char> > c2 = pq.top();
    // vector<char> lc2 = q.front();
    pq.pop();
    // q.pop();
    
    if (c1.first <= c2.first) {
      insert(c1.second, c2.second, out);
    } else {
      insert(c2.second, c1.second, out);
    }

    int merge = c1.first + c2.first;

    cout << c1.first << " " << c2.first << endl;

    vector<char> cc;

    for (char c : c1.second) {
      cc.push_back(c);
    }
    for (char c : c2.second) {
      cc.push_back(c);
    }

    pq.push(make_pair(merge, cc));
    // q.push(cc);

  }

  for (auto i : out) {
    reverse(i.second.begin(), i.second.end());
    cout << i.first << " : " << i.second << endl;
  }
}