/*
	�ǽ��� : 2023�� 3�� 21��
	�ǽ��� : ��ȫ��
	 �� �� : 202211286
	���α׷� ���� : ��¥���� ã�� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50
//�ϴ� �� ���ư��µ� �´��� �𸣰���
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
	printf("a[%d]�� ��¥ �����Դϴ�.\n", index);
}

int main(void)
{
	test();
	return 0;
}