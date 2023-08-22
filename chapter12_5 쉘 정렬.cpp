//프로그램 12.5 쉘 정렬 프로그램
//gap 만큼 떨어진 요소들을 삽입 정렬
//정렬의 범위는 first에서 last

//삽입정렬함수 
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j , key;
	for(i = first + gap; i <= last; i = i + gap){
		key = list[i];
		for(j = i - gap; j >= first && key < list[j]; j = j -gap){
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}	
} 

//참고 간격이 짝수일 경우 + 1 
void shell_sort(int list[], int n) // n = size
{
	int i , gap;
	//첫 갭은 리스트 사이즈의 절반 이후로 계속 절반 
	for(gap = n / 2; gap>0; gap = gap / 2){
		if((gap % 2) == 0){
			gap++;
		}
		//배열의 첫번째부터 gap 단위로 부분리스트 만들어서  삽입정렬 
		for(i = 0; i < gap; i++){
			inc_insertion_sort(list, i; n - 1, gap )
		}
		
	}
}
/*
1. 쉘정렬이 gap을 반으로 줄여가면서 아래의 key를 정렬할 때 key의 자리 변화를 단계별로 보여라.
1단계) gap = 5
2					4
	1					8
		3					5
			7
				6 

2 1 3 7 6 4 8 5

2단계)	gap = 3
2			7			8
	1			5			6
		3			4
2 1 3 7 5 4 8 6

3단계) gap = 1
1 2 3 4 5 6 7 8

2. 10, 000개의 레코드를 정렬할 때, 쉘 정렬이 삽입정렬보다 얼마나 빠른가?
10^4^3/4 = 1000배 빠르다. 
*/
