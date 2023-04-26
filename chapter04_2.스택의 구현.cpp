//전역변수(global variation)로 구현 
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element; //요소 데이터의 자료형(int)
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty()
{
	return (top == -1);
}
//포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item)
{
	if(is_full()) //is_full()의 return 값이 참이라면 
	{
		fprintf(stderr, "스택 포화 에러\n");
		return; //is_full()의 return값 다시 반환 
	}
	else stack[++top] = item; //top을 1 더해주고 난 뒤 아이템 반영 
}
//삭제 함수 
element pop() //함수 선언 하는데 자료형이 element이므로
{
	if(is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}	
	else return stack[top--]; //top아이템을 반환하고 top - 1 
}
//피크 함수
element peek()
{
	if (is_empty())
	{
		fprintf(stderr,"스택 공백 에러\n");
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
	
	printf("%d", stack[2]); //pop 을 하면 top만 변하고 데이터는 남아있다. 왜 안지우는걸까? top -1이면 비어있는걸로 간 
	return 0;	
}
*/ 
/*
//구조체로 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING]; 
} element; 
//이하 동일 선언부만 다름 

element stack[MAX_STACK_SIZE];
int top = -1; 


int is_empty()
{
	return (top == -1);
}
//포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item)
{
	if(is_full()) //is_full()의 return 값이 참이라면 
	{
		fprintf(stderr, "스택 포화 에러\n");
		return; //is_full()의 return값 다시 반환 
	}
	else stack[++top] = item; //top을 1 더해주고 난 뒤 아이템 반영 
}
//삭제 함수 
element pop() //함수 선언 하는데 자료형이 element이므로
{
	if(is_empty())
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}	
	else return stack[top--]; //top아이템을 반환하고 top - 1 
}
//피크 함수
element peek()
{
	if (is_empty())
	{
		fprintf(stderr,"스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	element ie = {20190001, "Hong", "Seoul"};
	
	element oe;
	
	push(ie);
	oe = pop(); //pop()은 stack[top] 즉 stack[0]을 출력하고 top = -1 이됨. 그니깐 ie를 출력한다는 뜻 .
	
	printf("학번 : %d", oe.student_no);
	printf("이름 : %s", oe.name);
	printf("주소 : %s", oe.address);
	
	return 0;
	 
}
*/
//프로그램 4.3 일반적인 배열 스택 프로그램
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top; 
} StackType;

//스택 초기화 함수
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
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	return 0;
}
 
  
