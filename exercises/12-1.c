#include <stdio.h>
#define NAME_LEN 64


struct student {
	char name[NAME_LEN];
	int height;
	double weight;
};

int main(void)
{
	struct student takao = {"Takao", 173};
	printf("The address of\n  name: %#llX\nheight: %#llX\nweight: %#llX\n", (long long)(&(takao.name)), (long long)(&(takao.height)), (long long)(&(takao.weight)));

	return 0;
}