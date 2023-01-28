c = [10, 5, 2, 1]
n = 48

i = 0
x = 0

while i < len(c) and n > 0:
  x += n // c[i]
  n = n % c[i]
  i += 1

print(x)