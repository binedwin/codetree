n = int(input())
arr=[[0 for _ in range(n)] for _ in range(n)]
num=1

for i in range(n):
    for j in range(n):
        if i%2==0:
            arr[n-j-1][n-i-1]+=num
            num+=1
        else:
            arr[j][n-i-1]+=num
            num+=1

for i in range(n):
    for j in range(n):
        print(arr[i][j], end=" ")
    print()