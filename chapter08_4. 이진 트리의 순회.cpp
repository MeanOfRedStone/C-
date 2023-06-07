/*
*전위 순회 
//트리 전위 순회 알고리즘: 루트 => 서브트리 

preorder(x):

1. if x != NULL
2.	then 	print DATA(x) ;
3.			preorder(LEFT(x));
4.			preorder(RIGHT(x));

*중위 순회 
//트리 중위 순회 알고리즘 : 서브트리1 => 루트 => 서브트리2 
inorder(x):

1. if x != NULL
2.	then 	inorder (LEFT(x)) ;
3.			print DATA(x);
4.			inorder (RIGHT(x)) ;

*후위 순회
//트리 후위 순회 알고리즘 : 서브트리 => 루트 
postorder(x):

1. if x != NULL
2.	then 	postorder (LEFT(x)) ;
3.			postorder (RIGHT(x)) ;
4.			print DATA(x);
*/

/*
*전위, 중위, 후위 순회 구현
-함수의 매개변수 = 루트를 가리키는 포인터 
-순환호출의 개념 사용 
-노드 방문 : 자료출력으로 정의

//프로그램8.2 이진트리의 3가지 순회방법
//중위순회
void inorder(TreeNode *root){
	if(root != NULL){
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}  

//전위 순회 
void preorder(TreeNOde *root){
	if(root != NULL){
		printf("[%d]", root->data)
		preorder(root->left);
		preorder(root->right);
	}
}

//후위 순회
void postorder(TreeNode *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
} 
*/


//*전체 프로그램
//프록램 8.3 링크법으로 생성된 이진틀
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
//malloc 안하고 전역변수로 선언: 간편하지만 실행중 변경 불가 -> 잘 사용 x(앞에도 비슷한 사례 있음 참고)

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL,NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

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

int main(void)
{
	printf("중위 순회 =");
	inorder(root);
	printf("\n");
	
	printf("전위 순회 = ");
	preorder(root);
	printf("\n");
	
	printf("후위 순회 = ");
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
					
전위 순회 [17] [15] [05] [93] [35] [22] [95] 
중위 순회 [05] [15] [17] [22] [35] [93] [95]
후위 순회 [05] [15]	[22] [35] [95] [93] [17]
*/	
