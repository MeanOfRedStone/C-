/*
1. 이진 탐색 알고리즘의 특징이 아닌 것은?
정답 : (3) 피보나치 수열에 따라 다음에 비교할 대상을 선정하여 검색한다.
-> 순회 중 만난 데이터의 크기와 비교해 다음 대상을 선정한다.
나머지는 이진 탐색 알고리즘의 특징이다.
*/

/*
2. 키 값 28을 가지고 아래의 리스트를 탐색할 때 다음의 탐색 방법에 따른 '탐색 과정'을 그리고 탐색 시에 필요한 '비교 연산 횟수'를 구하여라.
(1) 순차 탐색 
1. 8 =/28이므로 탐색을 계속
2. 11 =/28이므로 탐색을 계속 
3. 12 =/28이므로 탐색을 계속 
4. 15 =/28이므로 탐색을 계속 
5. 16 =/28이므로 탐색을 계속 
6. 19 =/28이므로 탐색을 계속 
7. 20 =/28이므로 탐색을 계속 
8. 23 =/28이므로 탐색을 계속 
9. 25 =/28이므로 탐색을 계속 
10 28 == 28이므로 탐색 중지

총 10번 비교

(2) 이진 탐색
1. 0 - 15 검색 middle = 7 위치의 값 23 < 28 -> 8 - 15 다시 이진 탐색 
2. 8 - 15 검색 middle = 11 위치의 값 31 > 28 -> 8 - 10 다시 이진 탐색 
3. 8 - 10 검색 middle = 9 위치의 값 28 == 28 -> 탐색 종료

총 3번 비교

(3) 보간 탐색 
1. j = (28 - 8) / (40 - 8) * (15 - 0) + 0 = 20 / 32 * 15 = 9.375 
9 위치의 값 28 == 28 -> 탐색 종료

총 1번 비교 
*/

/*
3. AVL 트리에서 회전은 언제 이루어지는가?
정담: (2) 삽입 후에 회전이 이루어진다. 
-> 삽입 후 균형이 깨지면 회전이 이루어진다. 
*/

/*
4. 정렬된 100, 000, 000개의 원소가 있다. 이진 탐색 알고리즘을 사용했을 때 최악의 경우를 대하여 비교 횟수를 구하라. 
마지막까지 이진 탐새을 계속하게 된다면
-> log 2 100,000,000 약 26번의 비교가 이루어진다.
*/

/*
5. 데이터 (60, 50, 20, 80, 90, 70, 55, 10, 40, 35)를 차례대로 삽입하면서 다음과 같은 균형트리를 구축하는 과정을 그림으로 설명하고 이들 3가지의 트리를 사용한 결과를 서로 비교하라. 
(a) 이진탐색트리 
>히프와 잘 구분하자(히프는 크기에 따라 구분 한게 아니라 부모-자식 노드간 관계로 구분) 
>이진 탐색과 잘 구분하자(이진 탐색은 정렬된 배열에서 시행하는 것이다.) 
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
	  
	  
	  
(b) avl 트리 
<1> 60
60

<2> 50
	60
50

<3>20
			60
	50
20
->LL회전
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
->RR 회전

			50
	20				80
				60		90 
				
<6> 70 
				50
	20						80
					60				90 
						70
-> 회전
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
	  
	  
(c) 2-3 트리 
<1> 60
60

<2> 50
50 60

<3> 20

20 50 60
-> 분리
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
-> 분리

	 50 60 80
20	  55 70    90
->분리

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
->분리

		    	60 
	20 50	    		80
10    40	55	 	70    	90 
 
<10> 35
		    	60 
	20 50	    		80
10  35 40	55	 	70    	90 
*/

/*
출제 포인트 
(1)이진 탐색 트리, AVL 트리, 2-3 트리의 개념을 잘 알고 있고 그 과정을 잘 이해하는지 

(2)이진 탐색 트리 이진 탐색 히프 간 헷갈리지 않는지 
 
6. 데이터 (10, 20, 30, 40, 50, 60, 70, 80, 90, 100)
(a) 이진탐색트리 
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
									
(b) AVL 트리 
<1> 10 삽입 
10

<2> 20 삽입 
10
	20
	
<3> 30 삽입 
10
	20
		30
->RR회전

	20
10		30

<4> 40 삽입 
	20
10		30
			40
			
<5> 50 삽입 
	20
10		30
			40
				50
->RR 회전
		
		20
10				40
			30		50 
				
<6> 60 삽입 
		20
10				40
			30		50 
						60
						
->RR 회전 

			40
10						50
	20						60
		30
		
->RR 회전

				40
	20 					50
10		30					60


<7> 70 삽입
				40
	20 					50
10		30					60
								70
								
->RR 회전

				40
	20 					60
10		30			50		70
								
								
								
								
<8> 80 삽입 
				40
	20 					60
10		30			50		70
								80




<9> 90 삽입 
				40
	20 					60
10		30			50		70
								80
						  		 	90
						  		 
						  		 
-> RR 회전 

				40
	20 					60
10		30			50		80
						  70  90
						  
<10> 100 삽입
				40
	20 					60
10		30			50		80
						  70  90
						  		100 
						  		 	
-> RR회전 

				40
	20 						80
10		30			50				90
					  60	  			100 
						70  		

-> RR회전 
				40
	20 						80
10		30			60				90
				  50  70	  			100 
				
				
(c) 2-3 트리
<1> 10 삽입
10

<2> 20 삽입
10 20

<3> 30 삽입

10 20 30

->분리

	20
10 		30

<4> 40 삽입

	20
10 		30 40

<5> 50삽입 
	20
10 		30 40 50

->분리

	20 40
10 	 30  50 
	
		
<6> 60 삽입 
	20 40
10 	 30  50 60

<7> 70 삽입
	20 40
10 	 30  50 60 70

-> 분리 
	20 40 60
10		50	70	

-> 분리
 
		40
	20		60
10		  50  70	

<8> 80 삽입
		40
	20		60
10		  50  70 80

<9> 90 삽입	
		40
	20		60
10		  50  70 80 90

-> 분리 


		40
	20		60 80
10		  50  70 90


<10> 100 삽입
 		40
	20		60 80
10		  50  70 90 100
*/

/*
7. 난수 발생기를 이용하여 n개의 정수를 생성하라. 
이들 정수를 공백 상태의 AVL 트리에 차례대로 넣어서 생성되는 트리의 높이를 측정한다. 
이 실험을 서로 다른 난수들의 집합에 대하여 되풀이하여 평균적인 높이를 계산하라.
이 값을 2[log2(n+1)]와 비교하라. n =100; 500; 1000; 10000, 50000일고 가정하라. 

출제 포인트: 
(1) 이진 트리의 높이에 대한 이해
- 1 : 이진 트리의 노드가 n개일 떄 최소(log2(n+1)) < 높이 < 최대(n) 이다.
  
(2) AVL 트리 개념 이해
- 왼쪽 서브트리 오른쪽 서브트리 높이 차 1이하인 트리를 말한다.

(3) AVL 트리 연산 구현

(4) 기본 코딩 이해 : 난수 발생시킬 수 있는지 

  
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h> 
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
//	-> balance는 순환 호출에서 돌아오면서 계속 구해진다. 밑에서부터 rotate 시키면서 올라간다. 
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

double logB(double x, double base) {
	return log(x)/log(base);
}

int main(void)
{
	
	
	srand(time(NULL));
	
//	printf("랜덤 값 확인 : %d, %d \n", rand(), rand());
	
	//노드 개수 100개인 트리 생성 
	AVLNode *root100_1 = NULL;
	for(int i = 0; i < 5000; i++){
		root100_1 = insert(root100_1, rand());
	}
	
	//노드 개수 100개인 트리 생성 
	AVLNode *root100_2 = NULL;
	for(int i = 0; i < 5000; i++){
		root100_2 = insert(root100_2, rand());
	}
	
	//노드 개수 100개인 트리 생성 
	AVLNode *root100_3 = NULL;
	for(int i = 0; i < 5000; i++){
		root100_3 = insert(root100_3, rand());
	}
	
	
	printf("노드가 100개일 때 높이 평균 : %d\n", (get_height(root100_1) + get_height(root100_2) + get_height(root100_3)) / 3 );
	printf("2[log2(n+1)]의 값: %f ", logB(5001, 2)*2);
	
	return 0;
}*/



/*
8. 이진 탐색 트리는 숫자들을 정렬시키는데 이용이 가능하다.
배열 a[]에 저장된 n개의 정수를 받아서 비어있는 이진 탐색트리에 삽입하고 중위 순회 순서대로 다시 배열에 넣으면 정렬된 숫자를 얻을 수 있다.
이 정렬 방법을 구현하고 이 방법의 시간 복잡도를 삽입 정렬과 히프 정렬과 비교하라.

출제 포인트:
(1) 이진 탐색 트리 정의 이해 및 구현(이진 탐색과 히프와 차이점 구분)  
(2) 삽입 정렬과 히프 정렬의 정의에 대한 이해 
(3) 이진 탐색 트리, 삽입 정렬, 히프 정렬 시간복잡도 구할 수 있는지(연산 과정에 대한 이해 필요) 
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
	int key;
	TreeNode *left, *right;
} TreeNode;

///순환적인 탐색함수 
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
	
	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	
	return 0;
} 

< 시간 복잡도>
0. 트리의 높이
노드의 개수 n, 높이 h
log2(n+1) <= h <= n 
 
1. 이진 탐색 트리 (삽입, 삭제, 탐색)
(1) 최악의 경우
O(n) : 일렬로 배열되는 경우
O(n * n)
(2) 평균적인 경우
O(h) = O(log2(n+1))  : 좌우 서브트리 균형 이룰 때
 O(n * log2(n+1))
2. 히프 정렬
히프트리 전체 높이 거의 log2(n) * 요소의 개수(n)
O( n * log2(n) ) 

3.삽입 정렬 
O(n^2) 

 

/*
9. 탐색키가 정수가 아닌 알파벳으로 되어 있는 경우에 공백 트리에서 시작하여 다음과 같은 순서로 AVL 트리로 삽입될 때, 각 단계에서의 AVL 트리를 그려라.
또 각 단계에서 회전의 유형을 표시하라.

출제 포인트: 
(1) AVL 트리 개념 이해
- 왼쪽 서브트리 오른쪽 서브트리 높이 차 1이하인 트리를 말한다.

(2) 문자열 비교 


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
		  	
-> RL 회전

 	DEC
APR			JULY
		JAN		MAR
		  	
<6> AUG 삽입
  		DEC
APR					JULY 
	AUG			JAN		MAR 
	
<7> OCT 삽입 
  		DEC
APR					JULY 
	AUG			JAN		MAR 
							OCT
							
<8> FEB 삽입
  			DEC
APR						JULY 
	AUG				JAN		MAR 
				FEB				OCT 
				
<9> SEPT 삽입
  			DEC
APR							JULY 
	AUG				JAN				OCT 
				FEB				MAR			SPET 
				
<10> NOV 삽입
  			DEC
APR							JULY 
	AUG				JAN					OCT 
				FEB				MAR				SPET  
									NOV 
 */
