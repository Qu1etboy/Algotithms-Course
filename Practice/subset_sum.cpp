#include <iostream>

using namespace std;

int main() {
  int s[] = { 2, 3, 5 }, n = 3, b = 5;

  int dp[n + 1][b + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= b; j++) {
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  
  for (int i = 1; i <= n; i++) {
    for (int j = b; j >= 0; j--) {
      dp[i][j] = dp[i - 1][j] || (j >= s[i - 1] && dp[i - 1][j - s[i - 1]]);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= b; j++) {
      cout << (dp[i][j] ? "T" : "F") << " ";
    }
    cout << endl;
  }

  // cout << dp[n][b] << endl;;
}