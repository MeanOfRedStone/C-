/*
//�˰��� 10.1 ���̿켱Ž��
depth_first_search(v):
	
	v�� �湮�Ǿ��ٰ� ǥ��;
	for all u (- (v�� ������ ����) do
		if(u�� ���� �湮���� �ʾ�����)
			then depth_first_search(u)
*/


/*
//���� �켱 Ž���� ����(���� ��� ����)
1. ��ȯ ȣ��(���� ����) 
2. ���� 


�迭 visited ���
�湮�� ��(True) �湮���� ���� ��(False) 


//���α׷�10.3 ���� �迭�� ǥ���� �׷����� ���� ���̿켱Ž�� ���α׷� 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType{
	int n; // ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
}GraphType; 

int visited[MAX_VERTICES];

//�׷��� �ʱ�ȭ
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

//���� ������ ���� 
void insert_vertex(GraphType * g, int v)
{
	if(((g->n) + 1) > MAX_VERTICES){
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�"); 
		return;
	}
	g->n++;
}

//���� ���� ����
void insert_edge(GraphType * g, int start, int end)
{
	if(start >= g->n || end >= g->n){
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return; 
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
} 

//����� Ʈ���� �ƴѵ� Ʈ��ó�� �湮�Ѵ�. 
//���� ��ķ� ǥ���� �׷����� ���� ���� �켱 Ž�� 
void dfs_mat(GraphType * g, int v)
{
	int w;
	visited[v] = TRUE;
	printf("���� %d -> ", v);
	for(w = 0; w < g->n; w++){
		if (g->adj_mat[v][w] && !visited[w]){
			dfs_mat(g, w); //���� w���� DFS ���� ���� 
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
	
	printf("���� �켱 Ž��\n");
	dfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0; 
	
}
*/

/*
*���� �켱 Ž���� ����(��������Ʈ ����)
���� ����Ʈ�� �ټ��� ���� ����Ʈ�� �����ȴ�.

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
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�");
		return; 
	}
	g->n++;
}

void insert_edge(GraphType * g, int u, int v)
{
	GraphNode * node;
	if(u >= g->n || v >= g->n){
		fprintf(stderr, "�׷��� : ���� ��ȣ ����");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u]; //u��°���� �����ϴ� ��ġ(���)�� ���Ḯ��Ʈ ������ ��Ÿ��. ��带 �� �տ� �����Ѵ�. 
	g->adj_list[u] = node; //���Ḯ��Ʈ�� �� �����  ���� �迭�� ��ü����. 
}

int visited[MAX_VERTICES];

//���� ����Ʈ�� ǥ���� �׷����� ���� ���� �켱 Ž��
void dfs_list(GraphType * g, int v)
{
	GraphNode * w;
	visited[v] = TRUE;
	printf("���� %d -> ", v);
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
	
	printf("���� �켱 Ž��\n");
	dfs_list(g, 0);
	printf("\n");
	free(g);
	
	return 0;	
} 
*/

/*
������� ������ �̿��� ���� �켱 Ž���� ����

//�ǻ��ڵ�
DFS-iterative(G, v):
	���� S�� �����Ѵ�.
	S.push(v)
	while(not is_empty(S)) do
		v = S.pop()
		if(v�� �湮���� �ʾ�����)
			v�� �湮�Ǿ��ٰ� ǥ��
			for all u (- (v�� ������ ����) do
				if (u�� ���� �湮���� �ʾ�����)
					S.push(u) 
					
(1)������ �ϳ� �����Ͽ� ���� ������ ���ÿ� �ִ´� .
(2) �̾ �ϳ��� ������ ������ Ž�� ����.
(3) ������ �湮�� �Ŀ� ������ ��� ���� �������� ���ÿ� �߰��Ѵ�.
(4) ���ÿ� �ϳ��� ���� ���� ������ �˰����� ��ӵȴ�.
*/ 
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphType{
	int n; // ������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; 
}GraphType; 

int visited[MAX_VERTICES];

//�׷��� �ʱ�ȭ
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

//���� ������ ���� 
void insert_vertex(GraphType * g, int v)
{
	if(((g->n) + 1) > MAX_VERTICES){
		fprintf(stderr, "�׷��� : ������ ���� �ʰ�"); 
		return;
	}
	g->n++;
}

//���� ���� ����
void insert_edge(GraphType * g, int start, int end)
{
	if(start >= g->n || end >= g->n){
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

#define SIZE 100
int top = -1;
int stack[SIZE];

void dfs_stack(GraphType * g, int v)
{
	
	stack[++top] = v;
	int pop = stack[top--];
	
//	printf("%d�� �湮 ��� : %d \n",pop, visited[pop]);
	if(visited[pop] != TRUE)
	{
//		printf("�۵�\n");
		visited[pop] = TRUE;
		printf("���� %d ->", pop);
		//for���� �ι�° ���� ������ ������ 
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
//�ǻ��ڵ�
DFS-iterative(G, v):
	���� S�� �����Ѵ�.
	S.push(v)
	while(not is_empty(S)) do
		v = S.pop()
		if(v�� �湮���� �ʾ�����)
			v�� �湮�Ǿ��ٰ� ǥ��
			for all u (- (v�� ������ ����) do
				if (u�� ���� �湮���� �ʾ�����)
					S.push(u) 
					
(1)������ �ϳ� �����Ͽ� ���� ������ ���ÿ� �ִ´� .
(2) �̾ �ϳ��� ������ ������ Ž�� ����.
(3) ������ �湮�� �Ŀ� ������ ��� ���� �������� ���ÿ� �߰��Ѵ�.
(4) ���ÿ� �ϳ��� ���� ���� ������ �˰����� ��ӵȴ�.
*/

/*
void dfs_mat(GraphType * g, int v)
{
	int w;
	visited[v] = TRUE;
	printf("���� %d -> ", v);
	for(w = 0; w < g->n; w++){
		if (g->adj_mat[v][w] && !visited[w]){
			dfs_mat(g, w); //���� w���� DFS ���� ���� 
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
	
	printf("���� �켱 Ž��\n");
	dfs_stack(g, 0);
	printf("\n");
	free(g);
	return 0; 
	
}

