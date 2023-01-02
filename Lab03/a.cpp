#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m), c;

  for (int i = 0; i < n; i++) 
    cin >> a[i];

  for (int i = 0; i < m; i++) 
    cin >> b[i];

  int i = 0, j = 0;

  while (i < (int) a.size() && j < (int) b.size()) {
    if (a[i] < b[j]) {
      c.push_back(a[i]);
      i++;
    } else {
      c.push_back(b[j]);
      j++;
    }
  }
  
  if (i == (int) a.size()) {
    for (int k = j; k < (int) b.size(); k++)
      c.push_back(b[k]);
  } else {
    for (int k = i; k < (int) a.size(); k++)
      c.push_back(a[k]);
  }

  int mid = (n + m) / 2;

  if (n + m == 0) {
    return 0;
  }

  if ((n + m) % 2 != 0) {
    cout << c[mid] << endl;
  } else {
    cout << (c[mid - 1] + c[mid]) / 2.0 << endl;
  }

  return 0;
}