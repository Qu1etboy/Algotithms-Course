#include <iostream>

using namespace std;

void merge(int a[], int b[], int c[]) {
  int i = 0, j = 0, k = 0;
  int p = sizeof(b) / sizeof(int);
  int q = sizeof(c) / sizeof(int);
  
  while (i < p && j < q) {
    if (b[i] <= c[j])
      a[k++] = b[i++];
    else 
      a[k++] = c[j++]; 
  }

  if (i == p) {
    for (int l = j; l < q; l++) {
      a[k++] = c[l];
    }
  } else {
    for (int l = i; l < p; l++) {
      a[k++] = b[l];
    }
  }
}

void mergeSort(int a[], int n) {
  if (n > 1) {
    int b[n], c[n];
    for (int i = 0; i < n/2; i++) {
      b[i] = a[i];
    }
    for (int i = n/2, j = 0; i < n; i++, j++) {
      c[j] = a[i];
    }

    mergeSort(b, n/2);
    mergeSort(c, n/2);
    merge(a, b, c);
  }
}

int main() {
  int a[] = {3, 2, 5, 4, 1};
  int n = sizeof(a) / sizeof(int);

  mergeSort(a, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}