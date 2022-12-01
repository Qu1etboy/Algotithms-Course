# bisection technique
def sqrt(n):
  L = 0
  U = n
  x = (L + U) / 2

  # logic to check floating point number equality
  while abs(n-x**2) > 1e-10*max(n,x**2) :
    if x**2 > n:
      U = x
    else:
      L = x
    x = (L + U) / 2
  return x

print(sqrt(2))
print(sqrt(10))
print(sqrt(16))