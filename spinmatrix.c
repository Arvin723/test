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
	if (num == len*len)//д�귵��
		return ;

	if (y < len-1 && x == 0) //�ϱߣ�����
		y++;
	else if (y == len-1 && x < len-1)//�ұߣ�����
		x++;
	else if (x == len-1 && y > 0)//�±ߣ�����
		y--;
	else if (y == 0 && x > 0 && a[x-1][y] == 0)//��ߣ�����
		x--;
	else if (y ==0 && x == 1)//��ߣ���������ʱ������
		y++;
	else
	{
		if ((a[x][y+1] == 0 && a[x+1][y] == 0) || //������Ҳ������ʱ������
			(a[x-1][y] != 0 && a[x][y+1] == 0))			//�������Ͽ�����ʱ������
			y++;
		else if (a[x+1][y] == 0 )//������
			x++;
		else if (a[x][y-1] == 0)//������
			y--;
		else if (a[x-1][y] == 0)//������
			x--;
	}
	num++;//��һ����
	setValue(num, x, y, a, len);
}
