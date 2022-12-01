# find all prime number from 2 to n
def sieve_of_eratosthenes(n):
  p = [1] * n 
  for i in range(2, int(n**0.5)): 
    if p[i]:
      for j in range(i * i, n, i):
        p[j] = 0
  
  for i in range(2, n):
    if p[i]:
      print(i, end=' ')

sieve_of_eratosthenes(100)