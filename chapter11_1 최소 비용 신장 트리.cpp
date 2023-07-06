//도전 문제: 위의 신장 트리 알고리즘을 참조하여 신장 트리를 출력하는 완전한 프로그램을 작성해보자.

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType; 

#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct QueueType{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType; 
