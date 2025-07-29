# 변수 선언 및 입력:
n = int(input())

# a번째 수열 값을 반환합니다.
def sequence(a):
    if a == 1:
        return 2
    if a == 2:
        return 4

    return (sequence(a - 1) * sequence(a - 2)) % 100


print(sequence(n))
