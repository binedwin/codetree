n = int(input())
arr = list(map(int, input().split()))

def arr_n(n):
    for elem in range(n):
        if arr[elem]%2==0:
            arr[elem]//=2

arr_n(n)

for elem in arr:
    print(elem, end=" ")