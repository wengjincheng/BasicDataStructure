typedef char ElemType;

//定义线索二叉树结构
typedef struct THREAD{
	ElemType data;	//数据域 
	int ltag,rtag;	//左右标志域 
	struct THREAD *lchild,*rchild;	//左右孩子指针 
}Thread,*ThreadPoint; 
