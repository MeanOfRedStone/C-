/*
1.문자 A, B, C, D, E를 큐에 넣었다가 다시 꺼내어 출력하면 어떻게 되는가?
답 : (a) A, B, C, D, E

2. 원형큐에서 front가 3이고 rear가 5라고 하면 현재 원형큐에 저장된 요소들의 개수는? 
원형큐에서 front 3이고 rear가 5라고 하면 현재 원형큐에 저장된 요소는?
(단 max_queue_size : 8)
답 : (b) 2

3. 10, 20, 30, 40, 50을 큐에 넣었다고 가정하고 3개의 항목을 삭제했다. 남 있는 항목은?
답: 40, 50

4. 다음 중 원형큐에서 공백상태에 해당하는 조건은?
답 : (c) front == rear 

5. 크기가 10이고 front: 3, rear : 5인 원형큐에서 새로운 항목이 삽입되었을
경우, front와 rear의 새로운 값은?
답: (2) front : 3 , rear : 6

6. 다음과 같은 원혀유에서 (a)에서 (c)까지의 연산을 차례로 수행한다고 하자.
수행이 완료된 후의 큐의 상태를 그려라. 현재 front는 0이고 rear는 2라고 하자.
답 : (a) A 추가-|  | B | C | A |  |
(b)D 추가 - |  | B | C | A | D |
(c)삭제 - |  |  | C | A | D |

7. 큐에 항목들을 삽입하고 삭제하는 연산은 시간 복잡도가 어떻게 되는가?
삽입 1 2 3 4 5 6 7 8 9 ... n
(c) O(n)
-> 시간 복잡도는 아직 잘 모르겠다. 
*/
/*
//8. 원형큐에 큐에 존재하는 요소의 개수를 반환하는 연산 get_count를 추가
#include <stdio.h>
#include <string.h> 
# define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//공백  상태 검출 함수
int is_empty(QueueType *q)
{
	return(q->front == q->rear);
} 

//포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);	
}

void queue_print(QueueType *q)
{
	printf("Queue(front = %d rear = %d) = ", q->front, q->rear)
	if(!is_empty(q))
	{
		int i = q->front
		do
		{
			i = (i+1) % (MAX_QUEUE_SIZE);
			printf(" %d |", q->data[i]);
			if(i == q->rear)
				break; 
		} while (i != q->front);
		printf("\n")
	}
}
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

void enqueue(QueueType *q, element item)
{
	if(is_full(q))
	{
		error("큐가 포화상태입니다.");
	}
	else 
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

element peek(QUeueType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	else
	{
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	}
}

//존재하는 요소의 개수를 반환하는 연산 get_count
int get_count(QueueType *q)
{
	if(q->rear > q->front)
	{
		return q->rear - q->front;
	}
	else if(q->rear < q->front)
	{
		return MAX_QUEUE_SIZE -q->front + q->rear;
	}
	else
	{
		error("큐가 공백상태입니다.");
	}
	
} 
*/

//9. 2개의 스택을 사용하여 큐를 구현. 입력이 들어오면 스택#1에 넣는다.
//출력 요청이 들어오면 스택 #2에서 요소를 꺼낸다. 
//스택 #2가 비어있을 때는 스택#1의 모든 요소를 꺼내서 스택 #2에 넣는다.
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	int top;
	element data[MAX_STACK_SIZE];
} StackType; 

void init_stack(StackType *s)
{
	s->top = -1;
}

int is_empty(StackType *s)
{
	return s->top == -1;
}

int is_full(StackType *s)
{
	return s->top == MAX_STACK_SIZE - 1;
}

void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
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
	if(is_empty(s))
	{
		fprintf(stderr,"스택 공백 에러\n");
	}
	else
	{
		return s->data[s->top];
	}
}
//큐에 데이터 넣기 
void enqueue(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else
	{
		push(s, item);
	}	
}
//스택 2에 데이터 넣어주기
void change(StackType *s1, StackType *s2)
{
	if(is_empty(s2))
	{
		int n = (s1->top + 1);
		for(int i = 0; i < n; i++)
		{
			element item = pop(s1);
			push(s2, item);
		}
	}
	else
	{
		printf("스택이 비어있지  않습니다.\n");
		exit(1);
	}
		
} 

element dequeue(StackType *s)
{
	return pop(s); 
}



int main(void)
{
	StackType s1;
	StackType s2;
	init_stack(&s1);
	init_stack(&s2);
	
	while(true)
	{
		if(!is_full(&s1));
		{
			int item; 
			printf("숫자를 입력하세요 : ");
			scanf("%d", &item);
			if(item == NULL)
			{
				break;
			}
			else
			{
				enqueue(&s1, item);
			}
		}
	}
	printf("%d", pop)
	return 0;
}

//10. 피보나치 수열 





  
 
 
