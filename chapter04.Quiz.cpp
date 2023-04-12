/*
//10번. 배열에 들어 있는 정수의 순서를 거꾸로 하는 프로그램을 작성해보자. 스택 사용 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top; 
} StackType;

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

int main(void)
{
	StackType s;
	init_stack(&s);
	int n;
	element item;
	printf("정수 배열의 크기 : ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++) 
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &item); 
		push(&s, item);
	}
	
	printf("반전된 정수 배열: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", pop(&s));

	}
	return 0;	
}
*/
//11.수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라.
//	왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가한다.
//	오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호 버호를 출력한다.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

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



int main(void)
{
	StackType s;
	char ch, open_ch; //ch 확인 문자열 open_ch 스택 확인 문자열 
	init_stack(&s);

	printf("수식 : ");
	char p[1001]; //여러개의 문자열 널 경우 char는 포인터 사용 
	gets(p);
	int n = strlen(p);
	int cnt = 0;
	printf("괄호 수 : ");
	
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
