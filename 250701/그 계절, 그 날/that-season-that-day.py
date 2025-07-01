Y, M, D = map(int, input().split())

def yun(n):
    if n % 400 == 0:
        return True
    elif n % 100 == 0:
        return False
    elif n % 4 == 0:
        return True
    else:
        return False

def day(month, is_yun):
    if month == 2:
        return 29 if is_yun else 28
    elif month in [4, 6, 9, 11]:
        return 30
    else:
        return 31

def weather(month):
    if 3 <= month <= 5:
        return "Spring"
    elif 6 <= month <= 8:
        return "Summer"
    elif 9 <= month <= 11:
        return "Fall"
    elif month == 12 or month <= 2:
        return "Winter"
    else:
        return -1

# 체크
if 1 <= M <= 12 and 1 <= D <= day(M, yun(Y)):
    print(weather(M))
else:
    print(-1)