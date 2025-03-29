arr=input().split()
a,b=int(arr[0]), int(arr[1])
k=False

for i in range(a,b+1):
    if 1920%i==0 and 2880%i==0:
        k=True
        break
    
if k==True:
    print(1)
else:
    print(0)