/*
1. 다음 초기 자료에 대하여 삽입 정렬(Insertion Sort)을 이용하여 오름차순 정렬한 경우 PASS1의 결과는?
초기 자료 : 8, 3, 4, 9, 7 

정답 : (4) 3, 8, 4, 9, 7
*/
/*
2. 다음 자료를 버블 정렬을 이용하여 오름차순으로 정렬할 경우 PASS1의 결과는?

정답: (2) 6, 7, 3, 5, 9
*/

/*
3. 다음 자료에 대하여 "선택 정렬"를 사용하여 오름차순으로 정렬할 경우 pass 3의 결과는?

정답: (1) 3, 4, 7, 9, 8
*/

/*
4. 다음은 배열 A에 저장된 n개의 정수를 오름차순으로 정렬하는 삽입 정렬 알고리즘이다. ㄱ과 ㄴ에 순서대로 들어갈 내용으로 옳은것은?

void sort(int A[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++){
		key = A[i];
		for(j = i - 1; ㄱ; j--){
			ㄴ 
		} 
		A[j+1] = key;
	}
}

정답: (4) j >= 0 && key < A[j]  | A[j+1] = A[j];
*/

/*
5. 다음의 정렬기법을 이용하여 다음의 정수 배열을 오름차순으로 정렬하라. 각 단계에서의 배열의 내용을 나타내어라.
7 | 4 | 9 | 6 | 3 | 8 | 7 | 5 |
 
(1) 선택 정렬
1단계) 3 4 9 6 7 8 7 5
2단계) 3 4 9 6 7 8 7 5
3단계) 3 4 5 6 7 8 7 9
4단계) 3 4 5 6 7 8 7 9
5단계) 3 4 5 6 7 8 7 9
6단계) 3 4 5 6 7 7 8 9   
7단계) 3 4 5 6 7 7 8 9 
8단계) 3 4 5 6 7 7 8 9 

(2) 삽입 정렬
1단계) 4 7 9 6 3 8 7 5
2단계) 4 7 9 6 3 8 7 5
3단계) 4 6 7 9 3 8 7 5
4단계) 3 4 6 7 9 8 7 5
5단계) 3 4 6 7 8 9 7 5
6단계) 3 4 6 7 7 8 9 5
7단계) 3 4 5 6 7 7 8 9

(3) 삽입 정렬
1단계) 4 7 6 3 8 7 5 9
2단계) 4 6 3 7 7 5 8 9
3단계) 4 3 6 7 5 7 8 9
4단계) 3 4 6 5 7 7 8 9
5단계) 3 4 5 6 7 7 8 9
6단계) 3 4 5 6 7 7 8 9
7단계) 3 4 5 6 7 7 8 9
8단계) 3 4 5 6 7 7 8 9

(4) 쉘 정렬 
1단계) 간격 5 
7					8
	4					7
		5					9
			6
				3
7 4 5 6 3 8 7 9
2단계) 간격 3
6			7			7
	3			4			9
		5			8		
		
6 3 5 7 4 8 7 9

3단계) 간격 2
4		5		6		7
	3		7		8		9
4 3 5 7 6 8 7 9

4단계) 간격 1
3 4 5 6 7 7 8 9
*/ 

/*
6. 다음의 정렬기법을 이용하여 다음의 정수 배열을 오름차순으로 정렬하라. 각 단계에서의 배열의 내용을 나타내어라.
71 | 49 | 92 | 55 | 38 | 82 | 72 | 53 | 

(1) 퀵 정렬
1단계)
71 | 49 92 55 38 82 72 53

49	53	55	38		| 71 |		82	72	92  

2단계)

49	| 53 55 38		| 71 |		82	| 72 92
 
 38		|49|		55 53	|71|		 72		|82| 	92 
 
3단계)
| 38 | 49 |		55 53	|71 | 72 | 82 | 92 |

| 38 | 49 |		53 	| 55 |71 | 72 | 82 | 92 |

4단계)
38 49 53 55 71 72 82 92

(2) 합병 정렬 
1단계) 
71 49 92 55		|		38 82 72 53

71 49	|	92 55	|	38 82	|	72 53

49 | 71		|		55 | 92		|	38 | 82		| 	53 | 72

2단계)
71 49 92 55		|		38 82 72 53

49 55 71 92	|		|	38  53 72 82

3단계)
49 55 71 92		|	38  53 72 82

38 49 53 55 71 72 82 92

(3) 히프 정렬 
71 | 49 | 92 | 55 | 38 | 82 | 72 | 53 |
1단계)
38 | 49 | 72 | 53 | 55 | 92 | 82 | 71

49 | 53 | 72 | 71 | 55 | 92 | 82
38 

2단계)
53 | 55 | 72 | 71 | 82 | 92 |
38 49 

3단계)
55 | 71 | 72 | 92 | 82
38 49 53 

4단계)
71 | 82 | 72 | 92
38 49 53 55 

5단계)
72 | 82 | 92
38 49 53 55 71 

6단계) 
82 | 92
38 49 53 55 71 72

7단계)
92
38 49 53 55 71 72 82

8단계)
38 49 53 55 71 72 82 92
*/
/*
7. 다음과 같은 입력 배열을 퀵 정렬을 이용하여 정렬할 때, 피봇을 선택하는 방법을 다르게 하여 각 단계별 내용을 나타내어라.
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
(1) 왼쪽 첫 번째 요소를 피봇으로 하는 방법
1단계)
1	|	2 3 4 5 6 7 8

2단계)
1 | 2	|	3 4 5 6 7 8

3단계)
1 | 2 | 3	|	4 5 6 7 8

4단계)
1 | 2 | 3 | 4	|	5 6 7 8

5단계)
1 | 2 | 3 | 4 | 5 	|	6 7 8

6단계)
1 | 2  | 3 | 4 | 5 | 6	|	7 8

7단계)
1 | 2 | 3 | 4 | 5 | 6 | 7	|	8

8단계)
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |

(2) 왼쪽, 중간, 오른쪽 가운데 중간값(median of three) 방법
1단계) 
4	|	1 2 3 5 6 7 8 

1 2 3 	|	4	|	5 6 7 8

2단계) 
2 |	1 3		| 4 |	6	| 5 7 8
1 	| 2 |	3	| 4 |	5	| 6 |	7 8

3단계)
 1 | 2 | 3 | 4 | 5 | 6 | 7 |	8
 
4단계)
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
*/

/*
8. 퀵 정렬에서 함수가 수행되면서 정렬의 매 패스마다 다음과 같은 형식으로 화면에  출력하도록 삼수를 수정하여 보라. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y , t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1; //pivot으로 left 하나 내줘야하기 때문이 high 도 이에 맞추어 하나 내주기 위해 +1 해준다.
	pivot = list[left];
	
	int i, n = MAX_SIZE;
//	for(i = 0; i < n; i++){
//			printf("%d\t", list[i]);
//	}
//	printf("\n");
//	for(i = 0; i < low + 1; i++){
//		printf("\t");
//	}
//	printf("low");
//	for(i = 0; i < high - 2; i++){
//		printf("\t");
//	}
//	printf("high");
//	printf("\n");
	
	do{
		
//		for(i = 0; i < n; i++){
//			printf("%d\t", list[i]);
//		}
//		printf("\n");
//		
//		for(i = 0; i < low + 1; i++){
//			printf("\t");
//		}
//		printf("low");
//		
//		for(i = 0; i < high - 2; i++){
//			printf("\t");
//		}
//		printf("high");
//		printf("\n");
		
		do{
			low++;
		} while (list[low] < pivot);
		
		do{
			high--;
		} while(list[high] > pivot);
		if(low <high){
			SWAP(list[low], list[high], temp);
		}
	} while(low < high);
	
	// 교환이 모두 끝나면 pivot값을 가운데로 이동
	SWAP(list[left], list[high], temp);
	
	return high; //pivot 의 인덱스를 반환 -> pivot은 부분 리스트 기주으로 이미 정렬된 위치에 있기 때문이다.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //부분 리스트의 데이터 개수가 1개가 되면 멈춘다.  
		//partion을 어떻게 구하느냐... 뒤의 알고리즘에서 
		int q = partition(list, left, right);
		
		// pivot 값은 제외하고 순환호출을 반복한다.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

int main(void)
{
	int i;
	n = MAX_SIZE;
	int list[n] = {67, 90, 57, 25, 84, 32, 73, 54};

	quick_sort(list, 0, n-1);
	
	printf("[정렬 후] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/

/*
9. 다음 중 안정적인 정렬 방법이 아닌 것은 무엇인가?

정답 : (2) 선택 정렬 
*/

/*
10.다음 중 삽입 정렬이 가장 효율적으로 적용될 수 있을 때는?
정답: (2) 어느 정도 정렬이 되어 있다.
-> 비교연산 횟수가 줄어든다. 이동 여산도 줄어든다. 
*/

/*
11. 퀵정렬을 이용하여 다음의 정수 배열을 정렬하고자 한다.

(a) 첫 번째 분할이 끝난 후의 배열의 내용을 나타내라.
정답: 
5 3 4 |5| 8 9 6 7

(b) 이 첫 번째 분할에서 몇 번의 비교연산이 수행되는가? 
정답: 
[quick_sort]
if(left < right) 1번

[partition]
1)
low 비교 1번
high 비교 1번
low < high 2번 

2)
low 비교 2번
high 비교 2번
low < high 2번 

3)
low 비교 1번 
high 비교 1번
low < high 1번 

총 14번 

(c) 분할이 이루어지면 피봇값은, 피봇값보다 더 작은 서브 배열과 피봇값보다 더 큰 서브배열, 2개의 서브배열의 중간에 위치하게 된다.
이 피봇값의 위치는 다음 단계가 진행되었을 대 변경이 되는가 아니면 되지 않는가? 그 이유는?
정답:
피봇값의 위치는 변경되지 않는다.
문제에서 언급했듯이 피봇값을 기준으로 이미 정렬이 완료되었기 때문에 피봇값의 위치는 다른 비교에 영향을 받지 않는다.

(d) 첫 번째 분할 다음에 호출되는 순환호출들은 무엇인가?
정답: 
서브배열의 크기가 1이 될때까지 계속해서 남은 서브배열을 정렬하기 위해 순환호출된다.
*/

/*
12. 다음의 정수배열을 기수정렬을 이용하여 정렬하고자 한다. 기수정렬의 각 단계를 보여라.

정답:
1단계)
210 220
123 003 513
294
398 528 
409 129

210 220 123 003 513 294 398 528 409 129

2단계)
003 409
210 513
220 123 528 129 
294 398

003 409 210 513 220 123 528 129 294 398

3단계)
003
123 129
210 220 294
398
409 
513 528

003 123 129 210 220 294 398 409 513 528
*/
 
 
/*
13. 삽입 정렬의 코드를 수정하여 숫자가 아니고 레코드를 삽입 정렬하는 프로그램을 구성해보자.
즉 정렬이 되는 단위가 숫자가 아니고 레코드이다. 먼저 레코드를 표현하기 위해 다음과 같은 구조체를 사용한다.
실무와 연관된 실제 프로그램들은 대부분 레코드를 정렬하여야 함을 기억해두길 바란다.
typedef struct
{
	int key;
	char name[NAME_SIZE]; 
} record;

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 6
#define NAME_SIZE 20
//문자열 비교하는 것 있으면 댐 


//레코드를 정의하기 위한 구조체 
typedef struct
{
	int key;
	char name[NAME_SIZE]; 
} record;

//삽입정렬 
void insertion_sort(record list[], int n)
{
	int i, j, k;
	char key[NAME_SIZE];

	for(i = 1; i < n; i++){
		printf("<%d단계>", i);
		for(k = 0; k < n; k++){
			printf(" %s |", list[k].name);
		}
		printf("\n");
		
		//문자열 변수 입력시 strcpy 써야한다!! 
		//key  값에 정렬할 문자열 보관 
		strcpy(key, list[i].name); 
		printf("변경할 key값: %s\n", key);
		
		//key 값이 가장 작은 경우 j <- '-1'로 끝남 
		for(j = i - 1; j >= 0 && strcmp(list[j].name, key) == 1; j--){
			strcpy(list[j + 1].name, list[j].name); 
		}
		strcpy(list[j + 1].name, key);
	}
	
} 

int main(void)
{
	int i, n = MAX_SIZE;

	record list[MAX_SIZE] = {{0, "amy"}, {1, "gabriel"}, {2, "tom"} ,{3, "samanda"}, {4, "kevin"}, {5, "bob"}};
	printf("삽입 정렬 전 리스트:\n");
	for(i = 0; i < n; i++){
		printf(" %s |", list[i].name);
	}
	printf("\n");
	//strcmp 앞단어 기준으로 뒷 단어랑 비교 앞단어가 더 빠르면 -1 같으면 0 늦으면 1 
//	printf("%d", strcmp("amy", "abc"));
	
	insertion_sort(list, n);
	printf("삽입 정렬 후 리스트 : \n");
	for(i = 0; i < n; i++){
		printf(" %s |", list[i].name);
	}
	return 0;
} 
*/
 
 
 
 
 
 
/*
14. 삽입 정렬의 코드를 수정하여 삽입 정렬의 각 단계를 출력하도락 하라. 
아래 그림에서 왼쪽 괄호 안에 있는 숫자는 정렬이 되어 있는 숫자들이다.
오른쪽은 정렬을 해야 할 숫자들이다. 
삽입정렬의 단계에서 다음과 같이 출력하도록 insertion_sort 함수를 수정하라.
이를 위하여 사용자로부터 숫자들을 입력받을 수 있도록 하라. 

#include <stdio.h>

#define MAX_SIZE 6

int before_sort[MAX_SIZE];
int after_sort[MAX_SIZE]; 


void insertion_sort(int list[], int n)
{
	int i, j , key, insert = 17;
	//정렬 전 배열 
	printf("()");
	printf("\t");
	printf("(");
	printf("%d", list[0]); //, 표시 때문에 첫번째거만 따로 
	for(i = 1; i < n; i++){
		printf(",%d", list[i]);
	}
	printf(")\n");
	
	for(i = 1; i < n; i++){
		//정렬된 부분 출력 
		printf("(%d", list[0]); 
		for(int k = 1; k < i; k++){
			printf(",%d", list[k]);
		}

		printf(")");
		printf("\t");
		
		//정렬 안된 부분 출력 
		printf("(");
		printf("%d", list[i]);
		for(int k = i + 1; k < n; k++){
			printf(",%d", list[k]);
		}
		printf(")");
		printf("\t");
		printf("%d삽입\n", insert);
		
		
		//정렬할 값을 선택 
		key = list[i];
		insert = key;		
		//key 값이 가장 작은 경우 j <- '-1'로 끝남 
		for(j = i - 1; j >= 0 && list[j] > key; j--){
			list[j + 1] = list[j]; 
		}
		
		//비교를 위해 인덱스 -1 줄었으니 삽입할 떄는 1 더해준다. 
		list[j + 1] = key;
	}
	//마지막 리스트 출력 
	printf("(%d",list[0]);
	for(int k = 1; k < n; k++){
		printf(",%d", list[k]);
	}
	printf(")");
	printf("\t");
	printf("()");
	printf("\t");
	printf("%d삽입\n", insert);
} 

int main(void)
{
	int i, n = MAX_SIZE;
	int list[MAX_SIZE] = {17, 9, 21, 6, 3, 12};
	
	insertion_sort(list, n);
	
	return 0;
}
*/

/*
15. 삽입 정렬에서 입력과 출력이 모두 동적 연결 리스트로 주어지는 경우의 삽입 정렬 함수를 구현하라.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link; //변수 선언해야 실제 노드 생김. 
} ListNode;

//연결리스트 관련 함수 모음 
//오류 처리 함수 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//첫행에 노드 삽입
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //head 자체는 포인터이기 때문에 head->link라고 하지 않는다. 
	head = p; //head 자체를 listnode p가 대신한다.
	return head; 
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //포인터 자리에 이제 새로운 노드를 넣어주는 것. 
	return head; 
} 

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		removed = head; //노드 removed 자리에 포인터인 head를 넣어준다.
		head = removed->link;
		free(removed);
		return head; 
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //노드 그 자체는 포인터와 같다.
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p=p->link) //새로운 링크 자리의 주소값이 비어있지 않다면 
	{
		printf("%d->",p->data);
	}
	printf("NULL \n");
}


ListNode * reverse_reverse(ListNode * head)
{
	ListNode * reverseHead = NULL;
	for(head; head != NULL; head = head->link){
		reverseHead = insert_first(reverseHead, head->data);
	}
	
	return reverseHead;
} 

ListNode * insertion_sort(ListNode *head, int n)
{
	int key;
	
	printf(">>>>>>Debug : head 출력\n");
	print_list(head);
	printf("\n"); 
	//정렬 후 배열
	ListNode * after_sort = head; 
	
	//첫번 째 노드는 다시 정렬하지 않는다. 
	head = head->link;
	
	//헤드 노드의 첫 번째 노드 값만 after_sort에 전달 
	after_sort->link = NULL;
	printf(">>>>>>debug : after_sort 출력 \n");
	print_list(after_sort); 
	printf("\n"); 
	
	
	//정렬 전  배열 
	ListNode * before_sort = head;
	printf(">>>>>>Debug : before_sort 출력\n");
	print_list(before_sort);
	
	for(before_sort; before_sort != NULL; before_sort = before_sort->link){
		key = before_sort->data;
		
		
		ListNode * temp = after_sort;
		if(key < temp->data){
			//삽입 정렬의 조건에 맞을때까지 탐색 
			for(temp; temp->link != NULL && temp->data > key; temp = temp->link){}
			//탐색이 끝난 자리에 키값 삽입 
			after_sort = insert(after_sort, temp, key);
		}
		else {
			after_sort = insert_first(after_sort, key);
		}
	}
	after_sort = reverse_reverse(after_sort);
	print_list(after_sort);
	
} 

int count_node(ListNode * head)
{
	int count = 0;
	
	for(head; head != NULL; head = head->link){
		count += 1;
	}
	return count;
}



int main(void)
{
	ListNode *head = NULL;
	head = insert_first(head, 12); 
	head = insert_first(head, 3); 
	head = insert_first(head, 6); 
	head = insert_first(head, 21); 
	head = insert_first(head, 9); 
	head = insert_first(head, 17); 
	
//	printf("정렬 전 연결리스트 출력 : \n");
//	print_list(head);
	
	insertion_sort(head, count_node(head));
	
	return 0;
}
*/ 

/*
16. 선택 정렬의 코드를 수정하여 서택 정렬의 각 단계를 출력하도록 하라.
	아래 그림에서 왼쪽 괄호 안에 있는 숫자는 정렬이 되어 있는 숫자들이다.
	오른쪽은 정렬을 해야 할 숫자들이다. 
	선택 정렬의 단계에서 다음과 같이 출력하도록 selection_sort 함수를 수정하라.
	이를 위하여 사용자로부터 숫자들을 입력받을 수 있도록 하라.

#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	int after_sort[MAX_SIZE];
	printf("( )\t");
	printf("(");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf(")\t");
	printf("초기상태");
	printf("\n");
	
	for(i = 0; i < n -1; i++){
		least = i;
		//최솟값 탐색 
		for(j = i + 1; j < n; j++){
			if(list[j] < list[least]){
				least = j;
			} 
		}
		SWAP(list[i], list[least], temp);
		
		printf("(");
		for(int k = 0; k < i + 1; k++){
			printf("%d ", list[k]);
		}
		printf(")");
		printf("\t");
		printf("(");
		for(int k = i + 1; k < n; k++){
			printf("%d ", list[k]);
		}
		printf(")");
		printf("\t");
		printf("%d선택 후 %d과 교환", list[i], list[least]);
		printf("\n"); 
	}
	printf("(");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf(")");
	printf("\t");
	printf("( )\t");
	printf("%d 선택 후 %d과 교환", list[n-1], list[n-1]);
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for(i = 0; i < n; i++){ //난수 생성 및 출력 
		list[i] = rand() % 100; //난수 발생 범위 0~99 
	}
	
	selection_sort(list, n); //선택 정렬 호출
//	for(i = 0; i < n; i++){
//		printf("%d ", list[i]);
//	}
//	printf("\n");
	
	return 0;
} 
*/

/*
17. 재귀 호출을 추적하기 위하여 quick_sort() 함수가 호출될 때마다 함수 이름과 인수의 값을 화면에 출력하라.
quick_sort(0, 99)
quick_sort(0,50)
....

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y , t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	printf("quick_sort(%d, %d)\n", left, right);
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1; //pivot으로 left 하나 내줘야하기 때문이 high 도 이에 맞추어 하나 내주기 위해 +1 해준다.
	pivot = list[left];
	do{
		do{
			low++;
		} while (list[low] < pivot);
		
	do{
		high--;
	} while(list[high] > pivot);
	if(low <high){
		SWAP(list[low], list[high], temp);
	}
	}  while(low < high);
	
	// 교환이 모두 끝나면 pivot값을 가운데로 이동
	SWAP(list[left], list[high], temp);
	
	return high; //pivot 의 인덱스를 반환 -> pivot은 부분 리스트 기주으로 이미 정렬된 위치에 있기 때문이다.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //부분 리스트의 데이터 개수가 1개가 되면 멈춘다.  
		//partion을 어떻게 구하느냐... 뒤의 알고리즘에서 
		int q = partition(list, left, right);
		
		// pivot 값은 제외하고 순환호출을 반복한다.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for(i = 0; i < n; i++){
		list[i] = rand() % 100;
	}
	
	printf("[정렬 전] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n-1);
	
	printf("[정렬 후] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/
/*
18. 퀵정렬함수인 quick_sort 함수에서 피봇 값을 결정할 때, 부분 리스트의 첫 번째, 중간, 마지막 키중 중간 값을 사용하면 성능이 향상된다.
quick_sort 함수가 이와 같은 3-중간값(median of three) 방법을 사용하도록 수정하여라.
median{10, 5, 7} = 7이 된다. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y , t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	printf("quick_sort(%d, %d)\n", left, right);
	int pivot, temp;
	int low, high;
	
	//pivot 값을 설정하기 위한 중간 값 설정
	int median = (left + right) / 2;  
//	printf("median 값 확인 : %d\n", median);
	low = left;
	high = right + 1; //pivot으로 left 하나 내줘야하기 때문이 high 도 이에 맞추어 하나 내주기 위해 +1 해준다.
	pivot = list[median];
	do{
		do{
			low++;
		} while (list[low] < pivot);
		
	do{
		high--;
	} while(list[high] > pivot);
	if(low <high){
		SWAP(list[low], list[high], temp);
	}
	}  while(low < high);
	
	// 교환이 모두 끝나면 pivot값을 가운데로 이동
	SWAP(list[left], list[high], temp);
	
	return high; //pivot 의 인덱스를 반환 -> pivot은 부분 리스트 기주으로 이미 정렬된 위치에 있기 때문이다.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //부분 리스트의 데이터 개수가 1개가 되면 멈춘다.  
		//partion을 어떻게 구하느냐... 뒤의 알고리즘에서 
		int q = partition(list, left, right);
		
		// pivot 값은 제외하고 순환호출을 반복한다.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for(i = 0; i < n; i++){
		list[i] = rand() % 100;
	}
	
	printf("[정렬 전] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n-1);
	
	printf("[정렬 후] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/

/*
19. 합병 정렬에서의 재귀 호출을 추적하기 위하여 함수 merge_sort가 호출되면 함수 이름과 인수의 값을 화면에 출력하게 변경하여보라.
예측한 것처럼 출력되는지를 확인하라.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted[MAX_SIZE]; // 추가 공간이 필요

//	i는 정렬된 왼쪽 리스트에 대한 인덱스
//	j는 정렬된 오른쪾 리스트에 대한 인덱스
//	k는 정렬될 리스트에 대한 인덱스
void merge(int list[], int left, int mid, int right)
{
	printf("**병합 %d부터 %d까지**\n",left, right);
	int i, j , k ,l;
	i = left; j = mid + 1; k = left;
	
	//분할 정렬된 list의 합병
	while(i <= mid && j <= right){
		if(list[i] <= list[j]){
			sorted[k++] = list[i++];
		}
		else{
			sorted[k++] = list[j++];
		}
	}
	 //남아 있는 레코드를 일괄 복사
	if( i > mid ){ 
		for(l = j; l <= right; l++){
			sorted[k++] = list[l];
		}
	}
	else{
		for(l = i; l <= mid; l++){
			sorted[k++] = list[l];
		}
	}
	// 배열 sorted[]의 리스트를 배열 list[]로 재복사
	for(l = left; l <= right; l++){
		list[l] = sorted[l];
	}
	printf("**병합 결과 확인 : %d부터 %d까지**\n",left, right);
	for(l = left; l <= right; l++){
		printf(" %d |", list[l]);
	}
	printf("\n");
} 

void merge_sort(int list[], int left, int right)
{
	printf("합병 정렬 (%d, %d)\n", left, right); 
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		printf("mid값 확인 : %d\n",mid);
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
	else{
		printf("**순환호출 중지**\n");
	}	
}  

int main(void)
{
	int i;
	int n = MAX_SIZE;
	
	srand(time(NULL));
	
	for(i = 0; i < n; i++){
		list[i] = rand() % 100;
	}
	
	printf("정렬 전 : \n");
	for(i = 0; i < n; i++){
		printf(" %d |", list[i]);
	}
	printf("\n");
	
	merge_sort(list, 0, n-1);
	
	printf("정렬 후 : \n");
	for(i = 0; i < n; i++){
		printf(" %d |", list[i]);
	}
	printf("\n");
	return 0;
}
*/
