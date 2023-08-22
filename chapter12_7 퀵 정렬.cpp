/*
//프로그램 12.6 퀵 정렬
void quick_sort(int list[], int left, int right)
{
	if(left < right){
		//partion을 어떻게 구하느냐... 뒤의 알고리즘에서 
		int q = partition(list, left, right);
		
		// pivot 값은 제외하고 순환호출을 반복한다.  
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
} 

//프로그램 12.7 partition함수 
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;
	
	low = left;
	high = right + 1; //pivot으로 left 하나 내줘야하기 때문이 high 도 이에 맞추어 하나 내주기 위해 +1 해준다.
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
	
	// 교환이 모두 끝나면 pivot값을 가운데로 이동
	SWAP(list[left], list[high], temp);
	
	return high; //pivot 의 인덱스를 반환 -> pivot은 부분 리스트 기주으로 이미 정렬된 위치에 있기 때문이다.
}
*/

//전체 프로그램 
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
	high = right + 1; //pivot으로 left 하나 내줘야하기 때문이 high 도 이에 맞추어 하나 내주기 위해 +1 해준다.
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
	
	// 교환이 모두 끝나면 pivot값을 가운데로 이동
	SWAP(list[left], list[high], temp);
	
	return high; //pivot 의 인덱스를 반환 -> pivot은 부분 리스트 기주으로 이미 정렬된 위치에 있기 때문이다.
}

void quick_sort(int list[], int left, int right)
{
	if(left < right){ //부분 리스트의 데이터 개수가 1개가 되면 멈춘다.  
		//partion을 어떻게 구하느냐... 뒤의 알고리즘에서 
		int q = partition(list, left, right);
		
		// pivot 값은 제외하고 순환호출을 반복한다.  
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
	
	printf("[정렬 전] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	quick_sort(list, 0, n-1);
	
	printf("[정렬 후] \n");
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}

