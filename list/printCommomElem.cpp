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

void printList(LinkList &L){

	LNode *p;
	p = L->next; // 有头节点的链表，所以要让其执行链表的第一个结点
	while(p != NULL){
		
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

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

int main(){
	LinkList A1,A2;
	cout << "请输入链表A1元素" << endl;
	createListByEnd(A1);
	//createListByHead(A1);
	printList(A1);
	cout << "请输入链表A2元素" << endl;
	createListByEnd(A2);
	//createListByHead(A2);
	printList(A2);
	printListCommomElem(A1,A2);
	return 0;
}
