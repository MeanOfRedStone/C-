/*
5. 히프 정렬

*히프 정렬의 구현 
*/
//프로그램 9.4 히프 정렬 프로그램
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

//우선순위 큐인 히프를 이용한 정렬
void heap_sort(element a[], int n)
{
	int i;
	HeapType * h;
	
	h = create();
	
	init(h);
	for(i = 0; i < n; i++){
		insert_max_heap(h, a[i]);
	}
	for(i = (n-1); i >= 0; i--){
		a[i] = delete_max_heap(h);
	}
	free(h);
} 
//quiz 1. 위의 히프 정렬 코드를 최소 히프를 사용하도록 수정하여 보자. 
void insert_min_heap(HeapType * h, element item)
{
	int i;
	i = ++(h->heap_size);
	
	//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while( (i != 1) && (item.key < h->heap[i / 2].key) ){
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	} 
	h->heap[i] = item; //새로운 노드를 삽입 
}

//삭제 함수
element delete_min_heap(HeapType * h)
{
	int parent, child;
	element item, temp;
	
	item = h->heap[1]; // 빠질 노드 = 루트노드 
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	
	while(child <= h->heap_size){
		//현재 노드의 자식노드 중 더 큰 자식노드를 찾느다.
		if( (child < h->heap_size) && (h->heap[child].key > h->heap[child+1].key) ) {
			child++;
		}
		if(temp.key <= h->heap[child].key){
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

//우선순위 큐인 히프를 이용한 정렬
void heap_min_sort(element a[], int n)
{
	int i;
	HeapType * h;
	
	h = create();
	
	init(h);
	for(i = 0; i < n; i++){
		insert_min_heap(h, a[i]);
	}
	for(i = (n-1); i >= 0; i--){
		a[i] = delete_min_heap(h);
	}
	free(h);
} 
#define SIZE 8
int main(void)
{
	element list[SIZE] = {23, 56, 11, 9, 56, 99, 27, 34};
	heap_min_sort(list,SIZE);
	for(int i = 0; i < SIZE; i++){
		printf("%d ", list[i].key);
	}
	printf("\n");
	
	return 0;
}

/*
히프 정렬의 복잡도

히프트리 전체 높이 = log2n(완전이진트리)
하나의 요소 넣는데 log2n -> O(log2n) -> 요소의 개수 n개 O(nlog2n) = O(n^2)
*/ 
