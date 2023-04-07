/*
	�ǽ��� : 2023�� 4�� 7��
	�ǽ��� : ��ȫ��
	 �� �� : 202211286
	���α׷� ���� : ������ ã�� ���α׷�
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ARRAY_SIZE 100
#define BOTTLE_ARRAY 9

void reset_array(int bottle_array[], int array_size)
{
	srand((unsigned)time(NULL));
	int poison = rand() % array_size;
	printf("������: ");
	for (int i = 0; i < array_size; i++)
	{
		if (i == poison)
		{
			bottle_array[i] = 1;
			printf("�� ");
		}
		else
		{
			bottle_array[i] = 0;
			printf("�� ");
		}
	}
	printf("\n");
}

int find_n_bit(int array_size)
{
	int n = 0, a, b;
	while (1)
	{
		a = pow(2.0, n);
		b = pow(2.0, n + 1);
		if (a < array_size && array_size < b)
		{
			break;
		}
		n++;
	}
	printf("%d��Ʈ�� ǥ���� �����մϴ�.\n", n + 1);
	return n + 1;
}

int find_poison(int bottle_array[], int bit, int n)
{
	int p[ARRAY_SIZE] = { 0 }, i = 0, j = 0, a = 0, res = 0;
	a = 1;
	
	//	�̷��� n��° ������� ������ �ο��Ѵ�.
	for (i = 0; i < bit; i++)
	{
		a *= 2;
		//3. n��Ʈ�� ǥ���� ������ �� 
		//1��° ����� �ֱ�� �� ������ �Դ´�. 
		//2��° ����� �ֱ�� �� ������ �Դ´�.
		for (j = 1; j <= n; j++)
		{
			//4. ���� ����� üũ�Ͽ� ������ 1, ��������� 0 ���� �ؼ� 2������ ���Ѵ�.
			if (((j % a) > (a / 2)) || (j%a == 0))
			{
				p[i] += bottle_array[j-1];
			}
		}
	}

	a = 1;
	//5, ������ 2������ 10������ �ٲ۴�.
	for (i = 0; i < bit; i++)
	{
		printf("%d: %d\n", i, p[i]);
		res += (a * p[i]);
		a *= 2;
	}
	return res;
}


void test()
{
	int bottle_array[BOTTLE_ARRAY] = { 0 }, array_size = 0, bit = 0, poison = 0;
	//1. ���� �� �� ������ ������ ���Ѵ�.
	array_size = sizeof(bottle_array) / sizeof(int);
	//2. �� ��Ʈ�� ǥ���� �������� ���Ѵ�.
	reset_array(bottle_array, array_size);
	bit = find_n_bit(array_size);
	poison = find_poison(bottle_array, bit, array_size);
	printf("���� �� �������� %d�� �Դϴ�.", poison+1);
}

int main(void)
{
	test();
	return 0;
}