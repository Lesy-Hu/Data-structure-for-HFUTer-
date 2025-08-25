#include <iostream>
#include "binary_tree.h" 
#include <cmath>

using namespace std;
//���ʽڵ�
void visit(BiNode *T){
	if(T != nullptr){
		cout << T->data <<endl;
	}else{
		cout <<"nullptr"<<endl; 
	}
} 


//�������ı���
//�������
void preOrderTraverse(BiNode *T){
	if(T){
		visit(T);   //���ʸ��ڵ� 
		preOrderTraverse(T->lChild);     //�ݹ����������������� 
		preOrderTraverse(T->rChild);	 //�ݹ����������������� 
	}
} 

 
//������� 
void inOrderTraverse(BiNode *T){
	if(T){
		inOrderTraverse(T->lChild);
		visit(T);
		inOrderTraverse(T->rChild);	
	}
}


//�������
void postOrderTraverse(BiNode *T){
	if(T){
		postOrderTraverse(T->lChild);
		postOrderTraverse(T->rChild);
		visit(T);
	}
}


//�������Ľ��������ڡ����������� 
//��������
void creatSubTree(BiNode *q,int k){
	BiNode *u;
	Elemtype x;
	cin >> x;
	if(x != '/'){
		u = new BiNode;
		u->data = x;
		u->lChild = NULL;
		u->rChild = NULL;
		if(k == 1){
			q->lChild = u;
		}
		if(k == 2){
			q->rChild = u;
		}
		creatSubTree(u,1);  //�ݹ鴴��u�������� 
		creatSubTree(u,2);	//�ݹ鴴��u�������� 
	}
} 

//�������ڵ� 
void creatBiTree(BiNode *& BT){
	BiNode *p;
	char x;
	cout <<"creat Bitree with previous order:" <<endl;
	cin >> x;
	if(x == '/'){
		return;
	}
	BT = new BiNode;
	BT->data = x;
	BT->lChild = NULL;
	BT->rChild = NULL;
	p = BT;
	creatSubTree(p,1);
	creatSubTree(p,2);
} 


//������������
void destroyBiTree(BiNode *pBT){
	if(pBT){
		destroyBiTree(pBT->lChild); 
		destroyBiTree(pBT->rChild);
		delete pBT;
	}
} 


//��������Ľڵ���(���������)
void getNodeNum(BiNode *pBT,int &num){
	if(pBT != NULL){
		getNodeNum(pBT->lChild,num);
		num++;
		getNodeNum(pBT->rChild,num);
	}
} 


//��������߶�
int getBiTreeHeight(BiNode *pBT){
	int m,n;
	if(pBT == NULL){
		return 0;
	}
	m = getBiTreeHeight(pBT->lChild);
	n = getBiTreeHeight(pBT->rChild);
	if(m > n){
		return m + 1;
	}else{
		return n + 1;
	} 
}



/*���������� 
�������� 
*/

TBiNode* preSuc(TBiNode *P){
	if(P->ltag == 0){
		return P->lChild;
	}else{
		return P->rChild;
	}
} 	

//��������
TBiNode* inSuc(TBiNode *P){
	TBiNode *q = P->rChild;
	if(P->rtag == 1){
		return P->rChild;
	}else{
		while(q->ltag == 0){
			q = q->lChild; 
		}
		return q;
	}
}
//ע��������ǰ���ͺ������������ʵ�ֵ�


//�����������������(�ǵݹ�)
void preOrder(TBiNode *T){
	BiNode *p = T;
	while(p != NULL){
		visit(p);
		p = preSuc(p);
	}
}


//algorithms
//���������������Ҷ�ӽ���ֵ
void visit2(BiNode *T){
	if(T != NULL&T->lChild == NULL&T->rChild == NULL){
		cout << T->data <<endl; 
	}
} 

void leaf_node(BiNode *T){
	if(T){
		visit2(T);
		leaf_node(T->lChild);
		leaf_node(T->rChild);
	}
}

//��������������н��ֵ�����Ӧ���/���

void visit3(int num,int level){
	cout << "level: "<<level<<endl;
	cout << "num: " <<num<<endl;
}

void nodeLevelInfo(BiNode *T,int &num,int level){
	if(T){
		num++;	
		visit3(num,level);
		nodeLevelInfo(T->lChild,num,level + 1);
		nodeLevelInfo(T->rChild,num,level + 1);
	}
}


                                                                                                                                                                                                                                                                                                                                                                                                                                                            
int main(){
	
	//�������� 
	BiNode *BT;
	creatBiTree(BT);
	preOrderTraverse(BT);
	
	return 0;

}


