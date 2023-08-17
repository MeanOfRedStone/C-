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

