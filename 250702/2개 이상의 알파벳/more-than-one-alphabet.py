A = input()

def dif(s):
    for i in range(len(s)):
        if s[i] != s[0]:
            return True
        
    return False

if dif(A):
    print("Yes")

else:
    print("No")