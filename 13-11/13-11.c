#include <stdio.h>
#define DATA_LEN 10

int main(void)
{
	FILE* fp;
	char src_filename[FILENAME_MAX] = "";
	char dst_filename[FILENAME_MAX] = "";
	double data[DATA_LEN] = { 10.2, 30.54830, 201.249302, 48.4830, 401.84302, 432.4302, 4020, 8761.42 };
	char temp;
	printf("Do you want to input source file? [y/n] ");
	scanf_s(" %c", &temp, 1);
	if (temp == 'y') {
		printf("Input source filename: ");
		scanf_s("%s", src_filename, FILENAME_MAX);
		if (fopen_s(&fp, src_filename, "rb") != 0) {
			printf("Could not open source file.");
			return 0;
		} else {
			for (int i = 0; i < DATA_LEN; i++) {
				fread(&data[i], sizeof(double), 1, fp);
			}
			fclose(fp);
		}
	}

	printf("data:");
	for (int i = 0; i < DATA_LEN; i++) {
		printf(" %lf", data[i]);
	}
	printf("\n");

	printf("Input destination filename: ");
	scanf_s("%s", dst_filename, FILENAME_MAX);

	if (fopen_s(&fp, dst_filename, "wb") != 0) {
		printf("Could not open destinatoin file.");
		return 0;
	} else {
		for (int i = 0; i < DATA_LEN; i++) {
			fwrite(&data[i], sizeof(double), 1, fp);
		}
		fclose(fp);
	}

	return 0;
}