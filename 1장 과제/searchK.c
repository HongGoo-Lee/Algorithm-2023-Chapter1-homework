#include <stdio.h>

int searchK(int);
void testSearchK(void);

int main(void)
{
	testSearchK();

	return 0;
}

//A배열에서 K를 찾는 함수
//있으면 K, 없으면 -1을 반환 
int searchK(int K)
{
	//1. 배열을 임의의 숫자로 초기화한다.
	int A[10] = { 5,7,3,0,80,95,42,31,23,15 };
	int ret = -1;

	//2. 순차적으로 찾는다.
	for (int i = 0; i < 10; i++)
	{
		if (A[i] == K)
		{
			ret = A[i];
			break;
		}
	}

	return ret;
}

void testSearchK()
{
	int fval = 15;
	int xret = -2;

	xret = searchK(fval);
	if (xret == fval)
	{
		printf("%d값을 찾았습니다.\n", xret);
	}
	else
	{
		printf("%d값을 찾지 못했습니다. %d\n", fval, xret);
	}
}