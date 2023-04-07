/*
	실습일 : 2023년 4월 7일
	실습자 : 이홍구
	 학 번 : 202211286
	프로그램 설명 : 미로해결 프로그램
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAZE 7
#define S 2 //시작지점
#define A 3 //도착지점
#define UP 4
#define DOWN 5
#define LEFT 6
#define RIGHT 7
#define ARRIVAL 8
#define MAX_ROUTE 1000

//2. 현재 위치와 상태를 합쳐서 구조체로 표현한다.
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
	//6. 도착지점이 나올 때까지 반복한다.
	while (1)
	{
		switch (user.state)
		{
		case UP:
			//4. 앞에 벽이 없고
			if (maze[user.y - 1][user.x] == 0)
			{
				//2시방향에 벽이 없으면 한칸 앞으로 가고 방향을 오른쪽으로 돌린다.
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
				//2시방향에 벽이 있으면 전진한다.
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
			//3. 앞에 벽이 있으면 현재 기준 왼쪽으로 방향을 돌린다.
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
			//3. 앞에 벽이 있으면 현재 기준 왼쪽으로 방향을 돌린다.
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
			//3. 앞에 벽이 있으면 현재 기준 왼쪽으로 방향을 돌린다.
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
			//3. 앞에 벽이 있으면 현재 기준 왼쪽으로 방향을 돌린다.
			else
			{
				user.state = UP;
			}
			break;
		}
		route[count] = user;
		//6. 도착지점이 나올 때까지 반복한다.
		if (escape == 1)
			break;
		count++;
	}
	return route;
}

void test()
{
	int count = 0;
	// 벽: 1, 길: 0
	//1. 2차원 배열로 미로를 구현한다.
	int maze[MAZE][MAZE] = {
		{1,1,1,1,1,1,1},
		{S,0,1,0,0,0,1},
		{1,0,0,0,0,0,1},
		{1,0,1,0,1,0,A},
		{1,0,1,0,0,1,1},
		{1,0,0,1,0,0,1},
		{1,1,1,1,1,1,1}
	};
	//2. 현재 위치와 상태를 합쳐서 구조체로 표현한다.
	USER user = {0};
	user.state = RIGHT;
	user.x = 0;
	user.y = 1;
	USER* route;
	route = escape_maze(maze, user);

	printf("해결 루트(4: up, 5: down, 6: left, 7: right, 8: 도착)\n");
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