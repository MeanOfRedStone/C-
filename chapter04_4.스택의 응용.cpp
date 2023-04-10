#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
//스택 데이터가 문자형일 때 선언 
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

int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);
	
	for(i = 0; i < n; i++)
	{
		ch = in[i]; //입력 문자열 확인 문자열에 삽입 
		switch(ch)
		{
		case '(' : case '[' : case '{' :
			push(&s, ch); //괄호일 경우 스택에 삽입
			break;
		case ')' : case ']' : case'}' :
			if(is_empty(&s))
			{
				return 0;
			}
			else
			{
				open_ch = pop(&s); //스택에서 오른쪽 문자  확인 스택에 삽입 
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
		printf("%s 괄호검사 성공\n", p);
	}
	else
	{
		printf("%s 괄호검사 실패\n", p);
	}
	return 0;
} 
