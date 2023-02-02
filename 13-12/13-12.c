#include <time.h>
#include <stdio.h>


char data_file[] = "datatime.dat";

void get_data(void)
{
	FILE* fp;

	if (fopen_s(&fp, data_file, "rb") != 0) {
		printf("�{�v���O���������s����̂͏��߂Ăł��ˁB\n");
	} else {
		struct tm temp;
		struct tm *timer = &temp;
		fread(timer, sizeof(struct tm), 1, fp);
		printf("�O���%d�N%d��%d��%d��%d��%d�b�ł����B\n", 
			timer->tm_year+1900, timer->tm_mon+1, timer->tm_mday, timer->tm_hour, timer->tm_min, timer->tm_sec);
		fclose(fp);
	}
}

void put_data(void)
{
	FILE* fp;
	if (fopen_s(&fp, data_file, "wb") != 0) {
		printf("\a�t�@�C�����I�[�v���ł��܂���B\n");
	} else {
		time_t current;
		time(&current);
		struct tm temp;
		struct tm* timer = &temp;
		localtime_s(timer, &current);

		fwrite(timer, sizeof(struct tm), 1, fp);
		fclose(fp);
	}
}

int main(void)
{
	get_data();
	put_data();
	return 0;
}