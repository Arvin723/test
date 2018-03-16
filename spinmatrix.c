#include<stdio.h>

#define LEN 9

void print(int (*a)[LEN] ,int len);
void setValue(int num, int x, int y, int (*a)[LEN], int len);

int main()
{
	int a[LEN][LEN] = {0};
	setValue(1, 0, 0, a, LEN);
	print(a, LEN);
}

void print(int (*a)[LEN] ,int len)
{
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < len; j++)
		{
			printf("%-3d ", a[i][j]);
		}
		printf("\n");
	}
}

void setValue(int num, int x, int y, int (*a)[LEN], int len)
{
	a[x][y] = num;
	if (num == len*len)
		return ;

	if (y < len-1 && x == 0)
		y++;
	else if (y == len-1 && x < len-1)
		x++;
	else if (x == len-1 && y > 0)
		y--;
	else if (y == 0 && x > 0 && a[x-1][y] == 0)
		x--;
	else if (y ==0 && x == 1)
		y++;
	else
	{
		if (a[x][y+1] == 0)
			y++;
		else if (a[x+1][y] == 0)
			x++;
		else if (a[x][y-1] == 0)
			y--;
		else if (a[x-1][y] == 0)
			x--;
	}
	num++;
	setValue(num, x, y, a, len);
}
