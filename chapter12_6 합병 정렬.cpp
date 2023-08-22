//���α׷� 12.6 merge �˰��� ����
int sorted[MAX_SIZE]; // �߰� ������ �ʿ�

/* 	i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
	j�� ���ĵ� �����U ����Ʈ�� ���� �ε���
	k�� ���ĵ� ����Ʈ�� ���� �ε���*/
	
void merge(int list[], int left, int mid, int right)
{
	int i, j , k ,l;
	i = left; j = mid + 1; k = left
	
	/*���� ���ĵ� list�� �պ�*/
	while(i <= mid && j <= right){
		if(list[i] <= list[j]){
			sorted[k++] = list[i++];
		}
		else{
			sorted[k++] = list[j++];
		}
	}
	 /*���� �ִ� ���ڵ带 �ϰ� ����*/
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
	/* �迭 sorted[]�� ����Ʈ�� �迭 list[]�� �纹��*/
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
