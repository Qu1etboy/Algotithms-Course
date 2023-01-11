def binarySearch(A):
  l = 0
  r = len(A) - 1

  while l <= r:
    mid = (l + r) // 2
    # print("mid = ", mid)
    if A[mid] == mid:
      return True
    elif A[mid] > mid:
      r = mid - 1
    else:
      l = mid + 1
    
  return False 

A = [ 0, 1, 2, 3, 4, 5 ]

print(binarySearch(A))