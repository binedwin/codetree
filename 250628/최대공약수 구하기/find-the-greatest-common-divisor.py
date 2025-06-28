n, m = map(int, input().split())
k= n*m

def max_1():
    if n>m:
        k=n
    else:
        k=m
    ans=0
    for i in range(1, k):
        if n%i==0 and m%i==0:
            ans=i
    
    print(ans)

max_1()