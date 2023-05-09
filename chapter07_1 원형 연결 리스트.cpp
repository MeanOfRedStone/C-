/*
*원형 리스트의 처음에 삽입 
기존 단순 연결리스트와 다르점 : 마지막 노드가 새로운 노드를 가리키도록 해야함.
//프로그램 7.1 원형 연결 리스트 처음에 삽입하는 함수
(1)새로운 노드의 링크인 node->link가 첫 번째 노드를 가리킴
(2)마지막 노드의 링크가 다시 처음 노드인 node를 가리킴
(3)head는 마지막 노드를 가리킴 
ListNode* insert_first(ListNode *head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if(head == NULL)
	{
		head = node; //head자리 node 가 채움 
		node->link = head; //마지막이자 최초인 노드인 node 가 최초의 노드를 가리키기 위해서는 head(=최초 노드 그 자체) 
	}
	else
	{
		node->link = head->link; //(1) head ->link는 마지막 노드가 가리키는 노드(최초의 노드) 
		head->link = node; //마지막 노드 그 자체인 head ->link가 최초의 노드 node를 가리킴 
	}
	
	return head;
}  


*원형 리스트의 끝에 삽입
->head->link 위치만 새로운 노드로 바꿔주면 마지막 노드가 된다.


//프로그램 7.2 원형연결리스트의 끝에 삽입하는 함수
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
		node->link = head->link; //새롭게 추가된 노드에 마지막 노드를 가리키는 head가 가리키는 자리에 넣어줌(=최초의 노드)
		head->link = node; //기존의 head 노드 가 가리키는 노드를 마지막 노드인 node가 가리킴 
		head = node; //마지막 노드를 node로 바꿔줌 
	}
	
	return head;
	
}

마지막 삽입과 최초삽입의 차이: 결국 head 다음 위치에 오지만 head가 바뀌는지 안바뀌는지가 중요
원형 연결 리스트는 순환하기 때문 

*/
//테스트 프로그램 -> 마지막 노드의 링크가 NULL이 아니라 리스트의 끝에 도달햇는지 검사하기 위해서 헤드포인터와 비교해야 한다.
//while 대신 do-while을 써야함. 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	ListNode *link;
} ListNode;

//리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode *p;
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		p = head->link;
		do{
			printf("%d->", p->data);
		}while (p! = head->link) //마지막 링크까지만 출력 
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
	}
	
	return head;
} 
