/*
4. 히프의 구현

*히프의 정의

#define MAX_ELEMENT 200
typedef struct{
	int key;
} element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size; 
} HeapType;

//히프 생성시
HeapType heap;

//동적으로 생성 시
HeapType *heap = create();

*/

/*
*삽입 연산
(1) 가장 마지막 위치에 노드 삽입.
(2)부모노드와 비교하여 자리를 이동 


//알고리즘9.1 히프트리에서 삽입 알고리즘
insert_max_heap(A, key);

1. heap_size <- heap_size + 1;
2. i <- heap_size;
3. A[i] <- key;
4. while i != 1 and A[i] > A[PARENT(i)] do
5.	A[i] <-> A[PARENT];
6.	i <- PARENT(i);

//프로그램 9.1 히프트리에서의 삽입 함수
//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
//삽입함수
void insert_max_heap(HeapType * h, element itme)
{
	int i;
	i = ++(h->heap_size);
	
	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while((i != 1) && (item.key > h->heap[i/2].key)){
		h->heap[i] = h->heap[i/2]; // 자식 자리에 부모 노드값을 삽입
		i /= 2; 
	}
	h->heap[i] = item; //새로운 노드를 삽입 
} 
*/ 

/*
히프의 삭제 연산
(최대 히프의 경우)
최대값을 가진 요소를 삭제하는 것이다. -> 루트 노드 삭제 -> 노드 교환 
(1) 루트 노드 삭제. 빈 자리에는 히프의 마지막 노드를 가져온다.

(2) 자식 노드 중 더 큰 값과 교환한다. 
 
//알고리즘 9.2 히프트리에서의 삭제 알고리즘
delete_mx_heap(A):
	
item <- A[1];
A[1] <- A[heap_size];
heap_size <- heap_size - 1;
i <- 2;
while i < heap_size do
	if i < heap_size and A[i+1] > A[i]
		then largest <- i+1;
		else largest <- i;
	if A[PARENT(largest)] > A[largest]
		then break;
	A[PARENT(largest)] <-> A[largest];
	i <- CHILD(largest);
	
return item;

//히프트리에서의 삭제 함수

//삭제 함수
element delete_max_heap(HeapType * h)
{
	int parent, child;
	element item, temp;
	
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while(child <= h->heap_size){
		//현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if( (child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key ){
			child ++;
		}
		if(temp.key >= h->heap[child].key){
			break;
		}
		//한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child; //왼 쪽 오른쪽 자식 노드 중 하나 선택 
		child *= 2; //왼쪽 자식노드의 인덱스는 부모노드의 2배 
	}
	h->heap[parent] = temp;
	
	return item; //루트 노드 돌려줌(히프의 목적) 
} 

*/

//프로그램9.3 히프트리 테스트 프로그램
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct{
	int key;
} element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

//생성함수
HeapType * create()
{
	return (HeapType *)malloc(sizeof(HeapType));
} 

//초기화 함수
void init(HeapType * h)
{
	h->heap_size = 0;	
} 

//현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다. 
//삽입 함수
void insert_max_heap(HeapType * h, element item)
{
	int i;
	i = ++(h->heap_size);
	
	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while( (i != 1) && (item.key > h->heap[i / 2].key) ){
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	} 
	h->heap[i] = item; //새로운 노드를 삽입 
}

//삭제 함수
element delete_max_heap(HeapType * h)
{
	int parent, child;
	element item, temp;
	
	item = h->heap[1]; // 빠질 노드 = 루트노드 
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	
	while(child <= h->heap_size){
		//현재 노드의 자식노드 중 더 큰 자식노드를 찾느다.
		if( (child < h->heap_size) && (h->heap[child].key < h->heap[child+1].key) ) {
			child++;
		}
		if(temp.key >= h->heap[child].key){
			break; //마지막 노드가 더 커질 경우 루프를 빠져나감 
		}
		//마지막 노드가 현재 위치의 자식노드보다 작을 경우 한 레벨 내려간다. 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item; 
} 

int main(void)
{
//	구조체에 바로 값을 넣는 방법 
	element e1 = {10}, e2 = {5}, e3 = {30};
	element e4, e5, e6;
	HeapType * heap;
	
	heap = create(); //히프 생성 
	init(heap); //초기화
	
	//삽입
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	
	//삭제
	e4 = delete_max_heap(heap);
	printf("< %d >\n", e4.key); 
	
	e5 = delete_max_heap(heap);
	printf("< %d >\n", e5.key);
	
	
	e6 = delete_max_heap(heap);
	printf("< %d >\n", e6.key);
	
	return 0;
}

/*
*히프의 복잡도 분석
삽입 / 삭제 -> O(log2n)

Quiz.
1. 최대 히프가 다음과 같이 배열에 저장되어 있다. 여기에 11을 삽입하였을 경우에, 재구성된 히프를 그려라. 
1  2  3  4  5 6 7 8 9

12 11 8 10  6 2 5 3 4

2. 위의 최대 히프에서 우선 순위가 가장 높은 요소를 삭제하였을 경우에, 재구성된 히프를 그려라.
4 11 8 10 6 2 5 3 4 -> 11 4 8 10 6 2 5 3 4 -> 11 10 8 4 6 2 5 3 4 
*/ 
 

