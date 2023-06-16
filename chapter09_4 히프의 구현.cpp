/*
4. ������ ����

*������ ����

#define MAX_ELEMENT 200
typedef struct{
	int key;
} element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size; 
} HeapType;

//���� ������
HeapType heap;

//�������� ���� ��
HeapType *heap = create();

*/

/*
*���� ����
(1) ���� ������ ��ġ�� ��� ����.
(2)�θ���� ���Ͽ� �ڸ��� �̵� 


//�˰���9.1 ����Ʈ������ ���� �˰���
insert_max_heap(A, key);

1. heap_size <- heap_size + 1;
2. i <- heap_size;
3. A[i] <- key;
4. while i != 1 and A[i] > A[PARENT(i)] do
5.	A[i] <-> A[PARENT];
6.	i <- PARENT(i);

//���α׷� 9.1 ����Ʈ�������� ���� �Լ�
//���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
//�����Լ�
void insert_max_heap(HeapType * h, element itme)
{
	int i;
	i = ++(h->heap_size);
	
	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while((i != 1) && (item.key > h->heap[i/2].key)){
		h->heap[i] = h->heap[i/2]; // �ڽ� �ڸ��� �θ� ��尪�� ����
		i /= 2; 
	}
	h->heap[i] = item; //���ο� ��带 ���� 
} 
*/ 

/*
������ ���� ����
(�ִ� ������ ���)
�ִ밪�� ���� ��Ҹ� �����ϴ� ���̴�. -> ��Ʈ ��� ���� -> ��� ��ȯ 
(1) ��Ʈ ��� ����. �� �ڸ����� ������ ������ ��带 �����´�.

(2) �ڽ� ��� �� �� ū ���� ��ȯ�Ѵ�. 
 
//�˰��� 9.2 ����Ʈ�������� ���� �˰���
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

//����Ʈ�������� ���� �Լ�

//���� �Լ�
element delete_max_heap(HeapType * h)
{
	int parent, child;
	element item, temp;
	
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while(child <= h->heap_size){
		//���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã�´�.
		if( (child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key ){
			child ++;
		}
		if(temp.key >= h->heap[child].key){
			break;
		}
		//�� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child; //�� �� ������ �ڽ� ��� �� �ϳ� ���� 
		child *= 2; //���� �ڽĳ���� �ε����� �θ����� 2�� 
	}
	h->heap[parent] = temp;
	
	return item; //��Ʈ ��� ������(������ ����) 
} 

*/

//���α׷�9.3 ����Ʈ�� �׽�Ʈ ���α׷�
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

//�����Լ�
HeapType * create()
{
	return (HeapType *)malloc(sizeof(HeapType));
} 

//�ʱ�ȭ �Լ�
void init(HeapType * h)
{
	h->heap_size = 0;	
} 

//���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�. 
//���� �Լ�
void insert_max_heap(HeapType * h, element item)
{
	int i;
	i = ++(h->heap_size);
	
	//Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while( (i != 1) && (item.key > h->heap[i / 2].key) ){
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	} 
	h->heap[i] = item; //���ο� ��带 ���� 
}

//���� �Լ�
element delete_max_heap(HeapType * h)
{
	int parent, child;
	element item, temp;
	
	item = h->heap[1]; // ���� ��� = ��Ʈ��� 
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	
	while(child <= h->heap_size){
		//���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã����.
		if( (child < h->heap_size) && (h->heap[child].key < h->heap[child+1].key) ) {
			child++;
		}
		if(temp.key >= h->heap[child].key){
			break; //������ ��尡 �� Ŀ�� ��� ������ �������� 
		}
		//������ ��尡 ���� ��ġ�� �ڽĳ�庸�� ���� ��� �� ���� ��������. 
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item; 
} 

int main(void)
{
//	����ü�� �ٷ� ���� �ִ� ��� 
	element e1 = {10}, e2 = {5}, e3 = {30};
	element e4, e5, e6;
	HeapType * heap;
	
	heap = create(); //���� ���� 
	init(heap); //�ʱ�ȭ
	
	//����
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	
	//����
	e4 = delete_max_heap(heap);
	printf("< %d >\n", e4.key); 
	
	e5 = delete_max_heap(heap);
	printf("< %d >\n", e5.key);
	
	
	e6 = delete_max_heap(heap);
	printf("< %d >\n", e6.key);
	
	return 0;
}

/*
*������ ���⵵ �м�
���� / ���� -> O(log2n)

Quiz.
1. �ִ� ������ ������ ���� �迭�� ����Ǿ� �ִ�. ���⿡ 11�� �����Ͽ��� ��쿡, �籸���� ������ �׷���. 
1  2  3  4  5 6 7 8 9

12 11 8 10  6 2 5 3 4

2. ���� �ִ� �������� �켱 ������ ���� ���� ��Ҹ� �����Ͽ��� ��쿡, �籸���� ������ �׷���.
4 11 8 10 6 2 5 3 4 -> 11 4 8 10 6 2 5 3 4 -> 11 10 8 4 6 2 5 3 4 
*/ 
 

