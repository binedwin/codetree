def print_rect(n,m):
    for _ in range(n):
        print("1" * m)

a,b = tuple(map(int, input().split()))
print_rect(a,b)