#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> a;

  string l;
  getline(cin, l);

  istringstream ss(l);

  string tmp;
  while (ss >> tmp) {
    a.push_back(stoi(tmp));
  }

  // bubble sort (the easiest)
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a.size() - 1; j++) {
      if (a[j] > a[j + 1]) {
        int t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
      }
    }
  }

  for (int e : a) {
    cout << e << " ";
  }
  cout << endl;

}