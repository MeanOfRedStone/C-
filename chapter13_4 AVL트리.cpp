/*프로그램 13.8 AVL트리 구현 #1
#include <stdio.h>
#include <stdlib.h>

//AVL 트리 노드 정의
typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;
*/
 
/*프로그램 13.9 AVL 트리 구현 #2
//오른쪽으로 회전시키는 함수
AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode *child = parent->left;
	parent->left = child->right; //위에서 값 전달했으니 NULL값을 넣어주는 것 
	child->right = parent;
	//새로운 루트 노드를 반환
	return child; 
} 

//왼쪽으로 회전시키는 함수
AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	//새로운 루트 반환
	return child; 
} 
*/
/*프로그램 13.10 AVL 트리 구현 #3
int get_height(AVLNode *node)
{
	int height = 0;
	
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height);
	}
	
	return height;
} 

//노드의 균형인수를 반환
int get_balance(AVLNode* node)
{
	if(node == NULL){
		return 0;
	}
	
	return get_height(node->left) - get_height(node->right);
} 
*/
/*새로운 노드 추가 함수
//AVL 트리에 새로운 노드 추가 함수
// 새로운 루트를 반환한다.
AVLNode * insert(AVLNode * node, int key)
{
	//이진 탐색 트리의 노드 추가 수행
	if(node == NULL){
		return (create_node(key);
	}
	
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	else if(key > node->key){
		node->right = insert(node->right, key);
	}
	else{ //동일한 ㅣㅋ는 허용되지 않음 
		return node;
	}
	
	//노드들의 균형인수 재계산-> 노드 삽입할때만 작동한다.(첫 번째 if블록 돌 떄만) 
	int balance = get_balance(node); 
	
	
//	Ll 타입 처리 : 새로운 노드가 왼쪽 자식의 왼쪽에 추가되었으면 LL 타입이다.
//	새로운 노드가 왼쪽 자식의 왼쪽에 추가 되었으며 LL 타입이다. 
//	-> balance는 순환 호출에서 돌아와 시작점 노드에서 구한다. 
//	
//	(1) if 첫번 째 조건: balance가 무너질 경우
//	(2) if 두번 째 조건: 시작한 왼쪽 노드에서 또 왼쪽으로 가는 경우 
	
	if(balance > 1 && key < node->left->key){
		return rotate_right(node);
	}
	
	//RR타입 처리
	if(balance < -1 && key > node->right->key){
		return rotate_left(node);
	} 
	
	//LR 타입 처리
	if(balance > 1 && key > node->left->key){
		node->left = rotate_left(node->left); //마지막 노드는 왼쪽 회전 
		return rotate_right(node); //LL 노드로 바뀐 노드를 다시 오른쪽 외전 시켜줌 -> 이중회전 완료 
	}
	
	//RL 타입 처리
	if(balance < -1 && key < node->right->key){
		node->right =rotate_right(node->right);
		return rotate_left(node);
	} 
	
	return node; //balance 무너지지 않을 경우 노드 반환 
} 
*/

//프로그램 13.11 AVL트리 전체 프로그램 
#include <stdio.h>
#include <stdlib.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

//AVL 트리 노드 정의
typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

//트리의 높이를 반환 
int get_height(AVLNode *node)
{
	int height = 0;
	
	if(node != NULL){
		height = 1 + max(get_height(node->left), get_height(node->right));
	}
	
	return height;
} 

//노드의 균형인수를 반환
int get_balance(AVLNode* node)
{
	if(node == NULL){
		return 0;
	}
	
	return get_height(node->left) - get_height(node->right);
} 

//노드를 동적으로 생성하는 함수
AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode *)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//오른쪽으로 회전시키는 함수
AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode *child = parent->left;
	parent->left = child->right; //위에서 값 전달했으니 NULL값을 넣어주는 것 
	child->right = parent;
	//새로운 루트 노드를 반환
	return child; 
} 

//왼쪽으로 회전시키는 함수
AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	//새로운 루트 반환
	return child; 
} 

//AVL 트리에 새로운 노드 추가 함수
// 새로운 루트를 반환한다.
AVLNode * insert(AVLNode * node, int key)
{
	//이진 탐색 트리의 노드 추가 수행
	if(node == NULL){
		return (create_node(key));
	}
	
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	else if(key > node->key){
		node->right = insert(node->right, key);
	}
	else{ //동일한 ㅣㅋ는 허용되지 않음 
		return node;
	}
	
	//노드들의 균형인수 재계산-> 노드 삽입할때만 작동한다.(첫 번째 if블록 돌 떄만) 
	int balance = get_balance(node); 
	
	
//	Ll 타입 처리 : 새로운 노드가 왼쪽 자식의 왼쪽에 추가되었으면 LL 타입이다.
//	새로운 노드가 왼쪽 자식의 왼쪽에 추가 되었으며 LL 타입이다. 
//	-> balance는 순환 호출에서 돌아와 시작점 노드에서 구한다. 
//	
//	(1) if 첫번 째 조건: balance가 무너질 경우
//	(2) if 두번 째 조건: 시작한 왼쪽 노드에서 또 왼쪽으로 가는 경우 
	
	if(balance > 1 && key < node->left->key){
		return rotate_right(node);
	}
	
	//RR타입 처리
	if(balance < -1 && key > node->right->key){
		return rotate_left(node);
	} 
	
	//LR 타입 처리
	if(balance > 1 && key > node->left->key){
		node->left = rotate_left(node->left); //마지막 노드는 왼쪽 회전 
		return rotate_right(node); //LL 노드로 바뀐 노드를 다시 오른쪽 외전 시켜줌 -> 이중회전 완료 
	}
	
	//RL 타입 처리
	if(balance < -1 && key < node->right->key){
		node->right =rotate_right(node->right);
		return rotate_left(node);
	} 
	
	return node; //balance 무너지지 않을 경우 노드 반환 
} 

//전위 순회 함수
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
	
	//예제 트리 구축
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 29);
	
	printf("전위 순회 결과 \n");
	preorder(root);
	
	return 0;
}

