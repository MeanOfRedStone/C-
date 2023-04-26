//chapter 6.4 단순 연결 리스트의 코드를 작성합니다.

//*노드의 정의
//자기 참조 구조체 : 자기 자신을 참조하는 포인터를 포함하는 구조체 
typedef int element;
typedef struct{
	element data;
	struct ListNode *link; //변수 선언해야 실제 노드 생김. 
} ListNode;

//*공백 리스트의 생성
//헤드포인트를 할아야 모든 노드를 찾을 수 있다.
//head 정의하면 하나의 단순 연결 리스트 만들어진 것이라고 볼 수 있다.
ListNode *head = NULL;

//*노드의 생성 
//연결리스트는 필요할 때마다 동적 메모리 할당을 이용해 동적으로 생성.
//이 동적 메모리가 하나의 노드가 된다. 
head = (ListNode *)malloc(sizeof(ListNode));

//새로 만들어진 노드에 데이터 저장하고 링크필드 NULL로 설정하는 것
/*
head->data = 10;
head->link = NULL;
*/
 
//노드의 연결
/*
//그림의 두 번째 노드 
ListNode *p;
p = (ListNode *)malloc(sizeof(ListNode)); // head 포인터 
p->data = 20;
p->link = NULL;
//head->link에 p를 연결하면 연결됨 
head->link = p;
