a, b = map(int, input().split())
cnt=0

def syg(n):
    cnt=0
    for n in str(n):
        if n in '369':
            return True

def sam(n):
    return n%3==0 or syg(n)
        
for i in range(a, b+1):
    if i%3==0 or syg(i):
        cnt+=1

print( cnt)