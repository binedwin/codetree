# 변수 선언 및 입력:
n = int(input())


# 재귀함수를 이용해 별을 1개부터 n개까지 줄을 쌓습니다.
def print_star(n):
    if n == 0:
        return

    print_star(n - 1)
    print("*" * n)


print_star(n);
