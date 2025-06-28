a, b = map(int, input().split())
cnt=0

def syg(n):
    return n % 10 == 3 or n % 10 == 6 or n % 10 == 9 or n//10==3 or n//10==6 or n//10==9

def sam(n):
    return n%3==0 or syg(n)


for i in range(a,b+1):
    if sam(i):
        cnt+=1

print(cnt)