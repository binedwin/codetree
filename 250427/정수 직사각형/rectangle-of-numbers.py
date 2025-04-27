n,m= tuple(map(int, input().split()))
cnt=1

arr=[
    [0 for _ in range(m)]
    for _ in range(n)
]

for i in range(n):
    for j in range(m):
        arr[i][j]=cnt
        cnt+=1
        print(arr[i][j],end =" ")
    print()