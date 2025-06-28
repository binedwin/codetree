# 변수 선언 및 입력:
n, m = tuple(map(int, input().split()))


# n과 m의 최소공배수를 출력합니다.
def find_lcm(n, m):
    gcd = 0
    for i in range(1, min(n, m) + 1):
        if n % i == 0 and m % i == 0:
            gcd = i

    print(n * m // gcd)
   

find_lcm(n, m)
