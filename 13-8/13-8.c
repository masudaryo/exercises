#include <stdio.h>

int main(void)
{
	FILE* sfp;
	FILE* dfp;
	char sname[FILENAME_MAX] = "";
	char dname[FILENAME_MAX] = "";

	printf("�R�s�[���t�@�C�����F");
	scanf_s("%s", sname, FILENAME_MAX);
	printf("�R�s�[��t�@�C�����F");
	scanf_s("%s", dname, FILENAME_MAX);

	if (fopen_s(&sfp, sname, "r") != 0) {
		printf("\a�R�s�[���t�@�C�����I�[�v���ł��܂���B\n");
	} else {
		if (fopen_s(&dfp, dname, "w") != 0) {
			printf("\a�R�s�[��t�@�C�����I�[�v���ł��܂���B\n");
		} else {
			int ch;
			while ((ch = fgetc(sfp)) != EOF) {
				putchar(ch);
				fputc(ch, dfp);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}

	return 0;
}