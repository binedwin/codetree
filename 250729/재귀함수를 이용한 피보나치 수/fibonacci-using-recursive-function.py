N = int(input())

def f(N):
    
    if N==1:
        return 1
    elif N==2:
        return 1
    
    return f(N-1)+ f(N-2)

print(f(N))