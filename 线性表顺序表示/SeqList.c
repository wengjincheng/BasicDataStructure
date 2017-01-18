#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h> 
//���Ա��˳���ʾ��insert,delete,search��
#define INITSIZE 10

typedef struct LIST{
	int * data;
	int length; 
}SeqList;



//��ʼ��
void init(SeqList *list){
	list->data = malloc(sizeof(int)*INITSIZE);
	list->length=10;
}

//����x
void ListInsert(SeqList *list,int x,int i){

	for(int j=list->length;j>i;j--){
		list->data[j]=list->data[j-1];
	}

	list->data[i]=x;
	list->length++;

}

//ɾ����i��Ԫ��
void ListDelete(SeqList *list,int i){
	for(int j=i;j<list->length-1;j++){
		list->data[j]=list->data[j+1];
	}

	list->length--;

}

//����x
int Search(SeqList *list,int x){
	for(int i=0;i<list->length;i++){
		if(list->data[i]==x) return i;
	}
}

void main(void){
	
	SeqList list;
	init(&list);
	for(int i=0;i<list.length;i++){
		list.data[i]=i;
	}
	ListDelete(&list,5);
	ListInsert(&list,100,2);
	for(int i=0;i<list.length;i++){
		printf("%d ",list.data[i]);
	}
	int position = Search(&list,100);
	printf("\n%d",position+1);
}

