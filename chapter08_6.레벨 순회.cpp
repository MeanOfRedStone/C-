/*
�˰��� 8.4 Ʈ�� ���� ��ȸ �˰���


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

//���α׷� 8.5 ���� ��ȸ ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;


//==========����ť �ڵ� ����============ 
#define MAX_QUEUE_SIZE 100
typedef TreeNode *element; //����ü �ȿ� �����ͷ� �־��ֱ⶧���� �ٽ� ���� 
typedef struct{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


//�����Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;	
}

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



//�����Լ�
void enqueue(QueueType *q, element item)
{
	if(is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�");
	}
	else
	{
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

//�����Լ�
element dequeue(QueueType *q)
{
	if(is_empty(q))
	{
		error("ť�� ��������Դϴ�");
	}
	else
	{
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; 
		return q->data[q->front];
	}
}

//���� ��ȸ �Լ� 
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
//malloc ���ϰ� ���������� ����: ���������� ������ ���� �Ұ� -> �� ��� x(�տ��� ����� ��� ���� ����)

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL,NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(void)
{
	printf("���� ��ȸ = ");
	levle_order(root);
	printf("\n");
	
	return 0; 
}

/*
� ��ȸ�� �����Ͽ��� �ұ�?
�ڽ� ��� ���� ó���� ���  -> ������ȸ(��: ���� ���丮 �뷮 ���)
�θ� ��� ���� ó���� ��� -> ���� ��ȸ 
*/ 
