/*
*이중 연결 리스트에서 임으의 노드를 가리키는  포인터 p
p = p->llink->rlink = p->rlink->llink

-> 공백 상태에서도 성립
*/

/*
*노드의 구조체
typedef int element;
typedef struct DListNode{
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode ;
*/

/*
*삽입연산
(1)새로 만들어진 노드의 링크를 먼저 바꿈 -> 안전함 
(2)기존의 노드와 연결 

//프로그램 7.5 이중 연결 리스트에서의 삽입함수
//새로운 데이터를 노드 before의 오른쪽에 삽입한다.

void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink; (1) 새 노드와 오른쪽 노드를 연결 : 새노드 링크 변경 
	before->rlink->llink = newnode; (2)기존의 before노드 다음 노드의 llink를 새 노드와 연결 : 기존의 링크 변경 1
	before->rlink = newnode;		(3) 왼쪽 노드와 새 노드를 연결  : 기존의 링크 변경 2
} 
*/

/*
*삭제연산
//프로그램 7.6 이중 연결 리스트에서의 삭제함수
void ddelete(DListNode* head, DListNode* removed)
{
	if(removed == head)
	{
		return ;
	}
	else
	{
		removed->llink->rlink = removed->rlink; //왼쪽노드와 연결을 해제 
		removed->rlink->llink = removed->llink; //오른쪽 노드와 연결을 해제 
		free(removed); 
	}	
} 
*/

/*
완전한 프로그램
(주의) 
(1)이중연결 리스트 : 헤드 노드 존재 -> 헤드 포인터 필요 없음 
(2)헤드 노드 : 포인터 x / 구조체 ㅇ
(3)초기화 필요 : 헤더 노드 링크필드가 자기 자신을 가리키도록 해야함
*/
//이중 여결 리스트의 완전한 프로그램
#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct DListNode{
	element data;
	DListNode* rlink;
	DListNode* llink;
}DListNode; 

//구조체를 초기값으로 사용하기 때문에 초기화 필요 
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

//이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode *p;
	//phead 자체는 포인터가 아니라 빈 노드이기 때문에 phead 다음 값부터 출력해야 한다. 
	for(p = phead->rlink; p != phead; p = p->rlink){
		printf("<- | %d | ->",p->data); 
	}	
	printf("\n");
} 

//새로운 노드를 before 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode* newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode; 
	before->rlink = newnode; //before노드의 연결을 제일 마지막에 변경 
} 

//공백 상태의 리스트일 수도 있으니 head노드의 값도 알려준다. 
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
	printf("추가 단계\n");
	for(int i = 0; i < 5; i++)
	{
		dinsert(head,i);
		print_dlist(head);
	}
	printf("삭제 단계\n");
	for(int i = 0; i < 5; i++)
	{
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
//	print_dlist(head); head값을 없애버렸기 때문에 아무 값이나 불러들임 
	return 0;
}
