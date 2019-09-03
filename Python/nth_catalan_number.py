# Nth Catalan Number


# Works even for large numbers -- Python

t = int(input())

for _ in range(t):
    n = int(input())
    a = []
    a.append(1)
    for i in range(1, n+1):
        res = 0
        for j in range(1, i+1):
            res = res + a[j-1]*a[i-j]
        a.append(res)
    print(a[n])