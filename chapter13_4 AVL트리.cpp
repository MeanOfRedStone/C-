/*���α׷� 13.8 AVLƮ�� ���� #1
#include <stdio.h>
#include <stdlib.h>

//AVL Ʈ�� ��� ����
typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;
*/
 
/*���α׷� 13.9 AVL Ʈ�� ���� #2
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
*/
/*���α׷� 13.10 AVL Ʈ�� ���� #3
int get_height(AVLNode *node)
{
	int height = 0;
	
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height);
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
*/
/*���ο� ��� �߰� �Լ�
//AVL Ʈ���� ���ο� ��� �߰� �Լ�
// ���ο� ��Ʈ�� ��ȯ�Ѵ�.
AVLNode * insert(AVLNode * node, int key)
{
	//���� Ž�� Ʈ���� ��� �߰� ����
	if(node == NULL){
		return (create_node(key);
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
//	-> balance�� ��ȯ ȣ�⿡�� ���ƿ� ������ ��忡�� ���Ѵ�. 
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
*/

//���α׷� 13.11 AVLƮ�� ��ü ���α׷� 
#include <stdio.h>
#include <stdlib.h>
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
//	-> balance�� ��ȯ ȣ�⿡�� ���ƿ� ������ ��忡�� ���Ѵ�. 
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

int main(void)
{
	AVLNode *root = NULL;
	
	//���� Ʈ�� ����
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);
	
	printf("���� ��ȸ ��� \n");
	preorder(root);
	
	return 0;
}

