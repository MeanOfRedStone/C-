/*
-정의 : 시작 정점에서부터 출발하여 신장 트리 집합을 단계적으로 확장해나가는 방법이다.
- 위의 Kruskal 알고리즘과 차이
  > kruskal은 간선을 기반 + 무조건 최저 간선만을 선택
  > Prim은 정점을 기반 + 이전 단계에서 만들어진 신장 트리를 확장

(알고리즘 11.4 Prim의 최소 비용 신장 트리 알고리즘 #1)
//최소 비용 신장 트리를 구하는 Prim의 알고리즘
//입력 : 네트워크 G = (V, E), S는 시작 정점
//출력 : Vr, 최소 비용 신장 트리를 이루는 정점들의 집합
Prim(G, s) :
	Vt <- {s}; vcounter<-1
	while vcounter < n do
		(u, v)는 u (= Vt and !(- Vt인 최저 비용 간선;
		if (그러한 (u,v)가 존재하면)
			then Vt <- Vt U v ; vcunter <- vcounter + 1
		else 실패
	return Vt
*/
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
	for(i = 0; i < g->n; i++){
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if(distance[u] == INF){
			return;
		}
		printf("정점 %d 추가\n", u);
		for(v = 0; v < g->n; v++){
			if(g->weight[u][v] != INF){
				if(!selected[v] && g->weight[u][v] < distance[v]){
					distance[v] = g->weight[u][v];
				}
			}
			
		}
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
