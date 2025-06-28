n, m = map(int, input().split())

def a():
    for i in range(max(n,m),n*m):
        if i%n==0 and i%m==0:
            print(i)
            break

a()