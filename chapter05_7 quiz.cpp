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
/*
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
*/
/*
//10. 피보나치 수열 
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
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
	printf("Queue(front = %d rear = %d) = ", q->front, q->rear);
	if(!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i+1) % (MAX_QUEUE_SIZE);
			printf(" %d |", q->data[i]);
			if(i == q->rear)
				break; 
		} while (i != q->front);
		printf("\n");
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

element peek(QueueType *q)
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

element fibonacci(QueueType *q)
{
	element a = dequeue(q);
	element b = dequeue(q);
	element c = b + a;
	enqueue(q, b);
	enqueue(q, c);
	
	return c;
}

int main(void)
{
	QueueType q;
	init_queue(&q);
	
	enqueue(&q, 0);
	enqueue(&q, 1);
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	printf("%d", fibonacci(&q));
	queue_print(&q);
	return 0;
}
*/
/*
//11.회문. 덱을 이용하여 주어진 문자열이 회문인지 아닌지를 결정하는 프로그램
//작성하시오
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 20
#define SIZE 100
typedef char element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear; 
} DequeType; 

//오류함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);	
} 
void init_dqueue(DequeType *q)
{
	q->front = q->rear = 0;
}

//초기화
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;	
}

//공백 상태 검출 함수
int is_empty(DequeType *q)
{
	return (q->front == q->rear);	
}

//포화 상태 검출 함수
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//원형큐 출력 함수
void deque_print(DequeType *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if(!is_empty(q))
	{
		int i = q->front;
		do{
			i = (i + 1)% (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if(i == q -> rear)
			{
				break;
			}
		} while (i != q->front);
		printf("\n");
	}	
} 

//삽입함수
void add_rear(DequeType *q, element item)
{
	if(is_full(q))
	{
		error("큐가 포화상태입니다.");
		
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;   	
} 

//삭제 함수 
element delete_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];	
}

//삭제 함수
element get_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];		
	
}  

void add_front(DequeType *q, element val)
{
	if(is_full(q))
	{
		error("큐가 포화상태입니다.");
	}
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;  
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev]; 
}

element get_rear(DequeType * q )
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	return q->data[q->rear]; 
}

int main(void)
{
	DequeType q;
	init_deque(&q);
	char p[SIZE];
	
	printf("문자열을 입력하세요 : ");
	gets(p);
	strlwr(p);
	int check = 1;
	int n = strlen(p);
	for(int i = 0; i < n; i++)
	{
		char ch = p[i];
		if(ch == ' ' || ch == '\'' || ch== ',' )
		{
			continue;
		}
		else
		{
			add_rear(&q, ch);
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
			if(p[i] == delete_rear(&q)) // 이렇게 하야 pop을 한 번만 해서 queue 공백 안생김 
			{
				check = check * 1 ;
			}
			else
			{
				check = check * 0;
			}
		}
	}
//	for(int i = 0; i < n; i++)
//	{
//		if(p[i] == ' ' || p[i] == '\'' || p[i] == ',' )
//		{
//			continue;
//		}
//		else if(p[i] == delete_rear(&q))
//		{
//			check = check * 1;
//		}
//		else if(p[i] != delete_rear(&q)) // 이렇게 해버리면 계속 pop이 생김
	
	if(check == 1)
	{
		printf("회문입니다");
	}
	else
	{
		printf("회문이 아닙니다");
	}
	return 0;	
} 
*/
//12.태스크 스캐쥴링 알고리즘 A-steal 알고리즘
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef char element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear; 
} DequeType; 

//오류함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);	
} 
void init_dqueue(DequeType *q)
{
	q->front = q->rear = 0;
}

//초기화
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;	
}

//공백 상태 검출 함수
int is_empty(DequeType *q)
{
	return (q->front == q->rear);	
}

//포화 상태 검출 함수
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//원형큐 출력 함수
void deque_print(DequeType *q)
{
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if(!is_empty(q))
	{
		int i = q->front;
		do{
			i = (i + 1)% (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if(i == q -> rear)
			{
				break;
			}
		} while (i != q->front);
		printf("\n");
	}	
} 

//삽입함수
void add_rear(DequeType *q, element item)
{
	if(is_full(q))
	{
		error("큐가 포화상태입니다.");
		
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;   	
} 

//삭제 함수 
element delete_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];	
}

//삭제 함수
element get_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];		
	
}  

void add_front(DequeType *q, element val)
{
	if(is_full(q))
	{
		error("큐가 포화상태입니다.");
	}
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;  
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev]; 
}

element get_rear(DequeType * q )
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	return q->data[q->rear]; 
}
int main(void)
{
	DequeType worker1;
	DequeType worker2;
	DequeType worker3;
	
	init_deque(&worker1);
	init_deque(&worker2);
	init_deque(&worker3);
	
	srand(time(NULL));
	for(int i = 0; i < 100; i++)
	{
		printf("%d회기\n",i+1);
		if( rand() % 4 == 0) // 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 - 19개 
		{
			add_rear(&worker1, rand() % 120);
		}
		else if(rand() % 5 == 0 && rand() % 4 != 0) //12 24 36 48 72 84 96  7개 
		{
			add_rear(&worker2, rand() % 120);
		}
		else if(rand() % 7 == 0 && rand() % 4 != 0 && rand() % 5 != 0) //7 14 21 28 42 49 56 63 77 91 98 11개 
		{
			add_rear(&worker3, rand() % 120);
		}
		printf("작업 투입\n");
		printf("worker1:");
		deque_print(&worker1); 
		printf("\n");
		printf("worker2:");
		deque_print(&worker2);
		printf("\n");
		printf("worker3:");
		deque_print(&worker3);
		printf("\n");
		
		if( rand () % 10 == 0 ) //100개 중 10의 배수는 10개이다. = 10% 
		{
			delete_front(&worker1);
		}
		else if( rand() % 12 == 0 && rand() % 10 != 0) //24 48 72 96
		{
			delete_front(&worker2);
		}
		else if(rand() % 14 == 0 && rand() % 10 != 0 && rand() % 12 != 0  ) //14 28  56 60 74 88
		{
			delete_front(&worker3);
		}
		printf("작업 수행\n"); 
		printf("worker1:");
		deque_print(&worker1);
		printf("\n");
		printf("worker2:");
		deque_print(&worker2);
		printf("\n");
		printf("worker3:");
		deque_print(&worker3);
		printf("\n");
		if(is_empty(&worker2))
		{
			if(!is_empty(&worker1))
			{
				printf(">>>>작업이 이전됩니다. work1 -> work2\n");
				element work = delete_rear(&worker1);
				add_rear(&worker2, work);
			}
		}
		
		if(is_empty(&worker3)&&!is_empty(&worker2))
		{
			if(!is_empty(&worker1))
			{
				printf(">>>>작업이 이전됩니다. work1 -> work3\n");
				element work = delete_rear(&worker1);
				add_rear(&worker3, work);
			}
		}
		
	}
	
	
	return 0;
}
  
 
 
