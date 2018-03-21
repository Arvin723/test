#include <stdio.h>
#include <stdlib.h>

/**********************
//combination:打印组合数C-n-m;
//ar:存放组合的数组，长度为m，
//s:当前递归栈中起始指针相对于ar的偏移量
//当递归到最后一个数字时，偏移量为最上层m-1,故打印时，s+1即为最上层m值
//用户使用时，参数s应为0
************************/
void combination(int n, int m, int *ar, int s);
void printCom(int *ar, int len);

int main()
{
	int n = 6;
	int m = 4;
	int *ar = (int *)malloc(sizeof(int) * m);
	combination(n, m, ar, 0);
	free(ar);
}


void combination(int n, int m, int *ar, int s) 
{
	for (int i = 0; i < n-m+1; i++)
	{
		//当前递归栈中，填写ar[s]位置的值，可取 n 至 m
		*(ar+s) = n - i;
		//未到最后一个数字，则递归，偏移量加1
		if (m != 1)
			combination(n-i-1, m-1, ar, s+1);
		//到最后一个数，可打印
		if (m == 1)
			printCom(ar, s+1);
	}
}


void printCom(int *ar, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", ar[i]);
	}
	printf("\n");
}
