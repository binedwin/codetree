l=input()
arr=l.split()
a_math=int(arr[0])
a_eng=(arr[1])

z=input()
arr=z.split()
b_math=int(arr[0])
b_eng=(arr[1])

if (a_math>=19 or b_math>=19) and (a_eng=='M' or b_eng=='M'):
    print(1)
else:
    print(0)
    