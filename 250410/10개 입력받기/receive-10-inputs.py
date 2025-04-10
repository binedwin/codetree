arr= list(map(int, input().split()))
sum=0
cnt=0

for i in arr:
    if i==0:
        break
    cnt+=1
    sum+=i

k=sum/cnt

print(f"{sum} {k:.1f}")