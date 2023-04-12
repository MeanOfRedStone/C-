/*
//10��. �迭�� ��� �ִ� ������ ������ �Ųٷ� �ϴ� ���α׷��� �ۼ��غ���. ���� ��� 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top; 
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
}

int main(void)
{
	StackType s;
	init_stack(&s);
	int n;
	element item;
	printf("���� �迭�� ũ�� : ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++) 
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &item); 
		push(&s, item);
	}
	
	printf("������ ���� �迭: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", pop(&s));

	}
	return 0;	
}
*/
//11.���Ŀ� �ִ� ��ȣ�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�.
//	���� ��ȣ�� ���� ������ ��ȣ ��ȣ�� �ϳ��� �����Ѵ�.
//	������ ��ȣ�� ������ ��Ī�Ǵ� ���� ��ȣ ��ȣ�� ����Ѵ�.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
}



int main(void)
{
	StackType s;
	char ch, open_ch; //ch Ȯ�� ���ڿ� open_ch ���� Ȯ�� ���ڿ� 
	init_stack(&s);

	printf("���� : ");
	char p[1001]; //�������� ���ڿ� �� ��� char�� ������ ��� 
	gets(p);
	int n = strlen(p);
	int cnt = 0;
	printf("��ȣ �� : ");
	
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		switch(ch)
		{
		case '(' :
		{
			push(&s, ch);
			cnt += 1;
			printf("%d ", cnt);
			break;
		}
		case ')' :
		{
			pop(&s);
			printf("%d ", s.top+2);
			break;
		}
		}
	}

	return 0;
} 
