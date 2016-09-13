#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define false 0
#define true 1
 
//�Զ������� 
typedef int ElemType;
typedef int bool;

//��� 
typedef struct NODE{
	ElemType data;
	struct NODE * next;
}Node;
//��ʽ���� 
typedef struct LINKQUEUE{
	Node *front,*rear;
}LinkQueue;

//�����������ʼ����ʽ���У�����ͷ���Ŀռ�
void Init(LinkQueue *lq){
	lq->front=lq->rear=(Node *)malloc(sizeof(Node));
	lq->front->next=NULL;
} 

//��������������β�巨�����µĽ�㣬��Ϊ����ʽ�����첻���ж϶������
bool EnQueue(LinkQueue *lq,ElemType e){
	//���½�����ռ� 
	Node *point = (Node *)malloc(sizeof(Node));
	
	//��� 
	point->data=e;
	point->next=NULL;
	lq->rear->next=point;
	lq->rear=point;
	
	return true;
} 

//������������ӣ��ж��Ƿ�ӿ�,�жϳ���һ�������Ƿ�ӿ�,��󷵻س��ӵ�Ԫ��x
ElemType DeQueue(LinkQueue *lq){
	
	//�Ƿ�ӿ� 
	if(lq->front==lq->rear) exit(0);
	
	//����
	Node * p;
	p=lq->front->next;
	ElemType x=p->data;
	lq->front->next=p->next;
	
	//���Ӻ��Ƿ�ӿ� 
	if(lq->rear==p) lq->rear=lq->front;
	
	//�ͷŽ��
	free(p);
	
	return x;
}

//����Ҫ�������ǰ����ĳһԪ�ص�λ��
int Locate(LinkQueue *lq,ElemType x){
	Node *go;
	go=lq->front->next;
	
	int count=1;
	while(go->next){
			if(go->data==x) return count;
		else{
			go=go->next;
			count++;
		}
	}
			
} 

//����Ҫ���ж϶ӿ� 
bool Empty(LinkQueue lq){
	if(lq.front==lq.rear) return true;
	else return false;
}

void main(void){
	LinkQueue lq;
	Init(&lq);
	printf("�Ƿ�ӿգ�%d (1:�� 0:��)\n",Empty(lq));
	
	//���4����� 
	for(int i=0;i<4;i++){
		EnQueue(&lq,i);
	}

	printf("����Ϊ2�Ľ���ڶ��еĵ�%d��λ��\n",Locate(&lq,2));
	
	//����3����㲢��ӡ����Ԫ�� 
	printf("����Ԫ�������ǣ�");
	for(int i=0;i<3;i++)
		printf("%d ",DeQueue(&lq));
	
}
