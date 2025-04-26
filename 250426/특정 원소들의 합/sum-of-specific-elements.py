arr2=[
    list(map(int, input().split()))
    for _ in range(4)
]
sum1=0

for i in range(4):
    for j in range(i+1):
        sum1+=arr2[i][j]
    
print(sum1)