n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort()
a=0

for i in range(n):
    if A[i]!=B[i]:
        a=2
        break
    else:
        a=1
    
if a==1:
    print("Yes")
elif a==2:
    print("No")