arr =list(map(int, input().split()))
cnt=0
sum=0

for i in arr:
    if i==0:
        break
    if i%2==0:
        cnt+=1
        sum+=i

print(cnt, sum)