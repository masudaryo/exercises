#include <stdio.h>

int main(void)
{
	FILE* fp;
	char filename[FILENAME_MAX] = "";
	printf("Input file path: ");
	scanf_s("%s", filename, FILENAME_MAX);
	if (fopen_s(&fp, filename, "r") == 0) {
		fclose(fp);
		if (fopen_s(&fp, filename, "w") == 0) {
			fclose(fp);
			printf("Deleted the contents of %s.", filename);
		}
	} else {
		printf("%s does not exist.", filename);
	}

	return 0;
}