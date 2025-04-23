arr = list(map(int, input().split()))  # A B
A, B = arr[0], arr[1]

count = [0] * 100  # 나머지 범위에 맞게 설정
while A >1:
    remainder = A % B
    count[remainder] += 1
    A //= B

# 제곱합 계산
total = sum(c ** 2 for c in count)
print(total)