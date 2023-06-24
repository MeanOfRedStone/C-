/*연습문제*/
/*
1. 다음 트리에 대한 중위 순회 결과는?
답 : D -> B -> A -> E -> C -> F (4번) 



2. 다음 트리를 전위 순회로 운행할 경우 다섯 번째로 탐색되는 것은?
A B D C E
E (2번)



3. 다음 그림과 같은 지니트리를 후위 순회한 결과는?
AB/ ... (4)



4. 다음 트리에서 단말 노드 수는?
D , G, H, F 4개 (3번)


5. 다음 그림에서 트리의 차수는?
답  : (1) 3

트리의 차수: 노드의 차수 중에서 가장 큰 값 



6. Y = A * B + C / D
답: (3)
 


7. 이진 트리에서 높이가 5일 때 이 트리는 최대 몇 개의 노드를 가질 수 있나.
높이 5
최대 노드의 수 : 2^5 - 1 = 31개 
답 : (4) 



8. NULL 포인터를 트리의 순회에 이용하는 트리를 무엇이라 하는가? 
(3) 스레드 이진 트리(threaded binary tree) 
*/

/*
9.
*/

/*
10. 다음의 이진트리에 대하여 다음 질문에 답하여라.
(1)위의 트리를 1차원 배열로 표현하시오.
NULL - 6 - 4 - 9 - 2 - 5 - 7 - 10 - 1 - 3 - NULL - NULL - NULL - NULL - 8 - 11

(2) 위의 트리를 전위 순회한 결과를 쓰시오.
6 - 4 - 2 - 1 - 3 - 5 - 9 - 7 - 10 - 8 - 11

(3) 위의 트리를 후위 순회한 결과를 쓰시오.
1 - 3 - 2 - 5 - 4 - 7 - 8 - 11 - 10 - 9 - 6

(4) 위의 트리를 중위 순회한 결과를 쓰시오.
1 - 2 - 3 - 4 - 5 - 6 - 7 - 9 - 8 - 10 - 11

(5) 위의 트리를 레벨 순회한 결과를 쓰시오.
6 - 4 - 9 - 2 - 5 - 7 - 10 - 1 - 3 - 8 - 11

(6) 위의 트리는 이진 탐색 트리인가? 그 이유는?
이진 탐색 트리가 아니다.
이진 탐색트리 조건 중 루트 노드의 오른쪽 서브트리는 루트보다 커야하는 조건이 있다.
하지만 8은 루트인 9보다 작은데 오른쪽에 있기 때문에  이 조건을 위배한다.
따라서 이진 탐색 트리가 아니다.



11. 다음 순서로 자료가 입력되었다고 가정하여 이진 탐색 트리를 생성하라.
(1) 생성된 이진 탐색 트리를 그리시오
  		11
  	6		19
  4  8	  17   43 
   5  10	 31	49
(2) 여기서 11을 삭제하면 어떻게 변경되는가?
->17이 루트 노드로 온다.
(3) 여기에 12를 추가하면 어떻게 변경되는가?
->17의 왼쪽 노드로 12가 추가됨
(4) 생성된 이진탐색트리에서 8을 탐색할 때 거치는 노드를 나열하시오
11 -> 6
(5) 생성된 이진탐색트리를 1차원 배열을 이용하여 저장하여 보시오. 저장된 결과를 그리시오.
-> 11 | 6 | 19 | 4 | 8 | 17 | 43 | NULL | 5 | NULL | 10 | NULL | NULL | 31 | 49 |
 
*/ 

/*
12. 다음과 같은 함수가 아래에 표시된 이진트리의 루트 노드에 대해 호출된다고 하자.
함수가 반환하는 값은 무엇인가?
3 | 5 | 1 | 4 | 2 | 8 | 6

->정답: 말단노드부터 최대값을 반영한다. 따라서 8
*/
/*
13. 이진 트리의 서브트리 높이가 최대 1차이나는 트리를 "균형 트리(balanced tree)"라고 한다.
주어진 이진 트리가 균형 트리인지를 검사하는 함수 isBalanced()를 작성하고 테스트하라.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>


#define max(a,b)  (((a) > (b)) ? (a) : (b))


typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

//순회 출력처럼 하면 cnt가 안더해진다. 
int inorder_cnt(TreeNode *root)
{
	int cnt = 0;
	if(root != NULL)
	{
		cnt = 1 + inorder_cnt(root->left) + inorder_cnt(root->right);
	}
	return cnt;
}

//자식노드로 한 레벨 낮아질때마다 높이를 추가해준다. 
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
//	printf("왼쪽 서브트리의 높이 : %d", left_h);
	
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
		printf("균형트리입니다.");
	}
	else{
		printf("균형트리가 아닙니다.");
	}
	
	return 0;
}
*/

/*
14. 주어진 이진트리에서 노드가 가지고 있는 값의 합을 계산하는 프로그램을 작성해보자. 

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
		printf("더해지는 값 : %d\n", root->data);
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
	
	printf("총합 : %d", inorder_sum(n1));
	

	return 0;
}
*/

/*
15. 주어진 이진트리에서 노드가 가지고 있는 값이 주어진 value보다 작으면 노드의 값을 출력하는 프로그램을 작성해보자. 

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
			printf("조건 만족 : %d\n", root->data);
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
	printf("조건 value : %d\n", value);
	inorder_condition(n1, value);
	
	

	return 0;
}
*/

/*
16. 주어진 이진 트리에서 자식이 하나만 있는 노드의 개수를 반환하는 함수를 작성하라. 

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

int odd_leafNode_count(TreeNode * root)
{
	//순환 호출 계속하며 나오는 값을 더하기 위해서는 순환 호출 자체를 더하기 형식으로 해야 반환값이 저장됨 
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
	
	printf("자식이 하나만 있는 노드의 개수 : %d", odd_leafNode_count(n1));
	
	

	return 0;
}
*/

/*
17. 일반 이진 트리에서 최대값과 최소값을 탐색하기 위한 함수를 작성하라. 이진 탐색 트리가 아니다.

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;


//순환반복은 마지막까지 간 것을 고려해서 계산해야한다. 여기서는 중위 후위 전위 이런 건 아닌 듯? 
int max_find(TreeNode * root)
{
	int max = -9999;
	//HINT : 순환 호출을 이용하라 
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
//		printf("debug : 노드%d 동작최대값 : %d\n", root->data, max);
	}
	
	return max;
} 

int min_find(TreeNode * root)
{
	int min = 9999;
	//HINT : 순환 호출을 이용하라 
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
//		printf("debug : 노드%d 동작최대값 : %d\n", root->data, max);
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
	
	printf("최대값 : %d 최솟값: %d \n", max_find(n1), min_find(n1));
	
	

	return 0;
}
*/

/*
18. 숫자들이 들어 있는 이진 탐색 트리를 중위 순회하면 정렬된 숫자가 얻어진다.
이를 이용하여 다음 배열에 들어있는 숫자들을 정렬시키는 함수를 작성하여 보라.
배열에 들어 있는 숫자들을 이진 탐색 트리에 추가한 후에 트리를 중위 순회하면서 숫자들을 출력한다.
단 숫자들은 중복되지 않는다고 가정하자.
idx: 0 											 10
	 11 | 3 | 4 | 1 | 56 | 5 | 6 | 2 | 98 | 32 | 23 | 

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
	
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");

	
	return 0;
} 
*/

/*
19.18번은 오름차순으로 정렬시키는 경우이다.
이진 탐색 트리를 이용하여 배열에 저장된 숫자들을 내림차순으로 정렬시키는 함수를 작성하여 보라.


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
void descendant(TreeNode *root){
	if(root){
		descendant(root->right); //오른쪽 서브트리 순회
		printf(" [%d] ", root->key); //노드 방문
		descendant(root->left); //왼쪽 서브트리 순회 
		//이게 계속 반복되는 거임 
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
	
	printf("이진 탐색 트리 중위 순회 결과 \n");
	descendant(root);
	printf("\n\n");

	
	return 0;
} 
*/ 

/*
//순회 개념 활용이 포인트 인가? 
20. 이진 탐색 트리의 모든 노드의 값을 1씩 증가시키는 함수를 작성하여 보라. 

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
void inorder(TreeNode * root)
{
	if(root){
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}
//중위 순회 더하기 
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
	
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	inorder_plus(root);
	inorder(root);
	
	
	return 0;
} 
*/

/*
21.
이진 탐색 트리를 활용하여 우선순위 큐를 구현할 수도 있다. 
우선순위 큐란 항목들이 우선순위를 가지고 있고 우선순위가 가장 큰 항목이 먼저 삭제되는 큐이다.
이진 탐색트리에서 가장 큰 탐색 값을 찾으려면 어떻게 해야 하는가.?

정답: 트리의 가장 오른쪽 노드로 가야한다. 
*/

/*
22.
이진 탐색 트리의 가장 큰 용도가 map(사전)이라는 자료구조를 구현하는 것이다.
본문에서 우리는 단어장을 구현해보았다. 
여기서는 이진 탐색트리를 이용하여 친구들의 연락처를 저장하고 탐색하는 프로그램을 작성하여 보자.
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
	
	//p!=null 이면 결론이 null로 나온다. 
	while( p->left != NULL){
		p = p->left;
	}
	
	return p;
}

TreeNode * delete_node(TreeNode * root, element data)
{
	//말단 다음에 NULL을 반환해야 순회가 끝나게 된다. 
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
		//왼쪽 서브트리가 비었을 경우 
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
		//세 번째 경우 : root가 없기 때문에 위의 경웨 해당되면 밑의 값은 안나옴  
		TreeNode * temp = min_value_node(root->right);
		
		root->key = temp->key;
		//중복된 값은 결국 오른쪽 노드에서 나올수 밖에 없음 -> 이진 탐색 트리의 특성을 생각하고 / 이진트리 삭제 시 3가지 경우를 생각해보자. 
		root->right = delete_node(root->right, temp->key); 
		
	}
	
	return root; 
}

void display(TreeNode * root)
{
	if(root != NULL){
		printf("(");
		display(root->left);
		printf("친구의 이름 : %s\n친구의 전화번호: %s ", root->key.name, root->key.phone);
		display(root->right);
		printf(")");
	}
}

void info()
{
	printf("삽입(i), 탐색(s), 삭제(d): ");
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
			printf("친구의 이름 : \n");
			char name[MAX_CHAR];
			gets(name); 
			printf("%s", name);
//			e.name = name;
			printf("친구의 전화번호 : ");
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
