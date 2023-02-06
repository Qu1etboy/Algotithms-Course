# 6410406860 Weerawong Vonggatunyu

def fib(n, memo):
  if n <= 1: return n
  if memo[n] != -1: return memo[n]
  memo[n] = fib(n-1, memo) + fib(n-2, memo)
  return memo[n]

n = int(input())
memo = [-1 for i in range(n+1)]

print(fib(n, memo))