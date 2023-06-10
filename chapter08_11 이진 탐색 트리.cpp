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

//프로그램 8.12 이진 탐색 트리에서의 삭제 함수 

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
//새로운 루트 노드를 반환한다.
/*
TreeNode* min_value_node(TreeNode* node)
{
	TreeNode * current = node;
	
	//맨 왼쪽 난말 노드를 찾으로 내려감 
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
	//만약 키가 루트보다 작으면 왼쪽 서브 트리에 있다.
	if(key < root->key){
		root->left = delete_node(root->left, key);
	} 
	//만약 키가 루트보다 크면 오른쪽 서브 트리에 있다.
	else if(key > root->key){
		root->right = delete_node(root->right, key);
	} 
	//키가 루트와 같으면 이 노드를 삭제하면 됨 
	else{
		//첫 번째나 두 번째 경우
		if(root->left == NULL){
			TreeNode *temp = root->right; 
			free(root);
			return temp; // if 구문 끝나서 붙임. 
		} 
		else if(root->right == NULL){
			TreeNode *temp = root->left;
			free(root);
			return temp; //if 구문 끝나고 붙임. 
		}
		//세 번째 경우(오른쪽 서브 트리 노드를 붙임) 
		TreeNode *temp = min_value_node(root->right); 
		
		//중위 순회시 후계노드를 복사한다.
		root->key = temp->key;
		//중위 순회시 후계노드를 삭제한다. (복사해온 원래 있떤 노드를 삭제 중위 순회이기 떄문에 root 다음은 오른쪽으로 이동해서 root->right 제거) 
		root->right = delete_node(root->right, temp->key); //밑에 노드 달린만큼 계속 다시 순환해서 지운다. 
	}
	
	return root;
	
} 
*/

//전체 프로그램 : 프로그램 8.13 이진 탐색 트리 
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode{
	element key;
	struct TreeNode *left, *right;
}TreeNode;

//순환적인 탐색함수 
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
	//트리가 공백이면 새로운 노드를 반환
	if(node == NULL){
		return new_node(key);
	} 
	//탐색이 실패로 끝난 그 지점이 새로운 노드 값이 들어오는 지점이다. NULL 인 곳은 순환에 의해 new_node(key) 
	if(key < node->key){
		node->left = insert_node(node->left,key);
	}
	else if(key > node->key){
		node->right = insert_node(node->right, key);
	}
	//변경된 루트 포인터를 반환한다. 
	return node;
}

TreeNode * min_value_node(TreeNode * node)
{
	TreeNode * current = node;
	
	//여기서는 매개변수로 root->right을 받고 그 맨 왼쪽 단말 노드를 찾으로 내려감 
	while(current->left != NULL){
		current = current->left;
	} 
	
	return current;
}

//이진 탐색 트리와 키가 주어지면 저장된 노들르 삭제하고
//새로운 루트 노드를 반환한다.
TreeNode * delete_node(TreeNode * root, int key)
{
	if(root == NULL){
		return root;
	}	
	
	//만약 키가 루트보다 작으면 왼쪽 트리에 있다.
	if(key < root->key){
		root->left = delete_node(root->left, key);
	} 
	else if(key > root->key){
		root->right = delete_node(root->right ,key);
	}
	//루트 노드와 key 값이 같을 경우는 삭제가 들어가는 거임 위의 값이 다른경우는 같은 값이 나올때까지 순환하는 것. 
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
		
		//중위 순회시 후계 노드를 복사한다.
		root->key = temp->key;
		//노드 자체를 때온 것이 아닌 키값만 넣어줬으니 아래 작업 필요 
		//중위 순회시 후계 노드를 삭제한다. (중위 순회는 다음 차례가 오른쪽임. 기존에 있떤 자리에서 같은 값을 제거해줘야하자너)
		root->right = delete_node(root->right, key);
		//그리고 이제 다시는 남은 노드값이 NULL이 될 경우 맨 앞의 if(root == NULL) return root; 로 마무리 된다.	(반복 순회의 제일 마지막) 
	}
	
	return root;//(여기서는 맨 처음의 root 까지 계속 타고타고 올라옴)
} 

//중위 순회
void inorder(TreeNode *root){
	if(root){
		inorder(root->left); //왼쪽 서브트리 순회
		printf(" [%d] ", root->key); //노드 방문
		inorder(root->right); //오른쪽 서브트리 순회 
		//이게 계속 반복되는 거임 
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
	
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if(search(root, 30) != NULL){
		printf("이진 탐색 트리에서 30을 발견함 \n");
	}
	else{
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	}
	
	return 0;
} 

/*
quiz 1. 다음과 같이 입력하여서 이진 탐색 트리를 구성하는 경우에 평균 검색 횟수는?

	    7
1		     9 
    5	        8
 2     6
  3
   4 
평균 2번
풀이 : 모든 노드의 순환 반복수를 더해서 노드의 수로 나누었다.

quiz 2. 다음 이진 탐색 트리에서 입력한 데이터의 순서를 추측하여 보라.
17 14 26 2 66 28 80 34 ... 여러개

quiz 3. 위의 이진 트리에서 17을 삭제했을 경우 어떻게 되는가? 
26이 root 노드가 되고 26의 자식노드가 루트의 오른쪽 서브트리가 된다.
*/ 

