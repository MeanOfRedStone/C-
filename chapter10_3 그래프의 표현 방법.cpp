/*
인접 행렬을 이용한 그래프 추상 데이터 타입의 구현 

#define MAX_VERTICES 50
typedef struct GraphType{
	int n; ///정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICIES]; 
}GraphType;


//프로그램10.1 adj_mat.c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType{
	int n; //정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
}GraphType;

//그래프 초기화 
void init(GraphType *g)
{
	printf("debug : 작동 init\n");
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
	printf("debug : 작동\n");
	if( (g->n) + 1 > MAX_VERTICES){
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType * g, int start, int end)
{
	printf("debug : 작동\n");
	if( start >= g->n || end >= g->n){
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

int main(void) 
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);
	printf("정점의 개수 : %d", g->n);
	for(int i = 0; i < 4; i++){
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	print_adj_mat(g);
	
	free(g);
	
	return 0;
}
*/

/*
*인접 리스트를 이용한 그래프 추상 데이터 타입의 구현
*/
//프로그램 10.2 adj_list.c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
//연결되는 간선을 의미한다. 
typedef struct GraphNode{
	int vertex; 
	struct GraphNode * link; 
} GraphNode;

//전체 인접 연결 리스트를 표시 
typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode * adj_list[MAX_VERTICES]; //시작하는 정점 배열 위치 하나당 시작 정점을 보관  : 예를들어 g->adj_lst[1]은 1번에서 시작하는 간선을 보유한다. 
}GraphType;
//그래프 초기화
void init(GraphType *g)
{
	int v;
	g->n = 0;
	for(v = 0; v < MAX_VERTICES; v++){
		g->adj_list[v] = NULL;
	}	
} 

//정점 사입 연산
void insert_vertex(GraphType * g, int v)
{
	if((g->n) + 1 > MAX_VERTICES){
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}	
	g->n++;
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
//위치는 상관 없지만 삽입을 쉽게하기 위하여 연결리스트의 맨 앞에 삽입. 
void insert_edge(GraphType * g, int u, int v)
{
	GraphNode * node;
	if(u >= g->n || v >= g->n){
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return; 
	}	
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;//u에서 v로 가는 간선
	node->link  = g->adj_list[u];
	g->adj_list[u] = node; 
} 

void print_adj_list(GraphType * g)
{
	for(int i = 0; i < g->n ; i++) {
		GraphNode * p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		
		while(p != NULL){
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
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
	
	print_adj_list(g);
	free(g);
	
	return 0;
}
