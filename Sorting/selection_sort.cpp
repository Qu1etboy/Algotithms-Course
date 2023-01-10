#include <iostream>

using namespace std;

void selectionSort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = 0; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    swap(a[i], a[min]);
  }
}

int main() {
  int a[] = { 5, 4, 3, 2, 1 };
  int n = sizeof(a) / sizeof(int);

  selectionSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// 3 2 5 4 1
// 2 3 5 4 1