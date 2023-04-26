/*
// *�ܼ� ���� ����Ʈ�� ���� : ��Ģ������ ��� �����͸� ������ �ȴ�. 
ListNode *head; 


//*���� ���� insert_first() : ����Ʈ�� ù �κп� ���ο� ���(head ��ġ ��)  �߰�
ListNode* insert_first(ListNode *head, element value); 

//���α׷� 6.1 �ܼ� ���� ����Ʈ�� �����Լ�
ListNode* insert_first(ListNode *head, int value)  //��� ���� ListNode ������(head)�̱� ���� 
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)���� �޸𸮸� �Ҵ��� ���ο� ��� p�� ���� 
	p->data = value; //	(2)p->data�� value�� ���� 
	p->link = head; //(3)p->link�� ��� ��ũ�� ����Ű�� ���� ���� 
	head = p; //(4) head�� p������ ���� �� 
	return head;  //head�� �����ָ� ��ü ���� ����Ʈ�� �� �� �ִ�. 
	
} 

//*���� ���� insert() : ���� ����Ʈ �߰��� ���ο� ��带 �߰��Ѵ�.
//���� ��� ��ġ: pre
//���ο� ������ ���� �� �ٸ� ��� �̵��� �ʿ� ����! - ���� ����Ʈ�� ���� 

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //pre->link(����Ų�ٴ� �ǹ� ��ü�� ��带 �ǹ�: head�� �����غ���)  �ش� �ڸ��� p ��ü�� �־���/ p->link�� �־��ָ� p�� ����Ű�� ���ο� ��带 �ǹ� .
	return head;	
} 

//*delete_first()�Լ�
ListNode* delete_first(ListNode *head) 
{
	ListNode *removed //������ ���
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		removed = head; //(1)��� ������ ���� removed�� ���� : removed �ڸ��� head�� ä���� ���� �ô� ���� �Ѵ�. 
		head = removed->link; //(2)��� ������ ���� head->link�� ���� 
		free(removed);
		return head;
	} 
}

//*���� ���� delete() 
//pre�� ����Ű�� ��带 ���� 
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //removed ��ü�� pre->link�� ��ü. ����Ų�ٴ� ��ü�� ����� 
	pre->link = removed->link; 
	free(removed);
	return head;
}

//*print_list() : ����� ��ũ���� NULL�� �ƴϸ� ��� ��ũ�� ���� ���� ��带 �湮 
//�湮���� - ���� ����Ʈ�� �⺻ ���� 
void print_list(ListNode)
{
	for(ListNode *p = head; p != NULL; p = p->link) 
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); 
}
*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

//���� ó�� �Լ� 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ù�࿡ ��� ����
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //head ��ü�� �������̱� ������ head->link��� ���� �ʴ´�. 
	head = p; //head ��ü�� listnode p�� ����Ѵ�.
	return head; 
}

//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //������ �ڸ��� ���� ���ο� ��带 �־��ִ� ��. 
	return head; 
} 

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if(head=NULL)
	{
		return NULL;
	}
	else
	{
		removed = head; //��� removed �ڸ��� �������� head�� �־��ش�.
		head = removed->link;
		free(removed);
		return head; 
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��� �� ��ü�� �����Ϳ� ����.
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p=p->link) //���ο� ��ũ �ڸ��� �ּҰ��� ������� �ʴٸ� 
	{
		printf("%d->",p->data);
	}
	printf("NULL \n");
}

int main(void)
{
	ListNode *head = NULL;
	
	for(int i = 0; i < 5; i++)
	{
		head = insert_first(head, i);
		print_list(head);
	}
	for(int i = 0; i < 5; i++)
	{
		head = delete_first(head);
		print_list(head);
	}
	
	return 0;
}
