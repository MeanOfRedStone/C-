//프로그램 12.6 merge 알고리즘 구현
int sorted[MAX_SIZE]; // 추가 공간이 필요

/* 	i는 정렬된 왼쪽 리스트에 대한 인덱스
	j는 정렬된 오른쪾 리스트에 대한 인덱스
	k는 정렬될 리스트에 대한 인덱스*/
	
void merge(int list[], int left, int mid, int right)
{
	int i, j , k ,l;
	i = left; j = mid + 1; k = left
	
	/*분할 정렬된 list의 합병*/
	while(i <= mid && j <= right){
		if(list[i] <= list[j]){
			sorted[k++] = list[i++];
		}
		else{
			sorted[k++] = list[j++];
		}
	}
	 /*남아 있는 레코드를 일괄 복사*/
	if( i > mid ){ 
		for(l = j; l <= right; l++){
			sorted[k++] = list[l];
		}
	}
	else{
		for(l = i; l <= mid; l++){
			sorted[k++] = list[l];
		}
	}
	/* 배열 sorted[]의 리스트를 배열 list[]로 재복사*/
	for(l = left; l <= right; l++){
		list[i] = sorted[l];
	}
} 

//
void merge_sort(int list[], int left, int right)
{
	int mid;
	if(left < right){
		mid = (left + right) / 2;
		merge_sort(int list, left, mid);
		merge_sort(int list, mid + 1, right);
		merge(list, left, mid, right);
	}	
} 
/*
1. 합병정렬이 아래의 key를 정렬할 때 key의 자리 변화를 단계별로 보여라.
(분할)
8 - 2 - 5 - 7 - 6 - 4 - 1 -3

8 - 2 - 5 - 7 		|	 	6 - 4 - 1 -3

8 - 2 	|	 5 - 7			6 - 4	|	1 - 3


8 | 2		5 | 7			6 | 4		1 | 3

(합병)
1단계)
8 - 2 - 5 - 7 		|	 	6 - 4 - 1 -3

2 - 8 	|	 5 - 7			4 - 6	|	1 - 3

2단계)
8 - 2 - 5 - 7 - 6 - 4 - 1 -3

2 - 5 - 7 - 8 		|	 	1 - 3 - 4 -6

3단계)
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8

2. 합병 정렬의 시간적복잡도가 최선, 평균, 최악의 경우에 별 차익 없는 이유를 설명하라.
->비교와 이동이 정해져있기 때문이다. + 안정적. 
*/ 






 
