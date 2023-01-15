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

def binarySearchRecursive(A, l, r):
  if l > r:
    return False
  
  mid = (l + r) // 2
  
  if A[mid] == mid:
    return True 
  elif A[mid] > mid:
    return binarySearchRecursive(A, l, mid - 1)
  else:
    return binarySearchRecursive(A, mid + 1, r)

A = [ 0, 2, 3, 4, 5, 8 ]

print(binarySearch(A))
print(binarySearchRecursive(A, 0, len(A)-1))