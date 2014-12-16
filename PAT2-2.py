'''
设计函数求一元多项式的导数。

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0
'''
import string
cell = string.split(raw_input())
item = []
L = []
for x in range(0,len(cell),2):
    item.append(int(cell[x]))
    item.append(int(cell[x+1]))
    L.append(item)
    item = []


for x in range(len(L)):
    if L[x][0] == 0 and L[x][1] == 0:
        print 0,0,
        break
    if L[x][0] != 0 and L[x][1] == 0:
        continue
    else:
        print L[x][0]*L[x][1],L[x][1]-1,
