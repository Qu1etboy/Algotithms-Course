def search(A, x):
  n = len(A)
  i = 0
  j = n - 1

  while i < n and j >= 0:
    if A[i][j] == x:
      return True
    if x > A[i][j]:
      i += 1
    else:
      j -= 1
  
  return False


A = [ [ 2, 3, 4, 5 ],
      [ 6, 7, 8, 9 ],
      [ 10, 11, 12, 13],
      [ 14, 15, 16, 17] ]

print(search(A, 0))