# Eucliden's Algorithms
def gcd(m, n):
  if n == 0:
    return m
  return gcd(n, m%n)

print(gcd(60, 24))
print(gcd(56, 42))
print(gcd(31415, 14142))