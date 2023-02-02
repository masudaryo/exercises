#include <stdio.h>

int main(void)
{
	FILE* fp;
	char filename[FILENAME_MAX] = "";
	printf("Input file path: ");
	scanf_s("%s", filename, FILENAME_MAX);
	if (fopen_s(&fp, filename, "r") == 0) {
		printf("%s exists.", filename);
		fclose(fp);
	} else {
		printf("%s does not exist.", filename);
	}

	return 0;
}