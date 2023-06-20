/*��������*/
/*
1. ���� Ʈ���� ���� ���� ��ȸ �����?
�� : D -> B -> A -> E -> C -> F (4��) 



2. ���� Ʈ���� ���� ��ȸ�� ������ ��� �ټ� ��°�� Ž���Ǵ� ����?
A B D C E
E (2��)



3. ���� �׸��� ���� ����Ʈ���� ���� ��ȸ�� �����?
AB/ ... (4)



4. ���� Ʈ������ �ܸ� ��� ����?
D , G, H, F 4�� (3��)


5. ���� �׸����� Ʈ���� ������?
��  : (1) 3

Ʈ���� ����: ����� ���� �߿��� ���� ū �� 



6. Y = A * B + C / D
��: (3)
 


7. ���� Ʈ������ ���̰� 5�� �� �� Ʈ���� �ִ� �� ���� ��带 ���� �� �ֳ�.
���� 5
�ִ� ����� �� : 2^5 - 1 = 31�� 
�� : (4) 



8. NULL �����͸� Ʈ���� ��ȸ�� �̿��ϴ� Ʈ���� �����̶� �ϴ°�? 
(3) ������ ���� Ʈ��(threaded binary tree) 
*/

/*
9.
*/

/*
10. ������ ����Ʈ���� ���Ͽ� ���� ������ ���Ͽ���.
(1)���� Ʈ���� 1���� �迭�� ǥ���Ͻÿ�.
NULL - 6 - 4 - 9 - 2 - 5 - 7 - 10 - 1 - 3 - NULL - NULL - NULL - NULL - 8 - 11

(2) ���� Ʈ���� ���� ��ȸ�� ����� ���ÿ�.
6 - 4 - 2 - 1 - 3 - 5 - 9 - 7 - 10 - 8 - 11

(3) ���� Ʈ���� ���� ��ȸ�� ����� ���ÿ�.
1 - 3 - 2 - 5 - 4 - 7 - 8 - 11 - 10 - 9 - 6

(4) ���� Ʈ���� ���� ��ȸ�� ����� ���ÿ�.
1 - 2 - 3 - 4 - 5 - 6 - 7 - 9 - 8 - 10 - 11

(5) ���� Ʈ���� ���� ��ȸ�� ����� ���ÿ�.
6 - 4 - 9 - 2 - 5 - 7 - 10 - 1 - 3 - 8 - 11

(6) ���� Ʈ���� ���� Ž�� Ʈ���ΰ�? �� ������?
���� Ž�� Ʈ���� �ƴϴ�.
���� Ž��Ʈ�� ���� �� ��Ʈ ����� ������ ����Ʈ���� ��Ʈ���� Ŀ���ϴ� ������ �ִ�.
������ 8�� ��Ʈ�� 9���� ������ �����ʿ� �ֱ� ������  �� ������ �����Ѵ�.
���� ���� Ž�� Ʈ���� �ƴϴ�.



11. ���� ������ �ڷᰡ �ԷµǾ��ٰ� �����Ͽ� ���� Ž�� Ʈ���� �����϶�.
(1) ������ ���� Ž�� Ʈ���� �׸��ÿ�
  		11
  	6		19
  4  8	  17   43 
   5  10	 31	49
(2) ���⼭ 11�� �����ϸ� ��� ����Ǵ°�?
->17�� ��Ʈ ���� �´�.
(3) ���⿡ 12�� �߰��ϸ� ��� ����Ǵ°�?
->17�� ���� ���� 12�� �߰���
(4) ������ ����Ž��Ʈ������ 8�� Ž���� �� ��ġ�� ��带 �����Ͻÿ�
11 -> 6
(5) ������ ����Ž��Ʈ���� 1���� �迭�� �̿��Ͽ� �����Ͽ� ���ÿ�. ����� ����� �׸��ÿ�.
-> 11 | 6 | 19 | 4 | 8 | 17 | 43 | NULL | 5 | NULL | 10 | NULL | NULL | 31 | 49 |
 
*/ 

/*
12. ������ ���� �Լ��� �Ʒ��� ǥ�õ� ����Ʈ���� ��Ʈ ��忡 ���� ȣ��ȴٰ� ����.
�Լ��� ��ȯ�ϴ� ���� �����ΰ�?
3 | 5 | 1 | 4 | 2 | 8 | 6

->����: ���ܳ����� �ִ밪�� �ݿ��Ѵ�. ���� 8
*/
/*
13. ���� Ʈ���� ����Ʈ�� ���̰� �ִ� 1���̳��� Ʈ���� "���� Ʈ��(balanced tree)"��� �Ѵ�.
�־��� ���� Ʈ���� ���� Ʈ�������� �˻��ϴ� �Լ� isBalanced()�� �ۼ��ϰ� �׽�Ʈ�϶�.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>


#define max(a,b)  (((a) > (b)) ? (a) : (b))


typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

//��ȸ ���ó�� �ϸ� cnt�� �ȴ�������. 
int inorder_cnt(TreeNode *root)
{
	int cnt = 0;
	if(root != NULL)
	{
		cnt = 1 + inorder_cnt(root->left) + inorder_cnt(root->right);
	}
	return cnt;
}

//�ڽĳ��� �� ���� ������������ ���̸� �߰����ش�. 
int get_height(TreeNode *node)
{
	int height = 0;
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	
	return height;
}
int isBalanced(TreeNode * root)
{
	TreeNode * left = root->left;
	TreeNode * right = root->right;
	

	int left_h = get_height(left);
	int right_h = get_height(right);
//	printf("���� ����Ʈ���� ���� : %d", left_h);
	
	if(abs(left_h - right_h) <= 1)
	{
		return 1; 
	}
	else
	{
		return 0;
	}

	
}

int main(void)
{
	TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
//	TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));
//	TreeNode *n4 = (TreeNode *)malloc(sizeof(TreeNode));
//	TreeNode *n5 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n6 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n7 = (TreeNode *)malloc(sizeof(TreeNode));
	
	n1->data = 1;
	n1->left = NULL;
	n1->right = n3;
	
//	n2->data = 2;
//	n2->left = n4;
//	n2->right = n5;
	
	n3->data = 3;
	n3->left = n6;
	n3->right = n7;
	 
//	n4->data = 4;
//	n4->left = NULL;
//	n4->right = NULL;
//	
//	n5->data = 5;
//	n5->left = NULL;
//	n5->right = NULL;
	
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	
	n7->data = 7;
	n7->left = NULL;
	n7->right = NULL; 
	
	if( isBalanced(n1) == 1){
		printf("����Ʈ���Դϴ�.");
	}
	else{
		printf("����Ʈ���� �ƴմϴ�.");
	}
	
	return 0;
}
*/

/*
14. �־��� ����Ʈ������ ��尡 ������ �ִ� ���� ���� ����ϴ� ���α׷��� �ۼ��غ���. 

#include <stdlib.h>
#include <stdio.h>
#include <memory.h> 
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int inorder_sum(TreeNode * root)
{
	int sum = 0;
	if(root != NULL){
		printf("�������� �� : %d\n", root->data);
		sum = inorder_sum(root->left) + root->data + inorder_sum(root->right);
	}
	
	return sum;
}

int main(void)
{
	TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n4 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n5 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n6 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n7 = (TreeNode *)malloc(sizeof(TreeNode));
	
	n1->data = 1;
	n1->left = n2;
	n1->right = n3;
	
	n2->data = 2;
	n2->left = n4;
	n2->right = n5;
	
	n3->data = 3;
	n3->left = n6;
	n3->right = n7;
	 
	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;
	
	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;
	
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	
	n7->data = 7;
	n7->left = NULL;
	n7->right = NULL; 
	
	printf("���� : %d", inorder_sum(n1));
	

	return 0;
}
*/

/*
15. �־��� ����Ʈ������ ��尡 ������ �ִ� ���� �־��� value���� ������ ����� ���� ����ϴ� ���α׷��� �ۼ��غ���. 

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

void inorder_condition(TreeNode * root, int value)
{
	if(root != NULL){
		inorder_condition(root->left, value);
		if(root->data < value){
			printf("���� ���� : %d\n", root->data);
		} 
		inorder_condition(root->right, value);
	}	
} 
int main(void)
{
	TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n4 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n5 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n6 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n7 = (TreeNode *)malloc(sizeof(TreeNode));
	
	n1->data = 1;
	n1->left = n2;
	n1->right = n3;
	
	n2->data = 2;
	n2->left = n4;
	n2->right = n5;
	
	n3->data = 3;
	n3->left = n6;
	n3->right = n7;
	 
	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;
	
	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;
	
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	
	n7->data = 7;
	n7->left = NULL;
	n7->right = NULL; 
	
	int value = 6;
	printf("���� value : %d\n", value);
	inorder_condition(n1, value);
	
	

	return 0;
}
*/

/*
16. �־��� ���� Ʈ������ �ڽ��� �ϳ��� �ִ� ����� ������ ��ȯ�ϴ� �Լ��� �ۼ��϶�. 

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int odd_leafNode_count(TreeNode * root)
{
	//��ȯ ȣ�� ����ϸ� ������ ���� ���ϱ� ���ؼ��� ��ȯ ȣ�� ��ü�� ���ϱ� �������� �ؾ� ��ȯ���� ����� 
	int cnt = 0;
	if(root != NULL){
		if(root->left == NULL && root->right != NULL){
			cnt = 1 + odd_leafNode_count(root->right);
		}
		else if(root->right == NULL && root->left != NULL){
			cnt = 1 + odd_leafNode_count(root->left);
		}
		else{
			cnt = odd_leafNode_count(root->left) + 0 + odd_leafNode_count(root->right);
		}
		
	}
	return cnt;	
} 

int main(void)
{
	TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n4 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n5 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n6 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n7 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n8 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n10 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n15 = (TreeNode *)malloc(sizeof(TreeNode));
	n1->data = 1;
	n1->left = n2;
	n1->right = n3;
	
	n2->data = 2;
	n2->left = n4;
	n2->right = n5;
	
	n3->data = 3;
	n3->left = n6;
	n3->right = n7;
	 
	n4->data = 4;
	n4->left = n8;
	n4->right = NULL;
	
	n5->data = 5;
	n5->left = n10;
	n5->right = NULL;
	
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	
	n7->data = 7;
	n7->left = NULL;
	n7->right = n15; 
	
	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;
	
	n10->data = 10;
	n10->left = NULL;
	n10->right = NULL;
	
	n15->data = 15;
	n15->left = NULL;
	n15->right = NULL;
	
	printf("�ڽ��� �ϳ��� �ִ� ����� ���� : %d", odd_leafNode_count(n1));
	
	

	return 0;
}
*/

/*
17. �Ϲ� ���� Ʈ������ �ִ밪�� �ּҰ��� Ž���ϱ� ���� �Լ��� �ۼ��϶�. ���� Ž�� Ʈ���� �ƴϴ�.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;


//��ȯ�ݺ��� ���������� �� ���� ����ؼ� ����ؾ��Ѵ�. ���⼭�� ���� ���� ���� �̷� �� �ƴ� ��? 
int max_find(TreeNode * root)
{
	int max = -9999;
	//HINT : ��ȯ ȣ���� �̿��϶� 
	if(root != NULL){
		
		if( max_find(root->left) >= root->data && max_find(root->left) >= max_find(root->right)){
			max = max_find(root->left);
		}
		else if( root->data >= max_find(root->left) && root->data >= max_find(root->right)){
			max = root->data;
		}
		else if( max_find(root->right) >= root->data && max_find(root->right) >= max_find(root->left)){
			max = max_find(root->right);
		}
//		printf("debug : ���%d �����ִ밪 : %d\n", root->data, max);
	}
	
	return max;
} 

int min_find(TreeNode * root)
{
	int min = 9999;
	//HINT : ��ȯ ȣ���� �̿��϶� 
	if(root != NULL){
		
		if( min_find(root->left) <= root->data && min_find(root->left) <= min_find(root->right)){
			min = min_find(root->left);
		}
		else if( root->data <= min_find(root->left) && root->data <= min_find(root->right)){
			min = root->data;
		}
		else if( min_find(root->right) > root->data && min_find(root->right) > min_find(root->left)){
			min = min_find(root->right);
		}
//		printf("debug : ���%d �����ִ밪 : %d\n", root->data, max);
	}
	
	return min;
} 

int main(void)
{
	TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n2 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n3 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n4 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n5 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n6 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n7 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n8 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n10 = (TreeNode *)malloc(sizeof(TreeNode));
	TreeNode *n15 = (TreeNode *)malloc(sizeof(TreeNode));
	n1->data = 1;
	n1->left = n2;
	n1->right = n3;
	
	n2->data = 2;
	n2->left = n4;
	n2->right = n5;
	
	n3->data = 3;
	n3->left = n6;
	n3->right = n7;
	 
	n4->data = 4;
	n4->left = n8;
	n4->right = NULL;
	
	n5->data = 120;
	n5->left = n10;
	n5->right = NULL;
	
	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;
	
	n7->data = 7;
	n7->left = NULL;
	n7->right = n15; 
	
	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;
	
	n10->data = 10;
	n10->left = NULL;
	n10->right = NULL;
	
	n15->data = 15;
	n15->left = NULL;
	n15->right = NULL;
	
	printf("�ִ밪 : %d �ּڰ�: %d \n", max_find(n1), min_find(n1));
	
	

	return 0;
}
