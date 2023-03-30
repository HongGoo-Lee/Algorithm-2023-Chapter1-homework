/*
	�ǽ��� : 2023�� 3�� 21��
	�ǽ��� : ��ȫ��
	 �� �� : 202211286
	���α׷� ���� : ��¥���� ã�� ���α׷�
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//5. �迭�� ũ�⸦ ���Ѵ�.
#define ARRAY_SIZE 50

void creat_fake_coin(int coin_array[], int array_size)
{
	int i, fake_coin;
	srand((unsigned)time(NULL));
	//3. �迭�� ũ�⸦ ���� �ʴ� �������� ������ ���Ѵ�.
	fake_coin = rand() % array_size;
	//2. ��� ���Ҹ� 1�� �ʱ�ȭ�Ѵ�.
	for (i = 0; i < array_size; i++)
	{
		//4. ������ ������ ��ġ�� ���Ҹ� 0���� �����.
		if (i == fake_coin)
		{
			coin_array[i] = 0;
			printf("%d ", coin_array[i]);
		}
		else
		{
			coin_array[i] = 1;
			printf("%d ", coin_array[i]);
		}
	}
	printf("\n");
}

int find_fake_coin(int coin_array[], int start_index, int fin_index, int array_size)
{
	int sum1=0, sum2=0, array_half,i;
	
	//6. �迭�� ù ��° ���ҿ� ������ ������ ��ġ�� ������ �迭�� ù ��° ������ ��ġ�� ��ȯ�Ѵ�.
	if (start_index == fin_index)
		return start_index;

	//7. �迭�� ũ�Ⱑ 2 �̸� 2���� ���� ���Ͽ� ���� ���� ������ ��ġ�� ��ȯ�Ѵ�.
	if (array_size == 2)
	{
		if (coin_array[start_index] < coin_array[fin_index])
			return start_index;
		else if (coin_array[start_index] > coin_array[fin_index])
			return fin_index;
		else
			return fin_index + 1;
	}
	//8. �迭�� ũ�Ⱑ Ȧ���̸� 1�� ����.
	if (array_size % 2 == 1)
	{
		fin_index -= 1;
		array_size -= 1;
	}
	//9. �迭�� �������� ������.
	array_half = array_size / 2;
	//10. ������ �迭�� ���ҵ��� �� ���Ѱ��� ���Ѵ�.
	for (i = start_index; i < array_half+start_index; i++)
	{
		sum1 += coin_array[i];
	}
	for (i = array_half+start_index; i <= fin_index; i++)
	{
		sum2 += coin_array[i];
	}
	printf("sum1 = %d, sum2 = %d\n",sum1,sum2);
	//11. �� ���� ���Ѵ�.
	//12. ���� ���� �迭�� ã�� 2������ �ٽ� �����Ѵ�.
	if (sum1 < sum2)
	{
		return find_fake_coin(coin_array, start_index, array_half - 1 + start_index, array_half);
	}
	else if (sum1 > sum2)
	{
		return find_fake_coin(coin_array, array_half + start_index, fin_index, array_half);
	}
	//13. ���� ���� ������ ���ܵ� ������ ��ġ�� ��ȯ�Ѵ�.
	else
	{
		return fin_index + 1;
	}	
}

void test(void)
{
	//1. ������ �迭�� �����.
	int coin_array[ARRAY_SIZE],index=-1;
	creat_fake_coin(coin_array, ARRAY_SIZE);
	index = find_fake_coin(coin_array, 0, ARRAY_SIZE-1,ARRAY_SIZE);
	printf("a[%d]�� ��¥ �����Դϴ�.\n", index);
}

int main(void)
{
	test();
	return 0;
}