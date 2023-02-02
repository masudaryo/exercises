#include <stdio.h>
#include <time.h>

void f(int a)
{
	printf("%d", a);
}

int main(void)
{
	double a = 3.1;
	f(a);
	return 0;
}

