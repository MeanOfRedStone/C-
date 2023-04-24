//chapter 6. 2 �迭�� ������ ����Ʈ�� �ڵ带 �ۼ��մϴ�.

//*����Ʈ�� ����
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 //����Ʈ�� �ִ� ũ��

typedef int element; //�׸��� ����
typedef struct{
	element array[MAX_LIST_SIZE]; //�迭�� ����
	int size; // ���� ����Ʈ�� ����� �׸���� ���� 
} ArrayListType;


//*���ʿ��� : ��� ������ ����ü �����ͷ� �ٵ��. �����ͷ� �޴� ������
//�Լ� �ȿ��� ����ü�� ������ �ʿ䵵 �ֱ� �����̴�. 
//����ü�� ��ȭ��ų �� ������ ��� ���ϸ� ���纻�� ���޵Ǿ� ���� �Ұ�.

//���� ó�� �Լ�
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType *L)
{
	L->size = 0;
} 

//����Ʈ ���� Ȯ�� �Լ� 
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

//����Ʈ ��ȭ Ȯ�� �Լ�
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE; //����, ���� ť�� �ٸ��� �����Ͱ� ���� �� ��ġ 0�̴�. 
}

//pos ��� �� ��ȯ 
element get_entry(ArrayListType *L, int pos)
{
	if(pos < 0 || pos >= L->size)
	{
		error("��ġ ����");
	}
	else
	{
		return L->array[pos];
	}
}

//����Ʈ ���
void print_list(ArrayListType *L)
{
	int i;
	for(i = 0; i < L->size; i++)
	{
		printf("%d->",L->array[i]);
	}
	printf("\n"); 
} 

//*�׸� �߰� ����
void insert_last(ArrayListType *L, element item)
{
	if(L->size >= MAX_LIST_SIZE)
	{
		error("����Ʈ �����÷ο�"); 
	}
	else
	{
		L->array[L->size++] = item;
	} 
} 

//pos ��ġ�� ���ο� �׸� �߰��� ���
void insert(ArrayListType *L, int pos, element item)
{
	if(!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for(int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

//*�׸� ���� ���� 
element delete_list(ArrayListType *L, int pos)
{
	element item;
	
	if(pos < 0 || pos >= L->size) //L->size�� ������ ��ġ�ϱ�
	{
		error("��ġ ����");	
	}
	else
	{
		item = L->array[pos];
		for(int i = pos; i<(L->size- 1); i++)
		{
			L->array[i] = L->array[i+1]; // �� ������ ��ġ�� ������ ���� ���� �����ϱ� 
		}
		L->size--;
		return item; 
	} 
}

void replace(ArrayListType *L, int pos, element item)
{
	if(pos < 0 || pos >= L->size)
	{
		error("��ġ ����");
	}
	else
	{
		L->array[pos] = item;
	} 
}

int get_length(ArrayListType *L)
{
	return L->size;
}

void insert_first(ArrayListType *L, element item)
{
	if(!is_empty(L))
	{
		for(int i = L->size; i > 0; i--)
		{
			L->array[i] = L->array[i-1];
		}
		L->array[0] = item;
		L->size ++;
	}
}

/*���α׷� 6.1 �迭����Ʈ 
int main(void)
{
	//ArryListType�� �������� �����ϰ� ArrayListTypedmf
	//����Ű�� �����͸� �Լ��� �Ű������� �����Ѵ�.
	//���� ������ �ٲٱ� ���� 
	ArrayListType list;
	
	init(&list);
	insert(&list, 0, 10);
	print_list(&list); 
	insert(&list, 0, 20);
	print_list(&list); 
	insert(&list, 0, 30);
	print_list(&list);
	insert_last(&list, 40);
	print_list(&list);
	delete_list(&list, 0);
	print_list(&list);
	
	return 0; 
	
}
*/
/* ���� ���� '����Ʈ'�� ���� �߿��� insert_first(list,item)������ �����Ͽ�
�׽�Ʈ�϶� 
int main(void)
{
	ArrayListType list;
	init(&list);
	
	insert_last(&list, 10);
	print_list(&list);	
	insert_last(&list,20);
	print_list(&list);
	insert_last(&list,30);
	print_list(&list);
	insert_last(&list,40);
	print_list(&list);
	insert_first(&list, 100);
	print_list(&list);
	return 0;
}
*/
//���� ���� malloc�� ����Ͽ� �������� ArrayListType ����� 
int main(void)
{
	ArrayListType *list;
	list = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(list);
	insert_last(list, 10);
	print_list(list);
	insert_last(list, 20);
	print_list(list);
	insert_last(list, 30);
	print_list(list);
	
	free(list);
	
	return 0;	
} 
