/*
스레드 = 중위 후속자 + 중위 선행자

여기서는 스레드 = 중위 후속자 
// 스레드 구분 태그 필드 추가 
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread; // 만약 오른쪽 링크가 스레드이면 TRUE 
}TreeNode;

//만약 is_threa True -> rihgt는 중위 후속자/ FALSE -> 오른쪽 자식을 가리키는 포인터 
*/


/*
//스레드 이진 트리 중위 순회 연산 
노드 p의 중위 후속자를 반환하는 함수 : find_successor
p의 is_trhead가 TRUE로 되어 있으면 바로 오른쪽 자식이 중위 후속자가 되므로 오른쪽 자식을 반환 
				오른쪽  자식이 NULL이면 더 이상 후속자가 없다는 것이므로 NULL을 반환한다.
				
p의 is_thread가 FALSE인 경우 서브 트리의 가장 왼쪾 노드로 가야한다.
				따라서, 왼쪽 자식이 NULL이 될 떄까지 왼쪽 링크를 타고 이동한다.		

TreeNode* find_successor(TreeNode *p)
{
	// q는 p의 오른쪽 포인터
	TreeNode *q = p->right;
	//만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if(q == NULL || p->is_thread == True){
		return q;
	}
	
	//만약 오른쪽 자식이면 다시 가장 왼쪼 노드로 이동	
	while(q->left != NULL){
		q = q->left;
	}
	return q;
} 
*/

/*
thread_inorder : 스레드 이진 트리에서 중위 순회를 하는 함수 
순회는 가장 왼쪽 노드부터 시작 -> 왼쪽 자식이 NULL이 될 떄까지 링크 타고 이동.
다음으로, 데이터를 출력하고 중위 후속자를 찾는 함수를 호출하여 후속자가 NULL 이 아니면 계속 루프를 반복한다. 

void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	
	q = t;
	while(q->left){		//가장 왼쪽 노드로 간다. 
		q = q->left;
	}
	
	do{
		printf("%c -> ", q->data); 	// 데이터 출력 
		q = find_successor(q); 		// 후속자 함수 호출 
	}while(q);						// NULL아 아니면 
}

*/

//프로그램 8.8 스레드 이진 트리 순회 프로그램
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
	int is_thread;
} TreeNode;

//		G
//	C		F
//A	  B	  D	  
//n1.right = &n3;
//n2.right = &n7;
//n4.right = &n6;
TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode * exp = &n7;

TreeNode* find_successor(TreeNode *p)
{
	// q는 p의 오른쪽 포인터
	TreeNode *q = p->right;
	//만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if(q == NULL || p->is_thread == TRUE){
		return q;
	}
	
	//만약 오른쪽 자식이면 다시 가장 왼쪼 노드로 이동	
	while(q->left != NULL){
		q = q->left;
	}
	return q;
} 

void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	
	q = t;
	while(q->left){		//가장 왼쪽 노드로 간다. 
		q = q->left;
	}
	
	do{
		printf("%c -> ", q->data); 	// 데이터 출력 
		q = find_successor(q); 		// 후속자 함수 호출 
	}while(q);						// NULL아 아니면 
}
/*
thread_inorder(exp);
n1
print : n1->data
q = find_succesor(n1)

find_succesor(n1);
*q = n1->right = n3
return n1->right //n1->right이 비었거나 있는데 thread 일 경우: 여기서는 is_trhead =TRUE 

print : n3-> data
q = find_successor(n3)

find_succeossr(n3)
*q = n3->right
q != NULL 이고 is_thread = FALSE 임
따라서 그냥 자식노드의 가장 왼쪽 반환 
왼쪽 노드 더이상 없으므로
return n2

print: n2 ->data
q = find_succeossr(n2)

find_succeossor(n2)
*q = n2->right
q는 그냥 자식노드이므로 q의 가장 왼쪽 자식인
q = n4 반환 
... 
 

*/
int main(void)
{
	//스레드 설정
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	
	//중위 순회
	thread_inorder(exp);
	printf("\n");
	return 0; 
}

/*스레드 트리 순회를 빠르게 하는 장점 / 스레드 설정하기 위해 삽입이나 삭제 함수가 더 많은 일을 해야한다.*/ 
		
