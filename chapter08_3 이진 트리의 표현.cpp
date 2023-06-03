/*
//TreeNode : 루트 노드 알면 트리 안의 모든 노드에  접근할 수 있다. 
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;
*/
//프로그램 8.1 링크법으로 생성된 이진트리
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

int main(void)
{
	TreeNode *n1, *n2, *n3;
	n1 = (TreeNode *)malloc(sizeof(TreeNode));
	n2 = (TreeNode *)malloc(sizeof(TreeNode));
	n3 = (TreeNode *)malloc(sizeof(TreeNode));
	
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;
	
	free(n1); free(n2); free(n3);
	return 0;	
} 
