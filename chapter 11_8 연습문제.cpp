/*
1. ������ �׷������� ������ ����  Ʈ���� ��� �����϶�.
1 - 2
|	|
3 - 4 

����: ����Ʈ���� �׷��� ���� ��� ������ �����ϴ� Ʈ���� ���Ѵ�.
�׷��� ��忡 �� ó�� �ش��ϴ� ��ȣ�� �شٸ� ��� �� �ؼ� 
(1)1 -> 2 -> 4 -> 3
(2)1 -> 3 -> 4 -> 2
(3)2 -> 1 -> 3 -> 4
(4)2 -> 4 -> 3 -> 1
(5)3 -> 1 -> 2 -> 4
(6)3 -> 4 -> 2 -> 1
(7)4 -> 2 -> 1 -> 3
(8)4 -> 3 -> 1 -> 2
�� ���� Ʈ���� ã�� �� �ִ�. 
*/

/*
2. �Ʒ��� ��Ʈ��ũ�� ���Ͽ� Kruskal�� MST �˰����� �̿��ؼ� �ּҺ�� ���� Ʈ���� �����Ǵ� ������ ������.

����: 
adfeg-abce
*/

/*
3. ���� ��Ʈ��ũ�� ���Ͽ� Prim�� MST �˰����� �̿��Ͽ� �ּҺ�� ���� Ʈ���� �����Ǵ� ������ ������
(A�� �������� ������ ��).

����: 
A - D - F - B - E - C
*/

/*
4. Prim�� �Լ����� distance[]�� selected[]���� ����ϴ� ������ �����Ͽ� ����Ͽ� ���� �̵��� �ǹ̸� �����϶�.

//���α׷� 11.9 Prim�� �ּ� ��� ���� Ʈ�� ���α׷� 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType{
	int n; //������ ����
	int weight[MAX_VERTICES][MAX_VERTICES]; 
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

//�ּ� dist[v]���� ���� ������ ��ȯ
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
	
	//distance �ʱ�  �迭 ����Ʈ
	printf("distance �ʱ� �迭 : ");
	for(u = 0; u < g->n; u++){
		printf(" %d |", distance[u]);
	}
	printf("\n"); 
	//selected �ʱ� �迭 ����Ʈ
	printf("selected �ʱ� �迭 : "); 
	for(u = 0; u < g->n; u++){
		printf(" %d |", selected[u]);
	}
	printf("\n"); 
	for(i = 0; i < g->n; i++){
		//for loop ���� ����ϴ� distance , selected �迭 �ܰ� 
		printf("*%d ȸ\n", i+1); 

		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		
		
		
		if(distance[u] == INF){
			return;
		}
		printf("���� %d �߰�\n", u);
		
		//selected ���
		printf("selected �迭\n"); 
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
		
		//distance ���
		printf("distance �迭\n"); 
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

����:
selected �迭�� �߰����� ���� �� �߿��� ���� �ּڰ��� ���� ������ distance�迭���� ã��
selected �迭�� �ٽ� �߰��Ѵ�.
�� ������ selected �迭�� ������ ������ ��ü �׷��� ������ ���� n���� 1 ���� ������ �����Ѵ�.
*/

/*
5. ������ ����׷������� ���� 0���� �ٸ� ��� ���������� �ִ� ����� ���̸� ���Ͽ���.
���������� ���� ������ ǥ�� �� �ܰ迡���� distance �迭�� ���� ���õ� �������� ��Ÿ�����.


selected
 0 | 0 | 0 | 0 | 0 | 0 |
distance
 I | I | I | I | I | I | 
 
1�ܰ�
���� 0 ����
selected
 1 | 0 | 0 | 0 | 0 | 0 |
distance
 0 | 50 | 45 | 10 | I | I |
 
2�ܰ�
���� 3 ����
selected
 1 | 0 | 0 | 1 | 0 | 0 |
distance
 0 | 50 | 45 | 10 | 15 | I | 
 
3�ܰ�
���� 4 ���� 
selected
 1 | 0 | 0 | 1 | 1 | 0 |
distance
 0 | 20 | 35 | 10 | 15 | I |
 
4�ܰ�
���� 1 ����
selected
 1 | 1 | 0 | 1 | 1 | 0 |
distance
 0 | 20 | 10 | 10 | 15 | I |
 
5�ܰ�
���� 2 ���� 
selected
 1 | 1 | 1 | 1 | 1 | 0 |
distance
 0 | 20 | 10 | 10 | 15 | I |
*/

/*
6. 5���� �׷����� ���Ͽ� Floyd �˰����� �����ϰ� �迭 A�� ������ �� �ܰ踶�� ����϶�.

����: ��� ���� ������ �ִ� �Ÿ��� ���� �� ����Ѵ�. 
//���α׷� 11.11 Floyd�� �ִ� ��� ���α׷�
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 ���Ѵ�(������ ���� ���)

typedef struct GraphType {
	int n; //������ ���� 
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
7.Dijkstra�� �ִ� ��� �Լ��� �׷����� ���� ����Ʈ�� ǥ���Ǿ� �ִٰ� �����ϰ� ���ۼ��϶�. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000 /*���Ѵ�� ����*/

typedef struct GraphNode{
	int vertex;
	int weight;
	struct GraphNode *link;
} GraphNode; 

typedef struct GraphType {
	int n; //������ ����
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

//������ķ� �ٲ���� ������ ������� ���� �Լ��� ȣ��
//�׷��� �ʱ�ȭ
void graph_init(GraphType *g)
{
	int v;
	g->n = 0;
	for(v = 0; v < MAX_VERTICES; v++){
		g->adj_list[v] = NULL;
	}
} 

//���� ���� ����
void insert_vertex(GraphType *g, int v)
{
	if( ((g->n) + 1) > MAX_VERTICES ) {
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

//���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType *g, int u, int v, int w)
{
	GraphNode *node;
	if( u >= g->n || v >= g->n ){
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return; 
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->weight = w;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
} 



//���ͽ�Ʈ�� �˰��� �κ� 
int distance[MAX_VERTICES]; /*���� �������κ����� �ִܰ�� �Ÿ�*/
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
	
	
	//�� distance[i]�� ���� ������ 4�� �ɱ�??? 
	for(i = 0; i < g->n; i++){
		distance[i] = INF;
	}
	printf(">>>>>>Debug distance[i] Ȯ��");
	for(i = 0; i < g->n; i++){
		printf(" %d |", distance[i]);
	}
	
	
	for(i = 0; i < g->n; i++) /* �ʱ�ȭ */
	{
		node = g->adj_list[i];
		for(node; node != NULL; node = node->link){
			distance[i] = node->weight;
		}
//		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	} 
	found[start] = TRUE; /* ���� ���� �湮 ǥ�� */
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

	//������ķ� �ٲ� GraphType �Լ�
	GraphType g;
	graph_init(&g); 
	insert_vertex(&g, 0);
	insert_vertex(&g, 1);
	insert_vertex(&g, 2);
	insert_vertex(&g, 3);
	insert_vertex(&g, 4);
	insert_vertex(&g, 5);
	insert_vertex(&g, 6);

//	printf("�׷��� ������ ���� : %d", g.n);

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
10. ������ �׷����� ���Ͽ� ���� ������ �����ϰ� �� ����� ���϶�.


����: 
�������� ���� ���� �� �ϳ��� ������ ����. 
cs1 -> cs2 -> cs3 -> cs8 -> cs5 -> cs6 -> cs4 -> cs7 
*/
