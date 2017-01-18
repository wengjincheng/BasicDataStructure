//线索化所需要的函数 

 
ThreadPoint pre;	//在Transform函数中充当前一个结点 

//操作结果：将二叉树中序线索化为线索二叉树 
void Transform(ThreadPoint tp){
		
	Transform(tp->lchild);	//左子树递归线索化 
	
	while(tp){
		//没有左子树时，建立前驱线索
		if(!tp->lchild){
			tp->ltag=1;
			tp->lchild=pre;
		}
	
		//前驱没有右子树时，建立后继线索
		if(!pre->rchild){
			pre->rtag=1;
			pre->rchild=tp;
		}
	
		//走你~
		pre=tp;
	}
	
	Transform(tp->rchild);	//右子树递归线索化 
} 


//线索树的中序遍历 
void Traversal(ThreadPoint tp){
 
	ThreadPoint p; 
	p=tp->lchild; 	//p指向头结点的左子树 
	
	while(p!=tp){	//树非空&遍历木有结束时 
		//实线，循环遍历左子树至左子树的最后一个叶子结点处
		while(p->ltag==0){
			p=p->lchild;
		}
		printf("%c",p->data);
		
		//虚线，找左子树的最后一个叶子结点的后继 
		while(p->rtag==1&&p->rchild!=tp){
			p=p->rchild; 
			printf("%c",p->data);
		}
	}
	
	//一路向右~
	p=p->rchild; 
} 
