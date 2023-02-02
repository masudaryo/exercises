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
		int count = 1;
		while ((ch = fgetc(fp)) != EOF) {
			if (ch == '\n') {
				count++;
			}
		}
		printf("The number of lines is %d.", count);
		fclose(fp);
	}

	return 0;
}