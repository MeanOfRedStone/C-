//LAB-SOLUTION 
/*
LAB1 .������ �̸��� �����ϴ� �ܼ� ���� ����Ʈ 

1. element�� !�迭�� ����!(�ϸ� ����ü�� ����?)�ϰ� �ִ� ����ü�� ����
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

//���� ó�� �Լ� 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ù�࿡ ��� ����
ListNode* insert_first(ListNode *head, element value)
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
LAB2. �ΰ��� ����Ʈ�� �ϳ��� ��ġ�� �Լ� �ۼ� 
(1) ù ��° ����Ʈ�� �� ������ ���� ����
(2) �� ��° ��带 ����Ű���� ���� 
����) list1�̳� list2�� NULL�ΰ�츦 �ݵ�� ó���ؾ� �Ѵ�.

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
//���� ���� :index ��°�� ������ ��ȯ 
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
//quiz 2�� ���� 
int get_length(ListNode *head)
{
	int count = 0;
	for(ListNode *p = head; p != NULL; p=p->link) //���ο� ��ũ �ڸ��� �ּҰ��� ������� �ʴٸ� 
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
LAB3. ����Ʈ�� �������� ����� ����
(1)3���� �����͸� ����ؼ� ������ ���� ����Ʈ �ȿ��� ���� �ذ� 
(2)�̸� ��带 �˾Ƶ־� �Ѵ�.
(3)p: �������� ���� ����Ʈ 
   / q: ���� �������� ���� ��� 
   / r : �̹� �������� ����� ����Ʈ 
ListNode* reverse(ListNode *head)
{
	//��ȸ �����ͷ� p, q, r ���
	ListNode *p, *q, *r;
	
	p = head; //p�� �������� ���� ����Ʈ 
	q = NULL; //q�� �������� ���� ��� -1���� ���� 
	while (p != NULL)
	{
		r = q; //r�� �������� �� ����Ʈ -��� ������ 
			   //r�� q��, q�� p�� ���ʷ� ���󰣴�.
		q = p;
		p = p->link;
		q->link = r; //q�� ��ũ ������ �ٲ۴�. 
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
//���� ���� :index ��°�� ������ ��ȯ 
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
//quiz 2�� ���� 
int get_length(ListNode *head)
{
	int count = 0;
	for(ListNode *p = head; p != NULL; p=p->link) //���ο� ��ũ �ڸ��� �ּҰ��� ������� �ʴٸ� 
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
	//��ȸ �����ͷ� p, q, r ���
	ListNode *p, *q, *r;
	
	p = head; //p�� �������� ���� ����Ʈ 
	q = NULL; //q�� �������� ���� ��� -1���� ���� 
	while (p != NULL)
	{
		r = q; //r�� �������� �� ����Ʈ -��� ������ 
			   //r�� q��, q�� p�� ���ʷ� ���󰣴�.
		q = p;
		p = p->link;
		q->link = r; //q�� ��ũ ������ �ٲ۴�. 
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
