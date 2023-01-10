#include <iostream>

using namespace std;

void bubleSort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j+1]);
      }
    }
  }
}

int main() {
  int a[] = { 3, 2, 5, 4, 1 };
  int n = sizeof(a) / sizeof(int);

  bubleSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// 3 2 5 4 1
// 2 3 5 4 1