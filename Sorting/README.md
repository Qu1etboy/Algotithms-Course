# Sorting Algorithms

### Bubble Sort

วนไปเรื่อยๆ สลับตัวมากกับตัวน้อย

```cpp
void bubleSort(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j+1]);
      }
    }
  }
}
```

### Selection Sort

วนไปเรื่อยๆ หาตัวน้อยสุดแล้วเอามาไว้ข้างหน้า

```cpp
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
```

### Insertion Sort

วนไปเรื่อยๆ เลื่อนตัวน้อยสุดไปไว้ข้างหน้าในตําแหน่งที่ควรอยู่

```cpp
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
```

### Merge Sort

ใช้ Divide and Conquer แบ่ง array ออกเป็นครึ่งๆ จนเหลือแค่ 1 ตัว และทําการ merge และ sort

```py
def mergeSort(a):
  if len(a) > 1:
    b = a[:len(a)//2]
    c = a[len(a)//2:]
    mergeSort(b)
    mergeSort(c)
    merge(b, c, a)

def merge(b, c, a):
  i, j, k = 0, 0, 0

  while i < len(b) and j < len(c):
    if b[i] >= c[j]:
      a[k] = b[i]
      i += 1
    else:
      a[k] = c[j]
      j += 1
    k += 1

  if i == len(b):
    a[k:len(a)] = (c[j:len(c)])
  else:
    a[k:len(a)] = (b[i:len(b)])
```

### Quick Sort

แบ่ง array ออกเป็น partition โดยใช้ `pivot` โดยค่ามากอยู่ด้านขวาของ `pivot` ค่าน้อยอยู่ด้านซ้าย ตําแหน่งที่ `pivot` อยู่คือตําแหน่งที่ sort แล้ว ให้ทําซํ้าจนกว่าจะแบ่งไม่ได้แล้ว

ฟังก์ชัน partition เริ่มจากให้ `pivot` คือตัวแรกของ array แล้วให้ `i` วิ่งทางซ้ายไปขวา `j` วิ่งจากขวาไปซ้าย โดย `i` จะหยุดเมื่อเจอตัวที่มากกว่า `pivot` และ `j` หยุดเมื่อเจอตัวที่น้อยกว่า เมื่อเจอครบแล้วสลับ `a[i]`, `a[j]` ทําต่อไปเรื่อยๆ จนกว่า `i >= j`เมื่อหลุดแล้วให้สลับ `a[i]`, `a[j]` อีกครั้ง แล้วสลับเอา pivot ไปอยู่ให้ถูกที่โดยสลับ `a[l]`, `a[j]`

```cpp
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
```

### Radix Sort

```py
# O(n)
def countingSort(arr, digit):
  result = [0] * len(arr)
  counts = [0]*10

  for i in range(len(arr)):
    counts[(arr[i] // digit) % 10] += 1;

  # Change count[i] so that count[i] now contains actual
  # position of this digit in output array
  for i in range(1, len(counts)):
    counts[i] += counts[i - 1]

  for i in range(len(arr) - 1, -1, -1):
    digit_value = (arr[i] // digit) % 10
    result[counts[digit_value] - 1] = arr[i]
    counts[digit_value] -= 1

  return result

# O(d)
def radixSort(arr):
  max_digit = max(arr)
  digit = 1
  while max_digit // digit > 0:
    arr = countingSort(arr, digit)
    print(arr)
    digit *= 10
  return arr
```
