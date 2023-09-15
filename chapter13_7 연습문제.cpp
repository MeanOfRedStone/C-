/*
1. ���� Ž�� �˰����� Ư¡�� �ƴ� ����?
���� : (3) �Ǻ���ġ ������ ���� ������ ���� ����� �����Ͽ� �˻��Ѵ�.
-> ��ȸ �� ���� �������� ũ��� ���� ���� ����� �����Ѵ�.
�������� ���� Ž�� �˰����� Ư¡�̴�.
*/

/*
2. Ű �� 28�� ������ �Ʒ��� ����Ʈ�� Ž���� �� ������ Ž�� ����� ���� 'Ž�� ����'�� �׸��� Ž�� �ÿ� �ʿ��� '�� ���� Ƚ��'�� ���Ͽ���.
(1) ���� Ž�� 
1. 8 =/28�̹Ƿ� Ž���� ���
2. 11 =/28�̹Ƿ� Ž���� ��� 
3. 12 =/28�̹Ƿ� Ž���� ��� 
4. 15 =/28�̹Ƿ� Ž���� ��� 
5. 16 =/28�̹Ƿ� Ž���� ��� 
6. 19 =/28�̹Ƿ� Ž���� ��� 
7. 20 =/28�̹Ƿ� Ž���� ��� 
8. 23 =/28�̹Ƿ� Ž���� ��� 
9. 25 =/28�̹Ƿ� Ž���� ��� 
10 28 == 28�̹Ƿ� Ž�� ����

�� 10�� ��

(2) ���� Ž��
1. 0 - 15 �˻� middle = 7 ��ġ�� �� 23 < 28 -> 8 - 15 �ٽ� ���� Ž�� 
2. 8 - 15 �˻� middle = 11 ��ġ�� �� 31 > 28 -> 8 - 10 �ٽ� ���� Ž�� 
3. 8 - 10 �˻� middle = 9 ��ġ�� �� 28 == 28 -> Ž�� ����

�� 3�� ��

(3) ���� Ž�� 
1. j = (28 - 8) / (40 - 8) * (15 - 0) + 0 = 20 / 32 * 15 = 9.375 
9 ��ġ�� �� 28 == 28 -> Ž�� ����

�� 1�� �� 
*/

/*
3. AVL Ʈ������ ȸ���� ���� �̷�����°�?
����: (2) ���� �Ŀ� ȸ���� �̷������. 
-> ���� �� ������ ������ ȸ���� �̷������. 
*/

/*
4. ���ĵ� 100, 000, 000���� ���Ұ� �ִ�. ���� Ž�� �˰����� ������� �� �־��� ��츦 ���Ͽ� �� Ƚ���� ���϶�. 
���������� ���� Ž���� ����ϰ� �ȴٸ�
-> log 2 100,000,000 �� 26���� �񱳰� �̷������.
*/

/*
5. ������ (60, 50, 20, 80, 90, 70, 55, 10, 40, 35)�� ���ʴ�� �����ϸ鼭 ������ ���� ����Ʈ���� �����ϴ� ������ �׸����� �����ϰ� �̵� 3������ Ʈ���� ����� ����� ���� ���϶�. 
(a) ����Ž��Ʈ�� 
>������ �� ��������(������ ũ�⿡ ���� ���� �Ѱ� �ƴ϶� �θ�-�ڽ� ��尣 ����� ����) 
>���� Ž���� �� ��������(���� Ž���� ���ĵ� �迭���� �����ϴ� ���̴�.) 
<1> 60
60

<2> 50

	60
50

<3> 20
		60
	50
20

<4> 80
		60
	50		80
20

<5> 90
		60
	50		80
20				90

<6> 70
			60
	50				80
20				70		90

<7> 55
			60
	50				80
20		55		70		90

<8>10
				60
		50				80
	20		55		70		90
10

<9> 40
						60
			50						80
	20				55			70		90
10		40

<10> 35
						60
			50						80
	20				55			70		90
10		40
	  35
	  
	  
	  
(b) avl Ʈ�� 
<1> 60
60

<2> 50
	60
50

<3>20
			60
	50
20
->LLȸ��
	50
20		60

<4> 80
			50
	20				60
						80
						
<5> 90
			50
	20				60
							80
								90
->RR ȸ��

			50
	20				80
				60		90 
				
<6> 70 
				50
	20						80
					60				90 
						70
-> ȸ��
				80
	20						60
		50							90 
								70 
								
<7> 55
				80
	20						60
		50							90 
			55					70 
			
<8> 10
				80
	20						60
10		50							90 
			55					70 
			
<9> 40
				80
	20						60
10			50							90 
		40		55					70 
		
<10> 35
				80
	20						60
10			50							90 
		40		55					70 
	  35
	  
	  
(c) 2-3 Ʈ�� 
<1> 60
60

<2> 50
50 60

<3> 20

20 50 60
-> �и�
	50
20		60 

<4> 80
	50
20		60 80

<5> 90
	50 80
20	 60    90

<6> 70
	50 80
20	60 70   90

<7> 55
	 50 80
20	55 60 70   90
-> �и�

	 50 60 80
20	  55 70    90
->�и�

	    	60 
	50	    		80
20	  	55	 	70    	90 

<8> 10
		    	60 
		50	    		80
  10 20	  	55	 	70    	90 

<9> 40
		    	60 
		50	    		80
10 20 40	  55	 70    	90 
->�и�

		    	60 
	20 50	    		80
10    40	55	 	70    	90 
 
<10> 35
		    	60 
	20 50	    		80
10  35 40	55	 	70    	90 
*/

/*
���� ����Ʈ 
(1)���� Ž�� Ʈ��, AVL Ʈ��, 2-3 Ʈ���� ������ �� �˰� �ְ� �� ������ �� �����ϴ��� 

(2)���� Ž�� Ʈ�� ���� Ž�� ���� �� �򰥸��� �ʴ��� 
 
6. ������ (10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
(a) ����Ž��Ʈ�� 
<1>
10

<2>
	10
		20
		
<3>
10
	20
		30
		
<4>
10
	20
		30
			40
			
<5>
10
	20
		30
			40
				50
				
<6>
10
	20
		30
			40
				50
					60

<7>
10
	20
		30
			40
				50
					60
						70
						
<8>
10
	20
		30
			40
				50
					60
						70
							80
							
<9>
10
	20
		30
			40
				50
					60
						70
							80
								90
								
<10>
10
	20
		30
			40
				50
					60
						70
							80
								90
									100
									
(b) AVL Ʈ�� 
<1> 10 ���� 
10

<2> 20 ���� 
10
	20
	
<3> 30 ���� 
10
	20
		30
->RRȸ��

	20
10		30

<4> 40 ���� 
	20
10		30
			40
			
<5> 50 ���� 
	20
10		30
			40
				50
->RR ȸ��
		
		20
10				40
			30		50 
				
<6> 60 ���� 
		20
10				40
			30		50 
						60
						
->RR ȸ�� 

			40
10						50
	20						60
		30
		
->RR ȸ��

				40
	20 					50
10		30					60


<7> 70 ����
				40
	20 					50
10		30					60
								70
								
->RR ȸ��

				40
	20 					60
10		30			50		70
								
								
								
								
<8> 80 ���� 
				40
	20 					60
10		30			50		70
								80




<9> 90 ���� 
				40
	20 					60
10		30			50		70
								80
						  		 	90
						  		 
						  		 
-> RR ȸ�� 

				40
	20 					60
10		30			50		80
						  70  90
						  
<10> 100 ����
				40
	20 					60
10		30			50		80
						  70  90
						  		100 
						  		 	
-> RRȸ�� 

				40
	20 						80
10		30			50				90
					  60	  			100 
						70  		

-> RRȸ�� 
				40
	20 						80
10		30			60				90
				  50  70	  			100 
				
				
(c) 2-3 Ʈ��
<1> 10 ����
10

<2> 20 ����
10 20

<3> 30 ����

10 20 30

->�и�

	20
10 		30

<4> 40 ����

	20
10 		30 40

<5> 50���� 
	20
10 		30 40 50

->�и�

	20 40
10 	 30  50 
	
		
<6> 60 ���� 
	20 40
10 	 30  50 60

<7> 70 ����
	20 40
10 	 30  50 60 70

-> �и� 
	20 40 60
10		50	70	

-> �и�
 
		40
	20		60
10		  50  70	

<8> 80 ����
		40
	20		60
10		  50  70 80

<9> 90 ����	
		40
	20		60
10		  50  70 80 90

-> �и� 


		40
	20		60 80
10		  50  70 90


<10> 100 ����
 		40
	20		60 80
10		  50  70 90 100
*/

/*
7. ���� �߻��⸦ �̿��Ͽ� n���� ������ �����϶�. 
�̵� ������ ���� ������ AVL Ʈ���� ���ʴ�� �־ �����Ǵ� Ʈ���� ���̸� �����Ѵ�. 
�� ������ ���� �ٸ� �������� ���տ� ���Ͽ� ��Ǯ���Ͽ� ������� ���̸� ����϶�.
�� ���� 2[log2(n+1)]�� ���϶�. n =100; 500; 1000; 10000, 50000�ϰ� �����϶�. 

���� ����Ʈ: 
(1) ���� Ʈ���� ���̿� ���� ����
- 1 : ���� Ʈ���� ��尡 n���� �� �ּ�(log2(n+1)) < ���� < �ִ�(n) �̴�.
  
(2) AVL Ʈ�� ���� ����
- ���� ����Ʈ�� ������ ����Ʈ�� ���� �� 1������ Ʈ���� ���Ѵ�.

(3) AVL Ʈ�� ���� ����

(4) �⺻ �ڵ� ���� : ���� �߻���ų �� �ִ��� 

  
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 
#define max(a,b)  (((a) > (b)) ? (a) : (b))

//AVL Ʈ�� ��� ����
typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

//Ʈ���� ���̸� ��ȯ 
int get_height(AVLNode *node)
{
	int height = 0;
	
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	
	return height;
} 

//����� �����μ��� ��ȯ
int get_balance(AVLNode* node)
{
	if(node == NULL){
		return 0;
	}
	
	return get_height(node->left) - get_height(node->right);
} 

//��带 �������� �����ϴ� �Լ�
AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode *)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//���������� ȸ����Ű�� �Լ�
AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode *child = parent->left;
	parent->left = child->right; //������ �� ���������� NULL���� �־��ִ� �� 
	child->right = parent;
	//���ο� ��Ʈ ��带 ��ȯ
	return child; 
} 

//�������� ȸ����Ű�� �Լ�
AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	//���ο� ��Ʈ ��ȯ
	return child; 
} 

//AVL Ʈ���� ���ο� ��� �߰� �Լ�
// ���ο� ��Ʈ�� ��ȯ�Ѵ�.
AVLNode * insert(AVLNode * node, int key)
{
	//���� Ž�� Ʈ���� ��� �߰� ����
	if(node == NULL){
		return (create_node(key));
	}
	
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	else if(key > node->key){
		node->right = insert(node->right, key);
	}
	else{ //������ �Ӥ��� ������ ���� 
		return node;
	}
	
	//������ �����μ� ����-> ��� �����Ҷ��� �۵��Ѵ�.(ù ��° if��� �� ����) 
	int balance = get_balance(node); 
	
	
//	Ll Ÿ�� ó�� : ���ο� ��尡 ���� �ڽ��� ���ʿ� �߰��Ǿ����� LL Ÿ���̴�.
//	���ο� ��尡 ���� �ڽ��� ���ʿ� �߰� �Ǿ����� LL Ÿ���̴�. 
//	-> balance�� ��ȯ ȣ�⿡�� ���ƿ��鼭 ��� ��������. �ؿ������� rotate ��Ű�鼭 �ö󰣴�. 
//	
//	(1) if ù�� ° ����: balance�� ������ ���
//	(2) if �ι� ° ����: ������ ���� ��忡�� �� �������� ���� ��� 
	
	if(balance > 1 && key < node->left->key){
		return rotate_right(node);
	}
	
	//RRŸ�� ó��
	if(balance < -1 && key > node->right->key){
		return rotate_left(node);
	} 
	
	//LR Ÿ�� ó��
	if(balance > 1 && key > node->left->key){
		node->left = rotate_left(node->left); //������ ���� ���� ȸ�� 
		return rotate_right(node); //LL ���� �ٲ� ��带 �ٽ� ������ ���� ������ -> ����ȸ�� �Ϸ� 
	}
	
	//RL Ÿ�� ó��
	if(balance < -1 && key < node->right->key){
		node->right =rotate_right(node->right);
		return rotate_left(node);
	} 
	
	return node; //balance �������� ���� ��� ��� ��ȯ 
} 

//���� ��ȸ �Լ�
void preorder(AVLNode *root)
{
	if(root != NULL){
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
} 

double logB(double x, double base) {
	return log(x)/log(base);
}

int main(void)
{
	
	
	srand(time(NULL));
	
//	printf("���� �� Ȯ�� : %d, %d \n", rand(), rand());
	
	//��� ���� 100���� Ʈ�� ���� 
	AVLNode *root100_1 = NULL;
	for(int i = 0; i < 5000; i++){
		root100_1 = insert(root100_1, rand());
	}
	
	//��� ���� 100���� Ʈ�� ���� 
	AVLNode *root100_2 = NULL;
	for(int i = 0; i < 5000; i++){
		root100_2 = insert(root100_2, rand());
	}
	
	//��� ���� 100���� Ʈ�� ���� 
	AVLNode *root100_3 = NULL;
	for(int i = 0; i < 5000; i++){
		root100_3 = insert(root100_3, rand());
	}
	
	
	printf("��尡 100���� �� ���� ��� : %d\n", (get_height(root100_1) + get_height(root100_2) + get_height(root100_3)) / 3 );
	printf("2[log2(n+1)]�� ��: %f ", logB(5001, 2)*2);
	
	return 0;
}*/



/*
8. ���� Ž�� Ʈ���� ���ڵ��� ���Ľ�Ű�µ� �̿��� �����ϴ�.
�迭 a[]�� ����� n���� ������ �޾Ƽ� ����ִ� ���� Ž��Ʈ���� �����ϰ� ���� ��ȸ ������� �ٽ� �迭�� ������ ���ĵ� ���ڸ� ���� �� �ִ�.
�� ���� ����� �����ϰ� �� ����� �ð� ���⵵�� ���� ���İ� ���� ���İ� ���϶�.

���� ����Ʈ:
(1) ���� Ž�� Ʈ�� ���� ���� �� ����(���� Ž���� ������ ������ ����)  
(2) ���� ���İ� ���� ������ ���ǿ� ���� ���� 
(3) ���� Ž�� Ʈ��, ���� ����, ���� ���� �ð����⵵ ���� �� �ִ���(���� ������ ���� ���� �ʿ�) 
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
	int key;
	TreeNode *left, *right;
} TreeNode;

///��ȯ���� Ž���Լ� 
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

#define SIZE 10
int list[SIZE];

int main(void)
{
	TreeNode * root = NULL;
	
	
	srand(time(NULL));
	
	int i, n = SIZE;
	
	for(i = 0; i < n; i++){
		list[i] = rand();
	}
	
	for(i = 0; i < n; i++){
		root = insert_node(root, list[i]);
	}
	
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	
	return 0;
} 

< �ð� ���⵵>
0. Ʈ���� ����
����� ���� n, ���� h
log2(n+1) <= h <= n 
 
1. ���� Ž�� Ʈ�� (����, ����, Ž��)
(1) �־��� ���
O(n) : �Ϸķ� �迭�Ǵ� ���
O(n * n)
(2) ������� ���
O(h) = O(log2(n+1))  : �¿� ����Ʈ�� ���� �̷� ��
 O(n * log2(n+1))
2. ���� ����
����Ʈ�� ��ü ���� ���� log2(n) * ����� ����(n)
O( n * log2(n) ) 

3.���� ���� 
O(n^2) 

 

/*
9. Ž��Ű�� ������ �ƴ� ���ĺ����� �Ǿ� �ִ� ��쿡 ���� Ʈ������ �����Ͽ� ������ ���� ������ AVL Ʈ���� ���Ե� ��, �� �ܰ迡���� AVL Ʈ���� �׷���.
�� �� �ܰ迡�� ȸ���� ������ ǥ���϶�.

���� ����Ʈ: 
(1) AVL Ʈ�� ���� ����
- ���� ����Ʈ�� ������ ����Ʈ�� ���� �� 1������ Ʈ���� ���Ѵ�.

(2) ���ڿ� �� 


<1>
DEC

<2>
DEC
	JAN
	
<3>
	DEC
APR		JAN
 
<4>
	DEC
APR		JAN
			MAR
			
<5>
	DEC
APR		JAN
				MAR
		  	JULY	
		  	
-> RL ȸ��

 	DEC
APR			JULY
		JAN		MAR
		  	
<6> AUG ����
  		DEC
APR					JULY 
	AUG			JAN		MAR 
	
<7> OCT ���� 
  		DEC
APR					JULY 
	AUG			JAN		MAR 
							OCT
							
<8> FEB ����
  			DEC
APR						JULY 
	AUG				JAN		MAR 
				FEB				OCT 
				
<9> SEPT ����
  			DEC
APR							JULY 
	AUG				JAN				OCT 
				FEB				MAR			SPET 
				
<10> NOV ����
  			DEC
APR							JULY 
	AUG				JAN					OCT 
				FEB				MAR				SPET  
									NOV 
 */
