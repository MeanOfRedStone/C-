/*
//���α׷� 12.6 �� ����
void quick_sort(int list[], int left, int right)
{
	if(left < right){
		//partion�� ��� ���ϴ���... ���� �˰��򿡼� 
		int q = partition(list, left, right);
		
		// pivot ���� �����ϰ� ��ȯȣ���� �ݺ��Ѵ�.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

//���α׷� 12.7 partition�Լ� 
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1; //pivot���� left �ϳ� ������ϱ� ������ high �� �̿� ���߾� �ϳ� ���ֱ� ���� +1 ���ش�.
	pivot = list[left];
	do{
		do{
			low++;
		} while (list[low] < pivot);
		
	do{
		high--;
	} while(list[high] > pivot);
	if(low <high){
		SWAP(list[low], list[high], temp);
	}
	}  while(low < high);
	
	// ��ȯ�� ��� ������ pivot���� ����� �̵�
	SWAP(list[left], list[high], temp);
	
	return high; //pivot �� �ε����� ��ȯ -> pivot�� �κ� ����Ʈ �������� �̹� ���ĵ� ��ġ�� �ֱ� �����̴�.
}
*/

//��ü ���α׷� 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y , t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1; //pivot���� left �ϳ� ������ϱ� ������ high �� �̿� ���߾� �ϳ� ���ֱ� ���� +1 ���ش�.
	pivot = list[left];
	do{
		do{
			low++;
		} while (list[low] < pivot);
		
	do{
		high--;
	} while(list[high] > pivot);
	if(low <high){
		SWAP(list[low], list[high], temp);
	}
	}  while(low < high);
	
	// ��ȯ�� ��� ������ pivot���� ����� �̵�
	SWAP(list[left], list[high], temp);
	
	return high; //pivot �� �ε����� ��ȯ -> pivot�� �κ� ����Ʈ �������� �̹� ���ĵ� ��ġ�� �ֱ� �����̴�.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //�κ� ����Ʈ�� ������ ������ 1���� �Ǹ� �����.  
		//partion�� ��� ���ϴ���... ���� �˰��򿡼� 
		int q = partition(list, left, right);
		
		// pivot ���� �����ϰ� ��ȯȣ���� �ݺ��Ѵ�.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for(i = 0; i < n; i++){
		list[i] = rand() % 100;
	}
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n-1);
	
	printf("[���� ��] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}

