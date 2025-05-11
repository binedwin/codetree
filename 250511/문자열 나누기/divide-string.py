n=int(input())
string = input().split()
strl=""
cnt=0

for i in range(n):
    strl+=string[i]
leng=len(strl)

for i in range(leng):
    print(strl[i],end="")
    cnt+=1
    if cnt%5==0:
        print("")
    