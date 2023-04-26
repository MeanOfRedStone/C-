//��������(global variation)�� ���� 
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element; //��� �������� �ڷ���(int)
element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
//��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(element item)
{
	if(is_full()) //is_full()�� return ���� ���̶�� 
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return; //is_full()�� return�� �ٽ� ��ȯ 
	}
	else stack[++top] = item; //top�� 1 �����ְ� �� �� ������ �ݿ� 
}
//���� �Լ� 
element pop() //�Լ� ���� �ϴµ� �ڷ����� element�̹Ƿ�
{
	if(is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}	
	else return stack[top--]; //top�������� ��ȯ�ϰ� top - 1 
}
//��ũ �Լ�
element peek()
{
	if (is_empty())
	{
		fprintf(stderr,"���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	
	printf("%d", stack[2]); //pop �� �ϸ� top�� ���ϰ� �����ʹ� �����ִ�. �� ������°ɱ�? top -1�̸� ����ִ°ɷ� �� 
	return 0;	
}
*/ 
/*
//����ü�� ����
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING]; 
} element; 
//���� ���� ����θ� �ٸ� 

element stack[MAX_STACK_SIZE];
int top = -1; 


int is_empty()
{
	return (top == -1);
}
//��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(element item)
{
	if(is_full()) //is_full()�� return ���� ���̶�� 
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return; //is_full()�� return�� �ٽ� ��ȯ 
	}
	else stack[++top] = item; //top�� 1 �����ְ� �� �� ������ �ݿ� 
}
//���� �Լ� 
element pop() //�Լ� ���� �ϴµ� �ڷ����� element�̹Ƿ�
{
	if(is_empty())
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}	
	else return stack[top--]; //top�������� ��ȯ�ϰ� top - 1 
}
//��ũ �Լ�
element peek()
{
	if (is_empty())
	{
		fprintf(stderr,"���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	element ie = {20190001, "Hong", "Seoul"};
	
	element oe;
	
	push(ie);
	oe = pop(); //pop()�� stack[top] �� stack[0]�� ����ϰ� top = -1 �̵�. �״ϱ� ie�� ����Ѵٴ� �� .
	
	printf("�й� : %d", oe.student_no);
	printf("�̸� : %s", oe.name);
	printf("�ּ� : %s", oe.address);
	
	return 0;
	 
}
*/
//���α׷� 4.3 �Ϲ����� �迭 ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top; 
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return (s->top == -1);	
} 

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
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
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	return 0;
}
 
  
