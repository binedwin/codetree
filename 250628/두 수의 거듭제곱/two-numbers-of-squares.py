a, b = map(int, input().split())

def zegob(a,b):
    cnt=1
    for _ in range(b):
        cnt*=a
    print(cnt)

zegob(a,b)