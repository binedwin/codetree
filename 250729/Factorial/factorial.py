N = int(input())

def f(N):
    if N==0:
        return 1

    return N*f(N-1)

print(f(N))