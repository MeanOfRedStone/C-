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

//10. �Ǻ���ġ ���� 





  
 
 
