/*
*���� ��ȸ 
//Ʈ�� ���� ��ȸ �˰���: ��Ʈ => ����Ʈ�� 

preorder(x):

1. if x != NULL
2.	then 	print DATA(x) ;
3.			preorder(LEFT(x));
4.			preorder(RIGHT(x));

*���� ��ȸ 
//Ʈ�� ���� ��ȸ �˰��� : ����Ʈ��1 => ��Ʈ => ����Ʈ��2 
inorder(x):

1. if x != NULL
2.	then 	inorder (LEFT(x)) ;
3.			print DATA(x);
4.			inorder (RIGHT(x)) ;

*���� ��ȸ
//Ʈ�� ���� ��ȸ �˰��� : ����Ʈ�� => ��Ʈ 
postorder(x):

1. if x != NULL
2.	then 	postorder (LEFT(x)) ;
3.			postorder (RIGHT(x)) ;
4.			print DATA(x);
*/

/*
*����, ����, ���� ��ȸ ����
-�Լ��� �Ű����� = ��Ʈ�� ����Ű�� ������ 
-��ȯȣ���� ���� ��� 
-��� �湮 : �ڷ�������� ����

//���α׷�8.2 ����Ʈ���� 3���� ��ȸ���
//������ȸ
void inorder(TreeNode *root){
	if(root != NULL){
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}  

//���� ��ȸ 
void preorder(TreeNOde *root){
	if(root != NULL){
		printf("[%d]", root->data)
		preorder(root->left);
		preorder(root->right);
	}
}

//���� ��ȸ
void postorder(TreeNode *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
} 
*/


//*��ü ���α׷�
//���Ϸ� 8.3 ��ũ������ ������ ����Ʋ
#include <stdio.h>
#include <stdlib.h> 
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
} TreeNode;

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

//���� ��ȸ
void inorder(TreeNode* root)
{
	if(root != NULL){
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
} 

//���� ��ȸ
void preorder(TreeNode* root)
{
	if(root != NULL){
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
} 

//���� ��ȸ
void postorder(TreeNode *root)
{
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}	
} 

int main(void)
{
	printf("���� ��ȸ =");
	inorder(root);
	printf("\n");
	
	printf("���� ��ȸ = ");
	preorder(root);
	printf("\n");
	
	printf("���� ��ȸ = ");
	postorder(root);
	printf("\n");
	 
	return 0;
}

/*
QUIZ
					17
			15				93
		05				35		95
					22
					
���� ��ȸ [17] [15] [05] [93] [35] [22] [95] 
���� ��ȸ [05] [15] [17] [22] [35] [93] [95]
���� ��ȸ [05] [15]	[22] [35] [95] [93] [17]
*/	
