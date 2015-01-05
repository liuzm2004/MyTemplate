'''
We have a network of computers and a list of bi-directional connections. Each of these connections allows a file transfer from one computer to another. Is it possible to send a file from any computer on the network to any other?

Input Specification:

Each input file contains one test case. For each test case, the first line contains N (2<=N<=104), the total number of computers in a network. Each computer in the network is then represented by a positive integer between 1 and N. Then in the following lines, the input is given in the format:

I c1 c2  
where I stands for inputting a connection between c1 and c2; or

C c1 c2    
where C stands for checking if it is possible to transfer files between c1 and c2; or

S
where S stands for stopping this case.

Output Specification:

For each C case, print in one line the word "yes" or "no" if it is possible or impossible to transfer files between c1 and c2, respectively. At the end of each case, print in one line "The network is connected." if there is a path between any pair of computers; or "There are k components." where k is the number of connected components in this network.

Sample Input 1:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:
no
no
yes
There are 2 components.
Sample Input 2:
5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:
no
no
yes
yes
The network is connected.

运行超时
'''

def Find(S, X):
#    if S[X]==-1:
#        return -1
    while(S[X]!= -1):
        X = S[X]
    return X
    
def Union(S, X1, X2):
    root1 = Find(S, X1)
    root2 = Find(S, X2)
    if(root1!=root2):
        S[root2]=root1

def read_input():
    n = input()
    command_list = []
    while True:
        command = raw_input().split()
        if command[0]=='S':
            break
        command_list.append(command)
    return n, command_list

computers = [0]
n, command_list = read_input()
for x in range(n):
    computers.append(-1)
    
for i, command in enumerate(command_list):
    if command[0]=='I':
        Union(computers, int(command[1]), int(command[2]))
    if command[0]=='C':
        root1 = Find(computers, int(command[1]))
        root2 = Find(computers, int(command[2]))
        if root1==root2 and root1!=-1:
            print 'yes'
        else:
            print 'no'

cnt=0
for c in computers:
    if c==-1:
        cnt+=1

if cnt==1:
    print 'The network is connected.'
else:
    print 'There are %d components.' % cnt
