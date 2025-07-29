N = int(input())
cnt=0


def f(N):
    global cnt
    if N==1:
        return cnt

    if N%2==0:
        N//=2
        cnt+=1
    else:
        N//=3
        cnt+=1

    return f(N)

f(N)
print(cnt)