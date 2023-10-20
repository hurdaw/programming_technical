# check factorial
def isfect(n):
    if(n==1):
        return 1
    return (n*isfect(n-1))
n=int(input())
print(isfect(n))