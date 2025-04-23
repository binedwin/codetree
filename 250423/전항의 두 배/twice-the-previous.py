p1, p2 =tuple(map(int, input().split()))

arr=[]

arr.append(p1)
arr.append(p2)

for i in range(2,10):
    arr.append(arr[i-1]+arr[i-2]*2)

for i in range(10):
    print(arr[i],end=" ")