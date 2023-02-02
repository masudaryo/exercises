#include <time.h>
#include <stdio.h>

#define FEELING_STR_MAX 100

char data_file[] = "datatime.dat";

void get_data(void)
{
	FILE* fp;

	if (fopen_s(&fp, data_file, "r") != 0) {
		printf("本プログラムを実行するのは初めてですね。\n");
	} else {
		int year, month, day, h, m, s;
		char feeling[FEELING_STR_MAX] = "";

		fscanf_s(fp, "%d%d%d%d%d%d%s", &year, &month, &day, &h, &m, &s, feeling, FEELING_STR_MAX);
		printf("前回は%d年%d月%d日%d時%d分%d秒で、気分は%sでした。\n", year, month, day, h, m, s, feeling);

		fclose(fp);
	}
}

void put_data(void)
{
	FILE* fp;
	if (fopen_s(&fp, data_file, "w") != 0) {
		printf("\aファイルをオープンできません。\n");
	} else {
		char feeling[FEELING_STR_MAX] = "";
		time_t current;
		time(&current);
		struct tm temp;
		struct tm *timer = &temp;
		localtime_s(timer, &current);


		printf("現在の気分は：");
		scanf_s("%s", feeling, FEELING_STR_MAX);

		fprintf(fp, "%d %d %d %d %d %d %s\n",
			timer->tm_year + 1900, timer->tm_mon + 1, timer->tm_mday, timer->tm_hour, timer->tm_min, timer->tm_sec, feeling);
		fclose(fp);
	}
}

int main(void)
{
	get_data();
	put_data();
	return 0;
}