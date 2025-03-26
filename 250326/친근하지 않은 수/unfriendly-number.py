# 변수 선언, 입력
n = int(input())
cnt = 0

# 1부터 n까지의 수 중, 2 또는 3 또는 5로 나누어지지 않는 수의 개수를 구합니다.
for i in range(1, n + 1):
	if i % 2 == 0 or i % 3 == 0 or i % 5 == 0:
		continue
	cnt += 1

# 출력
print(cnt)
