ans = 0
x = int(input())
if x < 0:
    print("Invalid input.")
elif x <= 6:
    ans = x
else:
    y = int (x/2)
    if x%2 == 0:
        ans = y*(y-1)
    else:
        ans = y*y
print(ans)