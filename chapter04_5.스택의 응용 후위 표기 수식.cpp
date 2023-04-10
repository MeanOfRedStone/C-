/*
//프로그램 4.7 후위표기식 계산 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top; 
}StackType;

//스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}
//스택 공백 확인 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//스택 포화 확인 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입함수
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}
//제거 함수 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//확인 함수 
element peek(StackType *s)
{
	if(is_empty(s))//함수 실제 선언할때만 주소 포인터 값 넣어주면 됨 
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
}

//후위 표기 수식 계산 함수
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
			value = ch - '0'; // 입력이 피연산자일 경우
			//문자 '5' - '0'을 하면 숫자로 입력 ?? 그렇다... 
			push(&s, value);	
		} 
		else // 연산자가 입력되면 피연산자 스택에서 제거 
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
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
}  
*/
//프로그램 4.8 중위 표기 수식을 후위 표기 수식으로 변환하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top; 
}StackType;

//스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}
//스택 공백 확인 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//스택 포화 확인 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입함수
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}
//제거 함수 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//확인 함수 
element peek(StackType *s)
{
	if(is_empty(s))//함수 실제 선언할때만 주소 포인터 값 넣어주면 됨 
	{
		fprintf(stderr, "스택 공백 에러\n");
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
//중위 -> 후위

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
			push(&s, ch); //s 구조체 안의 문자가 우선순위 더 클  경우 push
			break;//stack 의 연산자 빼고 현재 문자 넣는다. 
			
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
		printf("%c", pop(&s)); // 스택에 저장된 연산자들 출력 
}

int main(void)
{
	char *s = "(2+3)*4+9";
	printf("중위표기수식 %s\n", s);
	printf("후위표기수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0; 
} 
