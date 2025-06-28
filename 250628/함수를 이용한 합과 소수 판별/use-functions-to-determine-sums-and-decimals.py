a, b = map(int, input().split())

def suso(n):
    if n == 1:
        return False

    for i in range(2,n):
        if n%i==0:
            return False

    return True
        
def zzac(n):
    if ((n//10)+(n%10))%2==0:
        return True
    else:
        return False
cnt=0

for i in range(a,b+1):
    if suso(i) and zzac(i):
        cnt+=1

print(cnt)