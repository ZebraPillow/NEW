#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Point
{
    char show;//在游戏中的显示信息
    int mine;//包含雷的信息 1包含雷 0不包含雷
}Point;


#define WIDTH   10
#define HEIGHT  10

#define MINE_NUM  10 

Point map[HEIGHT][WIDTH];//表示游戏屏幕中所有点的二维数组

void initMap();//初始化，将所有点的show赋值*   mine 赋值0
void printMap();
void setMine();//将map中随机MINE_NUM个点的mine赋值1
void printMine();
int countMine(int x, int y);
void open(int x, int y);

int openCount = 0;

int main(void)
{
    initMap();
    setMine();
    printMine();
    while(1)
    {
        printMap();
        int x, y;
        printf("input x y\n");
        scanf("%d%d",&x, &y);
        if(map[y][x].mine == 1)
        {
            //GAME OVER
            printf("GAME OVER\n");
            break;
        }
        else
        {
            open(x, y);
        }
        if(openCount == WIDTH*HEIGHT-MINE_NUM)
        {
            printMap();
            printf("win\n");
            break;
        }
    } 
    return 0;
}
        
/*
初始化屏幕
*/
void initMap()
{
    int i,j;
    for(i = 0;i < HEIGHT;i++)//纵轴
    {
        for(j = 0;j < WIDTH;j++)//横轴
        {
            map[i][j].show = '*';
            map[i][j].mine = 0;
        }
    }
}

/*
打印屏幕 
*/
void printMap()
{
    int i,j;
    for(i = 0;i < HEIGHT;i++)//纵轴
    {
        for(j = 0;j < WIDTH;j++)//横轴
        {
            printf("%c ",map[i][j].show);
        }
        printf("\n");
    }
}

/*
布雷
*/
void setMine()
{
    srand(time(0));//以系统时间作为随机种子
    int i, x, y;
    for(i = 0;i < MINE_NUM;i++)
    {
        do{
            x = rand()%WIDTH;
            y = rand()%HEIGHT;
        }while(map[y][x].mine==1);
        map[y][x].mine = 1;
    }
}

/*
打印布雷信息
*/
void printMine()
{
    int i,j;
    for(i = 0;i < HEIGHT;i++)//纵轴
    {
        for(j = 0;j < WIDTH;j++)//横轴
        {
            printf("%d ",map[i][j].mine);
        }
        printf("\n");
    }
}

/*
查找点周围的雷数
*/
int countMine(int x, int y)
{ 
    int i,j;
    int count = 0;
    for(i = (y==0?0:y-1);i <= (y==HEIGHT-1?HEIGHT-1:y+1);i++)//遍历y
    {
        for(j = (x==0?0:x-1);j <= (x==WIDTH-1?WIDTH-1:x+1);j++)//遍历x
        {
            if(map[i][j].mine == 1)
            {
                count++;
            }
        }
    }
    return count;
}

/*
显示输入的点
*/

void open(int x, int y)
{
	if(map[y][x].show != '*')
		return;
	//如果一个点被打开过了，则下面逻辑都不用进行了  show 不等于'*'
    openCount++;//统计打开的点数
    int count = countMine(x, y);
    map[y][x].show = count+'0';//数字整数转换为数字字符
	//count>0递归停止
	if(count > 0)
		return;
	
	//向周围递归，如果是边界就不递归了
    int i,j;
    for(i = (y==0?0:y-1);i <= (y==HEIGHT-1?HEIGHT-1:y+1);i++)//遍历y
    {
        for(j = (x==0?0:x-1);j <= (x==WIDTH-1?WIDTH-1:x+1);j++)//遍历x
        {
			open(j, i);
        }
    }
}
