#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tools.h"

#define WIDTH 10
#define HEIGHT 20

// 表示一个点的结构体类型
struct Point
{
	int x;
	int y;
};

struct Block
{
	int shape;// 0无图形 1有图形 2边界
	int color;// 颜色
};

// 图形库
struct Point shapes[19][4] = {
    {{0,0},{-1,0},{1,0},{2,0}},		// 	横条		0
    {{0,0},{0,-1},{0,1},{0,2}},		//	竖条		1
	
    {{0,0},{-1,-1},{-1,0},{0,-1}},	// 	方块		2
	
    {{0,0},{0,-1},{0,-2},{1,0}},	//	正L1		3
    {{0,0},{0,1},{1,0},{2,0}},		//	正L2		4
    {{0,0},{-1,0},{0,1},{0,2}},		//	正L3		5
    {{0,0},{0,-1},{-1,0},{-2,0}},	// 	正L4		6
	
    {{0,0},{-1,0},{0,-1},{0,-2}},	//	反L1		7
    {{0,0},{0,-1},{1,0},{2,0}},		// 	反L2		8
    {{0,0},{1,0},{0,1},{0,2}},		// 	反L3		9
    {{0,0},{-1,0},{-2,0},{0,1}},	// 	反L4		10
	
    {{0,0},{-1,0},{1,0},{0,-1}},	//	T型1		11
    {{0,0},{0,1},{0,-1},{1,0}},		//	T型2		12
    {{0,0},{-1,0},{1,0},{0,1}},		//	T型3		13
    {{0,0},{-1,0},{0,-1},{0,1}},	//	T型4		14
	
    {{0,0},{1,0},{0,-1},{-1,-1}},	// 	正Z1		15
    {{0,0},{1,-1},{0,1},{1,0}},		// 	正Z2		16
	
    {{0,0},{1,-1},{-1,0},{0,-1}},	// 	反Z1		17
    {{0,0},{-1,-1},{-1,0},{0,1}}	// 	反Z2		18
};

// 全局变量
int x, y;// 坐标
int shapeIndex;// 图形下标
int color;// 颜色

/*
	静态图形，当图形下落到不能移动的时候都加入到静态图形数组中
	数组的每个元素表示坐标系中的一个点
	0 表示该点没有图形 1表示该点有图形 2表示边框
 */
struct Block map[HEIGHT][WIDTH] = {0};

void creatShape();
void drawScreen();
void changeShape();
int userCtrl();
void initMap();
int collide(int xDir, int yDir, int tIndex);
void moveLeft();
void moveRight();
void moveDown();
void addToMap();
void clearLines();
int isFull(int line);
void clearLine(int line);
void moveLine(int dst, int src);

int main()
{
	srand(time(NULL));// time()的形参是一个指针
	initMap();// 初始化地图（边界）
	creatShape();// 创建一个图形
	START_INPUT// 开启非阻塞输入模式
	int downCD = 0;
	// 主逻辑循环
	while(1)
	{
		if( !userCtrl() )
		{
			return 0;// 结束游戏
		}
		if(++downCD == 20)//循环执行20次下落一次
		{
			moveDown();
			downCD = 0;
		}
		drawScreen();
	}
	return 0;
}

// 初始化地图
void initMap()
{
	// 上下边界
	int x;
	for( x=0; x<WIDTH; x++ )
	{
		map[HEIGHT-1][x].shape = 2;// 下边界
		map[HEIGHT-1][x].color = 37;// 边界是白色
	}
	// 左右边界
	int y;
	for( y=0; y<HEIGHT; y++ )
	{
		map[y][0].shape = 2;// 左边界
		map[y][0].color = 37;// 边界是白色
		map[y][WIDTH-1].shape = 2;// 右边界
		map[y][WIDTH-1].color = 37;// 边界是白色
	}
}

// 创建新图形
void creatShape()
{
	x = WIDTH/2;// 在屏幕中间
	y = 0;// 保证图形不会有出界的部分（受终端的局限）
	shapeIndex = rand()%19;// 随机一个图形
	color = rand()%6+31;
}

// 绘制界面
void drawScreen()
{
	system("clear");
	
	// 绘制动态图形
	int i, j;
	for( i=0; i<4; i++ )
	{
		// 屏幕以外的点不绘制，避免乱码
		if(y+shapes[shapeIndex][i].y >= 0)
		{
			/*
				shapes[shapeIndex]计算得到一个一维数组
				数组元素有4个
				元素类型是 struct Point 类型
				整个for循环是在遍历shapes[shapeIndex]这个数组
				shapes[shapeIndex][i]运算得到shapes[shapeIndex]数组中的i元素
				i元素是 struct Point 类型的结构体变量
			*/
			drawPoint( x+shapes[shapeIndex][i].x, y+shapes[shapeIndex][i].y, color);
		}
	}
	
	// 绘制上边框
	for( i=0; i<WIDTH; i++ )
	{
		drawPoint( i, 0, 37 );
	}
	// 绘制其他边框和静态图形
	for( i=0; i<HEIGHT; i++ )
	{
		for( j=0; j<WIDTH; j++ )
		{
			if( map[i][j].shape != 0 )
			{
				drawPoint( j, i, map[i][j].color );
			}
		}
	}
	
	fflush(stdout);// 清除输出缓存
	usleep(1000*50);// 20帧
}

void moveLeft()
{
	if( !collide( -1, 0, shapeIndex ) )
	{
		x--;
	}
}

void moveRight()
{
	if( !collide( 1, 0, shapeIndex ) )
	{
		x++;
	}
}

void moveDown()
{
	if( !collide( 0, 1, shapeIndex ) )
	{
		y++;
	}
	else
	{
		addToMap();// 添加到静态图形
		clearLines();// 消行
		creatShape();// 创建新图形
	}
}

// 返回1游戏继续，返回0停止游戏
int userCtrl()
{
	switch( myget() )
	{
	case 'a':// 左移
		moveLeft();
		break;
	case 'd':// 右移
		moveRight();
		break;
	case 's':// 下移
		moveDown();
		break;
	case 'w':// 变形
		changeShape();
		break;
	case 'p':// 结束游戏
		system("clear");
		END_INPUT
		return 0;// 结束游戏
	}
	return 1;// 游戏继续
}

// 变形
void changeShape()
{
	int tIndex = shapeIndex;// 使用一个局部的值来表示变形逻辑
	
	switch(tIndex)
	{
	case 1://	竖条
	case 16://	正Z
	case 18://	反Z
		tIndex--;
		break;
	case 6://	正L
	case 10://	反L
	case 14://	 T
		tIndex -= 3;
		break;
	case 2://	方块
		break;
	default://	+1变形
		tIndex++;
	}
	// 判断tIndex这个图形是否会发生碰撞
	if( !collide( 0, 0, tIndex ))
	{
		shapeIndex = tIndex;// 完成变形
	}
}

/*	
	左侧 xDir == -1， yDir == 0
	右侧 xDir == +1， yDir == 0
	下侧 xDir == 0 ， yDir == 1
	tIndex用于判断变形
	返回1有碰撞，返回0无碰撞
*/ 
int collide(int xDir, int yDir, int tIndex)
{
	int i;
	for( i=0; i<4; i++ )
	{
		int tx = shapes[tIndex][i].x + x + xDir;
		int ty = shapes[tIndex][i].y + y + yDir;
		if( ty>=0 && map[ty][tx].shape!=0 )
		{
			return 1;// 发生碰撞
		}
	}
	return 0;// 未发生碰撞
}

// 添加静态图形
void addToMap()
{
	int i;
	for( i=0; i<4; i++ )
	{
		int tx = shapes[shapeIndex][i].x+x;		int ty = shapes[shapeIndex][i].y+y;
		map[ty][tx].shape = 1;
		map[ty][tx].color = color;
	}
}

// 消除
void clearLines()
{
	int y;
	int count = 0;
	for( y=HEIGHT-2; y>=0; y-- )
	{
		if( isFull(y) )
		{
			count++;	
			clearLine(y);
		}
		else if( count>0 )
		{
			moveLine(y+count, y);// 移动	
		}
	}
}

// 检测行是否满，返回0没满，返回1满
int isFull(int line)
{
	int i;
	// 0和WIDTH-1分别是左右边界，不判断
	for( i=1; i<WIDTH-1; i++ )
	{
		if( map[line][i].shape==0 )
		{
			return 0;
		}
	}
	return 1;
}

// 消除一行
void clearLine(int line)
{
	int i;
	for( i=1; i<WIDTH-1; i++ )
	{
		map[line][i].shape = 0;
	}
}

// 移动一行
void moveLine(int dst, int src)
{
	int i;
	for( i=1; i<WIDTH-1; i++ )
	{
		map[dst][i] = map[src][i];
		map[src][i].shape = 0;
	}
}
