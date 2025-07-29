a, b, c = map(int, input().split())

def f(k):
    if k<10:
        return k

    return f(k//10)+(k%10)

print(f(a*b*c))