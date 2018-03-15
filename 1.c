// 约瑟夫环 --- 使用不带头结点的单循环链表实现
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Lnode, * Linklist;

Linklist L = NULL;                                                              // 定义一个全局变量，全局变量要在所有函数前边定义

Linklist create(int );
void print_list(const Linklist, int );
int del(Linklist , int );

// 创建单循环链表的函数实体
Linklist create(int len)
{
	if(len <= 0){
		printf("You input an error length!");
		return NULL;                                                    // 注意是返回NULL，而不是返回空白值
	}
        
	int i;
	Linklist S, temp, sp;
        S = (Linklist)malloc(sizeof(Lnode));
	printf("Please input data into node: \n");
	scanf("%d", &S->data);                                                  // 不带头结点，因此第一个结点中要输入数据
	sp = S;
	temp = NULL;
      
	for(i = 2; i <= len; i++){                                              // 第一个结点已经创建好了，所以要循环计数量i初始化为2
		temp = (Linklist)malloc(sizeof(Lnode));
		sp->next = temp;
		sp = temp;
		scanf("%d", &temp->data);
	}
	sp->next = S;                                                           // 将尾指针指向第一个结点，完成闭环
 
	return S;
}

// 单循环链表数据打印函数实体
void print_list(const Linklist S, int len)
{
	Linklist sp = S;
	int i;
	printf("\nnode           data\n");
	for(i = 1; i <= len; i++){
		printf("%d              %d\n", i, sp->data);
		sp = sp->next;
	}
}

// 约瑟夫环结点删除函数实体
int del(Linklist S, int location)                                              // 约瑟夫环每次的首结点可能都不一样
{
	int i = 1, next_location;                                              // next_location为下一次约瑟夫环要输出值的位置
	Linklist prior, del_node;                                              // piror用于指向要删除结点的前驱结点，方便将环重新连接起来
	del_node = NULL;                                                       // del_node用于指向要删除的结点

	prior = S;
	while(prior->next != S)
		prior = prior->next;                                           // 在正式开始寻找要删除结点的位置时，先找到本次首结点的前驱结点
	
        while(i != location){
		i++;
		prior = S;                                                     // 始终指向下一个要判断的结点的前驱结点，循环结束时，prior指向删除结点的前驱结点
		S = S->next;
	}
	del_node = S;                                                          // 需要删除的结点
	next_location = S->data;                                               // 找出下一个要删除结点的位置值
	S = S->next;                                                           // 删除结点的后继结点，也是约瑟夫环的新头结点
        prior->next = S;                                                       // 将链表重新连接起来
	L = S;                                                                 // 使用全局指针，方便在子函数中更新约瑟夫环的头结点指针                         
	free(del_node);                                                        // 释放要删除结点占用的内存
	
	return next_location;
}

int main(void)
{
	int i, length, strat_location;                                          // 循环链表的指定长度length，初始首结点的位置strat_location

	printf("Please enter the length of Linklist you want to create: ");
	scanf("%d", &length);
	printf("\nPlease select the strat location: ");
	scanf("%d", &strat_location);
        
	L = create(length);
        print_list(L, length);

        for(i = 1; i < strat_location; i++)
		L = L->next;                                                    // 找到第一次的首结点
	strat_location = L->data;                                               // 第一次输出数据的结点位置，输出这个结点数据后，删除这个结点
        
	printf("\nThe sequence of data you input: \n");
	for(i = 1; i <= length; i++){
		strat_location = del(L, strat_location);
		printf("%d  ", strat_location);
                if(i % 10 == 0)
			printf("\n");
	}

	return 0;
}
