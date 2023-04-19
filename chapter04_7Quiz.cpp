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
/*
//11.수식에 있는 괄호의 번호를 출력하는 프로그램을 작성하라.
//	왼쪽 괄호가 나올 때마다 괄호 번호는 하나씩 증가한다.
//	오른쪽 괄호가 나오면 매칭되는 왼쪽 괄호 버호를 출력한다.
//그냥 (를 넣는게 아니라 괄호의 cnt를 스택에 넣는다. (응용) 
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
			cnt += 1;
			push(&s, cnt);
			printf("%d ", cnt);
			break;
		}
		case ')' :
		{
			printf("%d ", pop(&s));
			break;
		}
		}
	}

	return 0;
} 
*/
/*
//12.문자열 압축 프로그램. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int main() {

    char str[20] = "";
    int count = 0;
    StackType s;
    init_stack(&s);
    printf("enter a string : ");
    scanf("%s", str);
    for(int i=0;i<20;i++) {
        char chr = tolower(str[i]);
        if(is_empty(&s) || chr == peek(&s))  {
            count++;
            push(&s, chr);
        }
        else if(chr != peek(&s)) {
            printf("%d%c", count, peek(&s));
            count = 0;
            while(!is_empty(&s))
                pop(&s);
            i--;
        } 
    }
    printf("\n");
    return 0;
}


int main(void)
{	
	StackType a;
	StackType b;
	init_stack(&a);
	init_stack(&b);
	char ch, open_ch;
	
	printf("문자열을 입력하시오  : ");
	char p[1001]; //여러개의 문자열 널 경우 char는 포인터 사용 
	gets(p);
	
	int n = strlen(p);
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		switch(ch)
		{
		
		case 'a': case 'A':
		{
			push(&a, 'a');
			break;
		}
		case 'b': case 'B':
		{
			push(&b, 'b');
			break;
		}
		
		}
	}
	printf("%d%c%d%c",a.top+1, peek(&a), b.top+1, peek(&b));
	
	
	return 0;	
} */
/*
//13. 주어진 정수에서 반복되는 숫자를 제거하는 프로그램을 작성해보자.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

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
	StackType l;
	init_stack(&s);
	init_stack(&l);
	char ch;
	
	char p[SIZE];
	printf("정수를 입력하시오: ");
	gets(p);
	int n = strlen(p);
	
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		if(is_empty(&s))
		{
			push(&s, ch);
		}
		else
		{
			if(ch != peek(&s))
			{
				push(&s, ch);
			}
		}
	}
	
	while(!is_empty(&s))
	{
		char item = pop(&s);
		push(&l, item);
	}
	printf("출력: ");
	while(!is_empty(&l))
	{
		printf("%c", pop(&l));	
	}	
	
	return 0;
	
}
*/
//14.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

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
	init_stack(&s);
	char ch;
	char p[SIZE];
	printf("입력: ");
	gets(p);
	
	int n = strlen(p);
	
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		push(&s,ch);
	}
	
	printf("요소의 수 : %d", s.top + 1);
	
	return 0; 
}

