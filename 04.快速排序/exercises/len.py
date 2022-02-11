def mlen(arr):
  if arr == []:
    return 0
  return 1 + mlen(arr[1:])

print(mlen([1, 2, 3, 4]))