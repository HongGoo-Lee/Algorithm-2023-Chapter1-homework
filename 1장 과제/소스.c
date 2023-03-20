#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20
//오류나서 고쳐야함
void creat_fake_coin(int a[], int n)
{
	int i, fake_coin;
	srand((unsigned)time(NULL));
	fake_coin = rand()%n;
	for (i = 0; i < n; i++)
	{
		if (i == fake_coin)
		{
			a[i] = 0;
			printf("%d\n", i);
		}
		else
		{
			a[i] = 1;
		}
	}
}

int find_fake_coin(int a[], int start_index, int fin_index)
{
	int sum1=0, sum2=0, b,i;
	b = fin_index - start_index;
	if (b % 2 == 0)
	{
		fin_index -= 1;
		b = fin_index - start_index;		
	}

	for (i = start_index; i <= (b / 2) + start_index; i++)
	{
		sum1 += a[i];
	}
	for (; i <= fin_index; i++)
	{
		sum2 += a[i];
	}

	if (sum1 == 0)
	{
		return start_index;
	}
	else if (sum2 == 0)
	{
		return fin_index;
	}
	else if (sum1 > sum2)
	{
		return find_fake_coin(a, b / 2 + 1, fin_index);
	}
	else if (sum1 < sum2)
	{
		return find_fake_coin(a, start_index, (b / 2) + start_index);
	}
	else
	{
		return fin_index+1;
	}
}

void test(void)
{
	int a[ARRAY_SIZE],index=-1;
	creat_fake_coin(a, ARRAY_SIZE);
	index = find_fake_coin(a, 0, ARRAY_SIZE-1);
	printf("%d번에 있습니다.\n", index);
}

int main(void)
{
	test();
	return 0;
}