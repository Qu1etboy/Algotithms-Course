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

arr = [4, 5, 2, 3, 1]

mergeSort(arr)

print(arr)