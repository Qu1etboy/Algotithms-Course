#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int > &a,
              const pair<string, int > &b) {
  return a.second > b.second;
}

int main() {
  string l;
  getline(cin, l);

  map<char, int> freq;
  map<char, string> out;
  vector<pair<string, int> > count;

  for (char c : l) {
    freq[(char)tolower(c)]++;
  } 

  for (char c : l) {
    if (freq[(char)tolower(c)]) {
      string s(1, (char)tolower(c));
      // cout << s << endl;
      count.push_back(make_pair(s, freq[(char)tolower(c)]));
      freq.erase((char)tolower(c));
    }
  }

  while (count.size() > 1) {
    
    for (int i = 0; i < count.size(); i++) {
      for (int j = 0; j < count.size() - 1; j++) {
        if (compare(count[j], count[j + 1])) {
          swap(count[j], count[j + 1]);
        }
      }
    }

    for (char c : count[0].first) {
      // cout << c << endl;
      out[c] = "0" + out[c];
    }
    for (char c : count[1].first) {
      out[c] = "1" + out[c];
    }
    
    pair<string, int> p = make_pair(count[0].first + count[1].first, count[0].second + count[1].second);
    count[0] = p; 

    count.erase(count.begin() + 1);
    
  }

  for (char c : l) {
    cout << out[(char)tolower(c)];
  }
  cout << endl;
}

// 11001111010111101101011001110000010
// 11001111010111101101011001110000010