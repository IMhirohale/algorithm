#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>

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
//测试序列：
//（1）1 2 0 0 3 0 0 
//（2）1 2 4 0 0 5 0 0 3 6 0 0 7 0 0 
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

//利用栈的思想
//前序遍历

void preOrder(BiTree T){
	
	BiTNode *cur;
	stack<BiTNode*> stk; //使用栈来存储树的结点

	if(T == NULL) return ;

	stk.push(T);

	while(!stk.empty()){
		
		cur = stk.top(); stk.pop();//取栈顶元素并删除
		cout << cur->data << " ";//输出值

		if(cur->rchild != NULL) stk.push(cur->rchild);
		if(cur->lchild != NULL) stk.push(cur->lchild);	
		
	}

}

//中序遍历
void inOrder(BiTree T){
	
	BiTNode *cur;
	stack<BiTNode*> stk;

	if(T == NULL) return ;

	cur = T;

	while(cur != NULL){
		
		stk.push(cur);
		cur = cur->lchild;

	}

	while(!stk.empty()){
		
		cur = stk.top(); stk.pop();
		cout << cur->data << " ";

		cur = cur->rchild;

		while(cur != NULL){

			stk.push(cur);
			cur = cur->lchild;
		}
	}
	
}


//后序遍历
//利用2个栈的思路
void posOrder(BiTree T){

	if(T == NULL) return ;
	
	BiTNode *cur;
	stack<BiTNode*> stk1;
	stack<BiTNode*> stk2;

	stk1.push(T);

	while(!stk1.empty()){
	
		cur = stk1.top(); stk1.pop();
		stk2.push(cur);

		if(cur->lchild != NULL) stk1.push(cur->lchild);

		if(cur->rchild != NULL) stk1.push(cur->rchild);
		
	}

	while(!stk2.empty()){
		cur = stk2.top(); stk2.pop();
		cout << cur->data << " ";
	}
	
}

int main(){

	BiTree T1;
	cout << "请输入二叉树的元素!" << endl;
	createBiTree(T1);
	cout << "创建二叉树成功!" << endl;
	cout << "前序遍历：" << endl;
	preOrderTraverse(T1);
	cout << endl;
	preOrder(T1);
	cout << endl;
	cout << "中序遍历：" << endl;
	inOrder(T1);
	cout << endl;
	inOrderTraverse(T1);
	cout << endl;
	cout << "后序遍历：" << endl;
	posOrder(T1);
	cout << endl;
	postOrderTraverse(T1);
	cout << endl;
/*
请输入二叉树的元素!
1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
创建二叉树成功!
前序遍历：
1 2 4 5 3 6 7
1 2 4 5 3 6 7
中序遍历：
4 2 5 1 6 3 7
4 2 5 1 6 3 7
后序遍历：
4 5 2 6 7 3 1
4 5 2 6 7 3 1
*/
	return 0;
}
