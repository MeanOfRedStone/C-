/*
//6. 연결 리스트의 응용 : 다항식 
//다항식을 단순 연결 리스트로 표현해 보기
typedef struct ListNode{
	int coef;
	int expon;
	struct ListNode *link //리스트 노드의 포인터를 다시 선언해 준다. 
} ListNode;

//각 다항식은 다항식의 첫 번째 항을 가리키는 포인터로 표현된다. 큰 차수부터 노드로 표현 
ListNode *A, *B; 
*/

/*다항식의 연산시
(1) 지수가 같은 경우
-> 두 계수를 더한다.

(2) 지수가 다른 경우
->높은 지수의 항만 새로 추가한다.

왜냐 ! 다항식의 노드는 높은 순서부터 차례로 내려오기 때문에 낮은 지수는 나중에 다시 계산 하는 걸로! 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int coef; //계수 
	int expon; //지수
	struct ListNode *link; 
} ListNode;

//연결리스트 헤더
typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
} ListType;

//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//리스트 헤더 생성 함수 :초기화 함수와 같은 용도로 사용.
ListType* create() //연결리스트 헤더를 만들어서 반환함으로 ListType* 를 변수형태로 사용 
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist; 
}

//plist의 존재에 유의하자
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp == NULL)
	{
		error("메모리 할당 에러");
	}
	else
	{
		temp->coef = coef;
		temp->expon = expon;
		temp->link = NULL;
	}
	
	if(plist->tail == NULL)
	{
		plist->head = plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp; //마지막 링크 자리에 
		plist->tail = temp;
	}
	plist->size ++;		
}

//list3 = list1 + list2 
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	
	int sum;
	
	while(a && b)
	{
		if(a->expon == b->expon)
		{
			sum = a->coef + b->coef;
			if(sum != 0)
			{
				insert_last(plist3, sum, a->expon);
			}
			a = a->link;
			b = b->link;
		}
		else if(a->expon > b->expon)
		{
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else
		{
			insert_last(plist3, b->coef, b->expon);
			b = b->link; // 이해가 더 필요한 부분 위 a와 같이 
		}
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;a != NULL; a = a->link)  //a가 널이 아닐때까지 
	{
		insert_last(plist3, a->coef,a->expon);
	}	
	for(;b != NULL; b = b->link)
	{
		insert_last(plist3, b->coef, b->expon);  	
	}	
}

//
//
void poly_print(ListType* plist)
{
	ListNode *p = plist -> head;
	
	printf("polynomial = ");
	for(;p; p = p->link)
		printf("%d%^%d + ", p->coef, p->expon );
		printf("\n"); 
}

int main(void)
{
	ListType *list1, *list2, *list3;
	
	//연결리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create() ;
	
	//다항식 1 생성 
	insert_last(list1, 3, 12);
	insert_last(list2, 2, 8);
	insert_last(list1, 1, 0);
	
	//다항식 2 생성 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	
	poly_print(list1);
	poly_print(list2);
	
	//다항식 3 = 다항식 1+다항식2
	poly_add(list1, list2, list3);
	poly_print(list3);
	
	free(list1);
	free(list2);
	free(list3);
	
	return 0;
}
	
