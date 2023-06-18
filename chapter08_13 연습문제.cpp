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

13. 이진 트리의 서브트리 높이가 최대 1차이나는 트리를 "균형 트리(balanced tree)"라고 한다.
주어진 이진 트리가 균형 트리인지를 검사하는 함수 isBalanced()를 작성하고 테스트하라.
*/
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
