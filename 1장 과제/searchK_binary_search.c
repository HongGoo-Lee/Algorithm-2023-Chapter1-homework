/*
	�ǽ��� : ��ȫ��
	 �� �� : 202211286
	���α׷� ���� : ������ �迭���� ������ ���� 2��Ž������ ã�� ���α׷�
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define MAX_RAND 16

void reset_array(int a[],int n)
{
	srand((unsigned)time(NULL));
	printf("�迭 �� :");
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
	printf("���ĵ� �迭 :");
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
		printf("%d���� �����ϴ�.", K);
	}
	else
	{
		printf("%d���� %d��°�� �����մϴ�.", a[index], index + 1);
	}
}

int main(void)
{
	test();
	return 0;
}