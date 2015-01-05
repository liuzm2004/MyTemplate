/*
05-3. 六度空间 (30)

“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”如图6.4所示。


图6.4 六度空间示意图

“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

输入格式说明：

输入第1行给出两个正整数，分别表示社交网络图的结点数N （1<N<=104，表示人数）、边数M（<=33*N，表示社交关系数）。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。

输出格式说明：

对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

样例输入与输出：

序号  输入  输出
1   
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
2   
10 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
9 10
1: 70.00%
2: 80.00%
3: 80.00%
4: 80.00%
5: 80.00%
6: 80.00%
7: 80.00%
8: 70.00%
9: 20.00%
10: 20.00%
3   
11 10
1 2
1 3
1 4
4 5
6 5
6 7
6 8
8 9
8 10
10 11
1: 100.00%
2: 90.91%
3: 90.91%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 100.00%
9: 100.00%
10: 100.00%
11: 81.82%
4   
2 1
1 2
1: 100.00%
2: 100.00%
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int BFS(int v, vector<vector<int> >&graph, vector<int> &visited)
{
	queue<int> q;
	visited[v] = 1;
	int count =1;
	int level = 0, last = v, tail = 0;
	q.push(v);
	int V = 0;
	while(!q.empty())
	{
		V = q.front();
		q.pop();
		for (int w = 1; w < visited.size(); ++w)
		{
			if (visited[w] == 0 && graph[V][w] == 1)
			{
				visited[w] = 1;
				q.push(w);
				count++;
				tail = w;
			}
		}
		if (V == last)
		{
			level++;
			last = tail;
		}
		if (level == 6) break;

	}
	return count;
}

void SDS(vector<vector<int> >&graph, vector<int> &visited)
{
	int count = 0;
	for (int i = 1; i < visited.size(); ++i)
	{
		count = BFS(i, graph, visited);
		printf("%d: %.2f%%\n", i, 100*double(count)/(visited.size()-1));
		for (int j = 1; j < visited.size(); ++j)
		{
			visited[j] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<int> visited;
	vector<vector<int> > graph;
	int num, edge;
	int v1, v2;
	cin>>num>>edge;
	for (int i = 0; i < num+1; ++i)
	{
		visited.push_back(0);
	}

	for (int j = 0; j < num+1; ++j)
	{
		graph.push_back(visited);
	}

	for (int m = 0; m < edge; ++m)
	{
		cin>>v1>>v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	SDS(graph, visited);
	return 0;
}