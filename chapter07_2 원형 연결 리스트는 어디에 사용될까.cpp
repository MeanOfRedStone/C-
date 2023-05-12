#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef char element[100];
typedef struct ListNode {
	element data;
	ListNode *link;
} ListNode;

//리스트의 항목 출력 -> 멀티 플레이 게임은 계속 반복되야하기 때문에 일반적인 print_list 사용 x 
//void print_list(ListNode* head)
//{
//	ListNode *p;
//	if(head == NULL)
//	{
//		return;
//	}
//	else
//	{
//		p = head->link; //마지막 다음 노드에서 시작(=첫 노드) 
//		do{
//			printf("%d->", p->data);
//			p = p->link;
//		}while (p != head->link); //마지막 링크까지만 출력 : 순환하기 때문이 do-while을 써준다. 
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
		//순서가 중요한가? 그치 먼저 있는 걸 넣어줘야 하지 //단일 연결리스트도 데이타 넣고 / 링크 넣어줌 
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
//		head->link = node; // 어쨌드 기존의 헤드가 가리키는 노드가 가리키는 것은 새로운 노득 ㅏ되어야 함. head는 마지막 노드 그 자체 
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
		printf("현재 차례=%s \n", p->data);
		p = p->link;
	}
	return 0;
}
