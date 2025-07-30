secret_code, meeting_point, time = input().split()
time = int(time)

class k:
    def __init__(self,a,b,c):
        self.a = a
        self.b = b
        self.c = c

k1 = k(secret_code,meeting_point,time)
print("secret code :",k1.a)
print("meeting point :", k1.b)
print("time :", k1.c)