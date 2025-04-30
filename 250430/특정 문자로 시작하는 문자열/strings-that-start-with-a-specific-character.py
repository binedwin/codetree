# 입력
N = int(input())
strings = [input().strip() for _ in range(N)]
target_alpha = input().strip()

# 조건에 맞는 문자열 찾기
filtered = [s for s in strings if s.startswith(target_alpha)]

# 개수와 평균 길이 계산
count = len(filtered)
average_length = sum(len(s) for s in filtered) / count if count else 0

# 결과 출력
print(count, f"{average_length:.2f}")