#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
  vector<int> a;
  int n = 0;

  string l;
  getline(cin, l);

  istringstream ss(l);

  string tmp;
  while (ss >> tmp) {
    a.push_back(stoi(tmp));
    n++;
  }

  map<int,int> count;

  for (int e : a) {
    count[e]++;
  }

  for (int e : a) {
    if (count[e] > n / 2) {
      cout << e << endl;
      return 0;
    }
  }

  cout << "Balance (T-T)" << endl;
}