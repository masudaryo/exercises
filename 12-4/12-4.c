#include <stdio.h>
#include <string.h>

#define NUMBER 5
#define NAME_LEN 64

typedef struct {
	char name[NAME_LEN];
	int height;
	double weight;
} Student;

void swap_Student(Student* x, Student* y)
{
	Student temp = *x;
	*x = *y;
	*y = temp;
}

_Bool greater_than(char s1[], char s2[])
{
	for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
		if (s1[i] > s2[i]) {
			return 1;
		} else if (s1[i] == s2[i]) {
			continue;
		} else if (s1[i] < s2[i]) {
			return 0;
		}
	}
	return 0;
}

void sort_by(Student a[], int n, char by)
{
	_Bool temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (by == 'h') {
				temp = a[j - 1].height > a[j].height;
			} else if (by == 'n') {
				temp = greater_than(a[j - 1].name, a[j].name);
			} else {
				printf("The argument by is invalid.");
				return;
			}
			if (temp) {
				swap_Student(&a[j - 1], &a[j]);
			}
		}
	}
}



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
	Student std[NUMBER];
	char temp = '\0';

	int std_len = 0;
	for (; std_len < NUMBER; std_len++) {
		printf("Do you want to input a Student? [y/n] ");
		scanf_s(" %c", &temp, 1);
		if (temp == 'y') {
			std[std_len] = scan_Student();
		} else if (temp == 'n') {
			break;
		} else {
			std_len--;
			continue;
		}
	}
	
	temp = '\0';
	printf("sort by [h(eight)/n(ame)] ");
	scanf_s(" %c", &temp, 1);
	sort_by(std, std_len, temp);


	for (int i = 0; i < std_len; i++) {
		printf("%-8s %6d%6.1f\n", std[i].name, std[i].height, std[i].weight);
	}

	return 0;
}