#include "StructLib.h"
 
int len;
int i=0,j=0;		//次数
ThreadPoint tp[1024];

//操作结果：层次遍历构造二叉树 
int  createBinaryTree(ElemType *branch){

	ThreadPoint curr;

	curr = (ThreadPoint)malloc(sizeof(Thread));
	curr->data = *branch;		//结点的值
	curr->lchild = NULL;		//左子树置空
	curr->rchild = NULL;		//右子树置空

	tp[i] = curr;		//添加结点

	if (i == 0){
		++i;
		createBinaryTree(branch + 1);
	}
	
	if (i % 2 == 0 && i != 0){
		++j;		//每次到右子树时，j+1，则tp[j]就能实现同一层结点的遍历
		tp[j]->rchild = curr;		//右子树
	}	
	else if (i % 2 == 1){
		tp[j]->lchild = curr;		//左子树
	}

	if (i == (len - 1)){
		return 1;		//当i到达输入的末尾时，停止工作
	}

	i++;		//为了上面的模运算 我也是拼了
	createBinaryTree(branch + 1);		//递归呗


}

//访问当前结点
void visit(ThreadPoint tp){
	printf("%c",tp->data);
}



void main(){
	ElemType * branch;

	branch = (ElemType *)malloc(sizeof(ElemType));		//这行决定了你的指针是不是野指针

	printf("请输入你要建立的二叉树序列【如：AEBCD】：");
    scanf("%s",branch);        //一次性输入

	len = strlen(branch);			//计算下长度

	createBinaryTree(branch);		//构造开始

	printf("大爷，你要的二叉树做好了：");
	for (int i = 0; i < len; i++){
		visit(tp[i]);
	}
	printf("\n");
}
