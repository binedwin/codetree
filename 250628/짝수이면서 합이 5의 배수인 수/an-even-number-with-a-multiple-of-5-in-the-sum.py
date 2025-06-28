n = int(input())

def magic_number(n):
    return n%2==0 and (n%10+n//10)%5==0

if magic_number(n):
    print("Yes")

else:
    print("No")