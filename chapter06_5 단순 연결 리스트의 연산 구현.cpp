/*
// *단순 연결 리스트의 정의 : 원칙적으로 헤드 포인터만 있으면 된다. 
ListNode *head; 


//*삽입 연산 insert_first() : 리스트의 첫 부분에 새로운 노드(head 위치 변)  추가
ListNode* insert_first(ListNode *head, element value); 

//프로그램 6.1 단순 연결 리스트의 삽입함수
ListNode* insert_first(ListNode *head, int value)  //결과 값이 ListNode 포인터(head)이기 때문 
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //(1)동적 메모리를 할당해 새로운 노드 p를 생성 
	p->data = value; //	(2)p->data에 value를 저장 
	p->link = head; //(3)p->link에 헤드 링크가 가리키는 노드로 변경 
	head = p; //(4) head를 p값으로 변경 경 
	return head;  //head를 돌려주면 전체 연결 리스트를 알 수 있다. 
	
} 

//*삽입 연산 insert() : 연결 리스트 중간에 새로운 노드를 추가한다.
//선행 노드 위치: pre
//새로운 데이터 삽입 후 다른 노드 이동할 필요 없다! - 연결 리스트의 장점 

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //pre->link(가리킨다는 의미 자체가 노드를 의미: head를 생각해보자)  해당 자리에 p 자체를 넣어좀/ p->link를 넣어주면 p가 가리키는 새로운 노드를 의미 .
	return head;	
} 

//*delete_first()함수
ListNode* delete_first(ListNode *head) 
{
	ListNode *removed //제거할 노드
	if(head == NULL)
	{
		return NULL;
	}
	else
	{
		removed = head; //(1)헤드 포인터 값을 removed에 복사 : removed 자리를 head로 채워줌 삭제 시는 먼저 한다. 
		head = removed->link; //(2)헤드 포인터 값을 head->link로 변경 
		free(removed);
		return head;
	} 
}

//*삭제 연산 delete() 
//pre가 가리키는 노드를 삭제 
ListNode* delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //removed 자체를 pre->link가 대체. 가리킨다는 자체가 노드임 
	pre->link = removed->link; 
	free(removed);
	return head;
}

//*print_list() : 노드의 링크값이 NULL이 아니면 계속 링크를 따라 가며 노드를 방문 
//방문연산 - 연결 리스트의 기본 연산 
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

//오류 처리 함수 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//첫행에 노드 삽입
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //head 자체는 포인터이기 때문에 head->link라고 하지 않는다. 
	head = p; //head 자체를 listnode p가 대신한다.
	return head; 
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //포인터 자리에 이제 새로운 노드를 넣어주는 것. 
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
		removed = head; //노드 removed 자리에 포인터인 head를 넣어준다.
		head = removed->link;
		free(removed);
		return head; 
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //노드 그 자체는 포인터와 같다.
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p=p->link) //새로운 링크 자리의 주소값이 비어있지 않다면 
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
