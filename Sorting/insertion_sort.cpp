#include <iostream>

using namespace std;

void insertion(int a[], int n) {
  for (int i = 0; i < n; i++) {
    int v = a[i], j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
  }
}

int main() {
  int a[] = { 3, 2, 5, 4, 1 };
  int n = sizeof(a) / sizeof(int);

  insertion(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// 3 2 5 4 1
// 2 3 5 4 1