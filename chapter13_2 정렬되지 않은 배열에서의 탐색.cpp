//���α׷� 13.1 ���� Ž��
int seq_search(int key, int low, int high) 
{
	int i;
	
	for(i = low; i <= high; i++){
		if(list[i] == key){
			return i; //Ž���� �����ϸ� Ű ���� �ε��� ��ȯ 
		}
	}
	return -1; //Ž���� �����ϸ� -1 ��ȯ 
}

//���α׷� 13.2 ������ ����Ž��
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
