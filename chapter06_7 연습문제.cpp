/*
1. ���� �� NULL �����Ͱ� �������� �ʴ� ����ü��?
�� : (2) ���� ���Ḯ��Ʈ
-> ������ ��尡 ������ ���� ����Ǳ� ����

2.����Ʈ�� n��° ��Ҹ� ���� ������ ã�� �� �ִ� ���� �����?
�� : (4) ���� ���� ����Ʈ
->ó���� �� �� �� ����� ���������� ������ ��ũ�� Ÿ�� �̵��� �� �ֱ� ����

3.�ܼ� ���� ����Ʈ���� ������ last�� ������ ��带 �����ٰ� �� �� ���� ���� �� ���� ����
�� : (3) last->link == NULL 
-> ������ �����ʹ� �����ϰ� �� �������� ����� ��ũ�� ���� ���̴�.

4.�ܼ� ���� ����Ʈ�� ��带 ������ p�� �湮�ϰ��� �Ѵ�. ���� p�� ����Ű�� ��忡�� ���� �ڵ�� ������?  
�� : (3) p = p->link
->���� ����� ��ũ�� �� ���� ���� ����.
��, ���� ������ �� ��ü�� ����.

5.������ ���� ���� p�� 2�� �����ϴ� ��带 ����Ű���� �ϴ� ������ �ۼ��϶�.
���� ����
p = 1 / node a
node a = 2 / node b
node b = 3 / null

p = node a(��ũ�� �־���) 
p->link = node b 
->��ũ�� �־��ָ� �ȴ�. ��ũ�� ��� �� ��ü 

6.������ ���� ���� q�� 1�� �����ϴ� ��带 ����Ű���� �ϴ� ������ ����� 
��ũp = 1 / node a
node a = 2 / node b
node b = 3 / null 

��ũ q = 2 / node b
��ũ r = 3 / null 

��ũ q = 1 / node a

7.������ ���� ���� ����Ʈ���� �Ʒ��� ���� �ڵ带 �����Ѵٰ� ����, ������ ���� �Ŀ� ������ p�� ����Ű�� ���� � ����ΰ�?
�� : NULL�̴�. ������ ��尡 ����Ű�� ��ũ�� NULL�ε�, �ش� for �ݺ����� ���������� �̵���Ű�� �����̴�.

8.���� ���԰� ������ �糡���� ���Ƿ� ����Ǵ� �ڷ� �����̴�. ���� �׸��� ���̴ܼ����Ḯ��Ʈ�� ���� �����Ѵٰ� �� �� O(1) �ð�
���� ������ �� ���� ������? 
Ǯ�� 
(1) insertFirst  : Node x->data = value / Node x->link = first / first = Node x -> ������ 3�� ���길
(3) deletFirst : removed = first / head = Node x -> link / free(removed) -> ������ 3�� ���길 ����
�� 
(4) deleteLast 
deleteLast�� ��� ������ ��� ������ ��带 �˾ƾ� �ϴµ� �̸� ���ؼ��� �ܼ� ���� ����Ʈ������ head���� for�ݺ������� �̵��ؾ� �Ѵ�.
*/ 
/*
//9.������ ���� �ܼ� ���� ����Ʈ�� ����ڰ� �Է��ϴ� ���� �����ߴٰ� ����ϴ� ���α׷��� �ۼ��϶�.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //���� p�� �ϼ������ְ�
	head = p; //link ��ü�� head == ���� ��� �ڸ�. �̰���  p�� �־��ش�.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p�� �ϼ������ְ� ��ġ ����־��ش�. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //�����͸� ���� �ִ� ���� �ƴϱ� ������ ���� �޸� �Ҵ��� �� �ʿ䰡 ����.
	removed = head; //removed ���� �˱� ���ؼ��� removed�� ���� �˱� �˾ƾ� ��. �̸�  ���ؼ� link ����ü�� head == ù ��� 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��ũ�� ��� �� ��ü�̴ϱ� removed�� ���� �˷��� pre->link�� �־������. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //�������̶� �� �˸��� ����	
} 

int main(void)
{
	ListNode *head = NULL; //head ���� ó������ ����ִ� ���·� ����
	int n;
	printf("����� ���� : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 �̻� �Է��ϼ���.");
	}
	else if(n == 1)
	{
		element value;
		printf("��� #1�� ������ : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		print_list(head);
	}
	else
	{
		element value;
		printf("��� #1�� ������ : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("��� #%d�� ������ : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		print_list(head);
	}
	

//	Ǯ�̰��� (���� ������ if ���� / for loop �ȿ� ���� ���� 
//	head = insert_first(head, 3); //1�� 
//	location = head;
	//��ũ��ȭ :0�� 
//	head = insert(head, location, 5); //2�� 
//	location = head;
//	location = location->link; : 1�� 
//	head = insert(head, location, 7);//3�� 
//	location = head;
//	location = location->link;
//	location = location->link; : 2�� 
//	print_list(head); 

	
	return 0;	
} 
*/
/*
//10. ������ ���� ���Ḯ��Ʈ�� ����� ������ ����ϴ� ���α׷��� �ۼ��غ���. 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //���� p�� �ϼ������ְ�
	head = p; //link ��ü�� head == ���� ��� �ڸ�. �̰���  p�� �־��ش�.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p�� �ϼ������ְ� ��ġ ����־��ش�. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //�����͸� ���� �ִ� ���� �ƴϱ� ������ ���� �޸� �Ҵ��� �� �ʿ䰡 ����.
	removed = head; //removed ���� �˱� ���ؼ��� removed�� ���� �˱� �˾ƾ� ��. �̸�  ���ؼ� link ����ü�� head == ù ��� 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��ũ�� ��� �� ��ü�̴ϱ� removed�� ���� �˷��� pre->link�� �־������. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //�������̶� �� �˸��� ����	
} 

int main(void)
{
	ListNode *head = NULL; //head ���� ó������ ����ִ� ���·� ����
	int n;
	printf("����� ���� : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 �̻� �Է��ϼ���.");
	}
	else if(n == 1)
	{
		element value;
		printf("��� #1�� ������ : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		printf("���� ����Ʈ ����� ���� = 1"); 
	}
	else
	{
		element value;
		printf("��� #1�� ������ : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("��� #%d�� ������ : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		int cnt = 0;
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			cnt = cnt + 1;
		}
		printf("���� ����Ʈ ����� ���� = %d", cnt);
	}
	
	return 0;	
} 
*/
//11.�ܼ� ���� ����Ʈ�� ������ ����Ǿ� �ִ�. ���� ����Ʈ�� �ִ� ��� ����� ������ ���� ���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //���� p�� �ϼ������ְ�
	head = p; //link ��ü�� head == ���� ��� �ڸ�. �̰���  p�� �־��ش�.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p�� �ϼ������ְ� ��ġ ����־��ش�. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //�����͸� ���� �ִ� ���� �ƴϱ� ������ ���� �޸� �Ҵ��� �� �ʿ䰡 ����.
	removed = head; //removed ���� �˱� ���ؼ��� removed�� ���� �˱� �˾ƾ� ��. �̸�  ���ؼ� link ����ü�� head == ù ��� 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��ũ�� ��� �� ��ü�̴ϱ� removed�� ���� �˷��� pre->link�� �־������. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //�������̶� �� �˸��� ����	
} 

int main(void)
{
	ListNode *head = NULL; //head ���� ó������ ����ִ� ���·� ����
	int n;
	printf("����� ���� : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 �̻� �Է��ϼ���.");
	}
	else if(n == 1)
	{
		element value;
		printf("��� #1�� ������ : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		printf("���� ����Ʈ �������� �� = %d", value); 
	}
	else
	{
		element value;
		printf("��� #1�� ������ : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("��� #%d�� ������ : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		int sum = 0;
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			sum = sum + p->data;
		}
		printf("���� ����Ʈ�� ������ �� = %d", sum);
	}
	
	return 0;	
} 
	

