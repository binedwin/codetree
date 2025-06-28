a, o, c = input().split()
a = int(a)
c = int(c)

def sachic(a,o,c):
    if o=='+':
        return a+c
    elif o=='-':
        return a-c
    elif o=='/':
        return a//c
    elif o=='*':
        return a*c
    else:
        return False

print(a, o, c, "=",sachic(a,o,c))