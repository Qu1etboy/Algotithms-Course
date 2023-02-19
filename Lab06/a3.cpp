#include <iostream>
#include <cctype>
#include <map>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

string s;

bool compare(const pair<int, string > &a,
              const pair<int, string > &b) {
  return a.first > b.first;
}

void insert(string c1, string c2, map<char, string> &out) {
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
  // string s;
  getline(cin, s);

  map<char, int> freq;
  map<char, string> out;
  vector<pair<int, string > > v;
  priority_queue<int, vector<int>, greater<int> > pq;
  map<string, int> cf;

  for (int i = 0; i < s.size(); i++) {
    freq[tolower(s[i])]++;
  }

  // insert to priority queue
  for (auto x : s) {
    if (!freq[tolower(x)]) {
      continue;
    }

    string c = "";
    c += tolower(x);
    // c.push_back(tolower(x));    
    v.push_back(make_pair(freq[tolower(x)], c));
    // cf[c] += freq[tolower(x)];
    // pq.push(freq[tolower(x)]);
    // cout << x << " : " << freq[tolower(x)] << endl;
    freq.erase(tolower(x));
  }

  // sort(v.begin(), v.end(), compare);

  // for (auto e : v) {
  //   cout << e.second << " : " << e.first << endl;
  // }


  while (!pq.empty()) {
    
    // sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v.size() - 1; j++) {
        if (compare(v[j], v[j + 1])) {
          swap(v[j], v[j + 1]);
        }
      }
    }
  
    int f1 = pq.top();
    pq.pop();
    // pair<int, string > c1;
    // v.erase(v.begin());

    if (pq.empty()) {
      break;
    }

    int f2 = pq.top();
    pq.pop();

    // pair<int, string > c2;
    // v.erase(v.begin());

    string c1;
    string c2;

    int k = 0;

    for (auto c : v) {
      if (f1 == c.first) {
        c1 = c.second;
        v.erase(v.begin() + k);
        break;
      }
      k++;
    }

    k = 0;

    for (auto c : v) {
      if (f2 == c.first) {
        c2 = c.second;
        v.erase(v.begin() + k);
        break;
      }
      k++;
    }
    
    if (f1 <= f2) {
      insert(c1, c2, out);
    } else {
      insert(c2, c1, out);
    }

    int merge = f1 + f2;

    // cout << c1.first << " " << c2.first << endl;

    string cc;

    for (char c : c1) {
      cc += c;
    }
    for (char c : c2) {
      cc += c;
    }

    v.push_back(make_pair(merge, cc));

    // cf[cc] += merge;
    pq.push(merge);

  }

  for (auto i : out) {
    reverse(i.second.begin(), i.second.end());
    cout << i.first << " : " << i.second << endl;
  }
}