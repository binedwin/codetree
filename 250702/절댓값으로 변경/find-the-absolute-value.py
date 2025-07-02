n = int(input())
arr = list(map(int, input().split()))

def abv(s):
    for i in range(len(s)):
        if s[i]<0:
            s[i]*= -1
    return

abv(arr)

for elem in arr:
    print(elem, end= " ")