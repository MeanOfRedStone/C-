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
/*
1. �պ������� �Ʒ��� key�� ������ �� key�� �ڸ� ��ȭ�� �ܰ躰�� ������.
(����)
8 - 2 - 5 - 7 - 6 - 4 - 1 -3

8 - 2 - 5 - 7 		|	 	6 - 4 - 1 -3

8 - 2 	|	 5 - 7			6 - 4	|	1 - 3


8 | 2		5 | 7			6 | 4		1 | 3

(�պ�)
1�ܰ�)
8 - 2 - 5 - 7 		|	 	6 - 4 - 1 -3

2 - 8 	|	 5 - 7			4 - 6	|	1 - 3

2�ܰ�)
8 - 2 - 5 - 7 - 6 - 4 - 1 -3

2 - 5 - 7 - 8 		|	 	1 - 3 - 4 -6

3�ܰ�)
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8

2. �պ� ������ �ð������⵵�� �ּ�, ���, �־��� ��쿡 �� ���� ���� ������ �����϶�.
->�񱳿� �̵��� �������ֱ� �����̴�. + ������. 
*/ 






 
