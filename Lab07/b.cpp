#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int m, n = 0, ok = 0;

void subset(int k, vector<int> p) {
  if (k == p.size()) {
    if (n == m) {
      ok = 1;
    }
    return;
  }

  n += p[k];
  subset(k + 1, p);
  n -= p[k];
  subset(k + 1, p);
}

int main() {

  string l;
  vector<string> str_c;
  vector<int> p;

  getline(cin, l);

  istringstream ss(l);

  string tmp;
  while (ss >> tmp) {
    p.push_back(stoi(tmp));
  }

  cin >> m;

  // cout << m + 1;

  subset(0, p);

  cout << (ok ? "Yes" : "No") << endl;


}
