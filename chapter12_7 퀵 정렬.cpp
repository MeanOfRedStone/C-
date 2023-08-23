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

/*
//���α׷� 12.9 qsort.c
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//
int compare(const void *arg1, const void *arg2)
{
	if( *(double *)arg1 > *(double *)arg2){
		return 1;
	}
	else if( *(double *)arg1 == *(double *)arg2){
		return 0;
	}
	else{
		return -1;
	}
} 

int main(void)
{
	int i;
	double list[5] = {2.1, 0.9, 1.6, 3.8, 1.2};
	qsort( (void *)list, (size_t)5, sizeof(double), compare);
	for ( i = 0; i < 5; i++){
		printf("%f ", list[i]);
	}
	
	return 0;
}
*/


/*
1. �������� �Ʒ��� key�� ������ �� key�� �ڸ� ��ȭ�� �ܰ躰�� ������
1�ܰ�)

4 | 7 - 1 - 8 - 6 - 2 - 5 - 3

| 3 - 1 - 2 | 4 |6 -  8 - 5 - 7 

2�ܰ�)

3 - 1 - 2	| 4 |	6 - 8 - 5 - 7


 1 - 2 		| 3 |	| 4 |		 5  	| 6 | 	8 - 7 
 
 
3�ܰ�)

| 1 |	2	| 3 |	| 4 |	| 5 |	| 6 |		7	| 8 |

4�ܰ�)
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |

2. 1, 000, 000���� ���ڵ带 ������ ��, �������� �������ĺ��� �󸶳� �����ڴ°�?
��� 
���� 
10^12
/
��
10^6 * log2(10^6) 

�� ��ŭ ������. 
*/
