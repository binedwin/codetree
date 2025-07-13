# 변수 선언 및 입력:
n = int(input())


# 재귀함수를 이용해 숫자를 n부터 1까지 출력하고, 다시 1부터 n까지 출력합니다.
def print_star(n):
    if n == 0:
        return

    print(n, end=" ")
    print_star(n - 1)
    print(n, end=" ")


print_star(n);
