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
*/

/*
18. ���ڵ��� ��� �ִ� ���� Ž�� Ʈ���� ���� ��ȸ�ϸ� ���ĵ� ���ڰ� �������.
�̸� �̿��Ͽ� ���� �迭�� ����ִ� ���ڵ��� ���Ľ�Ű�� �Լ��� �ۼ��Ͽ� ����.
�迭�� ��� �ִ� ���ڵ��� ���� Ž�� Ʈ���� �߰��� �Ŀ� Ʈ���� ���� ��ȸ�ϸ鼭 ���ڵ��� ����Ѵ�.
�� ���ڵ��� �ߺ����� �ʴ´ٰ� ��������.
idx: 0 											 10
	 11 | 3 | 4 | 1 | 56 | 5 | 6 | 2 | 98 | 32 | 23 | 

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

//��ȯ���� Ž���Լ� 
TreeNode * search(TreeNode * node, int key)
{
	if(node == NULL){
		return NULL;
	}
	if(key == node->key){
		return node;
	}
	else if(key < node->key){
		return search(node->left, key);
	}
	else{
		return search(node->right, key);
	}
}

TreeNode * new_node(int item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->right = temp->left = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode * node, int key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ
	if(node == NULL){
		return new_node(key);
	} 
	//Ž���� ���з� ���� �� ������ ���ο� ��� ���� ������ �����̴�. NULL �� ���� ��ȯ�� ���� new_node(key) 
	if(key < node->key){
		node->left = insert_node(node->left,key);
	}
	else if(key > node->key){
		node->right = insert_node(node->right, key);
	}
	//����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	
	//���⼭�� �Ű������� root->right�� �ް� �� �� ���� �ܸ� ��带 ã���� ������ 
	while(current->left != NULL){
		current = current->left;
	} 
	
	return current;
}

//���� Ž�� Ʈ���� Ű�� �־����� ����� ��鸣 �����ϰ�
//���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode * delete_node(TreeNode * root, int key)
{
	if(root == NULL){
		return root;
	}	
	
	//���� Ű�� ��Ʈ���� ������ ���� Ʈ���� �ִ�.
	if(key < root->key){
		root->left = delete_node(root->left, key);
	} 
	else if(key > root->key){
		root->right = delete_node(root->right ,key);
	}
	//��Ʈ ���� key ���� ���� ���� ������ ���� ���� ���� ���� �ٸ����� ���� ���� ���ö����� ��ȯ�ϴ� ��. 
	else{
		if(root->left == NULL){
			TreeNode * temp = root->right;
			free(root);
			return temp;
		} 
		else if(root -> right == NULL)
		{
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode * temp = min_value_node(root->right);
		
		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		//��� ��ü�� ���� ���� �ƴ� Ű���� �־������� �Ʒ� �۾� �ʿ� 
		//���� ��ȸ�� �İ� ��带 �����Ѵ�. (���� ��ȸ�� ���� ���ʰ� ��������. ������ �ֶ� �ڸ����� ���� ���� ������������ڳ�)
		root->right = delete_node(root->right, key);
		//�׸��� ���� �ٽô� ���� ��尪�� NULL�� �� ��� �� ���� if(root == NULL) return root; �� ������ �ȴ�.	(�ݺ� ��ȸ�� ���� ������) 
	}
	
	return root;//(���⼭�� �� ó���� root ���� ��� Ÿ��Ÿ�� �ö��)
} 

//���� ��ȸ
void inorder(TreeNode *root){
	if(root){
		inorder(root->left); //���� ����Ʈ�� ��ȸ
		printf(" [%d] ", root->key); //��� �湮
		inorder(root->right); //������ ����Ʈ�� ��ȸ 
		//�̰� ��� �ݺ��Ǵ� ���� 
	}
} 
//	 11 | 3 | 4 | 1 | 56 | 5 | 6 | 2 | 98 | 32 | 23 | 
int main(void)
{
	TreeNode * root = NULL;

	
	root = insert_node(root, 11);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 1);
	root = insert_node(root, 56);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 2);
	root = insert_node(root, 98);
	root = insert_node(root, 32);
	root = insert_node(root, 23);
	
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");

	
	return 0;
} 
*/

/*
19.18���� ������������ ���Ľ�Ű�� ����̴�.
���� Ž�� Ʈ���� �̿��Ͽ� �迭�� ����� ���ڵ��� ������������ ���Ľ�Ű�� �Լ��� �ۼ��Ͽ� ����.


#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

//��ȯ���� Ž���Լ� 
TreeNode * search(TreeNode * node, int key)
{
	if(node == NULL){
		return NULL;
	}
	if(key == node->key){
		return node;
	}
	else if(key < node->key){
		return search(node->left, key);
	}
	else{
		return search(node->right, key);
	}
}

TreeNode * new_node(int item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->right = temp->left = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode * node, int key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ
	if(node == NULL){
		return new_node(key);
	} 
	//Ž���� ���з� ���� �� ������ ���ο� ��� ���� ������ �����̴�. NULL �� ���� ��ȯ�� ���� new_node(key) 
	if(key < node->key){
		node->left = insert_node(node->left,key);
	}
	else if(key > node->key){
		node->right = insert_node(node->right, key);
	}
	//����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	
	//���⼭�� �Ű������� root->right�� �ް� �� �� ���� �ܸ� ��带 ã���� ������ 
	while(current->left != NULL){
		current = current->left;
	} 
	
	return current;
}

//���� Ž�� Ʈ���� Ű�� �־����� ����� ��鸣 �����ϰ�
//���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode * delete_node(TreeNode * root, int key)
{
	if(root == NULL){
		return root;
	}	
	
	//���� Ű�� ��Ʈ���� ������ ���� Ʈ���� �ִ�.
	if(key < root->key){
		root->left = delete_node(root->left, key);
	} 
	else if(key > root->key){
		root->right = delete_node(root->right ,key);
	}
	//��Ʈ ���� key ���� ���� ���� ������ ���� ���� ���� ���� �ٸ����� ���� ���� ���ö����� ��ȯ�ϴ� ��. 
	else{
		if(root->left == NULL){
			TreeNode * temp = root->right;
			free(root);
			return temp;
		} 
		else if(root -> right == NULL)
		{
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode * temp = min_value_node(root->right);
		
		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		//��� ��ü�� ���� ���� �ƴ� Ű���� �־������� �Ʒ� �۾� �ʿ� 
		//���� ��ȸ�� �İ� ��带 �����Ѵ�. (���� ��ȸ�� ���� ���ʰ� ��������. ������ �ֶ� �ڸ����� ���� ���� ������������ڳ�)
		root->right = delete_node(root->right, key);
		//�׸��� ���� �ٽô� ���� ��尪�� NULL�� �� ��� �� ���� if(root == NULL) return root; �� ������ �ȴ�.	(�ݺ� ��ȸ�� ���� ������) 
	}
	
	return root;//(���⼭�� �� ó���� root ���� ��� Ÿ��Ÿ�� �ö��)
} 

//���� ��ȸ
void descendant(TreeNode *root){
	if(root){
		descendant(root->right); //������ ����Ʈ�� ��ȸ
		printf(" [%d] ", root->key); //��� �湮
		descendant(root->left); //���� ����Ʈ�� ��ȸ 
		//�̰� ��� �ݺ��Ǵ� ���� 
	}
} 
//	 11 | 3 | 4 | 1 | 56 | 5 | 6 | 2 | 98 | 32 | 23 | 
int main(void)
{
	TreeNode * root = NULL;

	
	root = insert_node(root, 11);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 1);
	root = insert_node(root, 56);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 2);
	root = insert_node(root, 98);
	root = insert_node(root, 32);
	root = insert_node(root, 23);
	
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	descendant(root);
	printf("\n\n");

	
	return 0;
} 
*/ 

/*
//��ȸ ���� Ȱ���� ����Ʈ �ΰ�? 
20. ���� Ž�� Ʈ���� ��� ����� ���� 1�� ������Ű�� �Լ��� �ۼ��Ͽ� ����. 

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

//��ȯ���� Ž���Լ� 
TreeNode * search(TreeNode * node, int key)
{
	if(node == NULL){
		return NULL;
	}
	
	if(key == node->key){
		return node;
	}
	else if(key < node->key){
		return search(node->left, key);
	}
	else{
		return search(node->right, key);
	}
}

TreeNode * new_node(int item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->right = temp->left = NULL;
	return temp;
}

TreeNode * insert_node(TreeNode * node, int key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ
	if(node == NULL){
		return new_node(key);
	} 
	//Ž���� ���з� ���� �� ������ ���ο� ��� ���� ������ �����̴�. NULL �� ���� ��ȯ�� ���� new_node(key) 
	if(key < node->key){
		node->left = insert_node(node->left,key);
	}
	else if(key > node->key){
		node->right = insert_node(node->right, key);
	}
	//����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	
	//���⼭�� �Ű������� root->right�� �ް� �� �� ���� �ܸ� ��带 ã���� ������ 
	while(current->left != NULL){
		current = current->left;
	} 
	
	return current;
}

//���� Ž�� Ʈ���� Ű�� �־����� ����� ��鸣 �����ϰ�
//���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode * delete_node(TreeNode * root, int key)
{
	if(root == NULL){
		return root;
	}	
	
	//���� Ű�� ��Ʈ���� ������ ���� Ʈ���� �ִ�.
	if(key < root->key){
		root->left = delete_node(root->left, key);
	} 
	else if(key > root->key){
		root->right = delete_node(root->right ,key);
	}
	//��Ʈ ���� key ���� ���� ���� ������ ���� ���� ���� ���� �ٸ����� ���� ���� ���ö����� ��ȯ�ϴ� ��. 
	else{
		if(root->left == NULL){
			TreeNode * temp = root->right;
			free(root);
			return temp;
		} 
		else if(root -> right == NULL)
		{
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		
		TreeNode * temp = min_value_node(root->right);
		
		//���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		//��� ��ü�� ���� ���� �ƴ� Ű���� �־������� �Ʒ� �۾� �ʿ� 
		//���� ��ȸ�� �İ� ��带 �����Ѵ�. (���� ��ȸ�� ���� ���ʰ� ��������. ������ �ֶ� �ڸ����� ���� ���� ������������ڳ�)
		root->right = delete_node(root->right, key);
		//�׸��� ���� �ٽô� ���� ��尪�� NULL�� �� ��� �� ���� if(root == NULL) return root; �� ������ �ȴ�.	(�ݺ� ��ȸ�� ���� ������) 
	}
	
	return root;//(���⼭�� �� ó���� root ���� ��� Ÿ��Ÿ�� �ö��)
} 

//���� ��ȸ
void inorder(TreeNode * root)
{
	if(root){
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}
//���� ��ȸ ���ϱ� 
void inorder_plus(TreeNode *root)
{
	if(root){
		inorder_plus(root->left); 
		root->key = root->key + 1;
		inorder_plus(root->right);	
	}
} 
//	 11 | 3 | 4 | 1 | 56 | 5 | 6 | 2 | 98 | 32 | 23 | 
int main(void)
{
	TreeNode * root = NULL;

	
	root = insert_node(root, 11);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 1);
	root = insert_node(root, 56);
	root = insert_node(root, 5);
	root = insert_node(root, 6);
	root = insert_node(root, 2);
	root = insert_node(root, 98);
	root = insert_node(root, 32);
	root = insert_node(root, 23);
	
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	inorder_plus(root);
	inorder(root);
	
	
	return 0;
} 
*/

/*
21.
���� Ž�� Ʈ���� Ȱ���Ͽ� �켱���� ť�� ������ ���� �ִ�. 
�켱���� ť�� �׸���� �켱������ ������ �ְ� �켱������ ���� ū �׸��� ���� �����Ǵ� ť�̴�.
���� Ž��Ʈ������ ���� ū Ž�� ���� ã������ ��� �ؾ� �ϴ°�.?

����: Ʈ���� ���� ������ ���� �����Ѵ�. 
*/

/*
22.
���� Ž�� Ʈ���� ���� ū �뵵�� map(����)�̶�� �ڷᱸ���� �����ϴ� ���̴�.
�������� �츮�� �ܾ����� �����غ��Ҵ�. 
���⼭�� ���� Ž��Ʈ���� �̿��Ͽ� ģ������ ����ó�� �����ϰ� Ž���ϴ� ���α׷��� �ۼ��Ͽ� ����.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_CHAR 100

typedef struct {
	char name[MAX_CHAR];
	char phone[MAX_CHAR];
} element;

typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
} TreeNode;

int compare(element e1, element e2) 
{
	return strcmp(e1.name, e2.name);
}

TreeNode * search(TreeNode * root, element data)
{
	TreeNode * p = root;
	if(p == NULL){
		return NULL;
	}
	
	if( compare(data, p->key) == 0 ) {
		return p;
	}
	else if( compare(data, p->key) < 0 ){
		search(p->left, data);
	}
	else if( compare(data, p->key) > 0 ){
		search(p->right, data);
	}
}

TreeNode * new_node(element item)
{
	TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
	node->key = item;
	node->left = node->right = NULL;
	return node;
}

TreeNode * insert_node(TreeNode * root, element item)
{
	if(root == NULL)
	{
		new_node(item);
	}
	
	if( compare(item, root->key) < 0 ){
		root->left = insert_node(root->left, item);
	}
	else if( compare(item, root->key) > 0 ){
		root->right = insert_node(root->right, item);
	}
	
	return root;
}

TreeNode * min_value_node(TreeNode * root){
	TreeNode *p = root;
	
	//p!=null �̸� ����� null�� ���´�. 
	while( p->left != NULL){
		p = p->left;
	}
	
	return p;
}

TreeNode * delete_node(TreeNode * root, element data)
{
	//���� ������ NULL�� ��ȯ�ؾ� ��ȸ�� ������ �ȴ�. 
	if(root == NULL){
		return root;
	}
	
	if( compare(data, root->key) < 0){
		root->left = delete_node(root->left, data);
	}
	else if( compare(data, root->key) > 0){
		root->right = delete_node(root->right, data);
	}
	else{
		//���� ����Ʈ���� ����� ��� 
		if(root->left == NULL){
			TreeNode * temp = root->right;
			free(root);
			return temp; 
		}
		else if(root->right == NULL){
			TreeNode * temp = root->left;
			free(root);
			return temp;
		}
		//�� ��° ��� : root�� ���� ������ ���� ��� �ش�Ǹ� ���� ���� �ȳ���  
		TreeNode * temp = min_value_node(root->right);
		
		root->key = temp->key;
		//�ߺ��� ���� �ᱹ ������ ��忡�� ���ü� �ۿ� ���� -> ���� Ž�� Ʈ���� Ư���� �����ϰ� / ����Ʈ�� ���� �� 3���� ��츦 �����غ���. 
		root->right = delete_node(root->right, temp->key); 
		
	}
	
	return root; 
}

void display(TreeNode * root)
{
	if(root != NULL){
		printf("(");
		display(root->left);
		printf("ģ���� �̸� : %s\nģ���� ��ȭ��ȣ: %s ", root->key.name, root->key.phone);
		display(root->right);
		printf(")");
	}
}

void info()
{
	printf("����(i), Ž��(s), ����(d): ");
}

int main(void)
{
	char command;
	element e;
	TreeNode * root = NULL;
	TreeNode * tmp;
	do{
		info();
		scanf("%c", &command);
		switch(command){
		case 'i' :
			printf("ģ���� �̸� : \n");
			char name[MAX_CHAR];
			gets(name); 
			printf("%s", name);
//			e.name = name;
			printf("ģ���� ��ȭ��ȣ : ");
			char phone[MAX_CHAR];
			gets(phone);
			printf("%s", phone);
//			insert_node(root, e);
		case 's' :
			display(root);
		}
		
	} while(command != 'q');
	
	
	
	return 0;
}
