#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>

//�Զ������� 
typedef char ElemType;

//���������������ṹ
typedef struct THREAD{
	ElemType data;    //������ 
	struct THREAD *lchild, *rchild;    //���Һ���ָ�� 
}Thread, *ThreadPoint;
