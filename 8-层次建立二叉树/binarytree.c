#include "StructLib.h"
 
int len;
int i=0,j=0;		//����
ThreadPoint tp[1024];

//�����������α������������ 
int  createBinaryTree(ElemType *branch){

	ThreadPoint curr;

	curr = (ThreadPoint)malloc(sizeof(Thread));
	curr->data = *branch;		//����ֵ
	curr->lchild = NULL;		//�������ÿ�
	curr->rchild = NULL;		//�������ÿ�

	tp[i] = curr;		//��ӽ��

	if (i == 0){
		++i;
		createBinaryTree(branch + 1);
	}
	
	if (i % 2 == 0 && i != 0){
		++j;		//ÿ�ε�������ʱ��j+1����tp[j]����ʵ��ͬһ����ı���
		tp[j]->rchild = curr;		//������
	}	
	else if (i % 2 == 1){
		tp[j]->lchild = curr;		//������
	}

	if (i == (len - 1)){
		return 1;		//��i���������ĩβʱ��ֹͣ����
	}

	i++;		//Ϊ�������ģ���� ��Ҳ��ƴ��
	createBinaryTree(branch + 1);		//�ݹ���


}

//���ʵ�ǰ���
void visit(ThreadPoint tp){
	printf("%c",tp->data);
}



void main(){
	ElemType * branch;

	branch = (ElemType *)malloc(sizeof(ElemType));		//���о��������ָ���ǲ���Ұָ��

	printf("��������Ҫ�����Ķ��������С��磺AEBCD����");
    scanf("%s",branch);        //һ��������

	len = strlen(branch);			//�����³���

	createBinaryTree(branch);		//���쿪ʼ

	printf("��ү����Ҫ�Ķ����������ˣ�");
	for (int i = 0; i < len; i++){
		visit(tp[i]);
	}
	printf("\n");
}
