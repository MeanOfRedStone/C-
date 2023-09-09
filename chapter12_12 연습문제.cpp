/*
1. ���� �ʱ� �ڷῡ ���Ͽ� ���� ����(Insertion Sort)�� �̿��Ͽ� �������� ������ ��� PASS1�� �����?
�ʱ� �ڷ� : 8, 3, 4, 9, 7 

���� : (4) 3, 8, 4, 9, 7
*/
/*
2. ���� �ڷḦ ���� ������ �̿��Ͽ� ������������ ������ ��� PASS1�� �����?

����: (2) 6, 7, 3, 5, 9
*/

/*
3. ���� �ڷῡ ���Ͽ� "���� ����"�� ����Ͽ� ������������ ������ ��� pass 3�� �����?

����: (1) 3, 4, 7, 9, 8
*/

/*
4. ������ �迭 A�� ����� n���� ������ ������������ �����ϴ� ���� ���� �˰����̴�. ���� ���� ������� �� �������� ��������?

void sort(int A[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++){
		key = A[i];
		for(j = i - 1; ��; j--){
			�� 
		} 
		A[j+1] = key;
	}
}

����: (4) j >= 0 && key < A[j]  | A[j+1] = A[j];
*/

/*
5. ������ ���ı���� �̿��Ͽ� ������ ���� �迭�� ������������ �����϶�. �� �ܰ迡���� �迭�� ������ ��Ÿ�����.
7 | 4 | 9 | 6 | 3 | 8 | 7 | 5 |
 
(1) ���� ����
1�ܰ�) 3 4 9 6 7 8 7 5
2�ܰ�) 3 4 9 6 7 8 7 5
3�ܰ�) 3 4 5 6 7 8 7 9
4�ܰ�) 3 4 5 6 7 8 7 9
5�ܰ�) 3 4 5 6 7 8 7 9
6�ܰ�) 3 4 5 6 7 7 8 9   
7�ܰ�) 3 4 5 6 7 7 8 9 
8�ܰ�) 3 4 5 6 7 7 8 9 

(2) ���� ����
1�ܰ�) 4 7 9 6 3 8 7 5
2�ܰ�) 4 7 9 6 3 8 7 5
3�ܰ�) 4 6 7 9 3 8 7 5
4�ܰ�) 3 4 6 7 9 8 7 5
5�ܰ�) 3 4 6 7 8 9 7 5
6�ܰ�) 3 4 6 7 7 8 9 5
7�ܰ�) 3 4 5 6 7 7 8 9

(3) ���� ����
1�ܰ�) 4 7 6 3 8 7 5 9
2�ܰ�) 4 6 3 7 7 5 8 9
3�ܰ�) 4 3 6 7 5 7 8 9
4�ܰ�) 3 4 6 5 7 7 8 9
5�ܰ�) 3 4 5 6 7 7 8 9
6�ܰ�) 3 4 5 6 7 7 8 9
7�ܰ�) 3 4 5 6 7 7 8 9
8�ܰ�) 3 4 5 6 7 7 8 9

(4) �� ���� 
1�ܰ�) ���� 5 
7					8
	4					7
		5					9
			6
				3
7 4 5 6 3 8 7 9
2�ܰ�) ���� 3
6			7			7
	3			4			9
		5			8		
		
6 3 5 7 4 8 7 9

3�ܰ�) ���� 2
4		5		6		7
	3		7		8		9
4 3 5 7 6 8 7 9

4�ܰ�) ���� 1
3 4 5 6 7 7 8 9
*/ 

/*
6. ������ ���ı���� �̿��Ͽ� ������ ���� �迭�� ������������ �����϶�. �� �ܰ迡���� �迭�� ������ ��Ÿ�����.
71 | 49 | 92 | 55 | 38 | 82 | 72 | 53 | 

(1) �� ����
1�ܰ�)
71 | 49 92 55 38 82 72 53

49	53	55	38		| 71 |		82	72	92  

2�ܰ�)

49	| 53 55 38		| 71 |		82	| 72 92
 
 38		|49|		55 53	|71|		 72		|82| 	92 
 
3�ܰ�)
| 38 | 49 |		55 53	|71 | 72 | 82 | 92 |

| 38 | 49 |		53 	| 55 |71 | 72 | 82 | 92 |

4�ܰ�)
38 49 53 55 71 72 82 92

(2) �պ� ���� 
1�ܰ�) 
71 49 92 55		|		38 82 72 53

71 49	|	92 55	|	38 82	|	72 53

49 | 71		|		55 | 92		|	38 | 82		| 	53 | 72

2�ܰ�)
71 49 92 55		|		38 82 72 53

49 55 71 92	|		|	38  53 72 82

3�ܰ�)
49 55 71 92		|	38  53 72 82

38 49 53 55 71 72 82 92

(3) ���� ���� 
71 | 49 | 92 | 55 | 38 | 82 | 72 | 53 |
1�ܰ�)
38 | 49 | 72 | 53 | 55 | 92 | 82 | 71

49 | 53 | 72 | 71 | 55 | 92 | 82
38 

2�ܰ�)
53 | 55 | 72 | 71 | 82 | 92 |
38 49 

3�ܰ�)
55 | 71 | 72 | 92 | 82
38 49 53 

4�ܰ�)
71 | 82 | 72 | 92
38 49 53 55 

5�ܰ�)
72 | 82 | 92
38 49 53 55 71 

6�ܰ�) 
82 | 92
38 49 53 55 71 72

7�ܰ�)
92
38 49 53 55 71 72 82

8�ܰ�)
38 49 53 55 71 72 82 92
*/
/*
7. ������ ���� �Է� �迭�� �� ������ �̿��Ͽ� ������ ��, �Ǻ��� �����ϴ� ����� �ٸ��� �Ͽ� �� �ܰ躰 ������ ��Ÿ�����.
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
(1) ���� ù ��° ��Ҹ� �Ǻ����� �ϴ� ���
1�ܰ�)
1	|	2 3 4 5 6 7 8

2�ܰ�)
1 | 2	|	3 4 5 6 7 8

3�ܰ�)
1 | 2 | 3	|	4 5 6 7 8

4�ܰ�)
1 | 2 | 3 | 4	|	5 6 7 8

5�ܰ�)
1 | 2 | 3 | 4 | 5 	|	6 7 8

6�ܰ�)
1 | 2  | 3 | 4 | 5 | 6	|	7 8

7�ܰ�)
1 | 2 | 3 | 4 | 5 | 6 | 7	|	8

8�ܰ�)
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |

(2) ����, �߰�, ������ ��� �߰���(median of three) ���
1�ܰ�) 
4	|	1 2 3 5 6 7 8 

1 2 3 	|	4	|	5 6 7 8

2�ܰ�) 
2 |	1 3		| 4 |	6	| 5 7 8
1 	| 2 |	3	| 4 |	5	| 6 |	7 8

3�ܰ�)
 1 | 2 | 3 | 4 | 5 | 6 | 7 |	8
 
4�ܰ�)
1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
*/

/*
8. �� ���Ŀ��� �Լ��� ����Ǹ鼭 ������ �� �н����� ������ ���� �������� ȭ�鿡  ����ϵ��� ����� �����Ͽ� ����. 

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
	high = right + 1; //pivot���� left �ϳ� ������ϱ� ������ high �� �̿� ���߾� �ϳ� ���ֱ� ���� +1 ���ش�.
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
	
	// ��ȯ�� ��� ������ pivot���� ����� �̵�
	SWAP(list[left], list[high], temp);
	
	return high; //pivot �� �ε����� ��ȯ -> pivot�� �κ� ����Ʈ �������� �̹� ���ĵ� ��ġ�� �ֱ� �����̴�.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //�κ� ����Ʈ�� ������ ������ 1���� �Ǹ� �����.  
		//partion�� ��� ���ϴ���... ���� �˰��򿡼� 
		int q = partition(list, left, right);
		
		// pivot ���� �����ϰ� ��ȯȣ���� �ݺ��Ѵ�.  
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
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/

/*
9. ���� �� �������� ���� ����� �ƴ� ���� �����ΰ�?

���� : (2) ���� ���� 
*/

/*
10.���� �� ���� ������ ���� ȿ�������� ����� �� ���� ����?
����: (2) ��� ���� ������ �Ǿ� �ִ�.
-> �񱳿��� Ƚ���� �پ���. �̵� ���굵 �پ���. 
*/

/*
11. �������� �̿��Ͽ� ������ ���� �迭�� �����ϰ��� �Ѵ�.

(a) ù ��° ������ ���� ���� �迭�� ������ ��Ÿ����.
����: 
5 3 4 |5| 8 9 6 7

(b) �� ù ��° ���ҿ��� �� ���� �񱳿����� ����Ǵ°�? 
����: 
[quick_sort]
if(left < right) 1��

[partition]
1)
low �� 1��
high �� 1��
low < high 2�� 

2)
low �� 2��
high �� 2��
low < high 2�� 

3)
low �� 1�� 
high �� 1��
low < high 1�� 

�� 14�� 

(c) ������ �̷������ �Ǻ�����, �Ǻ������� �� ���� ���� �迭�� �Ǻ������� �� ū ����迭, 2���� ����迭�� �߰��� ��ġ�ϰ� �ȴ�.
�� �Ǻ����� ��ġ�� ���� �ܰ谡 ����Ǿ��� �� ������ �Ǵ°� �ƴϸ� ���� �ʴ°�? �� ������?
����:
�Ǻ����� ��ġ�� ������� �ʴ´�.
�������� ����ߵ��� �Ǻ����� �������� �̹� ������ �Ϸ�Ǿ��� ������ �Ǻ����� ��ġ�� �ٸ� �񱳿� ������ ���� �ʴ´�.

(d) ù ��° ���� ������ ȣ��Ǵ� ��ȯȣ����� �����ΰ�?
����: 
����迭�� ũ�Ⱑ 1�� �ɶ����� ����ؼ� ���� ����迭�� �����ϱ� ���� ��ȯȣ��ȴ�.
*/

/*
12. ������ �����迭�� ��������� �̿��Ͽ� �����ϰ��� �Ѵ�. ��������� �� �ܰ踦 ������.

����:
1�ܰ�)
210 220
123 003 513
294
398 528 
409 129

210 220 123 003 513 294 398 528 409 129

2�ܰ�)
003 409
210 513
220 123 528 129 
294 398

003 409 210 513 220 123 528 129 294 398

3�ܰ�)
003
123 129
210 220 294
398
409 
513 528

003 123 129 210 220 294 398 409 513 528
*/
 
 
/*
13. ���� ������ �ڵ带 �����Ͽ� ���ڰ� �ƴϰ� ���ڵ带 ���� �����ϴ� ���α׷��� �����غ���.
�� ������ �Ǵ� ������ ���ڰ� �ƴϰ� ���ڵ��̴�. ���� ���ڵ带 ǥ���ϱ� ���� ������ ���� ����ü�� ����Ѵ�.
�ǹ��� ������ ���� ���α׷����� ��κ� ���ڵ带 �����Ͽ��� ���� ����صα� �ٶ���.
typedef struct
{
	int key;
	char name[NAME_SIZE]; 
} record;

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 6
#define NAME_SIZE 20
//���ڿ� ���ϴ� �� ������ �� 


//���ڵ带 �����ϱ� ���� ����ü 
typedef struct
{
	int key;
	char name[NAME_SIZE]; 
} record;

//�������� 
void insertion_sort(record list[], int n)
{
	int i, j, k;
	char key[NAME_SIZE];

	for(i = 1; i < n; i++){
		printf("<%d�ܰ�>", i);
		for(k = 0; k < n; k++){
			printf(" %s |", list[k].name);
		}
		printf("\n");
		
		//���ڿ� ���� �Է½� strcpy ����Ѵ�!! 
		//key  ���� ������ ���ڿ� ���� 
		strcpy(key, list[i].name); 
		printf("������ key��: %s\n", key);
		
		//key ���� ���� ���� ��� j <- '-1'�� ���� 
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
	printf("���� ���� �� ����Ʈ:\n");
	for(i = 0; i < n; i++){
		printf(" %s |", list[i].name);
	}
	printf("\n");
	//strcmp �մܾ� �������� �� �ܾ�� �� �մܾ �� ������ -1 ������ 0 ������ 1 
//	printf("%d", strcmp("amy", "abc"));
	
	insertion_sort(list, n);
	printf("���� ���� �� ����Ʈ : \n");
	for(i = 0; i < n; i++){
		printf(" %s |", list[i].name);
	}
	return 0;
} 
*/
 
 
 
 
 
 
/*
14. ���� ������ �ڵ带 �����Ͽ� ���� ������ �� �ܰ踦 ����ϵ��� �϶�. 
�Ʒ� �׸����� ���� ��ȣ �ȿ� �ִ� ���ڴ� ������ �Ǿ� �ִ� ���ڵ��̴�.
�������� ������ �ؾ� �� ���ڵ��̴�. 
���������� �ܰ迡�� ������ ���� ����ϵ��� insertion_sort �Լ��� �����϶�.
�̸� ���Ͽ� ����ڷκ��� ���ڵ��� �Է¹��� �� �ֵ��� �϶�. 

#include <stdio.h>

#define MAX_SIZE 6

int before_sort[MAX_SIZE];
int after_sort[MAX_SIZE]; 


void insertion_sort(int list[], int n)
{
	int i, j , key, insert = 17;
	//���� �� �迭 
	printf("()");
	printf("\t");
	printf("(");
	printf("%d", list[0]); //, ǥ�� ������ ù��°�Ÿ� ���� 
	for(i = 1; i < n; i++){
		printf(",%d", list[i]);
	}
	printf(")\n");
	
	for(i = 1; i < n; i++){
		//���ĵ� �κ� ��� 
		printf("(%d", list[0]); 
		for(int k = 1; k < i; k++){
			printf(",%d", list[k]);
		}

		printf(")");
		printf("\t");
		
		//���� �ȵ� �κ� ��� 
		printf("(");
		printf("%d", list[i]);
		for(int k = i + 1; k < n; k++){
			printf(",%d", list[k]);
		}
		printf(")");
		printf("\t");
		printf("%d����\n", insert);
		
		
		//������ ���� ���� 
		key = list[i];
		insert = key;		
		//key ���� ���� ���� ��� j <- '-1'�� ���� 
		for(j = i - 1; j >= 0 && list[j] > key; j--){
			list[j + 1] = list[j]; 
		}
		
		//�񱳸� ���� �ε��� -1 �پ����� ������ ���� 1 �����ش�. 
		list[j + 1] = key;
	}
	//������ ����Ʈ ��� 
	printf("(%d",list[0]);
	for(int k = 1; k < n; k++){
		printf(",%d", list[k]);
	}
	printf(")");
	printf("\t");
	printf("()");
	printf("\t");
	printf("%d����\n", insert);
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
15. ���� ���Ŀ��� �Է°� ����� ��� ���� ���� ����Ʈ�� �־����� ����� ���� ���� �Լ��� �����϶�.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link; //���� �����ؾ� ���� ��� ����. 
} ListNode;

//���Ḯ��Ʈ ���� �Լ� ���� 
//���� ó�� �Լ� 
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ù�࿡ ��� ����
ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //head ��ü�� �������̱� ������ head->link��� ���� �ʴ´�. 
	head = p; //head ��ü�� listnode p�� ����Ѵ�.
	return head; 
}

//��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //������ �ڸ��� ���� ���ο� ��带 �־��ִ� ��. 
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
		removed = head; //��� removed �ڸ��� �������� head�� �־��ش�.
		head = removed->link;
		free(removed);
		return head; 
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //��� �� ��ü�� �����Ϳ� ����.
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL; p=p->link) //���ο� ��ũ �ڸ��� �ּҰ��� ������� �ʴٸ� 
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
	
	printf(">>>>>>Debug : head ���\n");
	print_list(head);
	printf("\n"); 
	//���� �� �迭
	ListNode * after_sort = head; 
	
	//ù�� ° ���� �ٽ� �������� �ʴ´�. 
	head = head->link;
	
	//��� ����� ù ��° ��� ���� after_sort�� ���� 
	after_sort->link = NULL;
	printf(">>>>>>debug : after_sort ��� \n");
	print_list(after_sort); 
	printf("\n"); 
	
	
	//���� ��  �迭 
	ListNode * before_sort = head;
	printf(">>>>>>Debug : before_sort ���\n");
	print_list(before_sort);
	
	for(before_sort; before_sort != NULL; before_sort = before_sort->link){
		key = before_sort->data;
		
		
		ListNode * temp = after_sort;
		if(key < temp->data){
			//���� ������ ���ǿ� ���������� Ž�� 
			for(temp; temp->link != NULL && temp->data > key; temp = temp->link){}
			//Ž���� ���� �ڸ��� Ű�� ���� 
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
	
//	printf("���� �� ���Ḯ��Ʈ ��� : \n");
//	print_list(head);
	
	insertion_sort(head, count_node(head));
	
	return 0;
}
*/ 

/*
16. ���� ������ �ڵ带 �����Ͽ� ���� ������ �� �ܰ踦 ����ϵ��� �϶�.
	�Ʒ� �׸����� ���� ��ȣ �ȿ� �ִ� ���ڴ� ������ �Ǿ� �ִ� ���ڵ��̴�.
	�������� ������ �ؾ� �� ���ڵ��̴�. 
	���� ������ �ܰ迡�� ������ ���� ����ϵ��� selection_sort �Լ��� �����϶�.
	�̸� ���Ͽ� ����ڷκ��� ���ڵ��� �Է¹��� �� �ֵ��� �϶�.

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
	printf("�ʱ����");
	printf("\n");
	
	for(i = 0; i < n -1; i++){
		least = i;
		//�ּڰ� Ž�� 
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
		printf("%d���� �� %d�� ��ȯ", list[i], list[least]);
		printf("\n"); 
	}
	printf("(");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf(")");
	printf("\t");
	printf("( )\t");
	printf("%d ���� �� %d�� ��ȯ", list[n-1], list[n-1]);
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for(i = 0; i < n; i++){ //���� ���� �� ��� 
		list[i] = rand() % 100; //���� �߻� ���� 0~99 
	}
	
	selection_sort(list, n); //���� ���� ȣ��
//	for(i = 0; i < n; i++){
//		printf("%d ", list[i]);
//	}
//	printf("\n");
	
	return 0;
} 
*/

/*
17. ��� ȣ���� �����ϱ� ���Ͽ� quick_sort() �Լ��� ȣ��� ������ �Լ� �̸��� �μ��� ���� ȭ�鿡 ����϶�.
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
	high = right + 1; //pivot���� left �ϳ� ������ϱ� ������ high �� �̿� ���߾� �ϳ� ���ֱ� ���� +1 ���ش�.
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
	
	// ��ȯ�� ��� ������ pivot���� ����� �̵�
	SWAP(list[left], list[high], temp);
	
	return high; //pivot �� �ε����� ��ȯ -> pivot�� �κ� ����Ʈ �������� �̹� ���ĵ� ��ġ�� �ֱ� �����̴�.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //�κ� ����Ʈ�� ������ ������ 1���� �Ǹ� �����.  
		//partion�� ��� ���ϴ���... ���� �˰��򿡼� 
		int q = partition(list, left, right);
		
		// pivot ���� �����ϰ� ��ȯȣ���� �ݺ��Ѵ�.  
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
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n-1);
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/
/*
18. �������Լ��� quick_sort �Լ����� �Ǻ� ���� ������ ��, �κ� ����Ʈ�� ù ��°, �߰�, ������ Ű�� �߰� ���� ����ϸ� ������ ���ȴ�.
quick_sort �Լ��� �̿� ���� 3-�߰���(median of three) ����� ����ϵ��� �����Ͽ���.
median{10, 5, 7} = 7�� �ȴ�. 

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
	
	//pivot ���� �����ϱ� ���� �߰� �� ����
	int median = (left + right) / 2;  
//	printf("median �� Ȯ�� : %d\n", median);
	low = left;
	high = right + 1; //pivot���� left �ϳ� ������ϱ� ������ high �� �̿� ���߾� �ϳ� ���ֱ� ���� +1 ���ش�.
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
	
	// ��ȯ�� ��� ������ pivot���� ����� �̵�
	SWAP(list[left], list[high], temp);
	
	return high; //pivot �� �ε����� ��ȯ -> pivot�� �κ� ����Ʈ �������� �̹� ���ĵ� ��ġ�� �ֱ� �����̴�.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //�κ� ����Ʈ�� ������ ������ 1���� �Ǹ� �����.  
		//partion�� ��� ���ϴ���... ���� �˰��򿡼� 
		int q = partition(list, left, right);
		
		// pivot ���� �����ϰ� ��ȯȣ���� �ݺ��Ѵ�.  
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
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n-1);
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}
*/

/*
19. �պ� ���Ŀ����� ��� ȣ���� �����ϱ� ���Ͽ� �Լ� merge_sort�� ȣ��Ǹ� �Լ� �̸��� �μ��� ���� ȭ�鿡 ����ϰ� �����Ͽ�����.
������ ��ó�� ��µǴ����� Ȯ���϶�.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_SIZE 10

int list[MAX_SIZE];
int sorted[MAX_SIZE]; // �߰� ������ �ʿ�

//	i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
//	j�� ���ĵ� �����U ����Ʈ�� ���� �ε���
//	k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(int list[], int left, int mid, int right)
{
	printf("**���� %d���� %d����**\n",left, right);
	int i, j , k ,l;
	i = left; j = mid + 1; k = left;
	
	//���� ���ĵ� list�� �պ�
	while(i <= mid && j <= right){
		if(list[i] <= list[j]){
			sorted[k++] = list[i++];
		}
		else{
			sorted[k++] = list[j++];
		}
	}
	 //���� �ִ� ���ڵ带 �ϰ� ����
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
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹��
	for(l = left; l <= right; l++){
		list[l] = sorted[l];
	}
	printf("**���� ��� Ȯ�� : %d���� %d����**\n",left, right);
	for(l = left; l <= right; l++){
		printf(" %d |", list[l]);
	}
	printf("\n");
} 

void merge_sort(int list[], int left, int right)
{
	printf("�պ� ���� (%d, %d)\n", left, right); 
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		printf("mid�� Ȯ�� : %d\n",mid);
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
	else{
		printf("**��ȯȣ�� ����**\n");
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
	
	printf("���� �� : \n");
	for(i = 0; i < n; i++){
		printf(" %d |", list[i]);
	}
	printf("\n");
	
	merge_sort(list, 0, n-1);
	
	printf("���� �� : \n");
	for(i = 0; i < n; i++){
		printf(" %d |", list[i]);
	}
	printf("\n");
	return 0;
}
*/
