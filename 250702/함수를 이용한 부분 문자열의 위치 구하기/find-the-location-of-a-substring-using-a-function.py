text = input()
pattern = input()

def string(a, b):
    for i in range(len(a) - len(b) + 1):  # 슬라이딩 윈도우
        if a[i:i+len(b)] == b:
            return i
    return -1

print(string(text, pattern))