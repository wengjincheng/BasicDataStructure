#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>

//自定义类型 
typedef char ElemType;

//定义线索二叉树结构
typedef struct THREAD{
	ElemType data;    //数据域 
	struct THREAD *lchild, *rchild;    //左右孩子指针 
}Thread, *ThreadPoint;
