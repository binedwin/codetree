# 변수 선언 및 입력:
n = int(input())


def print_number1(n):
    if n == 0:
        return
    
    print_number1(n - 1)
    print(n, end=" ")


def print_number2(n):
    if n == 0:
        return

    print(n, end=" ")
    print_number2(n - 1)


print_number1(n)
print()
print_number2(n)
