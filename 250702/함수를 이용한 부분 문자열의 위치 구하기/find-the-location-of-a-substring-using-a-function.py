text = input()
pattern = input()

def string(a,b):
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i]==b[j]:
                if a[i+1] == b[j]:
                    return i

    return -1

print(string(text, pattern))