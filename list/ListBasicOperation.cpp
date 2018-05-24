#include <iostream>
#include <cstdio>
#include <stdlib.h> 
using namespace std;

typedef struct Node{
	int data;
	struct Node * next;
}LNode, *LinkList;

// Function 使用头插法，输入元素是倒顺序的
void createListByHead(LinkList &L){

	LNode *s;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	int x;
	scanf("%d",&x);

	while(x != 99){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		
		scanf("%d",&x);
	}

}

//尾插法进行单链表初始化
void createListByEnd(LinkList &L){

	LNode *s,*r;
	L = (LinkList)malloc(sizeof(LNode));
	r = L; //开始时候指向头结点

	int x;
	scanf("%d",&x);

	while(x != 99){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;

		scanf("%d",&x);
	}

	r->next = NULL;
}

// 打印链表
void printList(LinkList &L){

	LNode *p;
	p = L; // 有头节点的链表，所以要让其执行链表的第一个结点
	while(p != NULL){
		
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

//输出有序链表的公共部分
void printListCommomElem(LinkList &head1, LinkList &head2){

	cout << "print commom elements: " << endl;
	
	while(head1 != NULL && head2 != NULL){
		
		if(head1->data < head2->data){

			head1 = head1->next;

		}else if(head1->data > head2->data){

			head2 = head2->next;

		}else{
			
			cout << head1->data << " ";
			head1 = head1->next;
			head2 = head2->next;
		}
	}

	cout << endl;
	
}

//反转单链表：使用头插法的方式
void reverseListByCreateListHead(LinkList &L){
	
	if(L == NULL || L->next == NULL){
		return ;
	}

	LNode *p,*q;
	p = L->next;
	L->next = NULL;

	while(p != NULL){
	
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;

	}
	
}

//利用辅助指针进行单链表的
void reverseListAssistPointer(LinkList &L){
	
	if(L == NULL || L->next == NULL){
		return ;
	}
	LNode *pre = NULL;//先前指针
	LNode *next = NULL;//后继指针

	while(L != NULL){
		next = L->next;
		L->next = pre;
		pre = L;
		L = next;
	}

	L = pre;
}

//单链表中删除倒数第K的结点
void removeLastKthNode(LinkList &L, int lastKth){

	if(L == NULL || lastKth < 1)
		return ;

	LNode *cur;
	cur = L->next;
	
	while(cur != NULL){
		lastKth--;
		cur = cur->next;
	}

	if(lastKth == 0){
		cur = cur->next;//第一个结点就是倒数第k个结点,删除头结点
	}

	if(lastKth < 0){
		cur = L;
		while(lastKth++ != 0){
			cur = cur->next;
		}
		cur->next  = cur->next->next;//删除第k的结点
	}
	
}


int main(){
	LinkList A1,A2;
	cout << "请输入链表A1元素" << endl;
	createListByEnd(A1);
	printList(A1);
	removeLastKthNode(A1,2);
	//reverseListAssistPointer(A1);
	printList(A1);
	return 0;
}
