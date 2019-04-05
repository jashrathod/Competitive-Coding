x = int(input())
y = []
for j in range(x):
    a = int(input())
    b = int(input())
    y.append(a-b)

count = 0
pos = 0

for i in range(len(y)):
    count = count + y[i]
    if y[i]>=0 and pos==0:
        pos = i +1
    elif y[i]<0 and count<0:
        pos = 0

if count<0:
    print("not possible")
else:
    print(pos)