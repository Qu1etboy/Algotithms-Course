r = []
t = []
ans = 10000000000

# def solve(a):
#   if len(r) == len(a):
#     ans.append(r)
#     return
  
#   for i in a:
#     if i in t:
#       continue
    
#     r.append(i)
#     t.append(i)
#     solve(a)
#     r.pop()
#     t.pop()

def solve(a, k):
  global ans
  if len(r) == len(a):
    ans = min(sum(r), ans)
    # print(r)
    return
  
  for i in range(len(a[0])):
    if i in t:
      continue
    
    r.append(a[i][k])
    t.append(i)
    solve(a, k+1)
    r.pop()
    t.pop()

C = [ [9, 2, 7, 8],
      [6, 4, 3, 7],
      [5, 8, 1, 8],
      [7, 6, 9, 4] ]

solve(C, 0)

# print(len(ans))
print(ans)