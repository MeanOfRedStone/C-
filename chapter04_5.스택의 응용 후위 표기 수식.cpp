/*
//���α׷� 4.7 ����ǥ��� ��� 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top; 
}StackType;

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

//���� ǥ�� ���� ��� �Լ�
int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;
	
	init_stack(&s);
	
	for(i = 0 ; i < len; i++)
	{
		ch = exp[i];
		if(ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0'; // �Է��� �ǿ������� ���
			//���� '5' - '0'�� �ϸ� ���ڷ� �Է� ?? �׷���... 
			push(&s, value);	
		} 
		else // �����ڰ� �ԷµǸ� �ǿ����� ���ÿ��� ���� 
		{
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch)
			{
				case '+' : push(&s, op1 + op2); break;
				case '-' : push(&s, op1 - op2); break;
				case '*' : push(&s, op1 * op2); break;
				case '/' : push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main(void)
{
	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
}  
*/
//���α׷� 4.8 ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top; 
}StackType;

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

int prec(char op)
{
	switch (op)
	{
		case '(' : case ')' : return 0;
		case '+' : case '-' : return 1;
		case '*' : case '/' : return 2;
	}
	return -1;
}
//���� -> ����

void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	
	init_stack(&s);
	for(i = 0; i < len; i++)
	{
		ch = exp[i];
		switch(ch)
		{
		case '+' : case '-' : case '*' : case '/' :
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch); //s ����ü ���� ���ڰ� �켱���� �� Ŭ  ��� push
			break;//stack �� ������ ���� ���� ���� �ִ´�. 
			
		case '(' :
			push(&s, ch);
			break;
			
		case ')' :
			top_op = pop(&s);
			while(top_op != '(')
			{
				printf("%c", top_op); 
				top_op = pop(&s);
			}
			break;
			
		default :
			printf("%c", ch);
			break;	
		}
	}
	while(!is_empty(&s))
		printf("%c", pop(&s)); // ���ÿ� ����� �����ڵ� ��� 
}

int main(void)
{
	char *s = "(2+3)*4+9";
	printf("����ǥ����� %s\n", s);
	printf("����ǥ����� ");
	infix_to_postfix(s);
	printf("\n");
	return 0; 
} 
