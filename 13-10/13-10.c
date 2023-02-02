#include <stdio.h>
#include <ctype.h>

int main(void)
{
	FILE* sfp;
	FILE* dfp;
	char sname[FILENAME_MAX] = "";
	char dname[FILENAME_MAX] = "";

	printf("コピー元ファイル名：");
	scanf_s("%s", sname, FILENAME_MAX);
	printf("コピー先ファイル名：");
	scanf_s("%s", dname, FILENAME_MAX);

	if (fopen_s(&sfp, sname, "r") != 0) {
		printf("\aコピー元ファイルをオープンできません。\n");
	} else {
		if (fopen_s(&dfp, dname, "w") != 0) {
			printf("\aコピー先ファイルをオープンできません。\n");
		} else {
			int ch;
			while ((ch = fgetc(sfp)) != EOF) {
				fputc(tolower(ch), dfp);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}

	return 0;
}