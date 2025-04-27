n, m = map(int, input().split())
arr=[[0 for _ in range(m)] for _ in range(n)]
num=0

for i in range(m):
    for j in range(n):
        if i%2==0:
            arr[j][i]+=num
            num+=1
        else:
            arr[n-j-1][i]+=num
            num+=1
    

for i in range(n):
    for j in range(m):
        print(arr[i][j], end=" ")
    print()