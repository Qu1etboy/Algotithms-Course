#include <iostream>

using namespace std;

int partition(int a[], int l, int r) {
  int pivot = a[l], i = l, j = r + 1;

  while (i < j) {
    do {
      i++;
    } while (a[i] <= pivot && i <= r);
    do {
      j--;
    } while (a[j] > pivot && j > l);

    // cout << a[i] << " " << a[j] << endl;
    swap(a[i], a[j]);
  }
  swap(a[i], a[j]); // unswap i <= j
  swap(a[l], a[j]);

  return j;
}

void quickSort(int a[], int l, int r) {
  if (l < r) {
    int s = partition(a, l, r);
    quickSort(a, s + 1, r);
    quickSort(a, l, s);
  }
}

int main() {
  // int a[] = { 5, 3, 2, 4, 1 }; // 1 3 2 4 5
  int a[] = { 6, 5, 8, 9, 3, 10, 15, 12, 16 };
  int n = sizeof(a) / sizeof(int);

  quickSort(a, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}