#include <stdio.h>

#define NAME_LEN 64
#define MAX_STUDENTS_NUM 10

typedef struct {
	char name[NAME_LEN];
	double height;
	double weight;
} Student;





Student scan_Student()
{
	Student temp;
	printf("Input name: ");
	scanf_s("%s", temp.name, NAME_LEN);
	printf("Input height: ");
	scanf_s("%lf", &temp.height);
	printf("Input weight: ");
	scanf_s("%lf", &temp.weight);
	return temp;
}



int main(void)
{
	FILE* fp;

	if (fopen_s(&fp, "hw.txt", "w") != 0) {
		printf("\aファイルをオープンできません。\n");
	} else {
		int ninzu = 0;
		char name[NAME_LEN];
		double height, weight;
		double hsum = 0.0;
		double wsum = 0.0;
		Student students[MAX_STUDENTS_NUM];
		int students_len = 0;
		char temp = '\0';

		for (; students_len < MAX_STUDENTS_NUM; students_len++) {
			printf("Do you want to input a Student? [y/n] ");
			scanf_s(" %c", &temp, 1);
			if (temp == 'y') {
				students[students_len] = scan_Student();
				ninzu++;
				hsum += students[students_len].height;
				wsum += students[students_len].weight;
			} else if (temp == 'n') {
				break;
			} else {
				students_len--;
				continue;
			}
		}

		for (int i = 0; i < students_len; i++) {
			fprintf(fp, "%-10s %5.1f %5.1f\n", students[i].name, students[i].height, students[i].weight);
		}
		fprintf(fp, "-----------------------------\n");
		fprintf(fp, "平均 　　　%5.1f %5.1f\n", hsum / ninzu, wsum / ninzu);
		printf("Wrote the data to hw.txt.");
		fclose(fp);
	}

	return 0;
}