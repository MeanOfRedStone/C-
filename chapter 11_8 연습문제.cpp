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

