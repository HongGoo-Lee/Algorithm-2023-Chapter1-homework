/*
	실습자 : 이홍구
	 학 번 : 202211286
	프로그램 설명 : 가장 큰 수를 구하는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void reset_array(int a[],int n)
{
	srand((unsigned)time(NULL));
	printf("배열 값 :");
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
		printf(" %d", a[i]);
	}
	printf("\n");
}

int find_max(int a[], int n)
{
	int max = a[0], i;
	for (i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

void test_find_max(void)
{
	int a[ARRAY_SIZE];
	reset_array(a, ARRAY_SIZE);
	printf("max = %d\n", find_max(a, ARRAY_SIZE));
}

int main(void)
{
	test_find_max();
	return 0;
}