// Լɪ�� --- ʹ�ò���ͷ���ĵ�ѭ������ʵ��
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} Lnode, * Linklist;

Linklist L = NULL;                                                              // ����һ��ȫ�ֱ�����ȫ�ֱ���Ҫ�����к���ǰ�߶���

Linklist create(int );
void print_list(const Linklist, int );
int del(Linklist , int );

// ������ѭ������ĺ���ʵ��
Linklist create(int len)
{
	if(len <= 0){
		printf("You input an error length!");
		return NULL;                                                    // ע���Ƿ���NULL�������Ƿ��ؿհ�ֵ
	}
        
	int i;
	Linklist S, temp, sp;
        S = (Linklist)malloc(sizeof(Lnode));
	printf("Please input data into node: \n");
	scanf("%d", &S->data);                                                  // ����ͷ��㣬��˵�һ�������Ҫ��������
	sp = S;
	temp = NULL;
      
	for(i = 2; i <= len; i++){                                              // ��һ������Ѿ��������ˣ�����Ҫѭ��������i��ʼ��Ϊ2
		temp = (Linklist)malloc(sizeof(Lnode));
		sp->next = temp;
		sp = temp;
		scanf("%d", &temp->data);
	}
	sp->next = S;                                                           // ��βָ��ָ���һ����㣬��ɱջ�
 
	return S;
}

// ��ѭ���������ݴ�ӡ����ʵ��
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

// Լɪ�򻷽��ɾ������ʵ��
int del(Linklist S, int location)                                              // Լɪ��ÿ�ε��׽����ܶ���һ��
{
	int i = 1, next_location;                                              // next_locationΪ��һ��Լɪ��Ҫ���ֵ��λ��
	Linklist prior, del_node;                                              // piror����ָ��Ҫɾ������ǰ����㣬���㽫��������������
	del_node = NULL;                                                       // del_node����ָ��Ҫɾ���Ľ��

	prior = S;
	while(prior->next != S)
		prior = prior->next;                                           // ����ʽ��ʼѰ��Ҫɾ������λ��ʱ�����ҵ������׽���ǰ�����
	
        while(i != location){
		i++;
		prior = S;                                                     // ʼ��ָ����һ��Ҫ�жϵĽ���ǰ����㣬ѭ������ʱ��priorָ��ɾ������ǰ�����
		S = S->next;
	}
	del_node = S;                                                          // ��Ҫɾ���Ľ��
	next_location = S->data;                                               // �ҳ���һ��Ҫɾ������λ��ֵ
	S = S->next;                                                           // ɾ�����ĺ�̽�㣬Ҳ��Լɪ�򻷵���ͷ���
        prior->next = S;                                                       // ������������������
	L = S;                                                                 // ʹ��ȫ��ָ�룬�������Ӻ����и���Լɪ�򻷵�ͷ���ָ��                         
	free(del_node);                                                        // �ͷ�Ҫɾ�����ռ�õ��ڴ�
	
	return next_location;
}

int main(void)
{
	int i, length, strat_location;                                          // ѭ�������ָ������length����ʼ�׽���λ��strat_location

	printf("Please enter the length of Linklist you want to create: ");
	scanf("%d", &length);
	printf("\nPlease select the strat location: ");
	scanf("%d", &strat_location);
        
	L = create(length);
        print_list(L, length);

        for(i = 1; i < strat_location; i++)
		L = L->next;                                                    // �ҵ���һ�ε��׽��
	strat_location = L->data;                                               // ��һ��������ݵĽ��λ�ã�������������ݺ�ɾ��������
        
	printf("\nThe sequence of data you input: \n");
	for(i = 1; i <= length; i++){
		strat_location = del(L, strat_location);
		printf("%d  ", strat_location);
                if(i % 10 == 0)
			printf("\n");
	}

	return 0;
}
