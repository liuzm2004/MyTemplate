//计算程序运行时间

#include <stdio.h>
#include <time.h>

clock_t start, stop;

double duration;

int int main(int argc, char const *argv[])
{
	start = clock();
	/* do something */
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
	return 0;
}