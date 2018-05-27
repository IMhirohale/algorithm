#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


//给定的序列，必须是能够建立成二叉树的序列
//输入一颗二叉树，然后构建出来，空树的或者空结点的标志是
//二叉树结束的标志，这点尤为重要

//可在遍历的过程中生成结点，建立二叉树的存储结构
//前序、中序、后序都可
//通过前序遍历的方式建立二叉树
void createBiTree(BiTree &T){
	
	int ch;
	cin >> ch;
	if(ch == 0){ //表示空结点

		T = NULL;

	}else{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		//T = new BiTNode;
		T->data = ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);

	}

}

//递归前序遍历
void preOrderTraverse(BiTree T){

	if(T != NULL){
		cout << T->data << " ";
		preOrderTraverse(T->lchild);
		preOrderTraverse(T->rchild);
	}

}

//递归中序遍历
void inOrderTraverse(BiTree T){
	
	if(T != NULL){
		inOrderTraverse(T->lchild);
		cout << T->data << " ";
		inOrderTraverse(T->rchild);
	}
	
}

//递归后序遍历
void postOrderTraverse(BiTree T){

	if(T != NULL){
		postOrderTraverse(T->lchild);
		postOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
}

//非递归遍历二叉树

int main(){

	BiTree T1;
	cout << "请输入二叉树的元素!" << endl;
	createBiTree(T1);
	cout << "创建二叉树成功!" << endl;

	return 0;
}
