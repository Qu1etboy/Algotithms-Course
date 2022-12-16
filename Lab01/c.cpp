#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<int> ans, n, m;
  // read input
  string l1, l2;
  getline(cin, l1);
  getline(cin, l2);

  // split string by space
  istringstream ss1(l1);
  istringstream ss2(l2);

  string n1, n2;

  while (ss1 >> n1) {
    n.push_back(stoi(n1));
  }
  while (ss2 >> n2) {
    m.push_back(stoi(n2));
  }

  int i = 0, j = 0, k = 0;
  // work only if two array is sorted
  while (i < n.size() && j < m.size()) {
    if (n[i] > m[j]) {
      j++;
    }
    else if (n[i] < m[j]) {
      i++; 
    } else {
      cout << n[i] << " ";
      i++;
      j++;
    }
  }

  cout << endl;
}