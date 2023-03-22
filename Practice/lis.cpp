#include <iostream>

using namespace std;

// longest increasing subsequence 
int main() {
  int s[] = { 2, 5, 1, 0, 7, 3, 4, 6, 99, 10, 8 }, n = 11;
  int dp[11] = {};

  for (int i = 0; i < n; i++) {
    int mx = 0;
    for (int j = 0; j < i; j++) {
      if (s[j] < s[i]) {
        mx = max(mx, dp[j]);
      }
    }
    dp[i] = mx + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
    ans = max(dp[i], ans);
  }

  cout << "\n" << ans << endl;
}