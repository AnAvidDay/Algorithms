arr = [1, 4, 8 , 9]

for i in range(1, len(arr)):
  arr[i] += arr[i-1]
 
 # results in:
 # arr = [1, 5, 13, 22]
 # E.g., what is sum from index (1-3)
 # arr[3] - arr[1-1] = 22 - 1 = 21
