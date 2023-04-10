#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
//���� �����Ͱ� �������� �� ���� 
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

int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);
	
	for(i = 0; i < n; i++)
	{
		ch = in[i]; //�Է� ���ڿ� Ȯ�� ���ڿ��� ���� 
		switch(ch)
		{
		case '(' : case '[' : case '{' :
			push(&s, ch); //��ȣ�� ��� ���ÿ� ����
			break;
		case ')' : case ']' : case'}' :
			if(is_empty(&s))
			{
				return 0;
			}
			else
			{
				open_ch = pop(&s); //���ÿ��� ������ ����  Ȯ�� ���ÿ� ���� 
				if((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
				{
					return 0;
				}
				else
				{
					break;
				} 
			} 
		}
	}
	if(!is_empty(&s))
	{
		return 0;
	}
	else
	{
		return 1;
	}	
}

int main(void)
{
	char *p = "{ A[(i+1)]=0; }";
	if(check_matching(p) == 1)
	{
		printf("%s ��ȣ�˻� ����\n", p);
	}
	else
	{
		printf("%s ��ȣ�˻� ����\n", p);
	}
	return 0;
} 
