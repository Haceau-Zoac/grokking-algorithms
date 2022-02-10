def findSmallest(arr):
  smallest = 0
  for i in range(1, len(arr)):
    if arr[i] < arr[smallest]:
      smallest = i
  return smallest

def selectionSort(arr):
  newArr = []
  for _ in range(len(arr)):
    smallest = findSmallest(arr)
    newArr.append(arr.pop(smallest))
  return newArr

print(selectionSort([5, 3, 6, 2, 10]))