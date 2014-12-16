'''
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
4 1 5

'''
import string
N = input()
elem = []
Tree = []
for x in range(N):
	str = string.split(raw_input())
	if str[0] in '012345678910':
		elem.append(int(str[0]))
	else:
		elem.append(-1)

	if str[1] in '012345678910':
		elem.append(int(str[1]))	
	else:
		elem.append(-1)
	Tree.append(elem)
	elem = []
           
 
temp = []
for x in range(N):
	temp.append(Tree[x][0])
	temp.append(Tree[x][1])

for x in range(N):
	if x not in temp:
		root = x

queue = []

queue.append(root)

while queue:
	index = queue.pop(0)
	if Tree[index][0] == -1 and Tree[index][1] == -1:
		print index,
	if Tree[index][0] != -1:
		queue.append(Tree[index][0])
	if Tree[index][1] != -1:
		queue.append(Tree[index][1])
