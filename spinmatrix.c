#include<stdio.h>

#define LEN 9

void print(int (*a)[LEN] ,int len);
void setValue(int num, int x, int y, int (*a)[LEN], int len);
void buildSpinMatrix(int (*a)[LEN], int len);

int main()
{
	int a[LEN][LEN] = {0};
	buildSpinMatrix(a, LEN);
	print(a, LEN);
}

void print(int (*a)[LEN] ,int len)
{
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < len; j++)
			printf("%-3d ", a[i][j]);
		printf("\n");
	}
}

void buildSpinMatrix(int (*a)[LEN], int len)
{
	setValue(1, 0, 0, a, LEN);
}

void setValue(int num, int x, int y, int (*a)[LEN], int len)
{
	a[x][y] = num;
	if (num == len*len)//写完返回
		return ;

	if (y < len-1 && x == 0) //上边，向右
		y++;
	else if (y == len-1 && x < len-1)//右边，向下
		x++;
	else if (x == len-1 && y > 0)//下边，向左
		y--;
	else if (y == 0 && x > 0 && a[x-1][y] == 0)//左边，向上
		x--;
	else if (y ==0 && x == 1)//左边，不可向上时，向右
		y++;
	else
	{
		if ((a[x][y+1] == 0 && a[x+1][y] == 0) || //可向右也可向下时，向右
			(a[x-1][y] != 0 && a[x][y+1] == 0))			//不可向上可向右时，向右
			y++;
		else if (a[x+1][y] == 0 )//可向下
			x++;
		else if (a[x][y-1] == 0)//可向左
			y--;
		else if (a[x-1][y] == 0)//可向上
			x--;
	}
	num++;//下一个数
	setValue(num, x, y, a, len);
}
