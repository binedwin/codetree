n, k = map(int, input().split())
nums = list(map(int, input().split()))

nums.sort()

for i in range(n):
    if i == k:
        print(nums[i+1])