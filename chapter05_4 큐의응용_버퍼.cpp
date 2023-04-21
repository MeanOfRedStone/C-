#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//원형큐 코드 시작
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct{ //큐 타입 
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//오류함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;	
}

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

//원형큐 출력 함수
void queue_print(QueueType *q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if(!is_empty(q))
	{
		int i = q->front;
		do{
			i = (i+1) % (MAX_QUEUE_SIZE);
			printf(" %d |", q->data[i]);
			if(i == q->rear)
				break; 
		} while (i != q->front);
		printf("\n");
	}	
}

//삽입함수
void enqueue(QueueType *q, element item)
{
	if(is_full(q))
	{
		error("큐가 포화상태입니다");
	}
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

//삭제함수
element dequeue(QueueType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; 
		return q->data[q->front];
	}
}

//반출 차례에 있는 함수 
element peek(QueueType *q)
{
	if(is_empty(q))
	{
		error("큐가 공백상태입니다");
	}
	{
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE]; 
	}
}
//원형 큐 코드 끝

int main(void)
{
	QueueType queue;
	element item;
	init_queue(&queue);
	
	/*
	rand() 함수는 = srand(1)과 같다.
	srand()안의 숫자의 변화에 따라 rand() 값 바뀜
	time 함수는 time(NULL)의 형태로 기준 시간과 현재 시간과의 차이를 나타냄
	따라서 srand() 값이 계속 변하게 된다.	
	*/
	srand(time(NULL)); //뭘까?
	
	for(int i = 0; i < 100; i++)
	{
		if( rand() % 5 == 0) // 100개 중에 5의 배수는 20개이다. = 20% 
		{
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);
		if( rand () % 10 == 0 ) //100개 중 10의 배수는 10개이다. = 10% 
		{
			int data = dequeue(&queue);
		}
		queue_print(&queue); 
	}
	
	return 0;
}
