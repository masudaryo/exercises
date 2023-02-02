#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 16

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

	if (fopen_s(&sfp, sname, "rb") != 0) {
		printf("\a�R�s�[���t�@�C�����I�[�v���ł��܂���B\n");
	} else {
		if (fopen_s(&dfp, dname, "wb") != 0) {
			printf("\a�R�s�[��t�@�C�����I�[�v���ł��܂���B\n");
		} else {
			unsigned char buf[BUFFER_SIZE];
			int n;
			while ((n = fread(buf, 1, BUFFER_SIZE, sfp)) > 0) {
				fwrite(buf, 1, n, dfp);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}

	return 0;
}