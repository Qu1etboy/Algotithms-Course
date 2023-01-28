res = 0

def countStr(s, k):
  global res
  if len(s) == 1: return

  p = partition(s, k)

  if p < len(s):
    countStr(s[:p], k)
    countStr(s[p+1:], k)
  else:
    # print(s)
    res = max(res, len(s))

def partition(s, k):
  map = {}

  for i in s:
    if i not in map:
      map[i] = 1
    else :
      map[i] += 1
  
  p = 0
  for i in s:
    if map[i] < k:
      break
    p += 1

  return p

countStr("ababcceaaadc", 2)

print(res)