/*
	�ǽ��� : 2023�� 4�� 7��
	�ǽ��� : ��ȫ��
	 �� �� : 202211286
	���α׷� ���� : �̷��ذ� ���α׷�
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAZE 7
#define S 2 //��������
#define A 3 //��������
#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7
#define ARRIVAL 8
#define MAX_ROUTE 1000

//2. ���� ��ġ�� ���¸� ���ļ� ����ü�� ǥ���Ѵ�.
typedef struct user {
	int state;
	int x;
	int y;
}USER;

USER* escape_maze(int maze[][MAZE], USER user)
{
	int count = 0,escape = 0;
	USER route[MAX_ROUTE] = { 0 };
	printf("%d: x: %d, y: %d, state: %d\n", count, user.x, user.y, user.state);
	//6. ���������� ���� ������ �ݺ��Ѵ�.
	while (1)
	{
		switch (user.state)
		{
		case UP:
			//4. �տ� ���� ����
			if (maze[user.y - 1][user.x] == 0)
			{
				//2�ù��⿡ ���� ������ ��ĭ ������ ���� ������ ���������� ������.
				if (maze[user.y - 1][user.x + 1] == 1)
				{
					user.y -= 1;
				}
				else if(maze[user.y - 1][user.x + 1] == A)
				{
					user.y -= 1;
					user.state = RIGHT;
					route[count] = user;

					user.x += 1;
					user.state = ARRIVAL;
					count += 1;
					escape = 1;
				}
				//2�ù��⿡ ���� ������ �����Ѵ�.
				else
				{
					user.y -= 1;
					user.state = RIGHT;
					route[count] = user;
					user.x += 1;
					count += 1;
				}
			}
			else if (maze[user.y - 1][user.x] == A)
			{
				user.state = ARRIVAL;
				user.y -= 1;
				escape = 1;
			}
			//3. �տ� ���� ������ ���� ���� �������� ������ ������.
			else
			{
				user.state = LEFT;
			}
			break;
		case DOWN:
			if (maze[user.y + 1][user.x] == 0)
			{
				if (maze[user.y + 1][user.x - 1] == 1)
				{
					user.y += 1;
				}
				else if(maze[user.y + 1][user.x - 1] == A)
				{
					user.y += 1;
					user.state = LEFT;
					route[count] = user;

					user.x -= 1;
					user.state = ARRIVAL;
					count += 1;
					escape = 1;
				}
				else
				{
					user.y += 1;
					user.state = LEFT;
					route[count] = user;
					user.x -= 1;
					count += 1;
				}
			}
			else if (maze[user.y + 1][user.x] == A)
			{
				user.state = ARRIVAL;
				user.y += 1;
				escape = 1;
			}
			//3. �տ� ���� ������ ���� ���� �������� ������ ������.
			else
			{
				user.state = RIGHT;
			}
			break;
		case LEFT:
			if (maze[user.y][user.x-1] == 0)
			{
				if (maze[user.y - 1][user.x - 1] == 1)
				{
					user.x -= 1;
				}
				else if (maze[user.y - 1][user.x - 1] == A)
				{
					user.x -= 1;
					user.state = UP;
					route[count] = user;

					user.y -= 1;
					user.state = ARRIVAL;
					count += 1;
					escape = 1;
				}
				else
				{
					user.y -= 1;
					user.state = UP;
					route[count] = user;
					user.x -= 1;
					count += 1;
				}
			}
			else if (maze[user.y][user.x-1] == A)
			{
				user.state = ARRIVAL;
				user.x -= 1;
				escape = 1;
			}
			//3. �տ� ���� ������ ���� ���� �������� ������ ������.
			else
			{
				user.state = DOWN;
			}
			break;
		case RIGHT:
			if (maze[user.y][user.x + 1] == 0)
			{
				if (maze[user.y + 1][user.x + 1] == 1)
				{
					user.x += 1;
				}
				else if (maze[user.y + 1][user.x + 1] == A)
				{
					user.x += 1;
					user.state = DOWN;
					route[count] = user;

					user.y += 1;
					user.state = ARRIVAL;
					count += 1;
					escape = 1;
				}
				else
				{
					user.y += 1;
					user.state = DOWN;
					route[count] = user;
					user.x += 1;
					count += 1;
				}
			}
			else if (maze[user.y][user.x+1] == A)
			{
				user.state = ARRIVAL;
				user.x += 1;
				escape = 1;
			}
			//3. �տ� ���� ������ ���� ���� �������� ������ ������.
			else
			{
				user.state = UP;
			}
			break;
		}
		route[count] = user;
		//6. ���������� ���� ������ �ݺ��Ѵ�.
		if (escape == 1)
			break;
		count++;
	}
	return route;
}

void test()
{
	int count = 0;
	// ��: 1, ��: 0
	//1. 2���� �迭�� �̷θ� �����Ѵ�.
	int maze[MAZE][MAZE] = {
		{1,1,1,1,1,1,1},
		{S,0,1,0,0,0,1},
		{1,0,0,0,0,0,1},
		{1,0,1,0,1,0,A},
		{1,0,1,0,0,1,1},
		{1,0,0,1,0,0,1},
		{1,1,1,1,1,1,1}
	};
	//2. ���� ��ġ�� ���¸� ���ļ� ����ü�� ǥ���Ѵ�.
	USER user = {0};
	user.state = RIGHT;
	user.x = 0;
	user.y = 1;
	USER* route;
	route = escape_maze(maze, user);

	printf("�ذ� ��Ʈ(4: up, 5: down, 6: left, 7: right, 8: ����)\n");
	while (1)
	{
		printf("%d: x: %d, y: %d, state: %d\n",count+1,route[count].x, route[count].y,route[count].state);
		if (route[count].state == ARRIVAL)
		{
			break;
		}
		count++;
	}

}

int main(void)
{
	test();
	return 0;
}