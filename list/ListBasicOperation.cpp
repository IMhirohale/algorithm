#include <iostream>
#include <cstdio>
#include <stdlib.h> 
#include<stack>

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
	
	L = L->next;//抛弃头结点

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
	L = L->next;//抛弃头结点
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

//判断一个链表是否是回文结构
//使用栈的方式
bool isPalindromeList(LinkList L){
	
	stack<int> stack;//定义一个栈
	LNode *cur;
	cur = L;

	while(cur != NULL){
		stack.push(cur->data);	
		cur = cur->next;
	}

	while(L != NULL){
		if(L->data != stack.top()){
			return false;
		}
		stack.pop();
		L = L->next;
	}

	return true;
}

//优化一下:只压入一半的数据到栈中即可
//使用快慢指针的方式
//判断一个链表是否是回文结构
bool isPalindromeListOptimize(LinkList L){
	
	stack<int>stack;
	LNode *right;
	LNode *cur;
	
	right = L->next;
	cur = L;

	while(cur->next != NULL && cur->next->next != NULL){
		right = right->next;//慢指针
		cur = cur->next->next;//当前指针为快指针
	}

	while(right != NULL){
		stack.push(right->data);
		right = right->next;
	}

	while(!stack.empty()){
		if(L->data != stack.top()){
			return false;
		}
		stack.pop();
		L = L->next;
	}
	return true;	
}

//合并两个单链表
void mergeList(LinkList &L1, LinkList &L2, LinkList &L3){

	LNode *pa,*pb,*pc;
	pa = L1->next;
	pb = L2->next;
	pc = L3 = L1;

	while(pa != NULL & pb != NULL){
		
		if(pa->data <= pb->data){

			pc->next = pa; pc = pa; pa = pa->next;

		}else{
			pc->next = pb; pc = pb; pb = pb->next;
		}
		
	}

	pc->next = pa ? pa : pb;
    free(L2);	
}

//判断单链表是否有环，获取第一个进入环的结点
LNode * getLoopNode(LinkList L){
	if(L == NULL || L->next == NULL || L->next->next == NULL){
		return NULL;
	}

	LNode *slow;
	LNode *fast;

	slow = L->next;
	fast = L->next->next;
    while(slow != fast){

		if(fast->next == NULL || fast->next->next == NULL){
			return NULL;
		}
		slow = slow->next;
		fast = fast->next->next;
	}	

	fast = L;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	
	return slow;
}

//判断两个无环单链表是否相交，返回第一个相交结点
LNode * noLoop(LinkList L1, LinkList L2){
	if(L1 == NULL || L2 == NULL){
		return NULL;
	}

	LNode *cur1;
	LNode *cur2;

	cur1 = L1;
	cur2 = L2;

	int n = 0;
	while(cur1->next != NULL){
		n++;
		cur1 = cur1->next;
	}
	while(cur2->next != NULL){
		n--;
		cur2 = cur2->next;
	}

	if(cur1 != cur2){
		return NULL;
	}
	
	cur1 = n > 0 ? L1 : L2;
	cur2 = cur1 == L1 ? L2: L1;
	
	n = abs(n);
	while(n != 0){
		n--;
		cur1 = cur1->next;
	}

	while(cur1 != cur2){
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}

//判断两个有环单链表是否相交，返回第一个相交的结点
LNode * bothLoop(LinkList L1, LNode *loop1, LinkList L2, LNode *loop2){

	LNode *cur1;
	LNode *cur2;

	if(loop1 == loop2){
		cur1 = L1;
		cur2 = L2;
		int n = 0;

		while(cur1->next != loop1){
			n++;
			cur1 = cur1->next;
		}
		while(cur2->next != loop2){
			n--;
			cur2 = cur2->next;
		}

		cur1 = n > 0 ? L1 : L2;
		cur2 = cur1 == L1 ? L2 : L1;
		n = abs(n);
		while(n != 0){
			n--;
			cur1 = cur1->next;
		}
		
		while(cur1 != cur2){
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;

	}else{
		cur1 = loop1->next;
		while(cur1 != loop1){
			if(cur1 == loop2){
				return loop1;
			}
			cur1 = cur1->next;
		}
		
		return NULL;
	}
	
}

//单链表相交的一系列问题
LNode * getIntersectNode(LinkList L1, LinkList L2){

	if(L1 == NULL || L2 == NULL){
		return NULL;
	}

	LNode *loop1;
	LNode *loop2;

	loop1 = getLoopNode(L1);
	loop2 = getLoopNode(L2);
	if(loop1 == NULL && loop2 == NULL){
		return noLoop(L1,L2);
	}
	if(loop1 != NULL && loop2 != NULL){
		return bothLoop(L1,loop1,L2,loop2);
	}
	return NULL;
}


int main(){
	LinkList A1,A2,A3;
	cout << "请输入链表A1元素" << endl;
	createListByEnd(A1);
	cout << "请输入链表A2元素" << endl;
	createListByEnd(A2);
	printList(A1);
	printList(A2);
	//mergeList(A1,A2,A3);
	//printList(A3);
	/*if(isPalindromeListOptimize(A1)){
		cout << "yyyyy" << endl;
	}else{
		cout << "nnnnn" << endl;
	}*/
	return 0;
}
