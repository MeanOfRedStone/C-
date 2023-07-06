//알고리즘 10.2 너비 우선 탐색 알고리즘 
/*
breadth_first_search(v):
	v를 방문되었다고 표시;
	큐 Q에 정점 v를 삽입;
	while(Q가 공백이 아니면) do
		Q에서 정점 v를 삭제;
		for all u (- (v에 인접한 정점) do
			if(u가 아직 방문되지 않았으면)
				then u를 큐 삽입;
					 u를 방문되었다고 표시;
*/

//프로그램10.5 너비 우선 탐색(인접 행렬 표현) 프로그램 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//오류 함수
void error(char * message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);	
} 

//초기화 함수 
void queue_init(QueueType *q)
{
	q->front = q->rear = 0;	
} 

//공백  상태 검출 함수
int is_empty(QueueType *q)
{
	return (q->front == q->rear);
} 

//포화 상태 검출 핫무
int is_full(QueueType *q)
{
	return ( (q->rear + 1) % MAX_QUEUE_SIZE == q->front );
}

//삽입 함수
void enqueue(QueueType *q, element item)
{
	if(is_full(q)){
		error("큐가 포화상태입니다");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
} 

//삭제 함수
element dequeue(QueueType *q)
{
	if(is_empty(q)){
		error("큐가 공백상태입니다");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front]; 
}

//그래프 인접행렬 부분 
#define MAX_VERTICES 50
typedef struct GraphType{
	int n; //정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
} GraphType;
int visited[MAX_VERTICES];

//그래프 초기화
void graph_init(GraphType *g)
{
	int r, c;
	g->n = 0;
	for(r = 0; r < MAX_VERTICES; r++){
		for(c = 0; c < MAX_VERTICES; c++){
			g->adj_mat[r][c] = 0;
		}
	} 
} 
//정점 삽입 연산
void insert_vertex(GraphType * g, int v)
{
	if( ((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
} 
//간선 삽입 연산
void insert_edge(GraphType * g, int start, int end)
{
	if(start >= g->n || end >= g->n){
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return; 
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
} 

void bfs_mat(GraphType * g, int v)
{
	int w;
	QueueType q;
	
	queue_init(&q);
	visited[v] = TRUE;
	printf("%d 방문 ->", v);
	enqueue(&q, v);
	//처음에만 넣고 나머지는 반복문에서 해결 
	while( !is_empty(&q)){
		v = dequeue(&q);
		for(w = 0; w < g->n; w++){
			if(g->adj_mat[v][w] && !visited[w]){
				visited[w] = TRUE;
				printf("%d 방문 -> ", w);
				enqueue(&q, w);
			}
		}
	}
}

int main(void)
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	graph_init(g);
	for(int i = 0; i< 6; i++){
		insert_vertex(g, i);
	}
	
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);
	
	printf("너비 우선 탐색\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0; 
}

//프로그램 10.6
void bfs_lst(GraphType *g, int v)
{
	GraphNode * w;
	QueueType q;
	
	init(&q);
	visited[v] = TRUE;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	while (!is_empty(&q)){
		v = dequeue(&q);
		for( w = g->adj_list[v]; w; w = w->link){
			if(!visited[w->vertex]){
				visited[w->vertex] = TRUE;
				printf("%d 방문 -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
}
