/*
1. 다음 중 NULL 포인터가 존재하지 않는 구조체는?
답 : (2) 원형 연결리스트
-> 마지막 노드가 최초의 노드와 연결되기 때문

2.리스트의 n번째 요소를 가장 빠르게 찾을 수 있는 구현 방법은?
답 : (4) 이중 연결 리스트
->처음과 끝 중 더 가까운 곳에서부터 시작해 링크를 타고 이동할 수 있기 때문

3.단순 연결 리스트에서 포인터 last가 마지막 노드를 가진다고 할 때 다음 수식 중 참인 것은
답 : (3) last->link == NULL 
-> 마지막 데이터는 존재하고 그 다음으로 연결된 링크만 없는 것이다.

4.단순 연결 리스트의 노드를 포인터 p로 방문하고자 한다. 현재 p가 가리키는 노드에서 다음 코드로 가려면?  
답 : (3) p = p->link
->현재 노드의 링크는 그 다음 노드와 같다.
즉, 노드는 포인터 그 자체와 같다.

5.다음과 같이 변수 p가 2를 저장하는 노드를 가리키도록 하는 문장을 작성하라.
현재 상태
p = 1 / node a
node a = 2 / node b
node b = 3 / null

p = node a(링크를 넣어줌) 
p->link = node b 
->링크만 넣어주면 된다. 링크는 노드 그 자체 

6.다음과 같이 변수 q가 1를 저장하는 노드를 가리키도록 하는 문장을 적어라 
링크p = 1 / node a
node a = 2 / node b
node b = 3 / null 

링크 q = 2 / node b
링크 r = 3 / null 

링크 q = 1 / node a

7.다음과 같은 연결 리스트에서 아래와 같은 코드를 실행한다고 하자, 실행이 끝난 후에 포인터 p가 가리키는 노드는 어떤 노드인가?
답 : NULL이다. 마지막 노드가 가리키는 링크는 NULL인데, 해당 for 반복문은 마지막까지 이동시키기 때문이다.

8.덱은 삽입과 삭제가 양끝에서 임의로 수행되는 자료 구조이다. 다음 그림과 같이단순연결리스트로 덱을 구현한다고 할 때 O(1) 시간
내에 수행할 수 없는 연산은? 
풀이 
(1) insertFirst  : Node x->data = value / Node x->link = first / first = Node x -> 무조건 3개 연산만
(3) deletFirst : removed = first / head = Node x -> link / free(removed) -> 무조건 3개 연산만 가능
답 
(4) deleteLast 
deleteLast의 경우 마지막 노드 이전의 노드를 알아야 하는데 이를 위해서는 단순 연결 리스트에서는 head부터 for반복문으로 이동해야 한다.
*/ 
/*
//9.다음과 같이 단순 연결 리스트에 사용자가 입력하는 값을 저장했다가 출력하는 프로그램을 작성하라.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 

int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	int n;
	printf("노드의 개수 : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 이상 입력하세요.");
	}
	else if(n == 1)
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		print_list(head);
	}
	else
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("노드 #%d의 데이터 : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		print_list(head);
	}
	

//	풀이과정 (이하 내용을 if 구문 / for loop 안에 집어 넣음 
//	head = insert_first(head, 3); //1번 
//	location = head;
	//링크변화 :0번 
//	head = insert(head, location, 5); //2번 
//	location = head;
//	location = location->link; : 1번 
//	head = insert(head, location, 7);//3번 
//	location = head;
//	location = location->link;
//	location = location->link; : 2번 
//	print_list(head); 

	
	return 0;	
} 
*/
/*
//10. 다음과 같이 연결리스트의 노드의 개수를 계산하는 프로그램을 작성해보자. 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 

int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	int n;
	printf("노드의 개수 : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 이상 입력하세요.");
	}
	else if(n == 1)
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		printf("연결 리스트 노드의 개수 = 1"); 
	}
	else
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("노드 #%d의 데이터 : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		int cnt = 0;
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			cnt = cnt + 1;
		}
		printf("연결 리스트 노드의 개수 = %d", cnt);
	}
	
	return 0;	
} 
*/
/*
//11.단순 연결 리스트에 정수가 저장되어 있다. 연결 리스트에 있는 모든 노드의 데이터 값을 합한 결과를 출력하는 프로그램을 작성하시오.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 

int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	int n;
	printf("노드의 개수 : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 이상 입력하세요.");
	}
	else if(n == 1)
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		printf("연결 리스트 데이터의 합 = %d", value); 
	}
	else
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("노드 #%d의 데이터 : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		int sum = 0;
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			sum = sum + p->data;
		}
		printf("연결 리스트의 데이터 합 = %d", sum);
	}
	
	return 0;	
} 
*/
/*
//12. 연결 리스트에서 특정한 데이터 값을 갖는 노드의 개수를 계산하는 함수를 작성하라
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 

int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	int n;
	printf("노드의 개수 : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n < 1)
	{
		error("1 이상 입력하세요.");
	}
	else if(n == 1)
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		printf("탐색할 값을 입력하시오 : ");
		int find;
		scanf("%d", &find);
		if(find == value)
		{
			printf("%d는 연결 리스트에서 1번 나타납니다.", find);
		}
		else
		{
			printf("%d는 연결 리스트에서 0번 나타납니다.", find);
		}
	}
	else
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("노드 #%d의 데이터 : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		int cnt = 0;
		printf("탐색할 값을 입력하시오 : ");
		int find;
		scanf("%d", &find);
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			if(find == p->data)
			{
				cnt = cnt + 1;
			}
		}
		printf("%d는 연결 리스트에서 %d번 나타납니다.", find, cnt);
	}
	
	return 0;	
} 
*/
/*
//13. 단순 연결 리스트에서 탐색함수를 참고하여 특정한 데이터 값을 갖는 노드를 삭제하는 함수를 작성하라.   
ListNode* search_list(ListNode *head, element x)
{
	ListNode *p = head;
	ListNode *location;
	
	while(p != NULL)
	{
		if(p->data == x)
		{
			delete_delete(head, location);
			p = location;
			return head;
		}
		location = p;
		p = p->link;
	}
	return NULL; //탐색 실패 시 사용 
} 
*/
/*
//14.다음 그림과 같은 데이터를 저장할 수 있는 단순 연결 리스트를 생성하는 프로그램을 작성해보자.
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char name[100];
	int age;
	float heigh; 
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, char name[100], int age, float heigh)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	strcpy(p->name, name);
	p->age = age;
	p->heigh = heigh;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, char name[100], int age, float heigh)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	strcpy(p->name, name);
	p->age = age;
	p->heigh = heigh;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf(" %s | %d | %.1f ->",p->name, p->age, p->heigh);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 

int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	
	head = insert_first(head, "choi", 30, 1.3);
	head = insert_first(head, "lee", 48, 1.4);	
	head = insert_first(head, "park", 27, 1.2);
	head = insert_first(head, "kim", 34, 1.7);
	print_list(head);
	
	
	return 0;	
} 

*/

/*
//15. 단순 연결 리스트가 정렬되지 않은 정수들의 리스트를 저장하고 있다. 리스트에서 최대값과 최소값을 찾는 프로그램을 작성하라. 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; //먼저 p를 완성시켜주고
	head = p; //link 자체인 head == 다음 노드 자리. 이곳에  p를 넣어준다.
	
	return head; 
}

ListNode* insert(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p; //(3)p를 완성시켜주고 위치 집어넣어준다. 
	
	return head; 
}

ListNode* delete_first(ListNode *head)
{
	if(head==NULL)
	{
		return NULL; 
	}
	else
	{
	ListNode *removed; //데이터를 새로 주는 것이 아니기 때문에 동적 메모리 할당을 할 필요가 없다.
	removed = head; //removed 값을 알기 위해서는 removed가 뭔지 알기 알아야 함. 이를  위해서 link 그자체인 head == 첫 노드 
	head = removed->link;
	free(removed);
	
	return head;
	}
}

ListNode* delete_delete(ListNode *head, ListNode *pre)
{
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 
}

void print_list(ListNode *head)
{
	for(ListNode *p = head; p != NULL ; p = p->link)
	{
		printf("%d->",p->data);
	}
	printf("NULL\n"); //마지막이란 걸 알리기 위해	
} 


int main(void)
{
	ListNode *head = NULL; //head 생성 처음에는 비어있는 상태로 설정
	int n;
	printf("노드의 개수 : ");
	scanf("%d",&n);
	ListNode *location = head;
	if(n <= 1)
	{
		error("2개 이상 입력하세요.");
	}
	else
	{
		element value;
		printf("노드 #1의 데이터 : ");
		scanf("%d", &value);
		head = insert_first(head, value);
		location = head;
		for(int i = 1; i < n; i++)
		{
			printf("노드 #%d의 데이터 : ", i+1);
			scanf("%d", &value);
			head = insert(head, location, value);
			location = head;
			for(int j = 0; j < i; j++ )
			{
				location = location->link;
			}
		}
		
		int max = -9999;
		int min = 9999; 
		
		for(ListNode *p = head; p != NULL; p = p->link)
		{
			if(max < p->data)
			{
				max = p->data;
			}
			if(min > p->data)
			{
				min = p->data;
			}
		}
		printf("최댓값 : %d, 최솟값 : %d", max, min);
	}
	
	return 0;	
} 
*/

//16.단순 연결 리스트의 헤드 포인터가 주어지면 홀수번 째  노드를 삭제하는 함수를 작성하라. 

| 1(head) | -> | 2 | -> | 3 | -> | 4 | -> | 5 | -> | 6 | ->
head
p = p->link->link
head->link(2번째)
(1) 연결 바꾸기 
head = head->link
head->link->link = head->link->link->link(4번째)
head->link->link->link->link = head->link->link->link->link->link(6번째)

(2) 노드 삭제 
free(head)1, 2
free(head->link)3, 4
free(head->link->link)5
fre(head->link->link->link)7


int count_list(ListNode *head)
{
	int cnt = 0;
	for(ListNode *p = head; p != NULL; p = p->link )
	{
		cnt++;
	}
	
	return cnt;
}

j를 2번씩 건너지 말고 i 그대로 써보자!! 
i = 0 
head = head->link

i = 2
j = 0, j = 2
p = head->link->link = head->linnk->link->link

i = 4
j = 0 j = 2 j = 4
head->link->link->link
head->link->link->link
head->link->link->link(4번째) = 
ListNode* delete_odd(ListNode *head)
{
	if(count_list(head) % 2 == 0)
	{
		for(int i = 0; i < count_list(head); i = i + 2)
		{
			ListNode *p = head;	
			for(int j = 0; j < i; j = j + 2)     i = 0 / i = 2 / i = 4 / i = 6
			{
				p = p->link
			}
			p = p->link
			
		}
	}
	else
	{
		
	}
}
	
	ListNode *removed;
	removed = pre->link; //링크는 노드 그 자체이니깐 removed가 뭔지 알려면 pre->link를 넣어줘야함. 
	pre->link = removed->link;
	free(removed);
	
	return head; 





