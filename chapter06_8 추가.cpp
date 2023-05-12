//LAB-SOLUTION 
/*
LAB1 .과일의 이름을 저장하는 단순 연결 리스트 

1. element를 !배열을 포함!(하면 구조체만 가능?)하고 있는 구조체로 변경
typedef struct {
	char name[100];
} element;

2. print_list
void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p = p->link)
	{
		printf("%s->", p->data.name);
	}
	printf("NULL\n");
} 
*/
/*Solution1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
} element;
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
ListNode* insert_first(ListNode *head, element value)
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
	if(head==NULL)
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
	for(ListNode *p = head; p != NULL; p = p->link)
	{
		printf("%s->", p->data.name);
	}
	printf("NULL\n");
} 

int main(void)
{
	ListNode *head = NULL;
	element data;
	
	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);
	
	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);
	
	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}
*/
/*
LAB2. 두개의 리스트를 하나로 합치는 함수 작성 
(1) 첫 번째 리스트의 맨 마지막 노드로 가서
(2) 두 번째 노드를 가리키도록 변경 
주의) list1이나 list2가 NULL인경우를 반드시 처리해야 한다.

ListNode* concat_list(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL)
	{
		return head2;
	}
	else if(head2 == NULL)
	{
		return head1;
	}
	else
	{
		for(ListNode *p = head1; p != NULL; p = p->link)
		{
		}
		p->link = head2;
	}
	
	return head1;
}

*/
/*Solution2.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	if(head==NULL)
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
//도전 문제 :index 번째의 데이터 반환 
element get_entry(ListNode *head, int index) 
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p = head;
	for(int i = 0; i < index - 1; i++) 
	{
		p = p->link;
	}

	return p->data;
}
//quiz 2번 문제 
int get_length(ListNode *head)
{
	int count = 0;
	for(ListNode *p = head; p != NULL; p=p->link) //새로운 링크 자리의 주소값이 비어있지 않다면 
	{
		count = count + 1;
	}
	return count;
}

ListNode* concat_list(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL)
	{
		return head2;
	}
	else if(head2 == NULL)
	{
		return head1;
	}
	else
	{
		ListNode *p;
		p = head1;
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = head2;
	}
	
	return head1;
}

int main(void)
{
	ListNode *head1 = NULL;
	ListNode *head2 = NULL;
	
	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);
	
	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);
	
	head1 = concat_list(head1, head2);
	print_list(head1);
	
	return 0;
}
*/
/*
LAB3. 리스트를 역순으로 만드는 연산
(1)3개의 포인터를 사용해서 현재의 연결 리스트 안에서 문제 해결 
(2)미리 노드를 알아둬야 한다.
(3)p: 역순으로 만들 리스트 
   / q: 현재 역순으로 만들 노드 
   / r : 이미 역순으로 변경된 리스트 
ListNode* reverse(ListNode *head)
{
	//순회 포인터로 p, q, r 사용
	ListNode *p, *q, *r;
	
	p = head; //p는 역순으로 만들 리스트 
	q = NULL; //q는 역순으로 만들 노드 -1개씩 저장 
	while (p != NULL)
	{
		r = q; //r은 역순으로 된 리스트 -노드 여러개 
			   //r은 q를, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; //q의 링크 방향을 바꾼다. 
	}
	return q; 
} 
*/
/*Solution.3*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	if(head==NULL)
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
//도전 문제 :index 번째의 데이터 반환 
element get_entry(ListNode *head, int index) 
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p = head;
	for(int i = 0; i < index - 1; i++) 
	{
		p = p->link;
	}

	return p->data;
}
//quiz 2번 문제 
int get_length(ListNode *head)
{
	int count = 0;
	for(ListNode *p = head; p != NULL; p=p->link) //새로운 링크 자리의 주소값이 비어있지 않다면 
	{
		count = count + 1;
	}
	return count;
}

ListNode* concat_list(ListNode *head1, ListNode *head2)
{
	if(head1 == NULL)
	{
		return head2;
	}
	else if(head2 == NULL)
	{
		return head1;
	}
	else
	{
		ListNode *p;
		p = head1;
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = head2;
	}
	
	return head1;
}

ListNode* reverse(ListNode *head)
{
	//순회 포인터로 p, q, r 사용
	ListNode *p, *q, *r;
	
	p = head; //p는 역순으로 만들 리스트 
	q = NULL; //q는 역순으로 만들 노드 -1개씩 저장 
	while (p != NULL)
	{
		r = q; //r은 역순으로 된 리스트 -노드 여러개 
			   //r은 q를, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; //q의 링크 방향을 바꾼다. 
	}
	return q; 
}

int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	
	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);
	
	head2 = reverse(head1);
	print_list(head2);
	
	return 0;	
} 
