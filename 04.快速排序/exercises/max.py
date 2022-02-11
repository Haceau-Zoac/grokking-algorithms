def mmax_helper(arr, max):
  if (arr == []):
    return max
  if (arr[0] > max):
    return mmax_helper(arr[1:], arr[0])
  else:
    return mmax_helper(arr[1:], max)

def mmax(arr):
  return mmax_helper(arr[1:], arr[0])

print(mmax([1, 4, 2, 3]))