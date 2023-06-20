/*
���� ����� �̿��� �׷��� �߻� ������ Ÿ���� ���� 

#define MAX_VERTICES 50
typedef struct GraphType{
	int n; ///������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICIES]; 
}GraphType;


//���α׷�10.1 adj_mat.c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType{
	int n; //������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
}GraphType;

//�׷��� �ʱ�ȭ 
void init(GraphType *g)
{
	printf("debug : �۵� init\n");
	int r, c;
	g->n = 0;
	for(r = 0; r < MAX_VERTICES; r++){
		for(c = 0; c < MAX_VERTICES; c++){
			g->adj_mat[r][c] = 0;
		}
	}
}

//���� ���� ���� 
void insert_vertex(GraphType * g, int v)
{
	printf("debug : �۵�\n");
	if( (g->n) + 1 > MAX_VERTICES){
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

//���� ���� ����
void insert_edge(GraphType * g, int start, int end)
{
	printf("debug : �۵�\n");
	if( start >= g->n || end >= g->n){
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return; 
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
} 

//���� ��� ��� �Լ� 
void print_adj_mat(GraphType * g)
{
	printf("debug : �۵�\n");
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
	printf("������ ���� : %d", g->n);
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
*���� ����Ʈ�� �̿��� �׷��� �߻� ������ Ÿ���� ����
*/
//���α׷� 10.2 adj_list.c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
//����Ǵ� ������ �ǹ��Ѵ�. 
typedef struct GraphNode{
	int vertex; 
	struct GraphNode * link; 
} GraphNode;

//��ü ���� ���� ����Ʈ�� ǥ�� 
typedef struct GraphType {
	int n; // ������ ����
	GraphNode * adj_list[MAX_VERTICES]; //�����ϴ� ���� �迭 ��ġ �ϳ��� ���� ������ ����  : ������� g->adj_lst[1]�� 1������ �����ϴ� ������ �����Ѵ�. 
}GraphType;
//�׷��� �ʱ�ȭ
void init(GraphType *g)
{
	int v;
	g->n = 0;
	for(v = 0; v < MAX_VERTICES; v++){
		g->adj_list[v] = NULL;
	}	
} 

//���� ���� ����
void insert_vertex(GraphType * g, int v)
{
	if((g->n) + 1 > MAX_VERTICES){
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return;
	}	
	g->n++;
}

//���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
//��ġ�� ��� ������ ������ �����ϱ� ���Ͽ� ���Ḯ��Ʈ�� �� �տ� ����. 
void insert_edge(GraphType * g, int u, int v)
{
	GraphNode * node;
	if(u >= g->n || v >= g->n){
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return; 
	}	
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;//u���� v�� ���� ����
	node->link  = g->adj_list[u];
	g->adj_list[u] = node; 
} 

void print_adj_list(GraphType * g)
{
	for(int i = 0; i < g->n ; i++) {
		GraphNode * p = g->adj_list[i];
		printf("���� %d�� ���� ����Ʈ", i);
		
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
