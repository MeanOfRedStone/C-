//���α׷� 12.10 ��� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct{ // ť Ÿ�� 
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//���� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//ť �ʱ�ȭ 
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
} 

//��ȭ ���� ���� �Լ�
int is_full(QueueType *q)
{
	return ( (q->rear + 1) % MAX_QUEUE_SIZE == q->front);
} 

//���� �Լ�
void enqueue(QueueType *q, element item)
{
	if(is_full(q)){
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
} 

//���� �Լ�
element dequeue(QueueType *q)
{
	if(is_empty(q)){
		error("ť�� ��������Դϴ�.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front]; 
} 

#define BUCKETS 10
#define DIGITS 2
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	
	
	/*
	<�۾� ���>
	1. ��� �� ť �� �ʱ�ȭ 
	2. ���� ���� ���ڸ� 1�� �ڸ����� ����� queue�� �־��ش�.
	1) list[i] : ���޹��� ���� ��
	2) list[i] / factor % 10 : �ڸ������� ���� �з�  factor ���� 1, 10, ...���� �����Ѵ�.
	3) �� �ڸ������� ���� ���ڰ����� �ٽ� ����Ʈ�� �־��ش�.
	4) �� ������ �ڸ������� �ݺ� 
	*/
	
	// ť���� �ʱ�ȭ 
	//queue �ʱ�ȭ�� loop���� ���ִ� ���� : queue���� �迭 �� �ڸ����� ���ڸ��� ť�� ������ش�. 
	for(b = 0; b < BUCKETS; b++){
		init_queue(&queues[b]); 
	}
	
	for(d = 0; d < DIGITS; d++){
		//�����͵��� �ڸ����� ���� ť�� ���� (1���ڸ����� ���� �÷�����) 
		for(i = 0; i < n; i++){
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}
		
		//��Ŷ���� ������ list�� ��ģ��. 
		for(b = i = 0; b < BUCKETS; b++){
			
			//i�� b ������ ����: list ä���ִ� ���� ����ؼ� �Ͼ���ϰ� b�� loop �ȿ��� �ѹ��� ��� ������ϱ� ����. 
			while(!is_empty(&queues[b])){
				list[i++] = dequeue(&queues[b]);
			}
		}
		//�� ���� �ڸ����� ����. 
		factor *= 10;
	}
}

#define SIZE 10

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	//���� ���� �� ��� 
	for( int i = 0; i < SIZE; i++){
		list[i] = rand() % 100 ;
	}
	
	radix_sort(list, SIZE);
	for(int i = 0; i < SIZE; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}
/*
1. ��������� �Ʒ��� key�� ������ �� key�� �ڸ� ��ȭ�� �ܰ躰�� ������
1�ܰ�) 52 42 72 53 85 87 77 47

2�ܰ�) 42 47 52 53 72 77 85 87


2. 5õ�� �ֹε�Ϲ�ȣ�� Ű�� ����ؼ� ������ ��, ������İ� ������ �߿��� ��� ����� �� �����Ѱ�?

�ֹι�ȣ 13�ڸ�
- ������ ��� �ð����⵵ O (5000 * log2(5000)) =.. O(5000 * 12.xx)

- ������� �ð� ���⵵ O(10 *5000) * O(3 * 5000)

�ڸ����� 10�� �Ѿ�� ������ �������� �� �����ϴ�. 
*/

