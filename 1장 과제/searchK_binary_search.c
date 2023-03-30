/*
	실습자 : 이홍구
	 학 번 : 202211286
	프로그램 설명 : 정수형 배열에서 임의의 수를 2진탐색으로 찾는 프로그램
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define MAX_RAND 16

void reset_array(int a[],int n)
{
	srand((unsigned)time(NULL));
	printf("배열 값 :");
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % MAX_RAND;
		printf(" %d", a[i]);
	}
	printf("\n");
}

void sort_array(int a[], int n)
{
	int temp;
	printf("정렬된 배열 :");
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		printf(" %d", a[i]);
	}
	printf("\n");
}

int searchK(int a[], int k, int start_idex, int fin_index)
{
	int index = (fin_index - start_idex) / 2;
	if (index == 0)
		return -1;
	index += start_idex;
	if (a[index] == k)
	{
		return index;
	}
	else if(a[index]>k)
	{
		return searchK(a, k, start_idex, index);
	}
	else
	{
		return searchK(a, k, index, fin_index);
	}
}

void test()
{
	int a[ARRAY_SIZE];
	int index, K=10;
	reset_array(a, ARRAY_SIZE);
	sort_array(a, ARRAY_SIZE);
	index = searchK(a, K, 0, 9);
	if (index < 0)
	{
		printf("%d값이 없습니다.", K);
	}
	else
	{
		printf("%d값이 %d번째에 존재합니다.", a[index], index + 1);
	}
}

int main(void)
{
	test();
	return 0;
}