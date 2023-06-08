/*
알고리즘 8.4 트리 레벨 순회 알고리즘


level_order(root) :

1. initialize queue;
2. if(root == null) then return;
3. enqueue(queue, root);
4. while is_empty(queue) != True do
	x <- dequeue(queue);
	print x -> data;
	if(x->left != NULL) then
					enqueue(queue, x->left);
	if(x->right != NULL) then
					enqueue(queue, x->right)  
					
*/

//프로그램 8.5 레벨 순회 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;


//==========원형큐 코드 시작============ 
#define MAX_QUEUE_SIZE 100
typedef TreeNode *element; //구조체 안에 데이터로 넣어주기때문에 다시 선언 
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


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

//레벨 순회 함수 
void levle_order(TreeNode *ptr)
{
	QueueType q;
	
	init_queue(&q);
	
	if(ptr == NULL){
		return;
	}
	enqueue(&q, ptr);
	while(!is_empty(&q)){
		ptr = dequeue(&q);
		printf("[%d]", ptr->data);
		if(ptr->left){
			enqueue(&q, ptr->left);
		}
		if(ptr->right){
			enqueue(&q, ptr->right);
		}
	}
}

//			15
// 	4				20
//1	  			16		25
//malloc 안하고 전역변수로 선언: 간편하지만 실행중 변경 불가 -> 잘 사용 x(앞에도 비슷한 사례 있음 참고)

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL,NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(void)
{
	printf("레벨 순회 = ");
	levle_order(root);
	printf("\n");
	
	return 0; 
}

/*
어떤 순회를 선택하여야 할까?
자식 노드 먼저 처리할 경우  -> 후위순회(예: 하위 디렉토리 용량 계싼)
부모 노드 먼저 처리할 경우 -> 전위 순회 
*/ 
