#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//����һ��ջ�ռ�
#define MAXSIZE 10
#define bool int 
#define TRUE 1
#define FALSE 0
#define Elemtype int

typedef struct NODE{
	Elemtype data[MAXSIZE];
	int top;
}SeqStack;

//����Ҫ�󣺳�ʼ��ջ 
//���������ջ��ָ���ʼ��
void InitStack(SeqStack *ss){
	ss->top=-1;
}


//����Ҫ�󣺽�ջ
//���������ջ��ָ��+1��Ԫ��x��ջ 
bool Push(SeqStack *ss,int x){
	if(ss->top==MAXSIZE-1) return FALSE;
	int i = ++ss->top;
	ss->data[i]=x;
	return TRUE;
}

//����Ҫ�󣺳�ջ
//���������ջ����ջ��ջ��ָ��-1
bool Pop(SeqStack *ss){
	if(ss->top==-1) return FALSE;
	ss->top--;
	return TRUE;
}
//����Ҫ�󣺶�ջ��Ԫ��
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


