/*
//�˰��� 8.9 ���� Ž�� Ʈ�� Ž�� �˰���(��ȯ��)
search (root, key) :
if root == NULL
	then return NULL;
if key == KEY(root) //��Ʈ ����� Ű �� :
	then return root;
	else if key < KEY(root)
		then return search (LEFT(root), key)
		else return search (RIGHT(root), key) 
*/

/*
//���α׷� 8.9 ��ȯ���� Ž���Լ�
TreeNode * search(TreeNode * node, int key)
{
	if(node){
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
*/

/*
//���α׷� 8.10 �ݺ����� Ž���Լ�
TreeNode *search(TreeNode *node, int key)
{
	while(node != NULL){
		if(key == node->key){
			return node;
		}
		else if (key < node ->key){
			node = node->left;
		}
		else{
			node = node->right;
		}
	}	
	return NULL; // Ž�� ������ ��� NULL ��ȯ 
} 
*/

/*
//���α׷� 8.2 ����Ž��Ʈ�� ���� �˰��� 
insert(root, node)  :

if KEY(node) == KEY(root)
	then return;
else if KEY(n) < KEY(root) then
	if LEFT(root) == NULL
		then LEFT(root) <- node;
		else insert(LEFT(root), n); // ���� ���� ��� �ٽ� ��ȯȣ�� 
else
	if RIGHT(root)  == NULL
		then RIGHT(root) <- node;
		else insert(RIGHT(root), n);
*/

/*
//���α׷� 8.11 ����Ʈ�� ���� ���α׷� 
TreeNode * new_node(int item)
{
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if(node == NULL){
		return new_node(key);
	} 
	
	//�׷��� ������ ��ȯ������ Ʈ���� ��������.
	if(key < node->key){
		node->left = inser_node(node->left, key);
	} 
	else if(key > node->key){
		node->right = insert_node(node->right, key);
	}
	
	//����� ��Ʈ �����͸� ��ȯ�Ѵ�.
	return node; 
}
*/

/*
(1) �����Ϸ��� ��尡 �ܸ� ����� ��� 
-1�ܸ� ����� �θ��� ã�Ƽ� ��ũ�� ���´�.
-2��带 �������� �����ߴٸ� �޸� ���� 

(2) �����Ϸ��� ��尡 �ϳ��� ����Ʈ���� ������ �ִ� ��� 
-1 �θ���� ���� ����
-2 �ڽ� ��带 �θ� ���� ���� 

(3) �����Ϸ��� ��尡 �ΰ��� ����Ʈ���� ������ �ִ� ���
 
*/

//���α׷� 8.12 ���� Ž�� Ʈ�������� ���� �Լ� 

//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
//���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
/*
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode * current = node;
	
	//�� ���� ���� ��带 ã���� ������ 
	while(current->left != NULL){
		current = current->left;
	} 
	
	return current;
}

TreeNode * delete_node(TreeNode *root, int key)
{
	if(root == NULL){
		return root;
	}
	//���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ�.
	if(key < root->key){
		root->left = delete_node(root->left, key);
	} 
	//���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ�.
	else if(key > root->key){
		root->right = delete_node(root->right, key);
	} 
	//Ű�� ��Ʈ�� ������ �� ��带 �����ϸ� �� 
	else{
		//ù ��°�� �� ��° ���
		if(root->left == NULL){
			TreeNode *temp = root->right; 
			free(root);
			return temp; // if ���� ������ ����. 
		} 
		else if(root->right == NULL){
			TreeNode *temp = root->left;
			free(root);
			return temp; //if ���� ������ ����. 
		}
		//�� ��° ���(������ ���� Ʈ�� ��带 ����) 
		TreeNode *temp = min_value_node(root->right); 
		
		//���� ��ȸ�� �İ��带 �����Ѵ�.
		root->key = temp->key;
		//���� ��ȸ�� �İ��带 �����Ѵ�. (�����ؿ� ���� �ֶ� ��带 ���� ���� ��ȸ�̱� ������ root ������ ���������� �̵��ؼ� root->right ����) 
		root->right = delete_node(root->right, temp->key); //�ؿ� ��� �޸���ŭ ��� �ٽ� ��ȯ�ؼ� �����. 
	}
	
	return root;
	
} 
*/

//��ü ���α׷� : ���α׷� 8.13 ���� Ž�� Ʈ�� 
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

int main(void)
{
	TreeNode * root = NULL;
	TreeNode * temp = NULL;
	
	root = insert_node(root, 30);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 20);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	
	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	if(search(root, 30) != NULL){
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	}
	else{
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");
	}
	
	return 0;
} 

/*
quiz 1. ������ ���� �Է��Ͽ��� ���� Ž�� Ʈ���� �����ϴ� ��쿡 ��� �˻� Ƚ����?

	    7
1		     9 
    5	        8
 2     6
  3
   4 
��� 2��
Ǯ�� : ��� ����� ��ȯ �ݺ����� ���ؼ� ����� ���� ��������.

quiz 2. ���� ���� Ž�� Ʈ������ �Է��� �������� ������ �����Ͽ� ����.
17 14 26 2 66 28 80 34 ... ������

quiz 3. ���� ���� Ʈ������ 17�� �������� ��� ��� �Ǵ°�? 
26�� root ��尡 �ǰ� 26�� �ڽĳ�尡 ��Ʈ�� ������ ����Ʈ���� �ȴ�.
*/ 

