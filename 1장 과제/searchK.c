#include <stdio.h>

int searchK(int);
void testSearchK(void);

int main(void)
{
	testSearchK();

	return 0;
}

//A�迭���� K�� ã�� �Լ�
//������ K, ������ -1�� ��ȯ 
int searchK(int K)
{
	//1. �迭�� ������ ���ڷ� �ʱ�ȭ�Ѵ�.
	int A[10] = { 5,7,3,0,80,95,42,31,23,15 };
	int ret = -1;

	//2. ���������� ã�´�.
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
		printf("%d���� ã�ҽ��ϴ�.\n", xret);
	}
	else
	{
		printf("%d���� ã�� ���߽��ϴ�. %d\n", fval, xret);
	}
}