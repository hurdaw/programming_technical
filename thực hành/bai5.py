# is fibonacci
def isFibo(n):
    if(n==0):
        return 0
    if(n==1 or n==2):
        return 1
    return (isFibo(n-1)+isFibo(n-2))
n=int(input())
a=[]
for i in range(1,n+1):
    a.append(isFibo(i))
print(a) 