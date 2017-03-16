def oneDigitNum(s):
    n = 0
    while True:
        for c in s:
            n += int(c)

        s = str(n)
        if(n < 10):
            break
        else:
            n = 0
        
    return n

num = input().split(" ")

while(not(num[0] == "0" and num[1] == "0")):
    n1=oneDigitNum(num[0])
    n2=oneDigitNum(num[1])
    
    if(n1==n2):
        print(0)
    elif(n1>n2):
        print(1)
    else:
        print(2)

    num = input().split(" ")

