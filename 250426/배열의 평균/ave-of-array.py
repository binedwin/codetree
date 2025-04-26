arr=[
    list(map(int, input().split()))
    for _ in range(2)
]

print(sum(arr[0])/len(arr[0]),end =" ")
print(sum(arr[1])/len(arr[1]))

for j in range(4):
    col_sum = arr[0][j] + arr[1][j]
    col_avg = col_sum / 2
    print(f"{col_avg:.1f}", end=' ')
print()

total_sum = sum(map(sum, arr))
total_avg = total_sum / (2 * 4)
print(f"{total_avg:.1f}")
    
        