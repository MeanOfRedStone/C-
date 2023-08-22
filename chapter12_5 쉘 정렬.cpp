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
/*
1. �������� gap�� ������ �ٿ����鼭 �Ʒ��� key�� ������ �� key�� �ڸ� ��ȭ�� �ܰ躰�� ������.
1�ܰ�) gap = 5
2					4
	1					8
		3					5
			7
				6 

2 1 3 7 6 4 8 5

2�ܰ�)	gap = 3
2			7			8
	1			5			6
		3			4
2 1 3 7 5 4 8 6

3�ܰ�) gap = 1
1 2 3 4 5 6 7 8

2. 10, 000���� ���ڵ带 ������ ��, �� ������ �������ĺ��� �󸶳� ������?
10^4^3/4 = 1000�� ������. 
*/
