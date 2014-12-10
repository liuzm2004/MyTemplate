/***********************************************
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
***************************************************/

#include <iostream>
#include <string>

using namespace std;

typedef struct Node
{
	string ad;
	long cell;
	string next;
}node;
const long MAXSIZE = 10000;

int main(int argc, char const *argv[])
{
	node list[MAXSIZE];
	node list_sort[MAXSIZE];
	long cell;
	string ad, next;

	long num, K;
	string first;

	cin>>first>>num>>K;

	for(int i = 0; i < num; ++i)
	{
		cin>>ad>>cell>>next;
		list[i].ad = ad;
		list[i].cell = cell;
		list[i].next = next;
	}

	for (int i = 0; i < num; ++i)
		if (list[i].ad == first)
		{
			list_sort[0].ad = list[i].ad;
			list_sort[0].cell = list[i].cell;
			list_sort[0].next = list[i].next;
		}

	for (int i = 1; i < num; ++i)
		for (int j = 0; j < num; ++j)
		{
			if (list_sort[i-1].next == list[j].ad)
			{
				list_sort[i].ad = list[j].ad;
				list_sort[i].cell = list[j].cell;
				list_sort[i].next = list[j].next;
			}
		}



	for (int i = K-1; i < num - num%K; i+=K)
	{
		for (int j = i; j >= i-K+1; --j)
		{
			list[K-1-j].ad = list_sort[j].ad;
			list[K-1-j].cell = list_sort[j].cell;
			list[K-1-j].next = list_sort[j].next;
		}
	}

	for (int i = num - num%K; i < num; ++i)
	{
			list[i].ad = list_sort[i].ad;
			list[i].cell = list_sort[i].cell;
			list[i].next = list_sort[i].next;
	}

	for (int i = 0; i < num-1; ++i)
	{
		list[i].next = list[i+1].ad;
	}

	list[num].next = -1;
	for (int i = 0; i < num; ++i)
	{
		cout<<list[i].ad<<" "<<list[i].cell<<
		" "<<list[i].next<<endl;
	}


	return 0;
}