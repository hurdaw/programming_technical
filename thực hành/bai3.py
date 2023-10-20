import math
# kiem tra so nguyen to
def isprime(n):
    if(n<2):
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if(n%i==0):
            return False
    return True
n = int(input())
print(isprime(n))