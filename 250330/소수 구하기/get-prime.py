n=int(input())
k=True

for i in range(1,n+1):
    if i == 1:
        continue
    k=True
    
    for j in range(2,i):
        if i%j==0:
            k=False
            
    if k==True:
        print(i, end=" ")

