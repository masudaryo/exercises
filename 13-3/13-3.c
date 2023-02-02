#include <stdio.h>

#define NAME_LEN 64
#define MAX_STUDENTS_NUM 10

typedef struct {
	char name[NAME_LEN];
	double height;
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





int main(void)
{
	FILE* fp;

	if (fopen_s(&fp, "hw.txt", "r") != 0) {
		printf("\aファイルをオープンできません。\n");
	} else {
		int ninzu = 0;
		char name[NAME_LEN];
		double height, weight;
		double hsum = 0.0;
		double wsum = 0.0;
		Student students[MAX_STUDENTS_NUM];
		int students_len = 0;

		for (; fscanf_s(fp, "%s%lf%lf", students[students_len].name, NAME_LEN, &students[students_len].height, &students[students_len].weight) == 3; students_len++) {
			ninzu++;
			hsum += students[students_len].height;
			wsum += students[students_len].weight;
		}
		sort_by(students, students_len, 'h');
		for (int i = 0; i < students_len; i++) {
			printf("%-10s %5.1f %5.1f\n", students[i].name, students[i].height, students[i].weight);
		}
		printf("-----------------------------\n");
		printf("平均 　　　%5.1f %5.1f\n", hsum / ninzu, wsum / ninzu);
		fclose(fp);
	}

	return 0;
} 