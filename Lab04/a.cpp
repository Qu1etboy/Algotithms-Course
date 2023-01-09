#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// this solution better than using divide and conquer because it only take O(n)
int main() {
  int s = 0;
  string str;
  vector<int> a;
  
  getline(cin, str);
  
  int n = stoi(str);

  if (n == 0) {
    return 0;
  }

  string l;
  getline(cin, l);

  istringstream ss(l);

  string tmp;
  while (ss >> tmp) {
    a.push_back(stoi(tmp));
  }

  if (a.size() >= n) {
    cout << "`Out of range`" << endl;
    return 0;
  }

  for (int e : a) {
    if (e > n) {
      cout << "`Out of range`" << endl;
      return 0;
    }
    s += e;
  }

  int k = n * (n + 1) / 2;

  // cout << "s = " << s << " k = " << k << endl;

  if (s >= k) {
    cout << "`Out of range`" << endl;
  } else {
    cout << k - s << endl;
  }

  return 0;

}

/*
10
6 8 1 9 7 10 3 5 2

*/