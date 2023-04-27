/*
//6. ���� ����Ʈ�� ���� : ���׽� 
//���׽��� �ܼ� ���� ����Ʈ�� ǥ���� ����
typedef struct ListNode{
	int coef;
	int expon;
	struct ListNode *link //����Ʈ ����� �����͸� �ٽ� ������ �ش�. 
} ListNode;

//�� ���׽��� ���׽��� ù ��° ���� ����Ű�� �����ͷ� ǥ���ȴ�. ū �������� ���� ǥ�� 
ListNode *A, *B; 
*/

/*���׽��� �����
(1) ������ ���� ���
-> �� ����� ���Ѵ�.

(2) ������ �ٸ� ���
->���� ������ �׸� ���� �߰��Ѵ�.

�ֳ� ! ���׽��� ���� ���� �������� ���ʷ� �������� ������ ���� ������ ���߿� �ٽ� ��� �ϴ� �ɷ�! 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int coef; //��� 
	int expon; //����
	struct ListNode *link; 
} ListNode;

//���Ḯ��Ʈ ���
typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
} ListType;

//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//����Ʈ ��� ���� �Լ� :�ʱ�ȭ �Լ��� ���� �뵵�� ���.
ListType* create() //���Ḯ��Ʈ ����� ���� ��ȯ������ ListType* �� �������·� ��� 
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist; 
}

//plist�� ���翡 ��������
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp == NULL)
	{
		error("�޸� �Ҵ� ����");
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
		plist->tail->link = temp; //������ ��ũ �ڸ��� 
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
			b = b->link; // ���ذ� �� �ʿ��� �κ� �� a�� ���� 
		}
	}
	
	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵� �����
	//��� ���׽����� ����
	for(;a != NULL; a = a->link)  //a�� ���� �ƴҶ����� 
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
	
	//���Ḯ��Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create() ;
	
	//���׽� 1 ���� 
	insert_last(list1, 3, 12);
	insert_last(list2, 2, 8);
	insert_last(list1, 1, 0);
	
	//���׽� 2 ���� 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	
	poly_print(list1);
	poly_print(list2);
	
	//���׽� 3 = ���׽� 1+���׽�2
	poly_add(list1, list2, list3);
	poly_print(list3);
	
	free(list1);
	free(list2);
	free(list3);
	
	return 0;
}
	
