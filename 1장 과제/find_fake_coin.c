/*
	실습일 : 2023년 3월 21일
	실습자 : 이홍구
	 학 번 : 202211286
	프로그램 설명 : 가짜동전 찾는 프로그램
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//5. 배열의 크기를 구한다.
#define ARRAY_SIZE 50

void creat_fake_coin(int coin_array[], int array_size)
{
	int i, fake_coin;
	srand((unsigned)time(NULL));
	//3. 배열의 크기를 넘지 않는 범위에서 난수를 구한다.
	fake_coin = rand() % array_size;
	//2. 모든 원소를 1로 초기화한다.
	for (i = 0; i < array_size; i++)
	{
		//4. 구해진 난수의 위치한 원소를 0으로 만든다.
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
	
	//6. 배열의 첫 번째 원소와 마지막 원소의 위치가 같으면 배열의 첫 번째 원소의 위치를 반환한다.
	if (start_index == fin_index)
		return start_index;

	//7. 배열의 크기가 2 이면 2개의 값을 비교하여 값이 작은 원소의 위치를 반환한다.
	if (array_size == 2)
	{
		if (coin_array[start_index] < coin_array[fin_index])
			return start_index;
		else if (coin_array[start_index] > coin_array[fin_index])
			return fin_index;
		else
			return fin_index + 1;
	}
	//8. 배열의 크기가 홀수이면 1을 뺀다.
	if (array_size % 2 == 1)
	{
		fin_index -= 1;
		array_size -= 1;
	}
	//9. 배열을 절반으로 나눈다.
	array_half = array_size / 2;
	//10. 각각의 배열의 원소들을 다 더한값을 구한다.
	for (i = start_index; i < array_half+start_index; i++)
	{
		sum1 += coin_array[i];
	}
	for (i = array_half+start_index; i <= fin_index; i++)
	{
		sum2 += coin_array[i];
	}
	printf("sum1 = %d, sum2 = %d\n",sum1,sum2);
	//11. 그 값을 비교한다.
	//12. 값이 작은 배열을 찾고 2번부터 다시 실행한다.
	if (sum1 < sum2)
	{
		return find_fake_coin(coin_array, start_index, array_half - 1 + start_index, array_half);
	}
	else if (sum1 > sum2)
	{
		return find_fake_coin(coin_array, array_half + start_index, fin_index, array_half);
	}
	//13. 만약 값이 같으면 제외된 원소의 위치를 반환한다.
	else
	{
		return fin_index + 1;
	}	
}

void test(void)
{
	//1. 정수형 배열을 만든다.
	int coin_array[ARRAY_SIZE],index=-1;
	creat_fake_coin(coin_array, ARRAY_SIZE);
	index = find_fake_coin(coin_array, 0, ARRAY_SIZE-1,ARRAY_SIZE);
	printf("a[%d]가 가짜 동전입니다.\n", index);
}

int main(void)
{
	test();
	return 0;
}