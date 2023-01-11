# 2.

a = [3, 3, 4, 2, 4, 2, 4, 4]

v = [0] * ( max(a) + 1 )

# count number of appearence in element
for e in a:
  v[e] += 1

ans = None

for i in range(len(v)):
  if v[i] > len(a) // 2:
    ans = i 

print(ans)