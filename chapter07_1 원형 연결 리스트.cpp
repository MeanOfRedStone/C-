/*
*���� ����Ʈ�� ó���� ���� 
���� �ܼ� ���Ḯ��Ʈ�� �ٸ��� : ������ ��尡 ���ο� ��带 ����Ű���� �ؾ���.
//���α׷� 7.1 ���� ���� ����Ʈ ó���� �����ϴ� �Լ�
(1)���ο� ����� ��ũ�� node->link�� ù ��° ��带 ����Ŵ
(2)������ ����� ��ũ�� �ٽ� ó�� ����� node�� ����Ŵ
(3)head�� ������ ��带 ����Ŵ 
ListNode* insert_first(ListNode *head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL)
	{
		head = node; //head�ڸ� node �� ä�� 
		node->link = head; //���������� ������ ����� node �� ������ ��带 ����Ű�� ���ؼ��� head(=���� ��� �� ��ü) 
	}
	else
	{
		node->link = head->link; //(1) head ->link�� ������ ��尡 ����Ű�� ���(������ ���) 
		head->link = node; //������ ��� �� ��ü�� head ->link�� ������ ��� node�� ����Ŵ 
	}
	
	return head;
}  


*���� ����Ʈ�� ���� ����
->head->link ��ġ�� ���ο� ���� �ٲ��ָ� ������ ��尡 �ȴ�.


//���α׷� 7.2 �������Ḯ��Ʈ�� ���� �����ϴ� �Լ�
ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link; //���Ӱ� �߰��� ��忡 ������ ��带 ����Ű�� head�� ����Ű�� �ڸ��� �־���(=������ ���)
		head->link = node; //������ head ��� �� ����Ű�� ��带 ������ ����� node�� ����Ŵ 
		head = node; //������ ��带 node�� �ٲ��� 
	}
	
	return head;
	
}

������ ���԰� ���ʻ����� ����: �ᱹ head ���� ��ġ�� ������ head�� �ٲ���� �ȹٲ������ �߿�
���� ���� ����Ʈ�� ��ȯ�ϱ� ���� 

*/
//�׽�Ʈ ���α׷� -> ������ ����� ��ũ�� NULL�� �ƴ϶� ����Ʈ�� ���� �����޴��� �˻��ϱ� ���ؼ� ��������Ϳ� ���ؾ� �Ѵ�.
//while ��� do-while�� �����. 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	ListNode *link;
} ListNode;

//����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode *p;
	if(head == NULL)
	{
		return;
	}
	else
	{
		p = head->link; //������ ���� ��忡�� ����(=ù ���) 
		do{
			printf("%d->", p->data);
			p = p->link;
		}while (p != head->link); //������ ��ũ������ ��� : ��ȯ�ϱ� ������ do-while�� ���ش�. 
	}	
} 

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		//������ �߿��Ѱ�? ��ġ ���� �ִ� �� �־���� ���� //���� ���Ḯ��Ʈ�� ����Ÿ �ְ� / ��ũ �־��� 
	}
	
	return head;
} 

ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node; // ��·�� ������ ��尡 ����Ű�� ��尡 ����Ű�� ���� ���ο� ��� ���Ǿ�� ��. head�� ������ ��� �� ��ü 
		head = node;
	} 
	
	return head; 
} 

int main(void)
{
	ListNode *head = NULL;
	
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	
	return 0;
}
