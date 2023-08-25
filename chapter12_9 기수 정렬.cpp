//프로그램 12.10 기수 정렬 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct{ // 큐 타입 
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//큐 초기화 
void init_queue(QueueType *q)
{
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
} 

//포화 상태 검출 함수
int is_full(QueueType *q)
{
	return ( (q->rear + 1) % MAX_QUEUE_SIZE == q->front);
} 

//삽입 함수
void enqueue(QueueType *q, element item)
{
	if(is_full(q)){
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
} 

//삭제 함수
element dequeue(QueueType *q)
{
	if(is_empty(q)){
		error("큐가 공백상태입니다.");
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
	<작업 요약>
	1. 기수 별 큐 값 초기화 
	2. 전달 받은 숫자를 1의 자리부터 나누어서 queue에 넣어준다.
	1) list[i] : 전달받은 숫자 값
	2) list[i] / factor % 10 : 자리수별로 숫자 분류  factor 값은 1, 10, ...으로 증가한다.
	3) 각 자리수에서 작은 숫자값부터 다시 리스트에 넣어준다.
	4) 위 과정을 자리수별로 반복 
	*/
	
	// 큐들의 초기화 
	//queue 초기화를 loop에서 해주는 이유 : queue들의 배열 즉 자리수의 숫자마다 큐를 만들어준다. 
	for(b = 0; b < BUCKETS; b++){
		init_queue(&queues[b]); 
	}
	
	for(d = 0; d < DIGITS; d++){
		//데이터들을 자리수에 따라 큐에 삽입 (1의자리부터 점점 올려간다) 
		for(i = 0; i < n; i++){
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}
		
		//버킷에서 꺼내어 list로 합친다. 
		for(b = i = 0; b < BUCKETS; b++){
			
			//i와 b 구분한 이유: list 채워주는 것은 계속해서 일어나야하고 b는 loop 안에서 한번에 모두 빼줘야하기 때문. 
			while(!is_empty(&queues[b])){
				list[i++] = dequeue(&queues[b]);
			}
		}
		//그 다음 자리수로 간다. 
		factor *= 10;
	}
}

#define SIZE 10

int main(void)
{
	int list[SIZE];
	srand(time(NULL));
	//난수 생성 및 출력 
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
1. 기수정렬이 아래의 key를 정렬할 때 key의 자리 변화를 단계별로 보여라
1단계) 52 42 72 53 85 87 77 47

2단계) 42 47 52 53 72 77 85 87


2. 5천만 주민등록번호를 키로 사용해서 정렬할 때, 기수정렬과 퀵정렬 중에서 어느 방법이 더 유리한가?

주민번호 13자리
- 퀵정렬 평균 시간복잡도 O (5000 * log2(5000)) =.. O(5000 * 12.xx)

- 기수정렬 시간 복잡도 O(10 *5000) * O(3 * 5000)

자리수가 10을 넘어가기 때문에 퀵정렬이 더 유리하다. 
*/

