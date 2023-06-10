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
/*
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
*/
/*
//12. ���� ����Ʈ���� Ư���� ������ ���� ���� ����� ������ ����ϴ� �Լ��� �ۼ��϶�
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
		printf("Ž���� ���� �Է��Ͻÿ� : ");
		int find;
		scanf("%d", &find);
		if(find == value)
		{
			printf("%d�� ���� ����Ʈ���� 1�� ��Ÿ���ϴ�.", find);
		}
		else
		{
			printf("%d�� ���� ����Ʈ���� 0�� ��Ÿ���ϴ�.", find);
		}
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
		printf("Ž���� ���� �Է��Ͻÿ� : ");
		int find;
		scanf("%d", &find);
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			if(find == p->data)
			{
				cnt = cnt + 1;
			}
		}
		printf("%d�� ���� ����Ʈ���� %d�� ��Ÿ���ϴ�.", find, cnt);
	}
	
	return 0;	
} 
*/
/*
//13. �ܼ� ���� ����Ʈ���� Ž���Լ��� �����Ͽ� Ư���� ������ ���� ���� ��带 �����ϴ� �Լ��� �ۼ��϶�.   
ListNode* search_list(ListNode *head, element x)
{
	ListNode *p = head;
	ListNode *location;
	
	while(p != NULL)
	{
		if(p->data == x)
		{
			delete_delete(head, location);
			p = location;
			return head;
		}
		location = p;
		p = p->link;
	}
	return NULL; //Ž�� ���� �� ��� 
} 
*/
/*
//14.���� �׸��� ���� �����͸� ������ �� �ִ� �ܼ� ���� ����Ʈ�� �����ϴ� ���α׷��� �ۼ��غ���.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char name[100];
	int age;
	float heigh; 
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, char name[100], int age, float heigh)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	strcpy(p->name, name);
	p->age = age;
	p->heigh = heigh;
	p->link = head; //���� p�� �ϼ������ְ�
	head = p; //link ��ü�� head == ���� ��� �ڸ�. �̰���  p�� �־��ش�.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, char name[100], int age, float heigh)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	strcpy(p->name, name);
	p->age = age;
	p->heigh = heigh;
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
		printf(" %s | %d | %.1f ->",p->name, p->age, p->heigh);
	}
	printf("NULL\n"); //�������̶� �� �˸��� ����	
} 

int main(void)
{
	ListNode *head = NULL; //head ���� ó������ ����ִ� ���·� ����
	
	head = insert_first(head, "choi", 30, 1.3);
	head = insert_first(head, "lee", 48, 1.4);	
	head = insert_first(head, "park", 27, 1.2);
	head = insert_first(head, "kim", 34, 1.7);
	print_list(head);
	
	
	return 0;	
} 

*/

/*
//15. �ܼ� ���� ����Ʈ�� ���ĵ��� ���� �������� ����Ʈ�� �����ϰ� �ִ�. ����Ʈ���� �ִ밪�� �ּҰ��� ã�� ���α׷��� �ۼ��϶�. 
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
	if(n <= 1)
	{
		error("2�� �̻� �Է��ϼ���.");
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
		
		int max = -9999;
		int min = 9999; 
		
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			if(max < p->data)
			{
				max = p->data;
			}
			if(min > p->data)
			{
				min = p->data;
			}
		}
		printf("�ִ� : %d, �ּڰ� : %d", max, min);
	}
	
	return 0;	
} 
*/
/*
//16.�ܼ� ���� ����Ʈ�� ��� �����Ͱ� �־����� Ȧ���� °  ��带 �����ϴ� �Լ��� �ۼ��϶�. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

//���� ó�� �Լ� 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ù�࿡ ��� ����
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //head ��ü�� �������̱� ������ head->link��� ���� �ʴ´�. 
	head = p; //head ��ü�� listnode p�� ����Ѵ�.
	return head; 
}

//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //������ �ڸ��� ���� ���ο� ��带 �־��ִ� ��. 
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
		removed = head; //��� removed �ڸ��� �������� head�� �־��ش�.
		head = removed->link;
		free(removed);
		return head; 
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��� �� ��ü�� �����Ϳ� ����.
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p=p->link) //���ο� ��ũ �ڸ��� �ּҰ��� ������� �ʴٸ� 
	{
		printf("%d->",p->data);
	}
	printf("NULL \n");
}
int count_list(ListNode *head)
{
	int cnt = 0;
	for(ListNode *p = head; p != NULL; p = p->link )
	{
		cnt++;
	}
	
	return cnt;
}

ListNode* odd_remove(ListNode* head)
{
	
	int count = count_list(head);

	if(count % 2 == 0)
	{
		for(int i = 1; i < (count / 2) + 1; i++)
		{
			if(i ==1)
			{
				head = delete_first(head);
			}
			else
			{
				ListNode* pre = head; 
				//���� ��� ���� 
				for(int j = 2; j < i; j++)
				{
					pre = pre->link;
				}
				head = delete_delete(head, pre);
			}	
		}
	} 
	else
	{
		for(int i = 1; i < (count / 2) + 1; i++)
		{
			if(i ==1)
			{
				head = delete_first(head);
			}
			else
			{
				ListNode* pre = head; 
				//���� ��� ���� 
				for(int j = 2; j < i; j++)
				{
					pre = pre->link;
				}
				head = delete_delete(head, pre);
			}	
		}
		//Ȧ���� ��� �߰� 
		ListNode* pre = head;
		for(int i = 1; i < (count/2); i++)
		{
			pre = pre->link;
		}
		head = delete_delete(head, pre);
	}
	
	return head;
	
}

int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, 8);
	head = insert_first(head, 7);
	head = insert_first(head, 6);
	head = insert_first(head, 5);
	head = insert_first(head, 4);
	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 1);
	
	print_list(head);
	printf("\n");
//debugingr���� 
////	printf("����Ʈ�� �� : %d\n", count_list(head));
//	
//
//	//head�� ���� Ÿ���ؾ��� 
//	ListNode* removed = head;
//	head = head->link;
//	free(removed);
//	print_list(head);
//	
//	removed = head->link;
//	head->link = head->link->link;
//	free(removed);
//	
//	print_list(head);
	
	

	head = odd_remove(head);
	print_list(head);
	
	
	return 0;
}
*/
/*
17. �� ���� �ܼ����� ����Ʈ A,B�� �־��� ���� ���, alternate �Լ��� �ۼ��϶�. 
alternate �Լ��� A�� B�κ��� ��带 ������ �����ͼ� ���ο� ����Ʈ C�� ����� �����̴�. 
���� �Է¸���Ʈ �߿� �ϳ��� ������ �Ǹ� ������ ��带 ���� C�� �ű��.
�Լ��� �����Ͽ� �ùٸ��� �����ϴ��� �׽�Ʈ�϶�. �ۼ��� �Լ��� �ð� ���⵵�� ���϶�. 


#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link; 
} ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = (ListType *)malloc(sizeof(ListType));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}



//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

void insert_last(ListType *list, element value)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;
	
	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}



////list3 = list1 + list2 
void* alternate(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//��ũ�� �� : NULL ���� �ƴ� ������ ���� 
	while(head1 && head2)
	{
		//head1 ������ �ֱ� 
		insert_last(list3, head1->data);
		
		//head2 ������ �ֱ� 
		insert_last(list3, head2->data);
		
		//head1, head2 ���� ���� �Ѿ�� 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵� �����
	//��� ���׽����� ����
	for(;head1 != NULL; head1 = head1->link)  //a�� ���� �ƴҶ����� 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	

}

void print_list(ListType* list)
{
	ListNode* head = list->head;
	for(; head != NULL; head = head->link)
	{
		printf(" | %d | ->", head->data);
	}
	printf("\n");
}

int main(void)
{
	ListType *L1 = create();
	ListType *L2 = create();
	ListType *L3 = create();
		
	//����Ʈ��� 1 
	insert_last(L1, 12);
	insert_last(L1, 8);
	insert_last(L1, 0);
	
	//����Ʈ��� 2 
	insert_last(L2, 2);
	insert_last(L2, 10);
	insert_last(L2, 6);

	print_list(L1);
	print_list(L2);
	
	alternate(L1, L2, L3);
	
	print_list(L3);
	
	
	return 0;
}
*/

/*
18. 2���� �ܼ� ���� ����Ʈ�� �����ϴ� �Լ��� ���� ������ ����.
�� ���� ���Ḯ��Ʈ a, b�� �����Ͱ��� ������������ ������ ���ĵǾ� �ִ� ���,
�̷��� ���Ļ��¸� �����ϸ鼭 �պ��� �Ͽ� ���ο� ���Ḯ��Ʈ�� ����� �˰��� merge�� �ۼ��϶�.
a�� b�� �ִ� ������ ���� ���ο� ���� ����Ʈ�� �Ű�����. �ۼ��� �˰����� �ð� ���⵵�� ���϶�.

#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link; 
} ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = (ListType *)malloc(sizeof(ListType));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}



//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

void insert_last(ListType *list, element value)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;
	
	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}



////list3 = list1 + list2 
void* alternate(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//��ũ�� �� : NULL ���� �ƴ� ������ ���� 
	while(head1 && head2)
	{
		//head1 ������ �ֱ� 
		insert_last(list3, head1->data);
		
		//head2 ������ �ֱ� 
		insert_last(list3, head2->data);
		
		//head1, head2 ���� ���� �Ѿ�� 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵� �����
	//��� ���׽����� ����
	for(;head1 != NULL; head1 = head1->link)  //a�� ���� �ƴҶ����� 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}

void* merge(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//��ũ�� �� : NULL ���� �ƴ� ������ ���� 
	while(head1 && head2)
	{
		//head1�� �����Ͱ� �� ū ��� 
		if(head1->data > head2->data)
		{
			insert_last(list3, head2->data);
			insert_last(list3, head1->data);
		}
		else if(head1->data < head2->data)
		{
			insert_last(list3, head1->data);
			insert_last(list3, head2->data);
		}
		//head1, head2 ���� ���� �Ѿ�� 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵� �����
	//��� ���׽����� ����
	for(;head1 != NULL; head1 = head1->link)  //a�� ���� �ƴҶ����� 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}
void print_list(ListType* list)
{
	ListNode* head = list->head;
	for(; head != NULL; head = head->link)
	{
		printf(" | %d | ->", head->data);
	}
	printf("\n");
}

int main(void)
{
	ListType *L1 = create();
	ListType *L2 = create();
	ListType *L3 = create();
		
	//����Ʈ��� 1 
	insert_last(L1, 0);
	insert_last(L1, 8);
	insert_last(L1, 12);
	
	//����Ʈ��� 2 
	insert_last(L2, 2);
	insert_last(L2, 6);
	insert_last(L2, 10);

	print_list(L1);
	print_list(L2);
	
	merge(L1, L2, L3);
	
	print_list(L3);
	
	
	return 0;
}
*/
/*
19. �ܼ� ���� ����Ʈ C�� �� ���� �ܼ� ���� ����Ʈ A�� B�� �и��ϴ� �Լ� split�� �ۼ��Ͽ� ����.
C�� Ȧ�� ��° ������ ��� A�� �̵��ǰ� ¦�� ��° ������ ��� B�� �̵��ȴ�.
�� �Լ��� C�� �����Ͽ����� �ȵȴ�. �ۼ��� �˰����� �ð� ���⵵�� ���ϰ� �����Ͽ� �����Ͽ� ����.

#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link; 
} ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = (ListType *)malloc(sizeof(ListType));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}



//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

void insert_last(ListType *list, element value)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;
	
	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}



////list3 = list1 + list2 
void* alternate(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//��ũ�� �� : NULL ���� �ƴ� ������ ���� 
	while(head1 && head2)
	{
		//head1 ������ �ֱ� 
		insert_last(list3, head1->data);
		
		//head2 ������ �ֱ� 
		insert_last(list3, head2->data);
		
		//head1, head2 ���� ���� �Ѿ�� 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵� �����
	//��� ���׽����� ����
	for(;head1 != NULL; head1 = head1->link)  //a�� ���� �ƴҶ����� 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}

void* merge(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//��ũ�� �� : NULL ���� �ƴ� ������ ���� 
	while(head1 && head2)
	{
		//head1�� �����Ͱ� �� ū ��� 
		if(head1->data > head2->data)
		{
			insert_last(list3, head2->data);
			insert_last(list3, head1->data);
		}
		else if(head1->data < head2->data)
		{
			insert_last(list3, head1->data);
			insert_last(list3, head2->data);
		}
		//head1, head2 ���� ���� �Ѿ�� 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a�� b�� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵� �����
	//��� ���׽����� ����
	for(;head1 != NULL; head1 = head1->link)  //a�� ���� �ƴҶ����� 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}
void print_list(ListType* list)
{
	ListNode* head = list->head;
	for(; head != NULL; head = head->link)
	{
		printf(" | %d | ->", head->data);
	}
	printf("\n");
}

// | 0 | -> | 2 | -> | 6 | -> | 8 | -> | 10 | -> | 12 | ->
void split(ListType* list1, ListType* listA, ListType* listB)
{
	ListNode* head1 = list1->head;
	int size = list1->size;
	
	for(int i = 1; i < size + 1; i++)
	{
		if( (i % 2) != 0)
		{
			insert_last(listA, head1->data);
		}
		else
		{
			insert_last(listB, head1->data);
		}
		head1 = head1->link;
	}
}

int main(void)
{
	ListType *L1 = create();
	ListType *L2 = create();
	ListType *L3 = create();
		
	//����Ʈ��� 1 
	insert_last(L1, 0);
	insert_last(L1, 8);
	insert_last(L1, 12);
	
	//����Ʈ��� 2 
	insert_last(L2, 2);
	insert_last(L2, 6);
	insert_last(L2, 10);

	merge(L1, L2, L3);
	
	print_list(L3);
	
	ListType* La = create();
	ListType* Lb = create();
	
	split(L3, La, Lb);
	printf("La : \n");
	print_list(La);
	printf("Lb : \n");
	print_list(Lb);
	
	
	return 0;
}
*/ 

/*
20. �ΰ��� ���׽��� ������ ���� �־�����. 
�̵��� ���� ����Ʈ�� �̿��Ͽ� ��Ÿ���� ������ ���α׷��� �̿��Ͽ� �� ���׽��� ���� ���غ��ÿ�.

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
};

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
	//��ũ�� �� : NULL ���� �ƴ� ������ ���� 
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
		printf("%dx^%d + ", p->coef, p->expon );
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
	insert_last(list1, 3, 6);
	insert_last(list2, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -9, 0);
	
	//���׽� 2 ���� 
	insert_last(list2, -2, 6);
	insert_last(list2, -4, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);
	
	
	poly_print(list1);
	poly_print(list2);
	
	//���׽� 3 = ���׽� 1+���׽�2
	poly_add(list1, list2, list3);
	poly_print(list3);
	

	return 0;
} 
*/

/* 21. �迭�� �̿��Ͽ� ���ڵ��� �Է� �޾� �׻� ������������ ���ĵ� ���·� �����ϴ� ����Ʈ SortedList�� �����Ͽ� ����.
���� ������� �����ϸ� �ȴ�.
add(list, item) :: = ���ĵ� ����Ʈ�� ��Ҹ� �߰��Ѵ�.
delete(list, item) ::= ���ĵ� ����Ʈ���� item�� �����Ѵ�.
clear(list) ::= ����Ʈ�� ��� ��Ҹ� �����Ѵ�.
is_in_list(list,item) ::= item�� ����Ʈ�ȿ� �ִ����� �˻��Ѵ�.
get_length(list) ::= ����Ʈ�� ���̸� ���Ѵ�.
is_empty(list) ::= ����Ʈ�� ����ִ����� �˻��Ѵ�.
is_full(list) ::= ����Ʈ�� ��á������ �˻��Ѵ�.
display(list) ::= ����Ʈ�� ��� ��Ҹ� ǥ���Ѵ�. 


#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 //����Ʈ�� �ִ� ũ��

typedef int element; //�׸��� ����
typedef struct{
	element array[MAX_LIST_SIZE]; //�迭�� ����
	int size; // ���� ����Ʈ�� ����� �׸���� ���� 
} ArrayListType;


//*���ʿ��� : ��� ������ ����ü �����ͷ� �ٵ��. �����ͷ� �޴� ������
//�Լ� �ȿ��� ����ü�� ������ �ʿ䵵 �ֱ� �����̴�. 
//����ü�� ��ȭ��ų �� ������ ��� ���ϸ� ���纻�� ���޵Ǿ� ���� �Ұ�.

//���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType *L)
{
	L->size = 0;
} 

//����Ʈ ���� Ȯ�� �Լ� 
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

//����Ʈ ��ȭ Ȯ�� �Լ�
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE; //����, ���� ť�� �ٸ��� �����Ͱ� ���� �� ��ġ 0�̴�. 
}

//pos ��� �� ��ȯ 
element get_entry(ArrayListType *L, int pos)
{
	if(pos < 0 || pos >= L->size)
	{
		error("��ġ ����");
	}
	else
	{
		return L->array[pos];
	}
}

//����Ʈ ���
void print_list(ArrayListType *L)
{
	int i;
	for(i = 0; i < L->size; i++)
	{
		printf("%d->",L->array[i]);
	}
	printf("\n"); 
} 

//*�׸� �߰� ����
void insert_last(ArrayListType *L, element item)
{
	if(L->size >= MAX_LIST_SIZE)
	{
		error("����Ʈ �����÷ο�"); 
	}
	else
	{
		L->array[L->size++] = item;
	} 
} 

//pos ��ġ�� ���ο� �׸� �߰��� ���
void insert(ArrayListType *L, int pos, element item)
{
	if(!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for(int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

//*�׸� ���� ���� 
element delete_list(ArrayListType *L, int pos)
{
	element item;
	
	if(pos < 0 || pos >= L->size) //L->size�� ������ ��ġ�ϱ�
	{
		error("��ġ ����");	
	}
	else
	{
		item = L->array[pos];
		for(int i = pos; i<(L->size- 1); i++)
		{
			L->array[i] = L->array[i+1]; // �� ������ ��ġ�� ������ ���� ���� �����ϱ� 
		}
		L->size--;
		return item; 
	} 
}

void replace(ArrayListType *L, int pos, element item)
{
	if(pos < 0 || pos >= L->size)
	{
		error("��ġ ����");
	}
	else
	{
		L->array[pos] = item;
	} 
}

int get_length(ArrayListType *L)
{
	return L->size;
}

void insert_first(ArrayListType *L, element item)
{
	if(!is_empty(L))
	{
		for(int i = L->size; i > 0; i--)
		{
			L->array[i] = L->array[i-1];
		}
		L->array[0] = item;
		L->size ++;
	}
}
//sortedList �Լ� ���� 
void add(ArrayListType *L, element item)
{
//	printf("debug>>>> L->size : %d\n", L->size);
	int pos;
	if(!is_empty(L))
	{
		for(int i = L->size - 1; i >= 0; i--) // !!! �߿� �� ��° �׸��� ������ ��������� �Ѵ�. 
		{
			printf("debug>>>> i : %d\n", i);
//			printf("debug>>>> data : %d\n", L->array[i]);
			if(L->array[i] <= item)
			{
				pos = i + 1;
			}
//			break; �̷��� �ϸ� ù ��°���� ���� ������	
		}
//		printf("debug>>>>pos : %d\n", pos);	
		insert(L, pos, item);	
	} 
}


void delete_sort(ArrayListType *L, element item)
{
	int pos;
	for(int i = 0; i < L->size; i++)
	{
		if(L->array[i] == item)
		{
			pos = i;
		}
	}
	delete_list(L, pos);
}
int main(void)
{
	ArrayListType list;
	init(&list);
	insert_last(&list, 3);
	insert_last(&list, 10);
	insert_last(&list, 13);
	print_list(&list);

	delete_sort(&list, 10);
	print_list(&list);
	
	return 0;
}
*/

/*
23. �ܼ� ���� ����Ʈ�� �̿��Ͽ� ���ڵ��� �׻� ������������ ���ĵ� ���·� �����ϴ� ����Ʈ SortedList�� �����Ͽ� ����.
���� ������ ������� �����ϸ� �ȴ�.

add(list, item) :: = ���ĵ� ����Ʈ�� ��Ҹ� �߰��Ѵ�.
delete(list, item) ::= ���ĵ� ����Ʈ���� item�� �����Ѵ�.
clear(list) ::= ����Ʈ�� ��� ��Ҹ� �����Ѵ�.
is_in_list(list,item) ::= item�� ����Ʈ�ȿ� �ִ����� �˻��Ѵ�.
get_length(list) ::= ����Ʈ�� ���̸� ���Ѵ�.
is_empty(list) ::= ����Ʈ�� ����ִ����� �˻��Ѵ�.
is_full(list) ::= ����Ʈ�� ��á������ �˻��Ѵ�.
display(list) ::= ����Ʈ�� ��� ��Ҹ� ǥ���Ѵ�. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

//���� ó�� �Լ� 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ù�࿡ ��� ����
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //head ��ü�� �������̱� ������ head->link��� ���� �ʴ´�. 
	head = p; //head ��ü�� listnode p�� ����Ѵ�.
	return head; 
}

//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //������ �ڸ��� ���� ���ο� ��带 �־��ִ� ��. 
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
		removed = head; //��� removed �ڸ��� �������� head�� �־��ش�.
		head = removed->link;
		free(removed);
		return head; 
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��� �� ��ü�� �����Ϳ� ����.
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p=p->link) //���ο� ��ũ �ڸ��� �ּҰ��� ������� �ʴٸ� 
	{
		printf("%d->",p->data);
	}
	printf("NULL \n");
} 

ListNode * add(ListNode *head, element item)
{
	ListNode *p = head;
	if(head == NULL)
	{
		
		insert_first(head, item);
	}
	else
	{
		
//		for(ListNode *p = head; p != NULL p = p->link)
//		{
//			if(p->data == item)
//			{
//				insert(head, p, item);
//				break;
//			}
//			else if(p->data < item)
//			{	
//				insert(head, p, item);
//				break;
//			}
//		}
//		insert(head, p, item);
		if(item < head->data)
		{
//			printf(">>>>>debug : %d\n",item);
			insert_first(head, item);
		}
		else
		{
			for(ListNode *p = head; (p->data) < item; p = p->link)
			{
//			printf(">>>>>debug : %d",p->data);
				insert(head,p,item);
				break;
			}
		
		}

	}
}

int main(void)
{
	ListNode *head = NULL;
	
	head = add(head, 3);
	print_list(head);
	head = add(head, 5);
	print_list(head);
	head = add(head, 4);
	print_list(head);
	
	head = add(head, 1);
	print_list(head);
	
	return 0;
}
