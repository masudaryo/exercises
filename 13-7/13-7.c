#include <stdio.h>

int main(void)
{
	FILE* fp;
	char fname[FILENAME_MAX] = "";

	printf("Input filename: ");
	scanf_s("%s", fname, FILENAME_MAX);

	if (fopen_s(&fp, fname, "r") != 0) {
		printf("Could not open %s.\n", fname);
	} else {
		char ch;
		int count = 0;
		while ((ch = fgetc(fp)) != EOF) {
			if ('0' <= ch && ch <= '9') {
				count++;
			}
		}
		printf("The number of numbers is %d.", count);
		fclose(fp);
	}

	return 0;
}