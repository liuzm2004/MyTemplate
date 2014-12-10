/*************************************************
设计函数求一元多项式的导数。

输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是0，但是表示为“0 0”。

输入样例：
3 4 -5 2 6 1 -2 0
输出样例：
12 3 -10 1 6 0
*************************************************/

#include <iostream>

using namespace std;

typedef struct Node
{
	long co;
	long ex;
}node;

const long MAXSIZE = 10000;

int main(int argc, char const *argv[])
{
	node List[MAXSIZE];
	long coff,expe;
	long length = 0;

	while(cin>>coff>>expe)
	{
		List[length].co = coff;
		List[length].ex = expe;
		length++;
	}


	for (int i = 0; i < length; ++i)
	{
		if(List[i].ex == 0)
			break;
		else if(i != length-2)
			{
				cout<<List[i].co * List[i].ex<<" "
				<<List[i].ex -1<< " ";
			}
		else 
			cout<<List[i].co * List[i].ex<<" "
				<<List[i].ex -1;
	}


	return 0;
}