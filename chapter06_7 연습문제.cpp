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
/*
//16.단순 연결 리스트의 헤드 포인터가 주어지면 홀수번 째  노드를 삭제하는 함수를 작성하라. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

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
int count_list(ListNode *head)
{
	int cnt = 0;
	for(ListNode *p = head; p != NULL; p = p->link )
	{
		cnt++;
	}
	
	return cnt;
}

ListNode* odd_remove(ListNode* head)
{
	
	int count = count_list(head);

	if(count % 2 == 0)
	{
		for(int i = 1; i < (count / 2) + 1; i++)
		{
			if(i ==1)
			{
				head = delete_first(head);
			}
			else
			{
				ListNode* pre = head; 
				//지울 대상 설정 
				for(int j = 2; j < i; j++)
				{
					pre = pre->link;
				}
				head = delete_delete(head, pre);
			}	
		}
	} 
	else
	{
		for(int i = 1; i < (count / 2) + 1; i++)
		{
			if(i ==1)
			{
				head = delete_first(head);
			}
			else
			{
				ListNode* pre = head; 
				//지울 대상 설정 
				for(int j = 2; j < i; j++)
				{
					pre = pre->link;
				}
				head = delete_delete(head, pre);
			}	
		}
		//홀수일 경우 추가 
		ListNode* pre = head;
		for(int i = 1; i < (count/2); i++)
		{
			pre = pre->link;
		}
		head = delete_delete(head, pre);
	}
	
	return head;
	
}

int main(void)
{
	ListNode* head = NULL;
	head = insert_first(head, 8);
	head = insert_first(head, 7);
	head = insert_first(head, 6);
	head = insert_first(head, 5);
	head = insert_first(head, 4);
	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 1);
	
	print_list(head);
	printf("\n");
//debugingr과정 
////	printf("리스트의 수 : %d\n", count_list(head));
//	
//
//	//head를 직접 타겟해야함 
//	ListNode* removed = head;
//	head = head->link;
//	free(removed);
//	print_list(head);
//	
//	removed = head->link;
//	head->link = head->link->link;
//	free(removed);
//	
//	print_list(head);
	
	

	head = odd_remove(head);
	print_list(head);
	
	
	return 0;
}
*/
/*
17. 두 개의 단순연결 리스트 A,B가 주어져 있을 경우, alternate 함수를 작성하라. 
alternate 함수는 A와 B로부터 노드를 번갈아 가져와서 새로운 리스트 C를 만드는 연산이다. 
만약 입력리스트 중에 하나가 끝나게 되면 나머지 노드를 전부 C로 옮긴다.
함수를 구현하여 올바르게 동작하는지 테스트하라. 작성된 함수의 시간 복잡도를 구하라. 


#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link; 
} ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = (ListType *)malloc(sizeof(ListType));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}



//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

void insert_last(ListType *list, element value)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;
	
	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}



////list3 = list1 + list2 
void* alternate(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//링크의 끝 : NULL 값이 아닐 때까지 진행 
	while(head1 && head2)
	{
		//head1 데이터 넣기 
		insert_last(list3, head1->data);
		
		//head2 데이터 넣기 
		insert_last(list3, head2->data);
		
		//head1, head2 다음 노드로 넘어가기 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;head1 != NULL; head1 = head1->link)  //a가 널이 아닐때까지 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	

}

void print_list(ListType* list)
{
	ListNode* head = list->head;
	for(; head != NULL; head = head->link)
	{
		printf(" | %d | ->", head->data);
	}
	printf("\n");
}

int main(void)
{
	ListType *L1 = create();
	ListType *L2 = create();
	ListType *L3 = create();
		
	//리스트노드 1 
	insert_last(L1, 12);
	insert_last(L1, 8);
	insert_last(L1, 0);
	
	//리스트노드 2 
	insert_last(L2, 2);
	insert_last(L2, 10);
	insert_last(L2, 6);

	print_list(L1);
	print_list(L2);
	
	alternate(L1, L2, L3);
	
	print_list(L3);
	
	
	return 0;
}
*/

/*
18. 2개의 단순 연결 리스트를 병합하는 함수를 조금 변경해 보자.
두 개의 연결리스트 a, b가 데이터값의 오름차순으로 노드들이 정렬되어 있는 경우,
이러한 정렬상태를 유지하면서 합병을 하여 새로운 연결리스트를 만드는 알고리즘 merge를 작성하라.
a와 b에 있는 노드들은 전부 새로운 연결 리스트로 옮겨진다. 작성된 알고리즘의 시간 복잡도도 구하라.

#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link; 
} ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = (ListType *)malloc(sizeof(ListType));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}



//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

void insert_last(ListType *list, element value)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;
	
	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}



////list3 = list1 + list2 
void* alternate(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//링크의 끝 : NULL 값이 아닐 때까지 진행 
	while(head1 && head2)
	{
		//head1 데이터 넣기 
		insert_last(list3, head1->data);
		
		//head2 데이터 넣기 
		insert_last(list3, head2->data);
		
		//head1, head2 다음 노드로 넘어가기 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;head1 != NULL; head1 = head1->link)  //a가 널이 아닐때까지 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}

void* merge(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//링크의 끝 : NULL 값이 아닐 때까지 진행 
	while(head1 && head2)
	{
		//head1의 데이터가 더 큰 경우 
		if(head1->data > head2->data)
		{
			insert_last(list3, head2->data);
			insert_last(list3, head1->data);
		}
		else if(head1->data < head2->data)
		{
			insert_last(list3, head1->data);
			insert_last(list3, head2->data);
		}
		//head1, head2 다음 노드로 넘어가기 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;head1 != NULL; head1 = head1->link)  //a가 널이 아닐때까지 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}
void print_list(ListType* list)
{
	ListNode* head = list->head;
	for(; head != NULL; head = head->link)
	{
		printf(" | %d | ->", head->data);
	}
	printf("\n");
}

int main(void)
{
	ListType *L1 = create();
	ListType *L2 = create();
	ListType *L3 = create();
		
	//리스트노드 1 
	insert_last(L1, 0);
	insert_last(L1, 8);
	insert_last(L1, 12);
	
	//리스트노드 2 
	insert_last(L2, 2);
	insert_last(L2, 6);
	insert_last(L2, 10);

	print_list(L1);
	print_list(L2);
	
	merge(L1, L2, L3);
	
	print_list(L3);
	
	
	return 0;
}
*/
/*
19. 단순 연결 리스트 C를 두 개의 단순 연결 리스트 A와 B로 분리하는 함수 split을 작성하여 보자.
C의 홀수 번째 노드들읜 모두 A로 이동되고 짝수 번째 노드들은 모두 B로 이동된다.
이 함수가 C를 변경하여서는 안된다. 작성된 알고리즘의 시간 복잡도를 구하고 구현하여 수행하여 보라.

#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode{
	element data;
	struct ListNode *link; 
} ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

ListType* create()
{
	ListType* list = (ListType *)malloc(sizeof(ListType));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}



//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

void insert_last(ListType *list, element value)
{
	ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
	temp->data = value;
	temp->link = NULL;
	
	if(list->tail == NULL)
	{
		list->head = list->tail = temp;
	}
	else
	{
		list->tail->link = temp;
		list->tail = temp;
	}
	list->size++;
}



////list3 = list1 + list2 
void* alternate(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//링크의 끝 : NULL 값이 아닐 때까지 진행 
	while(head1 && head2)
	{
		//head1 데이터 넣기 
		insert_last(list3, head1->data);
		
		//head2 데이터 넣기 
		insert_last(list3, head2->data);
		
		//head1, head2 다음 노드로 넘어가기 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;head1 != NULL; head1 = head1->link)  //a가 널이 아닐때까지 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}

void* merge(ListType* list1, ListType* list2, ListType* list3)
{
	ListNode* head1 = list1->head;
	ListNode* head2 = list2->head;
	
	//링크의 끝 : NULL 값이 아닐 때까지 진행 
	while(head1 && head2)
	{
		//head1의 데이터가 더 큰 경우 
		if(head1->data > head2->data)
		{
			insert_last(list3, head2->data);
			insert_last(list3, head1->data);
		}
		else if(head1->data < head2->data)
		{
			insert_last(list3, head1->data);
			insert_last(list3, head2->data);
		}
		//head1, head2 다음 노드로 넘어가기 
		head1 = head1->link;
		head2 = head2->link;
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;head1 != NULL; head1 = head1->link)  //a가 널이 아닐때까지 
	{
		insert_last(list3, head1->data);
	}	
	for(;head2 != NULL; head2 = head2->link)
	{
		insert_last(list3, head2->data);  	
	}	
	
}
void print_list(ListType* list)
{
	ListNode* head = list->head;
	for(; head != NULL; head = head->link)
	{
		printf(" | %d | ->", head->data);
	}
	printf("\n");
}

// | 0 | -> | 2 | -> | 6 | -> | 8 | -> | 10 | -> | 12 | ->
void split(ListType* list1, ListType* listA, ListType* listB)
{
	ListNode* head1 = list1->head;
	int size = list1->size;
	
	for(int i = 1; i < size + 1; i++)
	{
		if( (i % 2) != 0)
		{
			insert_last(listA, head1->data);
		}
		else
		{
			insert_last(listB, head1->data);
		}
		head1 = head1->link;
	}
}

int main(void)
{
	ListType *L1 = create();
	ListType *L2 = create();
	ListType *L3 = create();
		
	//리스트노드 1 
	insert_last(L1, 0);
	insert_last(L1, 8);
	insert_last(L1, 12);
	
	//리스트노드 2 
	insert_last(L2, 2);
	insert_last(L2, 6);
	insert_last(L2, 10);

	merge(L1, L2, L3);
	
	print_list(L3);
	
	ListType* La = create();
	ListType* Lb = create();
	
	split(L3, La, Lb);
	printf("La : \n");
	print_list(La);
	printf("Lb : \n");
	print_list(Lb);
	
	
	return 0;
}
*/ 

/*
20. 두개의 다항식이 다음과 같이 주어졌다. 
이들을 연결 리스트를 이용하여 나타내고 본문의 프로그램을 이용하여 두 다항식의 합을 구해보시오.

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int coef; //계수 
	int expon; //지수
	struct ListNode *link; 
} ListNode;

//연결리스트 헤더
typedef struct ListType{
	int size;
	ListNode *head;
	ListNode *tail;
};

//오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//리스트 헤더 생성 함수 :초기화 함수와 같은 용도로 사용.
ListType* create() //연결리스트 헤더를 만들어서 반환함으로 ListType* 를 변수형태로 사용 
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist; 
}

//plist의 존재에 유의하자
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
	if(temp == NULL)
	{
		error("메모리 할당 에러");
	}
	else
	{
		temp->coef = coef;
		temp->expon = expon;
		temp->link = NULL;
	}
	
	if(plist->tail == NULL)
	{
		plist->head = plist->tail = temp;
	}
	else
	{
		plist->tail->link = temp; //마지막 링크 자리에 
		plist->tail = temp;
	}
	plist->size ++;		
}

//list3 = list1 + list2 
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	
	int sum;
	//링크의 끝 : NULL 값이 아닐 때까지 진행 
	while(a && b)
	{
		if(a->expon == b->expon)
		{
			sum = a->coef + b->coef;
			if(sum != 0)
			{
				insert_last(plist3, sum, a->expon);
			}
			a = a->link;
			b = b->link;
		}
		else if(a->expon > b->expon)
		{
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else
		{
			insert_last(plist3, b->coef, b->expon);
			b = b->link; // 이해가 더 필요한 부분 위 a와 같이 
		}
	}
	
	//a나 b중 하나가 먼저 끝나게 되면 남아있는 항들 ㅁ모두
	//결과 다항식으로 복사
	for(;a != NULL; a = a->link)  //a가 널이 아닐때까지 
	{
		insert_last(plist3, a->coef,a->expon);
	}	
	for(;b != NULL; b = b->link)
	{
		insert_last(plist3, b->coef, b->expon);  	
	}	
}

//
//
void poly_print(ListType* plist)
{
	ListNode *p = plist -> head;
	
	printf("polynomial = ");
	for(;p; p = p->link)
		printf("%dx^%d + ", p->coef, p->expon );
		printf("\n"); 
}

int main(void)
{
	ListType *list1, *list2, *list3;
	
	//연결리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create() ;
	
	//다항식 1 생성 
	insert_last(list1, 3, 6);
	insert_last(list2, 7, 3);
	insert_last(list1, -2, 2);
	insert_last(list1, -9, 0);
	
	//다항식 2 생성 
	insert_last(list2, -2, 6);
	insert_last(list2, -4, 4);
	insert_last(list2, 6, 2);
	insert_last(list2, 6, 1);
	insert_last(list2, 1, 0);
	
	
	poly_print(list1);
	poly_print(list2);
	
	//다항식 3 = 다항식 1+다항식2
	poly_add(list1, list2, list3);
	poly_print(list3);
	

	return 0;
} 
*/

/* 21. 배열을 이용하여 숫자들을 입력 받아 항상 오름차순으로 정렬된 상태로 유지하는 리스트 SortedList를 구현하여 보라.
다음 연산들을 구현하면 된다.
add(list, item) :: = 정렬된 리스트에 요소를 추가한다.
delete(list, item) ::= 정렬된 리스트에서 item을 제거한다.
clear(list) ::= 리스트의 모든 요소를 제거한다.
is_in_list(list,item) ::= item이 리스트안에 있는지를 검사한다.
get_length(list) ::= 리스트의 길이를 구한다.
is_empty(list) ::= 리스트가 비어있는지를 검사한다.
is_full(list) ::= 리스트가 꽉찼는지를 검사한다.
display(list) ::= 리스트의 모든 요소를 표시한다. 


#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 //리스트의 최대 크기

typedef int element; //항목의 정의
typedef struct{
	element array[MAX_LIST_SIZE]; //배열의 정의
	int size; // 현재 리스트에 저장된 항목들의 개수 
} ArrayListType;


//*기초연산 : 모든 연산은 구조체 포인터로 바든다. 포인터로 받는 이유는
//함수 안에서 구조체를 변경할 필요도 있기 때문이다. 
//구조체를 변화시킬 때 포인터 사용 안하면 복사본만 전달되어 변경 불가.

//오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//리스트 초기화 함수
void init(ArrayListType *L)
{
	L->size = 0;
} 

//리스트 공백 확인 함수 
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

//리스트 포화 확인 함수
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE; //스택, 선형 큐와 다르게 데이터가 없을 때 위치 0이다. 
}

//pos 요소 값 반환 
element get_entry(ArrayListType *L, int pos)
{
	if(pos < 0 || pos >= L->size)
	{
		error("위치 오류");
	}
	else
	{
		return L->array[pos];
	}
}

//리스트 출력
void print_list(ArrayListType *L)
{
	int i;
	for(i = 0; i < L->size; i++)
	{
		printf("%d->",L->array[i]);
	}
	printf("\n"); 
} 

//*항목 추가 연산
void insert_last(ArrayListType *L, element item)
{
	if(L->size >= MAX_LIST_SIZE)
	{
		error("리스트 오버플로우"); 
	}
	else
	{
		L->array[L->size++] = item;
	} 
} 

//pos 위치에 새로운 항목 추가할 경우
void insert(ArrayListType *L, int pos, element item)
{
	if(!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for(int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

//*항목 삭제 연산 
element delete_list(ArrayListType *L, int pos)
{
	element item;
	
	if(pos < 0 || pos >= L->size) //L->size는 공백인 위치니깐
	{
		error("위치 오류");	
	}
	else
	{
		item = L->array[pos];
		for(int i = pos; i<(L->size- 1); i++)
		{
			L->array[i] = L->array[i+1]; // 맨 마지막 위치는 가지오 오는 값이 없으니깐 
		}
		L->size--;
		return item; 
	} 
}

void replace(ArrayListType *L, int pos, element item)
{
	if(pos < 0 || pos >= L->size)
	{
		error("위치 오류");
	}
	else
	{
		L->array[pos] = item;
	} 
}

int get_length(ArrayListType *L)
{
	return L->size;
}

void insert_first(ArrayListType *L, element item)
{
	if(!is_empty(L))
	{
		for(int i = L->size; i > 0; i--)
		{
			L->array[i] = L->array[i-1];
		}
		L->array[0] = item;
		L->size ++;
	}
}
//sortedList 함수 구현 
void add(ArrayListType *L, element item)
{
//	printf("debug>>>> L->size : %d\n", L->size);
	int pos;
	if(!is_empty(L))
	{
		for(int i = L->size - 1; i >= 0; i--) // !!! 중요 두 번째 항목은 범위로 지정해줘야 한다. 
		{
			printf("debug>>>> i : %d\n", i);
//			printf("debug>>>> data : %d\n", L->array[i]);
			if(L->array[i] <= item)
			{
				pos = i + 1;
			}
//			break; 이렇게 하면 첫 번째에서 끝내 버리지	
		}
//		printf("debug>>>>pos : %d\n", pos);	
		insert(L, pos, item);	
	} 
}


void delete_sort(ArrayListType *L, element item)
{
	int pos;
	for(int i = 0; i < L->size; i++)
	{
		if(L->array[i] == item)
		{
			pos = i;
		}
	}
	delete_list(L, pos);
}
int main(void)
{
	ArrayListType list;
	init(&list);
	insert_last(&list, 3);
	insert_last(&list, 10);
	insert_last(&list, 13);
	print_list(&list);

	delete_sort(&list, 10);
	print_list(&list);
	
	return 0;
}
*/

/*
23. 단순 연결 리스트를 이용하여 숫자들을 항상 오름차순으로 정렬된 상태로 유지하는 리스트 SortedList를 구현하여 보라.
앞의 문제의 연산들을 구현하면 된다.

add(list, item) :: = 정렬된 리스트에 요소를 추가한다.
delete(list, item) ::= 정렬된 리스트에서 item을 제거한다.
clear(list) ::= 리스트의 모든 요소를 제거한다.
is_in_list(list,item) ::= item이 리스트안에 있는지를 검사한다.
get_length(list) ::= 리스트의 길이를 구한다.
is_empty(list) ::= 리스트가 비어있는지를 검사한다.
is_full(list) ::= 리스트가 꽉찼는지를 검사한다.
display(list) ::= 리스트의 모든 요소를 표시한다. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;

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

ListNode * add(ListNode *head, element item)
{
	ListNode *p = head;
	if(head == NULL)
	{
		
		insert_first(head, item);
	}
	else
	{
		
//		for(ListNode *p = head; p != NULL p = p->link)
//		{
//			if(p->data == item)
//			{
//				insert(head, p, item);
//				break;
//			}
//			else if(p->data < item)
//			{	
//				insert(head, p, item);
//				break;
//			}
//		}
//		insert(head, p, item);
		if(item < head->data)
		{
//			printf(">>>>>debug : %d\n",item);
			insert_first(head, item);
		}
		else
		{
			for(ListNode *p = head; (p->data) < item; p = p->link)
			{
//			printf(">>>>>debug : %d",p->data);
				insert(head,p,item);
				break;
			}
		
		}

	}
}

int main(void)
{
	ListNode *head = NULL;
	
	head = add(head, 3);
	print_list(head);
	head = add(head, 5);
	print_list(head);
	head = add(head, 4);
	print_list(head);
	
	head = add(head, 1);
	print_list(head);
	
	return 0;
}
