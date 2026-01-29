#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	校验是否存在重复
	返回值 1 有重复 0 没重复
	参数1：指向数组的指针
	参数2：当前元素的下标  判断的范围是0~index-1
*/
int check(int* p, int index);

/*
	随机生成系统数字
	参数1：指向数组的指针
	参数2：数组长度
*/
void systemNumber(int* p1, int n);

/*
	用户输入
	参数1：指向数组的指针
	参数2：数组长度
*/
void userNumber(int* p2, int n);

/*
	统计中奖数字个数
	参数1：指向系统数组的指针
	参数2：指向用户数组的指针
	参数3：数组长度
*/
int countNumber(int* p1, int* p2, int n);

/*
	显示中奖结果
	参数：中奖数字的个数
*/
void uesrResult(int num);

/*
	显示开奖结果
	参数1：指向系统数组的指针
	参数2：数组长度
*/
void systemResult(int* p1, int n);

int main()
{
	srand(time(0));
	int system[7];
	int user[7];
	systemNumber(system, 7);
	userNumber(user, 7);
	int count = countNumber(system, user, 7);
	uesrResult(count);
	systemResult(system, 7);
	return 0;
}

int check(int* p, int index)
{
	int i;
	for( i=0; i<index; i++ )
	{
		if( p[i]==p[index] )
		{
			return 1;
		}
	}
	return 0;
}

void systemNumber(int* p1, int n)
{
	int i;
	for( i=0; i<n; i++ )
	{
		p1[i] = rand()%35+1;
		if( check(p1, i) )
		{
			i--;
		}
	}
}

void userNumber(int* p2, int n)
{
	printf("请输入七个不同的数字：\n");
	int k;
	for( k=0; k<n; k++ )
	{
		printf("第%d个数字：", k+1);
		scanf("%d", &p2[k]);
		if( p2[k]<1 || p2[k]>35 )
		{
			k--;
			printf("超出范围,请重新输入\n");
			continue;
		}
		if( check(p2,k) )
		{
			k--;
			printf("输入重复,请重新输入\n");
		}
	}
}

int countNumber(int* p1, int* p2, int n)
{
	int i, j;
	int countnum = 0;
	for( i=0; i<n; i++ )
	{
		for( j=0; j<n; j++ )
		{
			if( p1[i]==p2[j] )
			{
				countnum++;
			}
		}
	}
	return countnum;
}

void uesrResult(int num)
{
	switch(num)
	{
	case 3:
		printf("您中了3个数字，奖金2元\n");
		break;
	case 4:
		printf("您中了4个数字，奖金100元\n");
		break;
	case 5:
		printf("您中了5个数字，奖金200元\n");
		break;
	case 6:
		printf("您中了6个数字，奖金50,000,000元\n");
		break;
	case 7:
		printf("您中了7个数字，奖金100,000,000元\n");
		break;
	default:
		printf("谢谢\n");
	}
}

void systemResult(int* p1, int n)
{
	int i;
	for( i=0; i<n; i++ )
	{
		printf("%d ", p1[i]);
	}
	printf("\n");
}