#include <time.h>
#include <stdio.h>


char data_file[] = "datatime.dat";

void get_data(void)
{
	FILE* fp;

	if (fopen_s(&fp, data_file, "rb") != 0) {
		printf("本プログラムを実行するのは初めてですね。\n");
	} else {
		struct tm temp;
		struct tm *timer = &temp;
		fread(timer, sizeof(struct tm), 1, fp);
		printf("前回は%d年%d月%d日%d時%d分%d秒でした。\n", 
			timer->tm_year+1900, timer->tm_mon+1, timer->tm_mday, timer->tm_hour, timer->tm_min, timer->tm_sec);
		fclose(fp);
	}
}

void put_data(void)
{
	FILE* fp;
	if (fopen_s(&fp, data_file, "wb") != 0) {
		printf("\aファイルをオープンできません。\n");
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