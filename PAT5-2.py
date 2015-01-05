'''
05-2. Saving James Bond - Easy Version (25)

This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a 100 by 100 square one. Assume that the center of the lake is at (0,0) and the northeast corner at (50,50). The central island is a disk centered at (0,0) with the diameter of 15. A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him whether or not he can escape.

Input Specification:

Each input file contains one test case. Each case starts with a line containing two positive integers N (<=100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x, y) location of a crocodile. Note that no two crocodiles are staying at the same position.

Output Specification:

For each test case, print in a line "Yes" if James can escape, or "No" if not.

Sample Input 1:
14 20
25 -15
-25 28
8 49
29 15
-35 -2
5 28
27 -29
-8 -28
-20 -35
-25 -20
-13 29
-30 15
-35 40
12 12
Sample Output 1:
Yes
Sample Input 2:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
No
'''
def isSafe(v, graph, dist):
    if (graph[v][0] <= dist - 50) or (graph[v][0] >= 50 -dist)\
    or (graph[v][1] >= 50 - dist) or (graph[v][1] <= dist - 50):
        return 1
    elif (graph[v][0] == 0) and (graph[v][1] == 0):
        if (graph[v][0]-15 <= dist - 50) or (graph[v][0]+15 >= 50 -dist)\
        or (graph[v][1]+15 >= 50 - dist) or (graph[v][1]-15 <= dist - 50):
            return 1
    else:
        return 0

def Jump(v, w, graph, dist):
    if graph[v][0] == 0 and graph[v][1] == 0:
        if (graph[v][0]-graph[w][0])**2 + (graph[v][1]-graph[w][1])**2\
        <= (15+dist)**2:
            return 1
        else:
            return 0
    else:
        if (graph[v][0]-graph[w][0])**2 + (graph[v][1]-graph[w][1])**2\
        <= (dist)**2:
            return 1
        else:
            return 0
            
def DFS(v, graph, dist):
    graph[v][2] = 1
    answer = 'No'
    if isSafe(v, graph, dist):
        answer = 'Yes'
    else:
        for w in range(len(graph)):
            if (graph[w][2] == 0) and (Jump(v, w, graph, dist)):
                answer = DFS(w, graph, dist)
                if answer == 'Yes':
                    break
    return answer
            
v,dist = raw_input().split()
graph=[]
graph.append([0, 0, 0])
for x in range(int(v)):
    i,j = raw_input().split()
    graph.append([int(i), int(j), 0])

print DFS(0, graph, int(dist))