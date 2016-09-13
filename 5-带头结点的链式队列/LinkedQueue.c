#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define false 0
#define true 1
 
//自定义类型 
typedef int ElemType;
typedef int bool;

//结点 
typedef struct NODE{
	ElemType data;
	struct NODE * next;
}Node;
//链式队列 
typedef struct LINKQUEUE{
	Node *front,*rear;
}LinkQueue;

//操作结果：初始化链式队列，分配头结点的空间
void Init(LinkQueue *lq){
	lq->front=lq->rear=(Node *)malloc(sizeof(Node));
	lq->front->next=NULL;
} 

//操作结果：入队用尾插法插入新的结点，因为是链式队列遂不用判断队满溢出
bool EnQueue(LinkQueue *lq,ElemType e){
	//给新结点分配空间 
	Node *point = (Node *)malloc(sizeof(Node));
	
	//入队 
	point->data=e;
	point->next=NULL;
	lq->rear->next=point;
	lq->rear=point;
	
	return true;
} 

//操作结果：出队，判断是否队空,判断出队一个结点后是否队空,最后返回出队的元素x
ElemType DeQueue(LinkQueue *lq){
	
	//是否队空 
	if(lq->front==lq->rear) exit(0);
	
	//出队
	Node * p;
	p=lq->front->next;
	ElemType x=p->data;
	lq->front->next=p->next;
	
	//出队后是否队空 
	if(lq->rear==p) lq->rear=lq->front;
	
	//释放结点
	free(p);
	
	return x;
}

//操作要求：输出当前队中某一元素的位置
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

//操作要求：判断队空 
bool Empty(LinkQueue lq){
	if(lq.front==lq.rear) return true;
	else return false;
}

void main(void){
	LinkQueue lq;
	Init(&lq);
	printf("是否队空：%d (1:空 0:否)\n",Empty(lq));
	
	//入队4个结点 
	for(int i=0;i<4;i++){
		EnQueue(&lq,i);
	}

	printf("内容为2的结点在队列的第%d个位置\n",Locate(&lq,2));
	
	//出队3个结点并打印出队元素 
	printf("出队元素依次是：");
	for(int i=0;i<3;i++)
		printf("%d ",DeQueue(&lq));
	
}
