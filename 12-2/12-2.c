#include <stdio.h>

struct xyz {
	int x;
	long y;
	double z;
};

struct xyz scan_xyz()
{
	struct xyz temp;
	printf("Input int: ");
	scanf_s("%d", &temp.x);
	printf("Input long: ");
	scanf_s("%ld", &temp.y);
	printf("Input double: ");
	scanf_s("%le", &temp.z);
	return temp;
}

int main(void)
{
	struct xyz temp = scan_xyz();
	printf("x = %d, y = %ld, z = %le\n", temp.x, temp.y, temp.z);

	return 0;
}