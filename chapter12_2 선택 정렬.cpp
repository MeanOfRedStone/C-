/*
SWAP ��ũ��
���� �ڷ����� �� ���� ��ȯ�ϴ� �Լ�
->������ ������� �ʰ� �ڷ� ��ȯ ���� 
 
*/
/*
//���α׷� 12.1 ���� ���� �Լ�
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for(i = 0; i < n -1; i++){
		least = i;
		//�ּڰ� Ž�� 
		for(j = i + 1; j < n; j++){
			if(lst[j] < list[least]){
				least = j;
			} 
		}
		SWAP(list[i], list[least], temp);
	}
}

*/

//���α׷� 12.2 ���� ���� ���α׷� 
//������ �߻� ���� MAX_SIZE���� �迭�� list�� ���� 

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
		//�ּڰ� Ž�� 
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
	for(i = 0; i < n; i++){ //���� ���� �� ��� 
		list[i] = rand() % 100; //���� �߻� ���� 0~99 
	}
	
	selection_sort(list, n); //���� ���� ȣ��
	for(i = 0; i < n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	return 0;
}

/*
1. ���� ������ �Ʒ��� key�� ������ �� key�� �ڸ� ��ȭ�� �ܰ� ���� ������. 

1 | 3 | 4 | 9 | 7 | 6 |

1�ܰ�)
1 | 3 | 4 | 9 | 7 | 6
2�ܰ�)
1 | 3 | 4 | 9 | 7 | 6
3�ܰ�)
1 | 3 | 4 | 6 | 7 | 9
4�ܰ�)
""
5�ܰ�)
"" 


