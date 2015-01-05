'''
05-1. List Components (25)

For a given undirected graph with N vertices and E edges, please list all the connected components by both DFS and BFS. Assume that all the vertices are numbered from 0 to N-1. While searching, assume that we always start from the vertex with the smallest index, and visit its adjacent vertices in ascending order of their indices.

Input Specification:

Each input file contains one test case. For each case, the first line gives two integers N (0<N<=10) and E, which are the number of vertices and the number of edges, respectively. Then E lines follow, each described an edge by giving the two ends. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in each line a connected component in the format "{ v1 v2 ... vk }". First print the result obtained by DFS, then by BFS.

Sample Input:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
Sample Output:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }


'''
def DFS(i, visited, graph):
    visited[i] = 1
    print i,
    for w in range(len(visited)):
        if visited[w] == 0 and graph[i][w] == 1:
            DFS(w, visited, graph)
            
def BFS(i, visited, graph, queue):
    visited[i] = 1
    queue.append(i)
    while queue != []:
        V = queue.pop(0)
        print V,
        for w in range(len(visited)):
            if visited[w] == 0 and graph[V][w] == 1:
                visited[w] = 1
                queue.append(w)



def ListComponents_DFS(graph, visited):
    for V in range(len(visited)):
        if visited[V] == 0:
            print '{',
            DFS(V, visited, graph)
            print '}'
    
            
def ListComponents_BFS(graph, visited, queue):
    for V in range(len(visited)):
        if visited[V] == 0:
            print '{',
            BFS(V, visited, graph, queue)
            print '}'
          
visited = []
graph = []
para = raw_input().split()
for x in range(int(para[0])):
    visited.append(0)
    graph.append([0])
for i in range(int(para[0])):
    for j in range(int(para[0])):
        graph[i].append(0)
        
for iter in range(int(para[1])):
    i,j = raw_input().split()
    graph[int(i)][int(j)] = 1
    graph[int(j)][int(i)] = 1
    
ListComponents_DFS(graph, visited)
for x in range(len(visited)):
    visited[x] = 0 
queue = []
ListComponents_BFS(graph, visited, queue)
                