arr=list(map(int, input().split()))
sum=0

count=[0]*10

for i in range(1000):
    count[arr[0] % arr[1]]+=1
    arr[0]//=arr[1]

    if arr[0]<1:
        break

for i in range(0,10):
    count[i]**=2
    sum+=count[i]

print(sum)