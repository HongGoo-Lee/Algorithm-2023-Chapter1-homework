#include <stdio.h>

typedef struct coins {
	int five_h;
	int one_h;
	int fifteen;
	int ten;
}COINS;

COINS find_coin(int total)
{
	COINS res = { 0 };
	res.five_h = total / 500;
	total %= 500;
	res.one_h = total / 100;
	total %= 100;
	res.fifteen = total / 50;
	total %= 50;
	res.ten = total / 10;

	return res;
}

void test(void)
{
	COINS res;
	int total = 990;
	res = find_coin(total);
	printf("500�� : %d��\n", res.five_h);
	printf("100�� : %d��\n", res.one_h);
	printf(" 50�� : %d��\n", res.fifteen);
	printf(" 10�� : %d��\n", res.ten);
}

int main(void)
{
	test();
	return 0;
}