#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tools.h"

int room[6][6];
int x, y;

void birth();
void move();
int over();
void showResult();
void drawScreen();
void initRoom();
void drawBoundary();
void drawStep();

int main()
{
	initRoom();
	birth();//出生不算走位
	while(!over())//只要没走完就继续走
	{
		move();
		drawScreen();
	}
	showResult();//显示结果
	return 0;
}

// 初始化地图
void initRoom()
{
	// 上下边界
	int x;
	for( x=0; x<6; x++ )
	{
		room[0][x] = 2;// 上边界
		room[5][x] = 2;// 下边界
	}
	// 左右边界
	int y;
	for( y=0; y<6; y++ )
	{
		room[y][0] = 2;// 左边界
		room[y][5] = 2;// 右边界
	}
}

// 显示
void drawScreen()
{
	system("clear");
	
	drawStep();
	drawPoint(x, y, 36);
	drawBoundary();
	
	fflush(stdout);
	usleep(1000*350);
}

// 画边界
void drawBoundary()
{
	int i;
	for( i=0; i<6; i++ )
	{
		drawPoint(0, i, 37);
		drawPoint(5, i, 37);
	}
	for( i=0; i<6; i++ )
	{
		drawPoint(i, 0, 37);
		drawPoint(i, 5, 37);
	}
}

// 热力图
void drawStep()
{
	int i, j;
	for( i=1; i<5; i++ )
	{
		for( j=1; j<5; j++ )
		{
			if( room[i][j]>=1 && room[i][j]<5 )
			{
				drawPoint(j, i, 32);
			}
			else if( room[i][j]>=5 && room[i][j]<10 )
			{
				drawPoint(j, i, 33);
			}
			else if( room[i][j]>=10  )
			{
				drawPoint(j, i, 31);
			}
		}
	}
}

// 出生
void birth()
{
	srand(time(NULL));
	x = rand()%4+1;
	y = rand()%4+1;//出生不算走位
}

// 漫步
void move()
{
	switch(rand()%4)
	{
	case 0://up
		if(y > 1)
		{
			y--;// up
            room[y][x]++;//留下脚印
		}
		break;
	case 1://down
		if(y < 4)
		{
			y++;// down
            room[y][x]++;//留下脚印
		}
		break;
	case 2://left
		if(x > 1)
		{
			x--;// left
            room[y][x]++;//留下脚印
		}
		break;
	case 3://right
		if(x < 4)
		{
			x++;// right
            room[y][x]++;//留下脚印
		}
		break;
	}
}

// 结束
int over()
{
	int i, j;
	for(i = 1;i < 5;i++)
	{
		for(j = 1;j < 5;j++)
		{
			if(room[i][j] == 0)
			{
				//找到一个格子还没走就说明没满
				return 0;
			}
		}
	}
	//循环能结束就说明满了
	return 1;
}

// 结果
void showResult()
{
	int sum = 0;
	int i, j;
	printf("\r\n");
	printf("\r\n");
	for(i = 1;i < 5;i++)
	{
		for(j = 1;j < 5;j++)
		{
			sum += room[i][j];
			printf("%d ", room[i][j]);
		}
		printf("\n");
	}
	printf("一共%d步\n", sum);
}
