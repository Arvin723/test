#include<stdio.h>

#define LEN 8
#define HEIGHT 8

void print(int (*a)[LEN] ,int height);
void setValue(int num, int x, int y, int (*a)[LEN], int height);
void buildSpinMatrix(int (*a)[LEN], int height);

int main()
{
	int a[HEIGHT][LEN] = {0};
	buildSpinMatrix(a, HEIGHT);
	print(a, HEIGHT);
}

void print(int (*a)[LEN] ,int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < LEN; j++)
			printf("%-4d", a[i][j]);
		printf("\n");
	}
}

void buildSpinMatrix(int (*a)[LEN], int height)
{
	setValue(1, 0, 0, a, height);
}

void setValue(int num, int x, int y, int (*a)[LEN], int height)
{
	a[x][y] = num;
	if (num == LEN*height)//写完返回
		return ;

	if (y < LEN-1 && x == 0) //上边，向右
		y++;
	else if (y == LEN-1 && x < height-1)//右边，向下
		x++;
	else if (x == height-1 && y > 0)//下边，向左
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
	setValue(num, x, y, a, height);
}
