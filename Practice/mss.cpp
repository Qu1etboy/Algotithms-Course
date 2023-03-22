// solution for https://beta.programming.in.th/tasks/1005

#include <iostream>

using namespace std;

int main() {
  int n, b = 0, ans = -10000, curr_start = -1, end = 0, start = -1;

  cin >> n;

  int s[n];

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    if (s[i] > b + s[i]) {
      b = s[i];
      curr_start = i;
    } else {
      b = s[i] + b;
    }

    // found new max sum
    if (ans < b) {
      ans = b;
      // update new start and end index
      start = curr_start;
      end = i;
    }
  }

  if (ans <= 0) {
    cout << "Empty sequence" << endl;
    return 0;
  }

  for (int i = start; i <= end; i++) {
    cout << s[i] << " ";
  }

  cout << "\n" <<  ans << endl;

  return 0;
}

/*
TC1
input
8
4 -6 3 -2 6 -4 -6 6
----
output
3 -2 6
7

######

TC2
input
3
-2 -3 -1
----
output
Empty sequence

*/