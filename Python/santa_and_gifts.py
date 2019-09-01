# Santa and Gifts

def fn(a, n, c):
    a.sort()
    while len(a) != c:
        x = a[0] + a[1]
        del(a[0])
        del(a[1])
        a.append(x)
        a.sort()
    return a[c-1]


if __name__ == '__main__': 
    t = int(input())
	for i in range(t):
	    n = int(input())
	    a = []
	    for j in range(n):
	        x = int(input())
	        a.append(x)
	    c = int(input())
	    if c>n:  c
	        print(-1)
	    else:
	        print(fn(a, n, c))
