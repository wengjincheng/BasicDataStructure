#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h> 
//线性表的顺序表示【insert,delete,search】
#define INITSIZE 10

typedef struct LIST{
	int * data;
	int length; 
}SeqList;



//初始化
void init(SeqList *list){
	list->data = malloc(sizeof(int)*INITSIZE);
	list->length=10;
}

//插入x
void ListInsert(SeqList *list,int x,int i){

	for(int j=list->length;j>i;j--){
		list->data[j]=list->data[j-1];
	}

	list->data[i]=x;
	list->length++;

}

//删除第i个元素
void ListDelete(SeqList *list,int i){
	for(int j=i;j<list->length-1;j++){
		list->data[j]=list->data[j+1];
	}

	list->length--;

}

//查找x
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

