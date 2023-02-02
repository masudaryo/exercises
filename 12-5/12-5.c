#include <math.h>
#include <stdio.h>

#define sqr(n) ((n) * (n))

typedef struct {
	double x;
	double y;
} Point;

typedef struct {
	Point pt;
	double fuel;
} Car;

double distance_of(Point p1, Point p2)
{
	return sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

void put_info(Car c)
{
	printf("���݈ʒu�F(%.2f, %.2f)\n", c.pt.x, c.pt.y);
	printf("�c��R���F%.2f���b�g��\n", c.fuel);
}

int move(Car* c, Point dest)
{
	double d = distance_of(c->pt, dest);
	if (d > c->fuel) {
		return 0;
	}
	c->pt = dest;
	c->fuel -= d;
	return 1;
}

int main(void)
{
	Car mycar = { {0.0, 0.0}, 90.0 };
	while (1) {
		int select;
		char select2;
		double temp;
		Point dest = mycar.pt;
		put_info(mycar);
		printf("�ړ����܂����yYes...1 / No...0�z�F");
		scanf_s("%d", &select);
		if (select != 1) break;
		printf("�ړI�n�̓��͕����y��΍��W...a / ���΍��W...r�z�F");
		scanf_s(" %c", &select2, 1);
		if (select2 == 'a') {
			printf("�ړI�n��x���W�F");
			scanf_s("%lf", &dest.x);
			printf("�ړI�n��y���W�F");
			scanf_s("%lf", &dest.y);
		} else if (select2 == 'r') {
			printf("�ړI�n�̑���x���W�F");
			scanf_s("%lf", &temp);
			dest.x += temp;
			printf("�ړI�n�̑���y���W�F");
			scanf_s("%lf", &temp);
			dest.y += temp;
		}
		if (!move(&mycar, dest)) {
			puts("\a�R���s���ňړ��ł��܂���B");
		}
	}
	return 0;
}
