typedef char ElemType;

//���������������ṹ
typedef struct THREAD{
	ElemType data;	//������ 
	int ltag,rtag;	//���ұ�־�� 
	struct THREAD *lchild,*rchild;	//���Һ���ָ�� 
}Thread,*ThreadPoint; 
