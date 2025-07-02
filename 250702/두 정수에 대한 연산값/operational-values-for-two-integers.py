a, b = map(int, input().split())

def A(a,b):
    if a>b:
        a+=25
        b*=2
    elif a<b:
        a*=2
        b+=25
    else:
        False
    return a,b

a,b = A(a,b)

print(a,b)