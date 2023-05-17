/*
*���� ���� ����Ʈ���� ������ ��带 ����Ű��  ������ p
p = p->llink->rlink = p->rlink->llink

-> ���� ���¿����� ����
*/

/*
*����� ����ü
typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode ;
*/

/*
*���Կ���
(1)���� ������� ����� ��ũ�� ���� �ٲ� -> ������ 
(2)������ ���� ���� 

//���α׷� 7.5 ���� ���� ����Ʈ������ �����Լ�
//���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.

void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink; (1) �� ���� ������ ��带 ���� : ����� ��ũ ���� 
	before->rlink->llink = newnode; (2)������ before��� ���� ����� llink�� �� ���� ���� : ������ ��ũ ���� 1
	before->rlink = newnode;		(3) ���� ���� �� ��带 ����  : ������ ��ũ ���� 2
} 
*/

/*
*��������
//���α׷� 7.6 ���� ���� ����Ʈ������ �����Լ�
void ddelete(DListNode* head, DListNode* removed)
{
	if(removed == head)
	{
		return ;
	}
	else
	{
		removed->llink->rlink = removed->rlink; //���ʳ��� ������ ���� 
		removed->rlink->llink = removed->llink; //������ ���� ������ ���� 
		free(removed); 
	}	
} 
*/

/*
������ ���α׷�
(����) 
(1)���߿��� ����Ʈ : ��� ��� ���� -> ��� ������ �ʿ� ���� 
(2)��� ��� : ������ x / ����ü ��
(3)�ʱ�ȭ �ʿ� : ��� ��� ��ũ�ʵ尡 �ڱ� �ڽ��� ����Ű���� �ؾ���
*/
//���� ���� ����Ʈ�� ������ ���α׷�
#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct DListNode{
	element data;
	DListNode* rlink;
	DListNode* llink;
}DListNode; 

//����ü�� �ʱⰪ���� ����ϱ� ������ �ʱ�ȭ �ʿ� 
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

//���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode *p;
	//phead ��ü�� �����Ͱ� �ƴ϶� �� ����̱� ������ phead ���� ������ ����ؾ� �Ѵ�. 
	for(p = phead->rlink; p != phead; p = p->rlink){
		printf("<- | %d | ->",p->data); 
	}	
	printf("\n");
} 

//���ο� ��带 before �����ʿ� �����Ѵ�.
void dinsert(DListNode *before, element data)
{
	DListNode* newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode; 
	before->rlink = newnode; //before����� ������ ���� �������� ���� 
} 

//���� ������ ����Ʈ�� ���� ������ head����� ���� �˷��ش�. 
void ddelete(DListNode* head, DListNode *removed)
{
	if(removed == head)
	{
		return ;	
	}
	else
	{
		removed->rlink->llink = removed->llink;
		removed->llink->rlink = removed->rlink;
		free(removed);
			
	} 
}

int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");
	for(int i = 0; i < 5; i++)
	{
		dinsert(head,i);
		print_dlist(head);
	}
	printf("���� �ܰ�\n");
	for(int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
//	print_dlist(head); head���� ���ֹ��ȱ� ������ �ƹ� ���̳� �ҷ����� 
	return 0;
}
