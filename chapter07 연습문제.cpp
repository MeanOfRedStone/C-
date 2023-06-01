/*
��������

1. 
�� : 3��
�ؼ� : pop ���� 3ȸ �ʿ�
a -> b-> c-> d
pop();
b->c->d 
pop();
c->d

2. ���԰� ���� �۾��� ���� �߻��� �� ����ð��� ���� ���� �ҿ�Ǵ� �ڷᱸ����? 
��: 4
�ؼ�: ���Ḯ��Ʈ�� �Ϲ������� �迭 ����Ʈ���� �۾��ð��� ��
		���� 1(x) 
���Ḯ��Ʈ �� (4) ���� ���� ����Ʈ: ������ ���� + ��ũ ���� �Ǵ� ����(�ִ� 4��)���� ���� ���� �ʿ��ϴ�. 
*/
//3. ���� ���� ����Ʈ���� Ư���� ���� Ž���ϴ� search()�� �ۼ��ϰ� �׽�Ʈ�϶�. search()�� ������ ���� ������ ������.
//���� ���Ḯ��Ʈ L���� data�� ������ �ִ� ��带 ã�Ƽ� ��ȯ�Ѵ�.
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	ListNode *link;
} ListNode;

//����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode *p;
	if(head == NULL)
	{
		return;
	}
	else
	{
		p = head->link; //������ ���� ��忡�� ����(=ù ���) 
		do{
			printf("%d->", p->data);
			p = p->link;
		}while (p != head->link); //������ ��ũ������ ��� : ��ȯ�ϱ� ������ do-while�� ���ش�. 
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
		//������ �߿��Ѱ�? ��ġ ���� �ִ� �� �־���� ���� //���� ���Ḯ��Ʈ�� ����Ÿ �ְ� / ��ũ �־��� 
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
		head->link = node; // ��·�� ������ ��尡 ����Ű�� ��尡 ����Ű�� ���� ���ο� ��� ���Ǿ�� ��. head�� ������ ��� �� ��ü 
		head = node;
	} 
	
	return head; 
} 

ListNode* search(ListNode *head, element data)
{
	ListNode *p;
	if(head == NULL){
		fprintf(stderr, "������ ������ϴ�.\n");
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
//4. ���� ���Ḯ��Ʈ�� ����� �������� ������ ��ȯ�ϴ� �Լ� get_size() 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	ListNode *link;
} ListNode;

//����Ʈ�� �׸� ���
void print_list(ListNode* head)
{
	ListNode *p;
	if(head == NULL)
	{
		return;
	}
	else
	{
		p = head->link; //������ ���� ��忡�� ����(=ù ���) 
		do{
			printf("%d->", p->data);
			p = p->link;
		}while (p != head->link); //������ ��ũ������ ��� : ��ȯ�ϱ� ������ do-while�� ���ش�. 
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
		//������ �߿��Ѱ�? ��ġ ���� �ִ� �� �־���� ���� //���� ���Ḯ��Ʈ�� ����Ÿ �ְ� / ��ũ �־��� 
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
		head->link = node; // ��·�� ������ ��尡 ����Ű�� ��尡 ����Ű�� ���� ���ο� ��� ���Ǿ�� ��. head�� ������ ��� �� ��ü 
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
	printf("����Ʈ�� ũ�� : %d", get_size(head));
	
	return 0;
}
*/
/*
5. ���� ���Ḯ��Ʈ�� ������ ������ �����ΰ�?
��:
(����) : Ư�� ��忡�� ��������� �����Ӱ� ������ �� �ִ�. -> ����Ʈ�� ������ �˻��� �� �ִ�.
(����) : (1)���԰� ���� ���꿡 �ɸ��� �ð��� ����. 
		 (2)�޸𸮸� ���� �����Ѵ�.
		 (3)�ڵ尡 ����������. 
*/
/*
//6. ���� ���� ����Ʈ�� �������� ��ȸ�ϸ鼭 ����� ������ ���� ����ϴ� ���α׷��� �ۼ��غ���.
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode *llink;
	struct DListNode *rlink;
}; 

//���߿��Ḯ��Ʈ�� head�� ����ִ� ���. �ʱ�ȭ �ʿ��ϴ�. 
void init(DListNode *phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

//���� ���� ����Ʈ������ ��� ���Խ� ���� ������ ��带 �˾ƾ� �Ѵ�. 
void dinsert(DListNode *before, element data)
{
	DListNode* newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode; 
}

//��尡 ��������� �� �ֱ� ������ head ��� �˾ƾ��Ѵ�. 
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
//��¥�� ���� ���Ḯ��Ʈ�� head�� ����ִ�. head==NULL ���� �ʿ� ����. 
void print_dlist(DListNode *head)
{
	DListNode *p;
	for(p = head->rlink; p != head; p = p->rlink){
		printf("<- | %d | ->", p->data);
	}
	printf("\n"); 
}

//�̹� �����ͷ� �Լ� �����߱� ������ ������ �׳� ���ش�. 
int main(void)
{
	DListNode *head = (DListNode *)malloc(sizeof(DListNode)); //�� ó�� �޸� �Ҵ� �ʿ��ϴ�. 
	init(head);
	
	printf("�������� ������ �Է��Ͻÿ� : ");
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i < n + 1; i ++)
	{
		printf("��� #%d�� �����͸� �Է��Ͻÿ� : ", i);
		element data;
		scanf("%d", &data);
		
		//�Է¹��� ��带 �ִ� �κ� //before�� ã�� ���� i�� ���� head���� rlink�� Ÿ�� �̵��ؾ� �Ѵ�.
		DListNode *p = head;
		for(int j = 1; j < i; j++){
			p = p->rlink;
		} 
		
		dinsert(p, data);
	}
	
// �Է�Ȯ�� 
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
