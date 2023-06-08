/*
*����� ���� 
�˰��� 8.6 ���� Ž�� Ʈ������ ��� ���� ���ϴ� �˰���
get_node_count(x):

if x != NULL then
	return 1 + get_count(x.left) + get_count(x.right);


//c��� ����

int get_node_count(TreeNode *node)
{
	int count = 0;
	
	if(node != NULL){
		count = 1 + get_node_cont(node->left) + get_node_count(node->right);
	}
	
	return count;
} 

*/

/*
*�ܸ� ��� ���� ���ϱ�
(����)�ܸ���� : �ڽ� ����� �� = 0 

�˰��� 8.7 ���� Ž�� Ʈ������ �ܸ���� ���� ���ϴ� �˰���
get_leaf_count(T) :
if T != NULL then
	if T.left == NULL and T.right == NULL
			then return 1;
			else return get_leaf_count(T.left) + get_leaf_count(T.right);
			
//C��� ����

int get_leaf_count(TreeNode *node)
{
	int count = 0;
	
	if(node != NULL){
		if(node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		else
		{
			count = get_leaf_count(node->left) + get_leaf_count(node->rihgt);
		}
	}
	
	return count;
} 

*/

/*
*���� ���ϱ�
- ���� Ʈ������ ��ȯ�� �߿��� �ִ밪�� ���Ͽ� ��ȯ.

�˰��� 8.8 ���� Ž�� Ʈ������ ���� ���ϴ� �˰���
get_height(T):

if T != NULL
	return 1 + max(get_height(T.left), get_height(T.right));


//C��� ����

int get_height(TreeNode *node)
{
	int height = 0;
	
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
} 
*/

#include <stdio.h>
#include <stdlib.h> 
#include <memory.h>

#ifndef max
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#endif

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

TreeNode n7 = {1, NULL, NULL};
TreeNode n8 = {5, &n7, NULL};
TreeNode n9 = {10, NULL,NULL};
TreeNode n10 = {25, NULL, NULL};
TreeNode n11 = {20, &n9, &n10};
TreeNode n12 = {15, &n8, &n11};
TreeNode *root2 = &n12;

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

int get_node_count(TreeNode *node)
{
	int count = 0;
	
	if(node != NULL){
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	
	return count;
} 

int get_leaf_count(TreeNode *node)
{
	int count = 0;
	
	if(node != NULL){
		if(node->left == NULL && node->right == NULL)
		{
			return 1;
		}
		else
		{
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}
	
	return count;
} 

int get_height(TreeNode *node)
{
	int height = 0;
	
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
} 

int get_nonterminalnode_count(TreeNode *node)
{
	return get_node_count(node) - get_leaf_count(node);
}

int equal(TreeNode* t1, TreeNode* t2)
{
	int count = 0;
	if(t1 != NULL && t2 != NULL){
		if(t1->data == t2->data){
			count = 1 + equal(t1->left, t2->left) + equal(t1->right, t2->right);
		}
		else
		{
			count = equal(t1->left, t2->left) + equal(t1->right, t2->right);
		}
	}
	
	return count;
}

int main(void)
{
	printf("����� ���� = %d\n",get_node_count(root));
	printf("��ܸ� ����� ���� = %d\n", get_leaf_count(root));
	printf("Ʈ���� ���� = %d\n", get_height(root));
	printf("��ܸ� ����� ���� = %d\n", get_nonterminalnode_count(root)); 
	printf("���� ����� ���� = %d\n", equal(root, root2));
	
	printf("��Ʈ 2 ����� ���� = %d\n",get_node_count(root2));
	inorder(root);
	printf("\n");
	inorder(root2);
	return 0;
}


