/*
//알고리즘 10.1 깊이우선탐색
depth_first_search(v):
	
	v를 방문되었다고 표시;
	for all u (- (v에 인접한 정점) do
		if(u가 아직 방문되지 않았으면)
			then depth_first_search(u)
*/


/*
//깊이 우선 탐색의 구현(인접 행렬 버전)
1. 순환 호출(교재 내용) 
2. 스택 


배열 visited 사용
방문한 곳(True) 방문하지 않은 곳(False) 


//프로그램10.3 인접 배열로 표현된 그래프에 대한 깊이우선탐색 프로그램 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType{
	int n; // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
}GraphType; 

int visited[MAX_VERTICES];

//그래프 초기화
void init(GraphType * g)
{
	int r, c;
	g->n = 0;
	for(r = 0; r < MAX_VERTICES; r++){
		for(c = 0; c < MAX_VERTICES; c++){
			g->adj_mat[r][c] = 0;
		}
	}
} 

//정점 삽입의 연산 
void insert_vertex(GraphType * g, int v)
{
	if(((g->n) + 1) > MAX_VERTICES){
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

//생긴건 트리가 아닌데 트리처럼 방문한다. 
//인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색 
void dfs_mat(GraphType * g, int v)
{
	int w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for(w = 0; w < g->n; w++){
		if (g->adj_mat[v][w] && !visited[w]){
			dfs_mat(g, w); //정점 w에서 DFS 새로 시작 
		}
	}
}

int main(void)
{
	GraphType * g;
	g = (GraphType * )malloc(sizeof(GraphType));
	init(g);
	for(int i = 0; i < 4; i++){
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	
	printf("깊이 우선 탐색\n");
	dfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0; 
	
}
*/

/*
*깊잉 우선 탐색의 구현(인접리스트 버전)
인접 리스트는 다수의 연결 리스트로 구성된다.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
#define TRUE 1
#define FALSE 0

typedef struct GraphNode{
	int vertex;
	struct GraphNode *link;
} GraphNode;

typedef struct GraphType{
	int n;
	GraphNode * adj_list[MAX_VERTICES];
}GraphType;

void init(GraphType *g)
{
	g->n = 0;
	int v;
	for(v = 0; v < MAX_VERTICES; v++){
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType * g, int v)
{
	if((g->n) + 1 > MAX_VERTICES){
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return; 
	}
	g->n++;
}

void insert_edge(GraphType * g, int u, int v)
{
	GraphNode * node;
	if(u >= g->n || v >= g->n){
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u]; //u번째에서 시작하는 위치(헤드)의 연결리스트 간선을 나타냄. 노드를 맨 앞에 삽입한다. 
	g->adj_list[u] = node; //연결리스트가 다 연결된  노드로 배열을 대체해줌. 
}

int visited[MAX_VERTICES];

//인접 리스트로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_list(GraphType * g, int v)
{
	GraphNode * w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for(w = g->adj_list[v]; w; w = w->link){
		if(!visited[w->vertex]){
			dfs_list(g, w->vertex);
		}
	}
} 

int main(void)
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	for(int i = 0; i < 4; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	
	printf("깊이 우선 탐색\n");
	dfs_list(g, 0);
	printf("\n");
	free(g);
	
	return 0;	
} 
*/

/*
명시적인 스택을 이용한 깊이 우선 탐색의 구현

//의사코드
DFS-iterative(G, v):
	스택 S를 생성한다.
	S.push(v)
	while(not is_empty(S)) do
		v = S.pop()
		if(v가 방문되지 않았으면)
			v를 방문되었다고 표시
			for all u (- (v에 인접한 정점) do
				if (u가 아직 방문되지 않았으면)
					S.push(u) 
					
(1)스택을 하나 생성하여 시작 정점을 스택에 넣는다 .
(2) 이어서 하나의 정점을 꺼내서 탐색 시작.
(3) 정점을 방문한 후에 정점의 모든 인접 정점들을 스택에 추가한다.
(4) 스택에 하나도 남지 않을 때까지 알고리즘은 계속된다.
*/ 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType{
	int n; // 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
}GraphType; 

int visited[MAX_VERTICES];

//그래프 초기화
void init(GraphType * g)
{
	int r, c;
	g->n = 0;
	for(r = 0; r < MAX_VERTICES; r++){
		for(c = 0; c < MAX_VERTICES; c++){
			g->adj_mat[r][c] = 0;
		}
	}
} 

//정점 삽입의 연산 
void insert_vertex(GraphType * g, int v)
{
	if(((g->n) + 1) > MAX_VERTICES){
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

//인접 행렬 출력 함수 
void print_adj_mat(GraphType * g)
{
	printf("debug : 작동\n");
	for(int i = 0; i < g->n; i++){
		for(int j = 0; j < g->n; j++){
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

#define SIZE 100
int top = -1;
int stack[SIZE];

void dfs_stack(GraphType * g, int v)
{
	
	stack[++top] = v;
	int pop = stack[top--];
	
//	printf("%d의 방문 기록 : %d \n",pop, visited[pop]);
	if(visited[pop] != TRUE)
	{
//		printf("작동\n");
		visited[pop] = TRUE;
		printf("정점 %d ->", pop);
		//for문의 두번째 조건 무조건 범위로 
		for(int w = g->n - 1; w >= 0; w--){
			if(g->adj_mat[pop][w] && !visited[w]){
				stack[++top] = w;
			}
		}
		while(top != -1){
			pop = stack[top--];
			dfs_stack(g, pop);
		}
	}
}
/*
//의사코드
DFS-iterative(G, v):
	스택 S를 생성한다.
	S.push(v)
	while(not is_empty(S)) do
		v = S.pop()
		if(v가 방문되지 않았으면)
			v를 방문되었다고 표시
			for all u (- (v에 인접한 정점) do
				if (u가 아직 방문되지 않았으면)
					S.push(u) 
					
(1)스택을 하나 생성하여 시작 정점을 스택에 넣는다 .
(2) 이어서 하나의 정점을 꺼내서 탐색 시작.
(3) 정점을 방문한 후에 정점의 모든 인접 정점들을 스택에 추가한다.
(4) 스택에 하나도 남지 않을 때까지 알고리즘은 계속된다.
*/

/*
void dfs_mat(GraphType * g, int v)
{
	int w;
	visited[v] = TRUE;
	printf("정점 %d -> ", v);
	for(w = 0; w < g->n; w++){
		if (g->adj_mat[v][w] && !visited[w]){
			dfs_mat(g, w); //정점 w에서 DFS 새로 시작 
		}
	}
}
*/

int main(void)
{
	GraphType * g;
	g = (GraphType * )malloc(sizeof(GraphType));
	init(g);
	for(int i = 0; i < 4; i++){
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	
	print_adj_mat(g);
	
	printf("깊이 우선 탐색\n");
	dfs_stack(g, 0);
	printf("\n");
	free(g);
	return 0; 
	
}

