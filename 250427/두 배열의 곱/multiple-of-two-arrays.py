# 첫 번째 2차원 배열을 구현해 정수를 입력받습니다.
arr_1 = [
	list(map(int, input().split()))
	for _ in range(3)
]

input()

# 두 번째 2차원 배열을 구현해 정수를 입력받습니다.
arr_2 = [
	list(map(int, input().split()))
	for _ in range(3)
]

# 2차원 배열을 구현합니다.
arr_3 = [
    [0 for _ in range(3)]
    for _ in range(3)
]

# 두 배열의 곱을 새로운 배열에 담습니다.
for i in range(3):
	for j in range(3):
		arr_3[i][j] = arr_1[i][j] * arr_2[i][j]
       
	
# 새로운 배열을 출력합니다.
for i in range(3):        
    for j in range(3):    
        print(arr_3[i][j], end=" ")
    print()
