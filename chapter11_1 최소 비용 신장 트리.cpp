//���� ����: ���� ���� Ʈ�� �˰����� �����Ͽ� ���� Ʈ���� ����ϴ� ������ ���α׷��� �ۼ��غ���.

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType; 

#define MAX_QUEUE_SIZE 10
typedef int element;
typedef struct QueueType{
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType; 
