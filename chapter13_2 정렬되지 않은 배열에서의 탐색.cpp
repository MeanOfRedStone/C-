//프로그램 13.1 순차 탐색
int seq_search(int key, int low, int high) 
{
	int i;
	
	for(i = low; i <= high; i++){
		if(list[i] == key){
			return i; //탐색에 성공하면 키 값의 인덱스 변환 
		}
	}
	return -1; //탐색에 실패하면 -1 반환 
}

//프로그램 13.2 개선된 순차탐색
int seq_search2(int key, int low, int high)
{
	int i;
	
	list[high+1] = key;
	for(i = low; list[i] != key; i++){
		;
	}
	if( i == (high + 1)){
		return -1;
	}
	else{
		return i;
	}
} 
