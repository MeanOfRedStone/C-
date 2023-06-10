/*
//알고리즘 8.9 이진 탐색 트리 탐색 알고리즘(순환적)
search (root, key) :
if root == NULL
	then return NULL;
if key == KEY(root) //루트 노드의 키 값 :
	then return root;
	else if key < KEY(root)
		then return search (LEFT(root), key)
		else return search (RIGHT(root), key) 
*/

/*
//프로그램 8.9 순환적인 탐색함수
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
//프로그램 8.10 반복적인 탐색함수
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
	return NULL; // 탐색 실패할 경우 NULL 반환 
} 
*/

/*
//프로그램 8.2 이진탐색트리 삽입 알고리즘 
insert(root, node)  :

if KEY(node) == KEY(root)
	then return;
else if KEY(n) < KEY(root) then
	if LEFT(root) == NULL
		then LEFT(root) <- node;
		else insert(LEFT(root), n); // 값이 있을 경우 다시 순환호출 
else
	if RIGHT(root)  == NULL
		then RIGHT(root) <- node;
		else insert(RIGHT(root), n);
*/

/*
//프로그램 8.11 이진트리 삽입 프로그램 
TreeNode * new_node(int item)
{
	TreeNode *temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	//트리가 공백이면 새로운 노드를 반환한다.
	if(node == NULL){
		return new_node(key);
	} 
	
	//그렇지 않으면 순환적으로 트리를 내려간다.
	if(key < node->key){
		node->left = inser_node(node->left, key);
	} 
	else if(key > node->key){
		node->right = insert_node(node->right, key);
	}
	
	//변경된 루트 포인터를 반환한다.
	return node; 
}
*/

/*
(1) 삭제하려는 노드가 단말 노드일 경우 
-1단말 노드의 부모노드 찾아서 링크를 끊는다.
-2노드를 동적으로 생성했다면 메모리 해제 

(2) 삭제하려는 노드가 하나의 서브트리만 가지고 있는 경우 
-1 부모노드와 연결 끊고
-2 자식 노드를 부모 노드와 연결 

(3) 삭제하려는 노드가 두개의 서브트리를 가지고 있는 경우
 
*/
