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

def s(A, i, j, x):
  if i >= len(A) or j < 0:
    return False 
  
  if A[i][j] == x:
    return True 
  elif A[i][j] < x:
    return s(A, i+1, j, x)
  else :
    return s(A, i, j-1, x)

A = [ [ 0, 3, 4, 5 ],
      [ 6, 7, 8, 9 ],
      [ 10, 11, 12, 13],
      [ 14, 15, 16, 17] ]

print(search(A, 0))
print(s(A, 0, len(A) - 1, 0))