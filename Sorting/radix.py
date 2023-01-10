# O(n)
def countingSort(arr, digit):
  result = [0] * len(arr)
  counts = [0]*10

  for i in range(len(arr)):
    counts[(arr[i] // digit) % 10] += 1;

  # Change count[i] so that count[i] now contains actual
  # position of this digit in output array
  for i in range(1, len(counts)):
    counts[i] += counts[i - 1]

  for i in range(len(arr) - 1, -1, -1):
    digit_value = (arr[i] // digit) % 10
    result[counts[digit_value] - 1] = arr[i]
    counts[digit_value] -= 1

  return result

# O(d)
def radixSort(arr):
  max_digit = max(arr)
  digit = 1
  while max_digit // digit > 0:
    arr = countingSort(arr, digit)
    print(arr)
    digit *= 10
  return arr 

arr = [82, 901, 100, 12, 150, 77, 55, 23]

print(radixSort(arr))

  