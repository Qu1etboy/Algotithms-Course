#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  vector<string> str_c, str_n;
  vector<int> c;

  string l, l2;
  getline(cin, l);

  istringstream ss(l);

  string tmp;
  while (ss >> tmp) {
    str_c.push_back(tmp);
  }

  for (int i = 1; i < str_c.size(); i++) {
    c.push_back(stoi(str_c[i]));
  }

  for (int e : c) {
    if (e < 0) {
      cout << "Just because a thing can be done, does not mean that it should be done." << endl;
      return 0;
    }
  }

  getline(cin, l2);

  istringstream ss2(l2);

  string tmp2;
  while (ss2 >> tmp2) {
    str_n.push_back(tmp2);
  }

  int n = stoi(str_n[1]);

  sort(c.begin(), c.end(), greater<int>());

  for (int i = 0; i < c.size(); i++) {
    cout << c[i] << ": " << n / c[i] << endl;
    n = n % c[i];
  }

  if (n > 0) {
    cout << "Change: " << n << endl;
  }

}

// Cash:42
// Coins: 1
// Cash:19
// Change: 4