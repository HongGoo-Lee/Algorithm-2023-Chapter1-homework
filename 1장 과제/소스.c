#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reset_array(int a[],int n)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 101;
	}
}

int find_max(int a[], int n)
{

}

int main(void)
{
	return 0;
}

