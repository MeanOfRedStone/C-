/*
*노드의 개수 
알고리즘 8.6 이진 탐색 트리에서 노드 개수 구하는 알고리즘
get_node_count(x):

if x != NULL then
	return 1 + get_count(x.left) + get_count(x.right);


//c언어 구현

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
*단말 노드 개수 구하기
(참고)단말노드 : 자식 노드의 수 = 0 

알고리즘 8.7 이진 탐색 트리에서 단말노드 개수 구하는 알고리즘
get_leaf_count(T) :
if T != NULL then
	if T.left == NULL and T.right == NULL
			then return 1;
			else return get_leaf_count(T.left) + get_leaf_count(T.right);
			
//C언어 구현

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
*높이 구하기
- 서브 트리들의 반환값 중에서 최대값을 구하여 반환.

알고리즘 8.8 이진 탐색 트리에서 높이 구하는 알고리즘
get_height(T):

if T != NULL
	return 1 + max(get_height(T.left), get_height(T.right));


//C언어 구현

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
//malloc 안하고 전역변수로 선언: 간편하지만 실행중 변경 불가 -> 잘 사용 x(앞에도 비슷한 사례 있음 참고)

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

//중위 순회
void inorder(TreeNode* root)
{
	if(root != NULL){
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
} 

//전위 순회
void preorder(TreeNode* root)
{
	if(root != NULL){
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
} 

//후위 순회
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
	printf("노드의 개수 = %d\n",get_node_count(root));
	printf("비단말 노드의 개수 = %d\n", get_leaf_count(root));
	printf("트리의 높이 = %d\n", get_height(root));
	printf("비단말 노드의 개수 = %d\n", get_nonterminalnode_count(root)); 
	printf("같은 노드의 개수 = %d\n", equal(root, root2));
	
	printf("루트 2 노드의 개수 = %d\n",get_node_count(root2));
	inorder(root);
	printf("\n");
	inorder(root2);
	return 0;
}


