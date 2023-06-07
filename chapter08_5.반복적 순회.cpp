//프로그램 8.4 반복적인 중위 순회
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
//TreeNode 저장하기 위해 stack로 만들어줌 
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
	if(top < SIZE -1){
		stack[++top] = p;
	}	
} 

TreeNode *pop()
{
	TreeNode *p = NULL;
	if(top >= 0){
		p = stack[top--];
	}
	return p;
}
/*
반복(1) 
stack = 15 -> 4 -> 1 -> NULL 
pop : root = 1
print [1]
root -> right = NULL

반복(2)
stack = 15-> 4 -> NULL 
pop : root = 4
print[4]
root -> rihgt = NULL

반복(3)
stack = 15 -> NULL
pop : root = 15 
print[15]
root->right = 20

반복(4)
stack = 20 -> 16 -> NULL
pop : root = 16
print[16]
root-> right = NULL

반복(5)
stack = 20 -> NULL
pop : root = 20
print[20]
root->right = 25

반복 (6)
stack = 25 -> NULL
pop : root = 25
print[25]
root->right = NULL

반복 (7)
!root
break 
*/
void inorder_iter(TreeNode *root)
{
	//1 = True -> 무한 루프 
	while (1) {
		//맨 처음 루트 노드부터 NULl 만날때까지 계속 왼쪾으로 이동 
		for(; root != NULL; root = root->left) 
		{
			push(root);
		}
		//스택에 쌓인 root가 NULL이 될 때까지 빼준다. 
		root = pop();
		if(!root){
			break;
		}
		printf("[%d]", root->data);
		root = root->right;
	}
}

//			15
// 	4				20
//1	  			16		25
//malloc 안하고 전역변수로 선언: 간편하지만 실행중 변경 불가 -> 잘 사용 x(앞에도 비슷한 사례 있음 참고)

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL,NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(void)
{
	printf("중위 순회 = ");
	inorder_iter(root);
	printf("\n"); 
	return 0;
}
/*
이진 트리의 왼쪽 노드들은 NULL 노드에 도달할 때까지 스택에 추가되었다가 NULL 노드에 도달하면 스택에서 하나씩 삭제된다.
이 삭된 노드를 방문한 후에 노드의 오른쪽 노드로 이동한다. 
이제 다시 이 노드의 왼쪽 노드들은 NULL 노드에 도달할 때까지 스택에 추가한다. 
공백 스택이 될 때까지 되풀이 하면 이진 트리를 중위순회
*/ 
