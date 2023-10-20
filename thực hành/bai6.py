# dao chuoi
def daoChuoi(s):
    a=[]
    for i in s[::-1]:
        a.append(i)
    return a
s=input()
print(''.join(daoChuoi(s)))