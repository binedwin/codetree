n=int(input())
k,b,h =0,0,0

for i in range(1,n+1):
    if i%12==0:
        h+=1
    elif i%3==0:
        b+=1
    elif i%2==0:
        k+=1
print(k,b,h)