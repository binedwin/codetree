n= int(input())
arr=[[0 for _ in range(n)] for _ in range(n)]
cnt=0

for i in range(n):
    cnt+=1
    for j in range(n):
        if j ==0:
            arr[i][j]=cnt
        else:
            arr[i][j]=arr[i][j-1]+n
        
        print(arr[i][j], end=" ")
    
    print()
    
