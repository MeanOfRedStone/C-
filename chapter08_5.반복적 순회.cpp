//���α׷� 8.4 �ݺ����� ���� ��ȸ
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
//TreeNode �����ϱ� ���� stack�� ������� 
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
�ݺ�(1) 
stack = 15 -> 4 -> 1 -> NULL 
pop : root = 1
print [1]
root -> right = NULL

�ݺ�(2)
stack = 15-> 4 -> NULL 
pop : root = 4
print[4]
root -> rihgt = NULL

�ݺ�(3)
stack = 15 -> NULL
pop : root = 15 
print[15]
root->right = 20

�ݺ�(4)
stack = 20 -> 16 -> NULL
pop : root = 16
print[16]
root-> right = NULL

�ݺ�(5)
stack = 20 -> NULL
pop : root = 20
print[20]
root->right = 25

�ݺ� (6)
stack = 25 -> NULL
pop : root = 25
print[25]
root->right = NULL

�ݺ� (7)
!root
break 
*/
void inorder_iter(TreeNode *root)
{
	//1 = True -> ���� ���� 
	while (1) {
		//�� ó�� ��Ʈ ������ NULl ���������� ��� �ަU���� �̵� 
		for(; root != NULL; root = root->left) 
		{
			push(root);
		}
		//���ÿ� ���� root�� NULL�� �� ������ ���ش�. 
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
//malloc ���ϰ� ���������� ����: ���������� ������ ���� �Ұ� -> �� ��� x(�տ��� ����� ��� ���� ����)

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL,NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(void)
{
	printf("���� ��ȸ = ");
	inorder_iter(root);
	printf("\n"); 
	return 0;
}
/*
���� Ʈ���� ���� ������ NULL ��忡 ������ ������ ���ÿ� �߰��Ǿ��ٰ� NULL ��忡 �����ϸ� ���ÿ��� �ϳ��� �����ȴ�.
�� ��� ��带 �湮�� �Ŀ� ����� ������ ���� �̵��Ѵ�. 
���� �ٽ� �� ����� ���� ������ NULL ��忡 ������ ������ ���ÿ� �߰��Ѵ�. 
���� ������ �� ������ ��Ǯ�� �ϸ� ���� Ʈ���� ������ȸ
*/ 
