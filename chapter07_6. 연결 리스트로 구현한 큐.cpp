/*
*연결된 큐 정의 

typedef int element;
typedef struct QueueNode{
	element data;
	struct QueueNode *link;
} QueueNode;

typedef struct{
	QueueNode *front, *rear;
} LinkedQueueType; 
*/

/*
*삽입 연산
(1) 동적 메모리 할당
(2) 데이터 저장
(3) 노드 연결 


//프로그램 7.10 연결된 큐 삽입 연산
void enqueue(LinkedQueueType *q, element data)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	tmep->data = data;
	temp->link = NULL;
	if(is_empty(q)){
		q->front = temp;
		r->rear = temp; 
	}
	else{
		q->rear->link = temp;
		q->rear = temp;
	}
}  
*/

/*
*삭제 연산
연결 리스트의 맨 처음에서 노드 꺼내오기
(1) 공백 검사
(2) front에서 노드 빼기 

//프로그램 7.11 연결된 큐 삭제 연산
element dequeue(LinkedQueueType *q)
{
	QueueNode *temp = q->front;
	element data;
	if(is_empty(q)){
		fprintf(stderr, "큐가 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if(q->front == NULL){
			q->rear = NULL; //큐의 노듸 1개일 경우 삭제 연산 후 rear 포인터 비워줘야함. 
		}
		free(temp);
		return data;
	}	
}   
*/
/*
*연결된 큐 프로그램 
*/   
//프로그램 7.12 연결된 큐 프로그램 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode *link;
} QueueNode;
typedef struct{
	QueueNode *front, *rear;
} LinkedQueueType; 

void init(LinkedQueueType * q)
{
	q->front = q->rear = NULL;	
}

int is_empty(LinkedQueueType *q)
{
	return (q->front == NULL);
}

int is_full(LinkedQueueType *q)
{
	return 0;
}

void enqueue(LinkedQueueType *q, element data)
{
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL; //마지막 링크는 NULL 
	if(is_empty(q)){
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear= temp;
	}
}

element dequeue(LinkedQueueType *q)
{
	QueueNode *temp = q->front;
	element data;
	if(is_empty(q)){
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else{
		data = temp->data;
		q->front = q->front->link;
		if(q->front == NULL){
			q->rear = NULL;
		}
		free(temp);
		return data;
	}
}

void print_queue(LinkedQueueType *q)
{
	QueueNode *p;
	for(p = q->front; p != NULL; p = p->link){
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main(void)
{
	LinkedQueueType queue;
	
	init(&queue);
	
	enqueue(&queue, 1);
	print_queue(&queue);
	enqueue(&queue, 2);
	print_queue(&queue);
	enqueue(&queue, 3);
	print_queue(&queue);
	
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	dequeue(&queue);
	print_queue(&queue);
	
	return 0;
	
}
