/*swap.c �����͸� �Լ��� �Ű������� ����ϴ� ���α׷� 
#include <stdio.h>

void swap(int *px, int *py)
{
	int tmp;
	tmp = *px;   //tmp�� ������px�� ġȯ(�ӽ�����). tmp�� px�� ���� ������ 
	*px =  *py;		//px�� py�� ġȯ.
	*py = tmp;		//py�� tmp�� ġȯ. ��, px�� ġȯ�ϴ°� 
}

int main(void)
{
	int a = 1, b = 2;
	printf("swap ȣ�� �� a�� : %d, b�� : %d\n", a, b);
	swap(&a, &b);
	printf("swap ȣ�� �� a�� : %d, b�� : %d\n", a, b); 
	return 0;
}
/*
���α׷� 3.7 array1.c �迭�� �Լ��� �Ű������� ����ϴ� ���α׷� 
#include <stdio.h>
#define SIZE 6
void get_integers(int list[]) // ����Ʈ�� �ּҰ��� �޾� �迭 ���ڸ� �Է� 
{
	printf("6���� ������ �Է��Ͻÿ� :");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &list[i]);
	} 
}

int cal_sum(int list[])
{
	int sum = 0;
	for(int i = 0; i < SIZE; i++ )
	{
		sum += *(list + i);
	}
	return sum;
}

int main(void)
{
	int list[SIZE];
	get_integers(list);
	printf("�� = %d", cal_sum(list));
	return 0;
} 
*/

