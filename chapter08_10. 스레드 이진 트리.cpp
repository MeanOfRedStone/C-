/*
������ = ���� �ļ��� + ���� ������

���⼭�� ������ = ���� �ļ��� 
// ������ ���� �±� �ʵ� �߰� 
typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
	int is_thread; // ���� ������ ��ũ�� �������̸� TRUE 
}TreeNode;

//���� is_threa True -> rihgt�� ���� �ļ���/ FALSE -> ������ �ڽ��� ����Ű�� ������ 
*/


/*
//������ ���� Ʈ�� ���� ��ȸ ���� 
��� p�� ���� �ļ��ڸ� ��ȯ�ϴ� �Լ� : find_successor
p�� is_trhead�� TRUE�� �Ǿ� ������ �ٷ� ������ �ڽ��� ���� �ļ��ڰ� �ǹǷ� ������ �ڽ��� ��ȯ 
				������  �ڽ��� NULL�̸� �� �̻� �ļ��ڰ� ���ٴ� ���̹Ƿ� NULL�� ��ȯ�Ѵ�.
				
p�� is_thread�� FALSE�� ��� ���� Ʈ���� ���� �ަU ���� �����Ѵ�.
				����, ���� �ڽ��� NULL�� �� ������ ���� ��ũ�� Ÿ�� �̵��Ѵ�.		

TreeNode* find_successor(TreeNode *p)
{
	// q�� p�� ������ ������
	TreeNode *q = p->right;
	//���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if(q == NULL || p->is_thread == True){
		return q;
	}
	
	//���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�	
	while(q->left != NULL){
		q = q->left;
	}
	return q;
} 
*/

/*
thread_inorder : ������ ���� Ʈ������ ���� ��ȸ�� �ϴ� �Լ� 
��ȸ�� ���� ���� ������ ���� -> ���� �ڽ��� NULL�� �� ������ ��ũ Ÿ�� �̵�.
��������, �����͸� ����ϰ� ���� �ļ��ڸ� ã�� �Լ��� ȣ���Ͽ� �ļ��ڰ� NULL �� �ƴϸ� ��� ������ �ݺ��Ѵ�. 

void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	
	q = t;
	while(q->left){		//���� ���� ���� ����. 
		q = q->left;
	}
	
	do{
		printf("%c -> ", q->data); 	// ������ ��� 
		q = find_successor(q); 		// �ļ��� �Լ� ȣ�� 
	}while(q);						// NULL�� �ƴϸ� 
}

*/

//���α׷� 8.8 ������ ���� Ʈ�� ��ȸ ���α׷�
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
	int is_thread;
} TreeNode;

//		G
//	C		F
//A	  B	  D	  
//n1.right = &n3;
//n2.right = &n7;
//n4.right = &n6;
TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode * exp = &n7;

TreeNode* find_successor(TreeNode *p)
{
	// q�� p�� ������ ������
	TreeNode *q = p->right;
	//���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if(q == NULL || p->is_thread == TRUE){
		return q;
	}
	
	//���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�	
	while(q->left != NULL){
		q = q->left;
	}
	return q;
} 

void thread_inorder(TreeNode *t)
{
	TreeNode *q;
	
	q = t;
	while(q->left){		//���� ���� ���� ����. 
		q = q->left;
	}
	
	do{
		printf("%c -> ", q->data); 	// ������ ��� 
		q = find_successor(q); 		// �ļ��� �Լ� ȣ�� 
	}while(q);						// NULL�� �ƴϸ� 
}
/*
thread_inorder(exp);
n1
print : n1->data
q = find_succesor(n1)

find_succesor(n1);
*q = n1->right = n3
return n1->right //n1->right�� ����ų� �ִµ� thread �� ���: ���⼭�� is_trhead =TRUE 

print : n3-> data
q = find_successor(n3)

find_succeossr(n3)
*q = n3->right
q != NULL �̰� is_thread = FALSE ��
���� �׳� �ڽĳ���� ���� ���� ��ȯ 
���� ��� ���̻� �����Ƿ�
return n2

print: n2 ->data
q = find_succeossr(n2)

find_succeossor(n2)
*q = n2->right
q�� �׳� �ڽĳ���̹Ƿ� q�� ���� ���� �ڽ���
q = n4 ��ȯ 
... 
 

*/
int main(void)
{
	//������ ����
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;
	
	//���� ��ȸ
	thread_inorder(exp);
	printf("\n");
	return 0; 
}

/*������ Ʈ�� ��ȸ�� ������ �ϴ� ���� / ������ �����ϱ� ���� �����̳� ���� �Լ��� �� ���� ���� �ؾ��Ѵ�.*/ 
		
