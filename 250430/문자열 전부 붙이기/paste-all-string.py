n=int(input())

a= [
    input()
    for _ in range(n)
]

str_all=""

for i in range(n):
    str_all+=a[i]

print(str_all)
