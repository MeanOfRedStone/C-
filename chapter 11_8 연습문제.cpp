/*
1. 다음의 그래프에서 가능한 신장  트리를 모두 나열하라.
1 - 2
|	|
3 - 4 

정답: 신장트리는 그래프 내에 모든 정점을 포함하는 트리를 말한다.
그래프 노드에 위 처럼 해당하는 번호를 준다면 모두 다 해서 
(1)1 -> 2 -> 4 -> 3
(2)1 -> 3 -> 4 -> 2
(3)2 -> 1 -> 3 -> 4
(4)2 -> 4 -> 3 -> 1
(5)3 -> 1 -> 2 -> 4
(6)3 -> 4 -> 2 -> 1
(7)4 -> 2 -> 1 -> 3
(8)4 -> 3 -> 1 -> 2
의 신장 트리를 찾을 수 있다. 
*/

/*
2. 아래의 네트워크에 대하여 Kruskal의 MST 알고리즘을 이용해서 최소비용 신장 트리가 구성되는 과정을 보여라.

정답: 
adfeg-abce
*/

/*
3. 앞의 네트워크에 대하여 Prim의 MST 알고리즘을 이용하여 최소비용 신장 트리가 구성되는 과정을 보여라
(A번 정점으로 시작할 것).

정답: 
A - D - F - B - E - C
*/

/*
4. Prim의 함수에서 distance[]와 selected[]값을 출력하는 문장을 삽입하여 출력하여 보고 이들의 의미를 설명하라.

//프로그램 11.9 Prim의 최소 비용 신장 트리 프로그램 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
	int n; //정점으 개수
	int weight[MAX_VERTICES][MAX_VERTICES]; 
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

//최소 dist[v]값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v, i;
	for(i = 0; i < n; i++){
		if(!selected[i]){
			v = i;
			break;
		}
	}
	for(i = 0; i < n; i++){
		if(!selected[i] && (distance[i] < distance[v])){
			v = i;
		}
	}
	return (v);
} 

void prim(GraphType *g, int s)
{
	int i, u, v;
	
	for(u = 0; u < g->n; u++){
		distance[u] = INF;
	}
	
	
	distance[s] = 0;
	
	//distance 초기  배열 프린트
	printf("distance 초기 배열 : ");
	for(u = 0; u < g->n; u++){
		printf(" %d |", distance[u]);
	}
	printf("\n"); 
	//selected 초기 배열 프린트
	printf("selected 초기 배열 : "); 
	for(u = 0; u < g->n; u++){
		printf(" %d |", selected[u]);
	}
	printf("\n"); 
	for(i = 0; i < g->n; i++){
		//for loop 에서 출력하는 distance , selected 배열 단계 
		printf("*%d 회\n", i+1); 

		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		
		
		
		if(distance[u] == INF){
			return;
		}
		printf("정점 %d 추가\n", u);
		
		//selected 출력
		printf("selected 배열\n"); 
		for(int j = 0; j < g->n; j++){
			printf(" %d |", selected[j]);
		}
		printf("\n"); 
		
		for(v = 0; v < g->n; v++){
			if(g->weight[u][v] != INF){
				if(!selected[v] && g->weight[u][v] < distance[v]){
					distance[v] = g->weight[u][v];
				}
			}	
		}
		
		//distance 출력
		printf("distance 배열\n"); 
		for(int j = 0; j < g->n; j++){
			printf(" %d |", distance[j]);
		}
		printf("\n"); 
	}
}

int main(void)
{
	GraphType g = {7,
	{{0, 29, INF, INF, INF, 10, INF},
	{29, 0, 16, INF, INF, INF, 15},
	{INF, 16, 0, 12, INF, INF, INF},
	{INF, INF, 12, 0, 22, INF, 18},
	{INF, INF, INF, 22, 0, 27, 25},
	{10, INF, INF, INF, 27, 0, INF},
	{INF, 15, INF, 18, 25, INF, 0}}
	};
	prim(&g, 0); 
	return 0;
} 

정답:
selected 배열에 추가되지 않은 점 중에서 가장 최솟값을 지닌 간선을 distance배열에서 찾아
selected 배열에 다시 추가한다.
이 과정은 selected 배열의 정점의 개수가 전체 그래프 정점의 개수 n보다 1 작을 때까지 시행한다.
*/

/*
5. 다음의 방향그래프에서 정점 0에서 다른 모든 정점까지의 최단 경로의 길이를 구하여라.
본문에서와 같이 다음의 표에 각 단계에서의 distance 배열의 값과 선택된 정점들을 나타내어라.


selected
 0 | 0 | 0 | 0 | 0 | 0 |
distance
 I | I | I | I | I | I | 
 
1단계
정점 0 선택
selected
 1 | 0 | 0 | 0 | 0 | 0 |
distance
 0 | 50 | 45 | 10 | I | I |
 
2단계
정점 3 선택
selected
 1 | 0 | 0 | 1 | 0 | 0 |
distance
 0 | 50 | 45 | 10 | 15 | I | 
 
3단계
정점 4 선택 
selected
 1 | 0 | 0 | 1 | 1 | 0 |
distance
 0 | 20 | 35 | 10 | 15 | I |
 
4단계
정점 1 선택
selected
 1 | 1 | 0 | 1 | 1 | 0 |
distance
 0 | 20 | 10 | 10 | 15 | I |
 
5단계
정점 2 선택 
selected
 1 | 1 | 1 | 1 | 1 | 0 |
distance
 0 | 20 | 10 | 10 | 15 | I |
*/

/*
6. 5번의 그래프에 대하여 Floyd 알고리즘을 적용하고 배열 A의 내용을 매 단계마다 출력하라.

정답: 모든 정점 사이의 최단 거리를 구할 때 사용한다. 
//프로그램 11.11 Floyd의 최단 경로 프로그램
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 무한대(연결이 없는 경우)

typedef struct GraphType {
	int n; //정점의 개수 
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType *g)
{
	int i, j;
	printf("================================\n");
	for(i = 0; i < g->n; i++){
		for(j = 0; j < g->n; j++){
			if(A[i][j] == INF){
				printf(" * ");
			}
			else{
				printf("%3d ", A[i][j]);
			}
		}
		printf("\n");
	}
	printf("================================\n");
}

void floyd(GraphType * g)
{
	int i, j, k;
	for(i = 0; i < g->n; i++){
		for(j = 0; j < g->n; j++){
			A[i][j] = g->weight[i][j];
		}
	}
	printA(g);
	
	for(k = 0; k < g->n; k++){
		for(i = 0; i < g->n; i++){
			for(j = 0; j < g->n; j++){
				if(A[i][k] + A[k][j] < A[i][j]){
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
		printA(g);
	}
}

int main(void)
{
	GraphType g = {6,
	{{0, 50, 45, 10, INF, INF},
	{INF, 0, 10, 15, INF, INF},
	{INF, INF, 0, INF, 30, INF},
	{20, INF, INF, 0, 15, INF},
	{INF, 20, INF, 35, 0, INF},
	{INF, INF, INF, INF, 3, 0}}
	};
	floyd(&g);
	
	return 0;
}
*/

/*
7.Dijkstra의 최단 경로 함수를 그래프가 인접 리스트로 표현되어 있다고 가정하고 재작성하라. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /*무한대로 가정*/

typedef struct GraphNode{
	int vertex;
	int weight;
	struct GraphNode *link;
} GraphNode; 

typedef struct GraphType {
	int n; //정점의 개수
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

//인접행렬로 바뀌었기 때문에 인접행렬 관련 함수들 호출
//그래프 초기화
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for(v = 0; v < MAX_VERTICES; v++){
		g->adj_list[v] = NULL;
	}
} 

//정점 삽입 연산
void insert_vertex(GraphType *g, int v)
{
	if( ((g->n) + 1) > MAX_VERTICES ) {
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType *g, int u, int v, int w)
{
	GraphNode *node;
	if( u >= g->n || v >= g->n ){
		fprintf(stderr, "그래프: 정점 번호 오류");
		return; 
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->weight = w;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
} 



//다익스트라 알고리즘 부분 
int distance[MAX_VERTICES]; /*시작 정점으로부터의 최단경로 거리*/
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i =0; i <n; i++){
		if(distance[i] < min && !found[i]){
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
} 

void print_status(GraphType * g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for(int i = 0; i < g->n; i++){
		if(distance[i] == INF){
			printf(" * ");
		}
		else{
			printf("%2d ", distance[i]);
		}
	}
	printf("\n");
	printf(" found: ");
	for(int i = 0; i < g->n; i++){
		printf("%2d ", found[i]);
	}
	printf("\n\n");
}

void shortest_path(GraphType * g, int start)
{
	int i, u, w;
	GraphNode *node;
	
	
	//왜 distance[i]에 값을 넣으면 4가 될까??? 
	for(i = 0; i < g->n; i++){
		distance[i] = INF;
	}
	printf(">>>>>>Debug distance[i] 확인");
	for(i = 0; i < g->n; i++){
		printf(" %d |", distance[i]);
	}
	
	
	for(i = 0; i < g->n; i++) /* 초기화 */
	{
		node = g->adj_list[i];
		for(node; node != NULL; node = node->link){
			distance[i] = node->weight;
		}
//		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	} 
	found[start] = TRUE; /* 시작 정점 방문 표시 */
	distance[start] = 0;
	
	
	
//	for(i = 0; i < g->n-1; i++){
//		print_status(g);
//		u = choose(distance, g->n, found);
//		found[u] = TRUE;
//		for(w = 0; w < g->n; w++){
//			if(!found[w]){
//				if(distance[u] + g->weight[u][w] < distance[w]){
//					distance[w] = distance[u] + g->weight[u][w];
//				}
//			}
//		}
//	}
//	print_status(g); 
}

int main(void)
{
//	GraphType g = {7,
//	{{0, 7, INF, INF, 3, 10, INF},
//	{7, 0, 4, 10, 2, 6, INF},
//	{INF, 4, 0, 2, INF, INF, INF},
//	{INF, 10, 2, 0, 11, 9, 4},
//	{3, 2, INF, 11, 0, INF, 5},
//	{10, 6, INF, 9, INF, 0, INF},
//	{INF, INF, INF, 4, 5, INF, 0} }
//	};

	//인접행렬로 바뀐 GraphType 함수
	GraphType g;
	graph_init(&g); 
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);
	insert_vertex(&g, 6);

//	printf("그래프 정점의 개수 : %d", g.n);

	insert_edge(&g, 0, 1, 7);
	insert_edge(&g, 0, 4, 3);
	insert_edge(&g, 0, 5, 10);
	
	insert_edge(&g, 1, 0, 7);
	insert_edge(&g, 1, 2, 4);
	insert_edge(&g, 1, 3, 10);
	insert_edge(&g, 1, 4, 2);
	insert_edge(&g, 1, 5, 6);
	
	insert_edge(&g, 2, 1, 4);
	insert_edge(&g, 2, 3, 2);
	
	insert_edge(&g, 3, 1, 10);
	insert_edge(&g, 3, 2, 2);
	insert_edge(&g, 3, 4, 11);
	insert_edge(&g, 3, 5, 9);
	insert_edge(&g, 3, 6, 4);
	
	insert_edge(&g, 4, 0, 3);
	insert_edge(&g, 4, 1, 2);
	insert_edge(&g, 4, 3, 11);
	insert_edge(&g, 4, 6, 5);
	
	insert_edge(&g, 5, 0, 10);
	insert_edge(&g, 5, 1, 6);
	insert_edge(&g, 5, 3, 9);
	
	insert_edge(&g, 6, 3, 4);
	insert_edge(&g, 6, 4, 5);
	
	shortest_path(&g, 0);
	
	return 0;
}




/*
10. 다음의 그래프에 대하여 위상 정렬을 적용하고 그 결과를 구하라.


정답: 
여러개의 위상 순서 중 하나는 다음과 같다. 
cs1 -> cs2 -> cs3 -> cs8 -> cs5 -> cs6 -> cs4 -> cs7 
*/
