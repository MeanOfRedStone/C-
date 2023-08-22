//���α׷� 12.5 �� ���� ���α׷�
//gap ��ŭ ������ ��ҵ��� ���� ����
//������ ������ first���� last

//���������Լ� 
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

//���� ������ ¦���� ��� + 1 
void shell_sort(int list[], int n) // n = size
{
	int i , gap;
	//ù ���� ����Ʈ �������� ���� ���ķ� ��� ���� 
	for(gap = n / 2; gap>0; gap = gap / 2){
		if((gap % 2) == 0){
			gap++;
		}
		//�迭�� ù��°���� gap ������ �κи���Ʈ ����  �������� 
		for(i = 0; i < gap; i++){
			inc_insertion_sort(list, i; n - 1, gap )
		}
		
	}
}
