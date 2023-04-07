/*
	실습일 : 2023년 4월 7일
	실습자 : 이홍구
	 학 번 : 202211286
	프로그램 설명 : 술단지 찾는 프로그램
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
	printf("술단지: ");
	for (int i = 0; i < array_size; i++)
	{
		if (i == poison)
		{
			bottle_array[i] = 1;
			printf("독 ");
		}
		else
		{
			bottle_array[i] = 0;
			printf("술 ");
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
	printf("%d비트로 표현이 가능합니다.\n", n + 1);
	return n + 1;
}

int find_poison(int bottle_array[], int bit, int n)
{
	int p[ARRAY_SIZE] = { 0 }, i = 0, j = 0, a = 0, res = 0;
	a = 1;
	
	//	이렇게 n번째 사람까지 역할을 부여한다.
	for (i = 0; i < bit; i++)
	{
		a *= 2;
		//3. n비트로 표현이 가능할 때 
		//1번째 사람은 주기로 술 단지를 먹는다. 
		//2번째 사람은 주기로 술 단지를 먹는다.
		for (j = 1; j <= n; j++)
		{
			//4. 죽은 사람을 체크하여 죽으면 1, 살아있으면 0 으로 해서 2진수를 구한다.
			if (((j % a) > (a / 2)) || (j%a == 0))
			{
				p[i] += bottle_array[j-1];
			}
		}
	}

	a = 1;
	//5, 구해진 2진수를 10진수로 바꾼다.
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
	//1. 독이 든 술 단지의 개수를 구한다.
	array_size = sizeof(bottle_array) / sizeof(int);
	//2. 몇 비트로 표현이 가능한지 구한다.
	reset_array(bottle_array, array_size);
	bit = find_n_bit(array_size);
	poison = find_poison(bottle_array, bit, array_size);
	printf("독이 든 술단지는 %d번 입니다.", poison+1);
}

int main(void)
{
	test();
	return 0;
}