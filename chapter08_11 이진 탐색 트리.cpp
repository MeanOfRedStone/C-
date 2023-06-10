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
