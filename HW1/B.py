# solution 1
def commonElement(list1, list2):
  common = []
  taken = [0] * len(list2)
  # O(n^2)
  for i in list1:
    for k, j in enumerate(list2):
      if i == j and taken[k] == 0:
        common.append(i)
        # mark element as taken
        taken[k] = 1
        break
  
  return common 

print(commonElement([5, 2, 5, 5], [2, 2, 3, 5, 5, 7]))
print(commonElement([2, 2, 3, 5, 5, 7], [2, 5, 5, 5]))
print(commonElement([1, 1, 2], [1]))
print(commonElement([2, 2, 2, 2, 2, 2, 2, 2, 2], [2, 2, 2, 2, 2, 2, 2]))