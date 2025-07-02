a, b = map(int, input().split())

def k(a,b):
    if a>b:
        b+=10
        a*=2
    elif a<b:
        a+=10
        b*=2
    else:
        return False
        
    return a,b

a,b = k(a,b)
print(a,b )