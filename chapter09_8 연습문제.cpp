/*
1. 히프트리에서 노드가 삭제되는 위치는 어디인가?
정답: (1) 루트
-> 히프의 목적은 우선순위에 따라 노드를 빼는 것이다.

2. 히프를 배열로 표현할 수 있는 이유는 무엇인가?
정답 : (1) 완전 이진 트리이기 때문이다.
->완전 이진 트리이기 때문에 인덱스만 알아도 된다.

3. 히프 연산 중에서 하나의 노드가 삽입되거나 삭제되는 시간은 무엇이 비례하는가?
정답 :(1)X (2) 트리의 높이이다. 
->최대 트리의 높이만큼 이동해야 하므로 트리의 높이인 log2n 만큼 연산 시간 필요.

4. 다음 중 히프 정렬이 특히 유용하게 사용될 수 있는 경우는?
정답: (1) 데이터 100개 중에서 오름차순으로 20개만 뽑고자 할 때이다.
->히프 정렬이 유용할 때는 우선순위 데이터를 순서대로 몇개만 뽑을 때이다.(암기하자)

5. 최소 히프에서 가장 작은 데이터가 있는 노드는?
정답: (2) 첫 번째 노드이다.
->최소 히프는 데이터가 가장 작은 순서대로 정렬하기 때문에 첫 번째 노드가 가장 작다.

6. 최소 히프에서 2번째로 작은 데이터가 있는 노드는?
정답 :알 수 없다. 
최소 히프는 작은 순서대로 정렬하는 스택이며 부모노드와 자식노드를 비교하여
더 큰 노드를 자식노드로 삼는다. 따라서 가장 작은 루트 노드보다 큰 값이 그 자식노드에 삽입된다. 
삽입 순서에 따라 위치가 달라질 수 있기 때문에 노드의 위치는 알 수 없다. 

7. 10개의 데이터를 저장하고 있는 히프트리의 높이는?
정답 : 트리의 높이는 log210 -> 3이다. 

8. 최소 히프를 구현한 배열의 내용이 다음과 같을 대 해당하는 히프트리를 그려라.
(1) 이 힙에서 가제 연산을 한 번 수행한 후의 배열의 내용을 적어라 
정답:  9 | 6 | 18 | 14 | 15 | 7 | 3 |
(2) 이 힙에서 데이터 을 삽입한 후의 배열의 내용을 적어라 
정답 : 2 | 9 | 18 | 6 | 15 | 7 | 3 | 14 | 7 

9. 다음의 최소 히프트리에서 답하라.
idx 1 - 2 - 3 -  4 -  5 -  6 - 7
	3 | 6 | 7 | 12 | 13 | 15 | 20
	
(1) 2를 삽입하였을 경우, 히프트리를 재구성하는 과정을 보여라.
2 | 3 | 7 | 6 | 13 | 15 | 20 | 12

(2) 삭제연산이 한번 이루어진 다음에 히프를 재구성하는 과정을 보여라 
-1 : 20 | 6 | 7 | 12 | 13 | 15 | 20
-2 : 6 | 20 | 7 | 12 | 13 | 15 |
-3 6 | 12 | 7 | 20 | 13 | 15

10. 다음의 파일에 대하여 다음 물음에 답하시오.
10, 40, 30, 5 , 12, 6, 15, 9, 60
(1) 위의 파일을 순차적으로 읽어서 최대 히프트리를 구성하라. 
공백 트리에서 최대 히프트리가 만들어지는 과정을 보여라.
(2) 구성된 최대 히프트리가 저장된 배열의 내용을 표시하라.  
-1 10 |
-2 40 | 10
-3 40 | 10 | 30
-4 40 | 10 | 30 | 5 |
-5 40 | 12 | 30 | 5 | 10 |
-6 40 | 12 | 30 | 5 | 10 | 6
-7 40 | 12 | 30 | 5 | 10 | 6 | 15
-8 40 | 12 | 30 | 9 | 10 | 6 | 15 | 5
-9 60 | 40 | 30 | 12 | 10 | 6 | 15 | 5 | 9
(3) 구성된 최대 히프트리에서 최댓값을 제거한 다음 재정비하는 과정을 설명하라.
-1 최대트리에서 최댓값은  루트 노드에 있다. 따라서 루트노드를 제거한다.
-2 가장 마지막 노드를 루트노드로 가져온 뒤 자식노드와 계속 비교하며 단말노드 또는 크기가 더 작은 노드가 나오지 않을 때까지 계속해서 바꾼다.
*/
//11. 자신의 할일에 우선순위를 매겨서 힙에 저장했다가 우선순위로 꺼내서 출력하는 프로그램을 작성하여 보자.
 
/*
12. 아래의 이진 트리는 최소 히프트리인가? 그 이유는?
최소 히프트리가 아니다.
왜냐하면 5의 값을 가진 노드가 그 부모노드보다 값이 작기 때문이다.
최소 히프트리는 완전 이진트리를 만족하고 부모노드는 자식노드보다 값이 작아야한다.
2번째 조건을 위반하기 때문에 최소 히프트리가 아니다.
*/ 

/*
13. 히프트리가 비어있는 상태에서 다음의 연산들을 차례대로 수행한 후의 최소 히프트리의 모습을 그려라.

insert(20), insert(12), insert(3), insert(2), delete(), insert(5), insert(16), delete(), insert(1), is_empty()

(1)	insert(20) 

20

(2) insert(12)

12
	20
	
(3)	insert(3)
	12
3	
	20
	
(4) insert(2)

	12
3
	2
		20
		
(5)	delete()
	12
2
	20
	
(6) insert(5)
	12
2	
	5
		20
		
(7) insert(16)

	12

2		
		16	
	5
		20
		
(8) delete()

	12

5

	16
		20
		
(9) insert(1)

	12

1
		16
	5
		20
		
(10) is_empty()
Null이 아니다.
*/ 

/*
14. 정렬되지 않은 배열(array)을 이용하여 우선순위 큐 추상자료형의 각종 연산들을 구현하여보라.
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct StackType{
	int top;
	element item[MAX_STACK_SIZE];
} StackType;


void insert(StackType * s, element item)
{
	s->item[top++] = item;
}

element delete(StackType *s)
{
	element item;
	int min 99999;
	idx;
	
	for(int i = 0; i < top; i++){
		if(s->item[i] < min){
			min = s->item[i];
			idx = i;
		}
	}
	for(int i = idx; i < top; i++){
		s->item[i] = s->item[i+1]
	}
	
	return min;
}
*/ 

/*
15. 연결리스트를 이용하여 우선순위 큐 추상자료형의 각종 연산들을 구현하여 보라.


typedef int element;
typedef struct LinkNode{
	element item;
	struct LinkNode *link;
} LinkNode;

void insert(LinkNode *head, element data)
{
	LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));
	temp->item = data;
	temp->link = head->link;
	head = temp; 
	free(temp);
}

element delete(LinkNode * head)
{
	int min = 99999;
	for(LinkNode * temp = head; temp != NULL; temp = temp->link){
		if(temp->item < min){
			min = temp->item
		}
	}
	LinkNode * temp = head;
	do{
		temp = temp->link
	} while (temp->link->item == min )
	delete_delete(head, temp);
}
*/ 

/*
16. 최소 히프에서 임의의 요소를 삭제하는 C 함수를 작성하라.
	결과 히프는 히프의 조건을 만족하여야 한다.

#define MAX_ELEMENT 200
typedef struct{
	int key;
} element;
typedef struct{
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

element max_heap_find_delete(HeapType * h, element item)
{
	element data, temp;
	int parent, child;
	for(int i = 0; i < h->heap_size; i++){
		if(h->heap[i].key == item.key){
			data = h->heap[i];
			parent = i;
			break;
		}
	}
	temp = h->heap[(h->heap_size)--];
	
	child = 2*parent;
	
	while (child <= h->heap_size){
		if( (child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key ){
			child++;
		}기 
		if(temp.key >= h->heap[child].key){
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	
	return data;
} 
*/

/*
17. 다음과 같이 각 글자들의 빈도가 있을 대, 호프만 코드를 계산해보자.
	생성되는 트리를 그려보자. 
	a:1 b:1 c:2 d:3 e:5 f:8 g:13 h:21
	
정답: 책에 필 
*/



