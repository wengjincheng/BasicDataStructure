#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//定义一个栈空间
#define MAXSIZE 10
#define bool int 
#define TRUE 1
#define FALSE 0
#define Elemtype int

typedef struct NODE{
	Elemtype data[MAXSIZE];
	int top;
}SeqStack;

//操作要求：初始化栈 
//操作结果：栈顶指针初始化
void InitStack(SeqStack *ss){
	ss->top=-1;
}


//操作要求：进栈
//操作结果：栈顶指针+1，元素x进栈 
bool Push(SeqStack *ss,int x){
	if(ss->top==MAXSIZE-1) return FALSE;
	int i = ++ss->top;
	ss->data[i]=x;
	return TRUE;
}

//操作要求：出栈
//操作结果：栈顶出栈，栈顶指针-1
bool Pop(SeqStack *ss){
	if(ss->top==-1) return FALSE;
	ss->top--;
	return TRUE;
}
//操作要求：读栈顶元素
int GetTop(SeqStack *ss){
	int x;
	x=ss->data[ss->top];
	return x;
}

void main(void){
	SeqStack ss;
	InitStack(&ss);
	for(int i=0;i<10;i++){
		Push(&ss,i);
	}
	for(int i=0;i<5;i++){
		Pop(&ss);
	}
	
	printf("%d",GetTop(&ss));
	
}


