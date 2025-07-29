# 변수 선언 및 입력:
n = int(input())


def get_sum(n):
    # 한 자리 숫자라면 제곱한 값이 결과가 됩니다.
    if n < 10:
        return n * n

    # 마지막 자리 숫자의 제곱에 
    # 남은 숫자들의 합을 계산한 결과를 더해 반환합니다.
    digit = (n % 10)
    return get_sum(n // 10) + digit * digit


print(get_sum(n))
