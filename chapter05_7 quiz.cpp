/*
1.���� A, B, C, D, E�� ť�� �־��ٰ� �ٽ� ������ ����ϸ� ��� �Ǵ°�?
�� : (a) A, B, C, D, E

2. ����ť���� front�� 3�̰� rear�� 5��� �ϸ� ���� ����ť�� ����� ��ҵ��� ������? 
����ť���� front 3�̰� rear�� 5��� �ϸ� ���� ����ť�� ����� ��Ҵ�?
(�� max_queue_size : 8)
�� : (b) 2

3. 10, 20, 30, 40, 50�� ť�� �־��ٰ� �����ϰ� 3���� �׸��� �����ߴ�. �� �ִ� �׸���?
��: 40, 50

4. ���� �� ����ť���� ������¿� �ش��ϴ� ������?
�� : (c) front == rear 

5. ũ�Ⱑ 10�̰� front: 3, rear : 5�� ����ť���� ���ο� �׸��� ���ԵǾ���
���, front�� rear�� ���ο� ����?
��: (2) front : 3 , rear : 6

6. ������ ���� ���������� (a)���� (c)������ ������ ���ʷ� �����Ѵٰ� ����.
������ �Ϸ�� ���� ť�� ���¸� �׷���. ���� front�� 0�̰� rear�� 2��� ����.
�� : (a) A �߰�-|  | B | C | A |  |
(b)D �߰� - |  | B | C | A | D |
(c)���� - |  |  | C | A | D |

7. ť�� �׸���� �����ϰ� �����ϴ� ������ �ð� ���⵵�� ��� �Ǵ°�?
���� 1 2 3 4 5 6 7 8 9 ... n
(c) O(n)
-> �ð� ���⵵�� ���� �� �𸣰ڴ�. 
*/
/*
//8. ����ť�� ť�� �����ϴ� ����� ������ ��ȯ�ϴ� ���� get_count�� �߰�
#include <stdio.h>
#include <string.h> 
# define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//����  ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return(q->front == q->rear);
} 

//��ȭ ���� ���� �Լ�
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
		error("ť�� ��ȭ�����Դϴ�.");
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
		error("ť�� ��������Դϴ�.");
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
		error("ť�� ��������Դϴ�.");
	}
	else
	{
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
	}
}

//�����ϴ� ����� ������ ��ȯ�ϴ� ���� get_count
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
		error("ť�� ��������Դϴ�.");
	}
	
} 
*/

//9. 2���� ������ ����Ͽ� ť�� ����. �Է��� ������ ����#1�� �ִ´�.
//��� ��û�� ������ ���� #2���� ��Ҹ� ������. 
//���� #2�� ������� ���� ����#1�� ��� ��Ҹ� ������ ���� #2�� �ִ´�.
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
		fprintf(stderr, "���� ��ȭ ����\n");
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
		fprintf(stderr, "���� ���� ����\n");
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
		fprintf(stderr,"���� ���� ����\n");
	}
	else
	{
		return s->data[s->top];
	}
}
//ť�� ������ �ֱ� 
void enqueue(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		exit(1);
	}
	else
	{
		push(s, item);
	}	
}
//���� 2�� ������ �־��ֱ�
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
		printf("������ �������  �ʽ��ϴ�.\n");
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
			printf("���ڸ� �Է��ϼ��� : ");
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
//10. �Ǻ���ġ ���� 
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
# define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//����  ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return(q->front == q->rear);
} 

//��ȭ ���� ���� �Լ�
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
		error("ť�� ��ȭ�����Դϴ�.");
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
		error("ť�� ��������Դϴ�.");
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
		error("ť�� ��������Դϴ�.");
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
//11.ȸ��. ���� �̿��Ͽ� �־��� ���ڿ��� ȸ������ �ƴ����� �����ϴ� ���α׷�
//�ۼ��Ͻÿ�
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

//�����Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);	
} 
void init_dqueue(DequeType *q)
{
	q->front = q->rear = 0;
}

//�ʱ�ȭ
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;	
}

//���� ���� ���� �Լ�
int is_empty(DequeType *q)
{
	return (q->front == q->rear);	
}

//��ȭ ���� ���� �Լ�
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//����ť ��� �Լ�
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

//�����Լ�
void add_rear(DequeType *q, element item)
{
	if(is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�.");
		
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;   	
} 

//���� �Լ� 
element delete_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];	
}

//���� �Լ�
element get_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];		
	
}  

void add_front(DequeType *q, element val)
{
	if(is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;  
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev]; 
}

element get_rear(DequeType * q )
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	return q->data[q->rear]; 
}

int main(void)
{
	DequeType q;
	init_deque(&q);
	char p[SIZE];
	
	printf("���ڿ��� �Է��ϼ��� : ");
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
			if(p[i] == delete_rear(&q)) // �̷��� �Ͼ� pop�� �� ���� �ؼ� queue ���� �Ȼ��� 
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
//		else if(p[i] != delete_rear(&q)) // �̷��� �ع����� ��� pop�� ����
	
	if(check == 1)
	{
		printf("ȸ���Դϴ�");
	}
	else
	{
		printf("ȸ���� �ƴմϴ�");
	}
	return 0;	
} 
*/
//12.�½�ũ ��ĳ�층 �˰��� A-steal �˰���
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

//�����Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);	
} 
void init_dqueue(DequeType *q)
{
	q->front = q->rear = 0;
}

//�ʱ�ȭ
void init_deque(DequeType *q)
{
	q->front = q->rear = 0;	
}

//���� ���� ���� �Լ�
int is_empty(DequeType *q)
{
	return (q->front == q->rear);	
}

//��ȭ ���� ���� �Լ�
int is_full(DequeType *q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//����ť ��� �Լ�
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

//�����Լ�
void add_rear(DequeType *q, element item)
{
	if(is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�.");
		
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;   	
} 

//���� �Լ� 
element delete_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];	
}

//���� �Լ�
element get_front(DequeType *q)
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];		
	
}  

void add_front(DequeType *q, element val)
{
	if(is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;  
}

element delete_rear(DequeType *q)
{
	int prev = q->rear;
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev]; 
}

element get_rear(DequeType * q )
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
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
		printf("%dȸ��\n",i+1);
		if( rand() % 4 == 0) // 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75 80 85 90 95 - 19�� 
		{
			add_rear(&worker1, rand() % 120);
		}
		else if(rand() % 5 == 0 && rand() % 4 != 0) //12 24 36 48 72 84 96  7�� 
		{
			add_rear(&worker2, rand() % 120);
		}
		else if(rand() % 7 == 0 && rand() % 4 != 0 && rand() % 5 != 0) //7 14 21 28 42 49 56 63 77 91 98 11�� 
		{
			add_rear(&worker3, rand() % 120);
		}
		printf("�۾� ����\n");
		printf("worker1:");
		deque_print(&worker1); 
		printf("\n");
		printf("worker2:");
		deque_print(&worker2);
		printf("\n");
		printf("worker3:");
		deque_print(&worker3);
		printf("\n");
		
		if( rand () % 10 == 0 ) //100�� �� 10�� ����� 10���̴�. = 10% 
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
		printf("�۾� ����\n"); 
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
				printf(">>>>�۾��� �����˴ϴ�. work1 -> work2\n");
				element work = delete_rear(&worker1);
				add_rear(&worker2, work);
			}
		}
		
		if(is_empty(&worker3)&&!is_empty(&worker2))
		{
			if(!is_empty(&worker1))
			{
				printf(">>>>�۾��� �����˴ϴ�. work1 -> work3\n");
				element work = delete_rear(&worker1);
				add_rear(&worker3, work);
			}
		}
		
	}
	
	
	return 0;
}
  
 
 
