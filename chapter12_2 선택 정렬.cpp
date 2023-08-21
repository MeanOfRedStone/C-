/*
SWAP 매크로
같은 자료형인 두 값을 교환하는 함수
->포인터 사용하지 않고 자료 교환 가능 
 
*/
/*
//프로그램 12.1 선택 정렬 함수
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for(i = 0; i < n -1; i++){
		least = i;
		//최솟값 탐색 
		for(j = i + 1; j < n; j++){
			if(lst[j] < list[least]){
				least = j;
			} 
		}
		SWAP(list[i], list[least], temp);
	}
}

*/

//프로그램 12.2 선택 정렬 프로그램 
//난수를 발생 시켜 MAX_SIZE개의 배열을 list에 저장 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for(i = 0; i < n -1; i++){
		least = i;
		//최솟값 탐색 
		for(j = i + 1; j < n; j++){
			if(list[j] < list[least]){
				least = j;
			} 
		}
		SWAP(list[i], list[least], temp);
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for(i = 0; i < n; i++){ //난수 생성 및 출력 
		list[i] = rand() % 100; //난수 발생 범위 0~99 
	}
	
	selection_sort(list, n); //선택 정렬 호출
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}

/*
1. 선택 정렬이 아래의 key를 정렬할 때 key의 자리 변화를 단계 별로 보여라. 

1 | 3 | 4 | 9 | 7 | 6 |

1단계)
1 | 3 | 4 | 9 | 7 | 6
2단계)
1 | 3 | 4 | 9 | 7 | 6
3단계)
1 | 3 | 4 | 6 | 7 | 9
4단계)
""
5단계)
"" 


