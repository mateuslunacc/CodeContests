def pow(x, n):
    if n < 0:
        return pow(1/x, -n)
    elif n == 0:
        return 1
    elif n == 1:
        return x
    elif n%2 == 0:
        return pow(x*x, n/2)
    else:
        return x*pow(x*x, (n-1)/2)


x = int(input())

print(pow(3, x)%(pow(2, 31) - 1))
    
