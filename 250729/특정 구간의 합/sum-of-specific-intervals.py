n, m = map(int, input().split())
arr = list(map(int, input().split()))
queries = [tuple(map(int, input().split())) for _ in range(m)]

def k():
    for i in range(m):
        cnt=0
        for j in range(queries[i][0]-1,queries[i][1],1):
            cnt+=arr[j]
        print(cnt)

k()