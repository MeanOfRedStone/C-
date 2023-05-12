#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef char element[100];
typedef struct ListNode {
	element data;
	ListNode *link;
} ListNode;

//����Ʈ�� �׸� ��� -> ��Ƽ �÷��� ������ ��� �ݺ��Ǿ��ϱ� ������ �Ϲ����� print_list ��� x 
//void print_list(ListNode* head)
//{
//	ListNode *p;
//	if(head == NULL)
//	{
//		return;
//	}
//	else
//	{
//		p = head->link; //������ ���� ��忡�� ����(=ù ���) 
//		do{
//			printf("%d->", p->data);
//			p = p->link;
//		}while (p != head->link); //������ ��ũ������ ��� : ��ȯ�ϱ� ������ do-while�� ���ش�. 
//	}	
//} 

ListNode* insert_first(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	strcpy(node->data, data);
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

//ListNode* insert_last(ListNode* head, element data)
//{
//	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
//	strcpy(node->data, data);
//	if(head == NULL)
//	{
//		head = node;
//		node->link = head;
//	}
//	else
//	{
//		node->link = head->link;
//		head->link = node; // ��·�� ������ ��尡 ����Ű�� ��尡 ����Ű�� ���� ���ο� ��� ���Ǿ�� ��. head�� ������ ��� �� ��ü 
//		head = node;
//	} 
//	
//	return head; 
//} 

int main(void)
{
	ListNode *head = NULL;
	
	head = insert_first(head, "kim");
	head = insert_first(head, "park");
	head = insert_first(head, "choi");
	
	ListNode *p = head;
	for(int i = 0; i < 10; i++)
	{
		printf("���� ����=%s \n", p->data);
		p = p->link;
	}
	return 0;
}
