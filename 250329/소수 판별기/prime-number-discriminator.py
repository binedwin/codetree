n= int(input())
k=True

for i in range(2,n):
    if n%i==0:
        k=False

if k==True:
    print("P")
else:
    print("C")