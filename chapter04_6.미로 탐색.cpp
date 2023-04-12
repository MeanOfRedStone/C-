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

