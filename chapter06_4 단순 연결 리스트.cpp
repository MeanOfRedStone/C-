//chapter 6.4 �ܼ� ���� ����Ʈ�� �ڵ带 �ۼ��մϴ�.

//*����� ����
//�ڱ� ���� ����ü : �ڱ� �ڽ��� �����ϴ� �����͸� �����ϴ� ����ü 
typedef int element;
typedef struct{
	element data;
	struct ListNode *link; //���� �����ؾ� ���� ��� ����. 
} ListNode;

//*���� ����Ʈ�� ����
//�������Ʈ�� �Ҿƾ� ��� ��带 ã�� �� �ִ�.
//head �����ϸ� �ϳ��� �ܼ� ���� ����Ʈ ������� ���̶�� �� �� �ִ�.
ListNode *head = NULL;

//*����� ���� 
//���Ḯ��Ʈ�� �ʿ��� ������ ���� �޸� �Ҵ��� �̿��� �������� ����.
//�� ���� �޸𸮰� �ϳ��� ��尡 �ȴ�. 
head = (ListNode *)malloc(sizeof(ListNode));

//���� ������� ��忡 ������ �����ϰ� ��ũ�ʵ� NULL�� �����ϴ� ��
/*
head->data = 10;
head->link = NULL;
*/
 
//����� ����
/*
//�׸��� �� ��° ��� 
ListNode *p;
p = (ListNode *)malloc(sizeof(ListNode)); // head ������ 
p->data = 20;
p->link = NULL;
//head->link�� p�� �����ϸ� ����� 
head->link = p;
