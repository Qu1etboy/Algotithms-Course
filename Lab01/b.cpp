#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int L = 0, R = n / 2, ans;

  if (n == 0 || n == 1) {
    cout << n << endl;
    return 0;
  }

  // using binary search to find floor sqrt
  while (L <= R) {
    int x = (L + R) / 2;
    if (x*x == n) {
      ans = x;
      break;
    }
    if (x*x > n) {
      R = x - 1;
    }
    else {
      L = x + 1;
      ans = x;
    }
  }

  cout << ans << endl;
}