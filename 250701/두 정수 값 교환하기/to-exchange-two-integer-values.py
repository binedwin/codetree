n, m = map(int, input().split())

def swap(n,m):
    n,m = m,n
    return n,m

n,m, =swap(n,m)
print(n,m)