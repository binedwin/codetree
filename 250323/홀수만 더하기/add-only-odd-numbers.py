n= int(input())
sum=0

for _ in range(n):
    a=int(input())
    if a%2==1 and a%3==0:
        sum+=a

print(sum)