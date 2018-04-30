#include<stdio.h>

int x[50] = { 0 };
void main()
{
	void split(int n, int k);
	int n;
	printf("Please input 'n'(0<n<100):");
	scanf_s("%d", &n);
	split(n, 0);
	system("pause");
}

void split(int n, int k)//k是数组中的位置，亦是递归层数
{
	void output(int k);
	int i;
	if (n == 0)//分解完成，输出结果
		output(k);
	else
		for (i = n; i>0; i--)
			if (k == 0 || i <= x[k - 1])
			{
				x[k] = i;//写入数组
				split(n - i, k + 1);
			}
}


void output(int k)//输出数组前k项
{
	int i;
	for (i = 0; i < k-1; i++)
		printf("%d+", x[i]);
	printf("%d", x[k-1]);
	printf("\n");
}
