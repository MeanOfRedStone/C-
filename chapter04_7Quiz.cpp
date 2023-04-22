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
/*
//14. 배열로 구성된 스택에 저장된 요소(elemet)의 수를  반환하는 size 연산을 구하라. 
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
*/
//15.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAZE_SIZE 6

#define MAX_STACK_SIZE 100
 

typedef struct {
	short r;
	short c;
} element;
//가능한 경로 보관하는 스택 
typedef struct {
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
//시작 위치 설정 element임 (r, c)로 구성 
element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
	
};

//위치 스택 삽입 함수
void push_loc(StackType *s, int r, int c)
{
	if(r < 0 || c < 0)
	{
	}
	if(maze[r][c] != '1' && maze[r][c] != '.')//벽이 아니거나, 왔던길이 아니면 
	{
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp); //스택에 가능한 경로 넣기 
	}
} 

//미로 화면에 출력
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for(int r= 0; r < MAZE_SIZE; r++)
	{
		for(int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
} 

int main(void)
{
	int r, c;
	StackType s;
	
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x')
	{
	r = here.r;
	c = here.c;

	maze[r][c] = '.';
	maze_print(maze);
	push_loc(&s, r - 1, c); //현재 위치 기준 위쪽
	push_loc(&s, r + 1, c);
	push_loc(&s, r, c - 1);
	push_loc(&s, r, c + 1);
		//다 넣고 갈 수 있는 경로로 이동 스택 가장 위쪾부터 
	if(is_empty(&s))
	{
		printf("실패\n");

	}
	else
	{
		here = pop(&s);	
	}
		
	}
	printf("성공\n");
	return 0;
}
/*
//16.회문결정 프로그램 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	char p[SIZE];
	int check = 1;
	printf("문자열을 입력하시오:");
	gets(p);
	strlwr(p);
	int n = strlen(p);
	for(int i = 0; i < n ; i++)
	{
		char ch;
		ch = p[i];
		
		if(ch == ' ' || ch == '\'' || ch == ',' )
		{
			continue;
		}
		else
		{
			push(&s, ch);
		}
	}

	for(int i = 0; i < n; i++)
	{

		if(p[i] == ' ' || p[i] == '\'' || p[i] == ',' )
		{
			continue;	
		}		
		else
		{
			if(p[i] == pop(&s))
			{
				check = check * 1;
			}
			else 
			{
				check = check * 0;
			}
		}
		
	}
	if(check == 1)
	{
		printf("회문입니다.");
	}
	else
	{
		printf("회문이 아닙니다.");
	}

	
	return 0;	
} 
*/
 

