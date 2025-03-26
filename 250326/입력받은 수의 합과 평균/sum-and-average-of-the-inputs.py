n= int(input())
sum=0
cnt=0

for _ in range(1,n+1):
    a= int(input())
    sum+=a
    cnt+=1

print(f"{sum} {sum/cnt:.1f}")