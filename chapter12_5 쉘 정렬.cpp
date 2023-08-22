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
