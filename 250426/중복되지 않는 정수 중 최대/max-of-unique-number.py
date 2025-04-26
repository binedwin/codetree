n = int(input())
arr = list(map(int, input().split()))

count = {}  # 등장 횟수 저장

# 1. 등장 횟수 세기
for num in arr:
    count[num] = count.get(num, 0) + 1

# 2. 등장 횟수가 1인 값들 중 최대값 찾기
candidates = [num for num in count if count[num] == 1]

if candidates:
    print(max(candidates))
else:
    print("-1")  # 중복되지 않은 값이 없을 때 처리