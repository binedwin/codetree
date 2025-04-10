n = int(input())
arr= list(map(float, input().split()))


sum_arr=sum(arr)


k= sum_arr/n

if k>=4.0:
    print(f"{k:.1f}\nPerfect")
elif k>=3.0:
    print(f"{k:.1f}\nGood")
else:
    print(f"{k:.1f}\nPoor")