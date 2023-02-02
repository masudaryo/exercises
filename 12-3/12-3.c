#include <stdio.h>

#define NAME_LEN 64


typedef struct {
	char name[NAME_LEN];
	int height;
	double weight;
} Student;

Student scan_Student()
{
	Student temp;
	printf("Input name: ");
	scanf_s("%s", temp.name, NAME_LEN);
	printf("Input height: ");
	scanf_s("%d", &temp.height);
	printf("Input weight: ");
	scanf_s("%lf", &temp.weight);
	return temp;
}

int main(void)
{
	Student temp = scan_Student();
	printf("name: %s, height: %d, weight: %lf", temp.name, temp.height, temp.weight);

	return 0;
}