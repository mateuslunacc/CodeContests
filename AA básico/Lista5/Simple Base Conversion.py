n = str(input())

while(n != "-1"):
    if (n[0] == "0"):
        print(int(n, 16))
    else:
        n = hex(int(n)).upper()
        print("0x" + n[2:])

    n = str(input())
