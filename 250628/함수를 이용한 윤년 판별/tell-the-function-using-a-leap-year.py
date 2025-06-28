y = int(input())

def yun(n):
    if n%100==0:
        if n%400!=0:
            return False
    if n%4!=0:
        return False  
    return True

if yun(y)==True:
    print("true")
else:
    print("false")