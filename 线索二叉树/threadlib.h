//����������Ҫ�ĺ��� 

 
ThreadPoint pre;	//��Transform�����г䵱ǰһ����� 

//���������������������������Ϊ���������� 
void Transform(ThreadPoint tp){
		
	Transform(tp->lchild);	//�������ݹ������� 
	
	while(tp){
		//û��������ʱ������ǰ������
		if(!tp->lchild){
			tp->ltag=1;
			tp->lchild=pre;
		}
	
		//ǰ��û��������ʱ�������������
		if(!pre->rchild){
			pre->rtag=1;
			pre->rchild=tp;
		}
	
		//����~
		pre=tp;
	}
	
	Transform(tp->rchild);	//�������ݹ������� 
} 


//��������������� 
void Traversal(ThreadPoint tp){
 
	ThreadPoint p; 
	p=tp->lchild; 	//pָ��ͷ���������� 
	
	while(p!=tp){	//���ǿ�&����ľ�н���ʱ 
		//ʵ�ߣ�ѭ�������������������������һ��Ҷ�ӽ�㴦
		while(p->ltag==0){
			p=p->lchild;
		}
		printf("%c",p->data);
		
		//���ߣ��������������һ��Ҷ�ӽ��ĺ�� 
		while(p->rtag==1&&p->rchild!=tp){
			p=p->rchild; 
			printf("%c",p->data);
		}
	}
	
	//һ·����~
	p=p->rchild; 
} 
