/*
연습문제

1. 
답 : 3번
해설 : pop 연산 3회 필요
a -> b-> c-> d
pop();
b->c->d 
pop();
c->d

2. 삽입과 삭제 작업이 자주 발생할 때 실행시간이 가장 많이 소요되는 자료구조는? 
답: 4
해설: 연결리스트는 일반적으로 배열 리스트보다 작업시간이 김
		따라서 1(x) 
연결리스트 중 (4) 이중 연결 리스트: 데이터 삽입 + 링크 연결 또는 해제(최대 4번)으로 가장 많이 필요하다. 
*/
//3. 원형 연결 리스트에서 특정한 값을 탐색하는 search()를 작성하고 테스트하라. search()는 다음과 같은 원형을 가진다.
//원형 연결리스트 L에서 data를 가지고 있는 노드를 찾아서 반환한다.
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
		return;
	}
	else
	{
		p = head->link; //마지막 다음 노드에서 시작(=첫 노드) 
		do{
			printf("%d->", p->data);
			p = p->link;
		}while (p != head->link); //마지막 링크까지만 출력 : 순환하기 때문이 do-while을 써준다. 
		printf("\n");
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
		//순서가 중요한가? 그치 먼저 있는 걸 넣어줘야 하지 //단일 연결리스트도 데이타 넣고 / 링크 넣어줌 
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
		head->link = node; // 어쨌드 기존의 헤드가 가리키는 노드가 가리키는 것은 새로운 노득 ㅏ되어야 함. head는 마지막 노드 그 자체 
		head = node;
	} 
	
	return head; 
} 

ListNode* search(ListNode *head, element data)
{
	ListNode *p;
	if(head == NULL){
		fprintf(stderr, "스택이 비었습니다.\n");
		exit(1); 
	}
	else{
		p = head->link;
		do{
			if(p->data == data)
			{
				return p;
			}
			else
			{
				continue;
			}
			p = p->link;
		} while(p != head->link);
	}
} 

int main(void)
{
	ListNode *head = NULL;
	
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	head = insert_first(head, 20);
	print_list(head);
	ListNode *L;
	L = search(head, 20);
	do{
		printf("%d ->", L->data);
		L = L->link;
	} while (L != head->link);
	
	
	return 0;
}

/*
//4. 원형 연결리스트에 저장된 데이터의 개수를 반환하는 함수 get_size() 
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
		return;
	}
	else
	{
		p = head->link; //마지막 다음 노드에서 시작(=첫 노드) 
		do{
			printf("%d->", p->data);
			p = p->link;
		}while (p != head->link); //마지막 링크까지만 출력 : 순환하기 때문이 do-while을 써준다. 
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
		//순서가 중요한가? 그치 먼저 있는 걸 넣어줘야 하지 //단일 연결리스트도 데이타 넣고 / 링크 넣어줌 
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
		head->link = node; // 어쨌드 기존의 헤드가 가리키는 노드가 가리키는 것은 새로운 노득 ㅏ되어야 함. head는 마지막 노드 그 자체 
		head = node;
	} 
	
	return head; 
} 

int get_size(ListNode* head)
{
	ListNode* p;
	int count = 0;
	if(head == NULL){
		return 0;
	}
	else {
		p = head->link;
		do{
			count = count + 1;
			p = p->link;
		} while (p != head->link);
	}
	
	return count;
}

int main(void)
{
	ListNode *head = NULL;
	
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	printf("리스트의 크기 : %d", get_size(head));
	
	return 0;
}
*/
/*
5. 이중 연결리스트의 장점과 단점은 무엇인가?
답:
(장점) : 특정 노드에서 양방향으로 자유롭게 움직일 수 있다. -> 리스트를 빠르게 검색할 수 있다.
(단점) : (1)삽입과 삭제 연산에 걸리는 시간이 많다. 
		 (2)메모리를 많이 차지한다.
		 (3)코드가 복잡해진다. 
*/
/*
//6. 이중 연결 리스트를 역순으로 순회하면서 저장된 데이터 값을 출력하는 프로그램을 작성해보자.
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
}; 

//이중연결리스트의 head는 비어있는 노드. 초기화 필요하다. 
void init(DListNode *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

//이중 연결 리스트에서는 노드 삽입시 삽입 직전의 노드를 알아야 한다. 
void dinsert(DListNode *before, element data)
{
	DListNode* newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode; 
}

//노드가 공백상태일 수 있기 때문에 head 노드 알아야한다. 
void ddelete(DListNode *head, DListNode *removed)
{
	if(removed == head)
	{
		return ;
	}
	else
	{
		removed->llink->rlink = removed->rlink;
		removed->rlink->llink = removed->llink;
		free(removed);	
	} 
}
//어짜피 이중 연결리스트의 head는 비어있다. head==NULL 검증 필요 없다. 
void print_dlist(DListNode *head)
{
	DListNode *p;
	for(p = head->rlink; p != head; p = p->rlink){
		printf("<- | %d | ->", p->data);
	}
	printf("\n"); 
}

//이미 포인터로 함수 선언했기 떄문에 변수는 그냥 써준다. 
int main(void)
{
	DListNode *head = (DListNode *)malloc(sizeof(DListNode)); //맨 처음 메모리 할당 필요하다. 
	init(head);
	
	printf("데이터의 개수를 입력하시오 : ");
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i < n + 1; i ++)
	{
		printf("노드 #%d의 데이터를 입력하시오 : ", i);
		element data;
		scanf("%d", &data);
		
		//입력받은 노드를 넣는 부분 //before을 찾기 위해 i에 따라 head에서 rlink를 타고 이동해야 한다.
		DListNode *p = head;
		for(int j = 1; j < i; j++){
			p = p->rlink;
		} 
		
		dinsert(p, data);
	}
	
// 입력확인 
//	print_dlist(head);

	DListNode *r;
	r = head->llink;
	do{
		printf("%d", r->data);
		r = r->llink;
	} while( r != head);
	
	return 0;
}
*/
