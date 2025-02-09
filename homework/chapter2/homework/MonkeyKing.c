#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node     /* 这个结构类型包括三个域 */
{
	int number;        /* 猴子的编号 */
	int mydata;        /* 猴子的定数 */
	struct node *next; /* 指向下一只猴子的指针 */
} linklist;

/* 创建一个由n只猴子圈 */
linklist *CreateCircle(int n) {
	linklist *head, *p, *s;
	int i;
	head = (linklist*)malloc(sizeof(linklist)); /* 首节点创建 */
	p = head;
	p->number = 1;
	scanf("%d", &p->mydata); /* 定数(正整数)，确定下一只出局的猴子*/
	p->next = NULL;
	/* 链表创建*/
	for (i = 2; i <= n; i++) 
	{  
		s = (linklist*)malloc(sizeof(linklist)); /* 申请储存空间 */
		s->number = i; /* 给每只猴子编号 */
		scanf("%d", &s->mydata); /* 报数(正整数)，确定下一只出局的猴子*/
		p->next = s; /* 前一只猴子指向该猴子  */
		p = s;  /*  此时最后一个结点为新创建的猴子结点,将p指向它  */
	}
	p->next = head;   /* 链表首尾相接构成循环链表 */
	return p;  /* 返回最后一只猴子的指针，因为它指向第一只猴子 */
}

/* 删除循环链表中p所指的下一个结点 */
linklist *DeleteNext(linklist *p)    
{
	linklist *q;
	q = p->next;/* 获取p所指的下一个结点 */
	p->next = q->next;/* p指向后一个结点 */
	free(q);/* 删除并释放结点 */
	return p;
}

int KingOfMonkey(int n, linklist *head) {
	linklist *p = head;       /* head指向最后一只猴子结点 */
	int i, j, steps = p->mydata;       /* 用最后一只猴子的定数开始 */
	for (j = 1; j <= n - 1; j++) {   /* 重复该过程n-1次 */
		for (i = 1; i<steps; i++)    p = p->next;
		/* 将p所指的下一个结点删除, 删除前取其定数 */
		steps = p->next->mydata;  /*  修改定数，准备下一轮循环 */
		printf(" %d ", p->next->number);
			DeleteNext(p);     /*  该猴子退出圈子 */
	}
	return p->number;     /*  返回猴王的编号 */
}

int main() {
	linklist *head;
	int n;
	printf("请输入猴子的总数和每只猴子的定数(必须是正整数):");
	scanf_s("%d", &n);
	head = CreateCircle(n); /* 创建单循环链表，返回最后一个结点的指针 */
	printf("\nThe king is monkey[%d].\n", KingOfMonkey(n,head));
	system("pause");
	return 0;
}
