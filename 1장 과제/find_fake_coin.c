/*
	실습일 : 2023년 3월 21일
	실습자 : 이홍구
	 학 번 : 202211286
	프로그램 설명 : 가짜동전 찾는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50
//일단 잘 돌아가는데 맞는지 모르겠음
void creat_fake_coin(int a[], int array_size)
{
	int i, fake_coin;
	srand((unsigned)time(NULL));
	fake_coin = rand() % array_size;
	for (i = 0; i < array_size; i++)
	{
		if (i == fake_coin)
		{
			a[i] = 0;
			printf("%d ", a[i]);
		}
		else
		{
			a[i] = 1;
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}

int find_fake_coin(int a[], int start_index, int fin_index, int array_size)
{
	int sum1=0, sum2=0, array_half,i;
	
	if (start_index == fin_index)
		return start_index;

	if (array_size == 2)
	{
		if (a[start_index] < a[fin_index])
			return start_index;
		else if (a[start_index] > a[fin_index])
			return fin_index;
		else
			return fin_index + 1;
	}

	if (array_size % 2 == 1)
	{
		fin_index -= 1;
		array_size -= 1;
	}

	array_half = array_size / 2;
	for (i = start_index; i < array_half+start_index; i++)
	{
		sum1 += a[i];
	}
	for (i = array_half+start_index; i <= fin_index; i++)
	{
		sum2 += a[i];
	}
	printf("sum1 = %d, sum2 = %d\n",sum1,sum2);

	if (sum1 < sum2)
	{
		return find_fake_coin(a, start_index, array_half - 1 + start_index, array_half);
	}
	else if (sum1 > sum2)
	{
		return find_fake_coin(a, array_half + start_index, fin_index, array_half);
	}
	else
	{
		return fin_index + 1;
	}	
}

void test(void)
{
	int a[ARRAY_SIZE],index=-1;
	creat_fake_coin(a, ARRAY_SIZE);
	index = find_fake_coin(a, 0, ARRAY_SIZE-1,ARRAY_SIZE);
	printf("a[%d]가 가짜 동전입니다.\n", index);
}

int main(void)
{
	test();
	return 0;
}