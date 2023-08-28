//���α׷� 13.4 ��ȯ ȣ���� �̿��� ���� Ž��
int search_binary(int key, int low, int high)
{
	int middle;
	
	if(low <= high){
		middle = (low + high) / 2;
		if (key == list[middle]){
			return middle;
		}
		else if (key < list[middle]){
			return search_binary(key, low, middle - 1);
		}
		else{
			return search_binary(key, middle + 1; high);
		}
	}
	return -1; //Ž�� ���� 
} 

//���α׷� 13.5 �ݺ��� �̿��� ����Ž��( �� ȿ�����̴�)
int search_binary2(int key, int low, int high)
{
	int middle;
	
	while(low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle]){
			return middle;
		}
		else if (key > list[middle]){
			low = middle + 1;
		}
		else{
			high = middle - 1;
		}
	}
	return -1;
} 

//���α׷�13.6 ���� ���� Ž��
#define INDEX_SIZE 256
typedef struct
{
	int key;
	int index;
} itable;
itable index_list[INDEX_SIZE];

//INDEX_SIZE�� �ε��� ���̺��� ũ��
int search_index(int key, int n)
{
	int i, low, high;
	
	//Ű ���� ����Ʈ ���� ���� ���� �ƴϸ� ����	
	if(key < list[0] || key > list[n-1]){
		return -1;
	} 
	
	//�ε��� ���̺��� �����Ͽ� �ش�Ű�� ���� ����
	for(i = 0; i < INDEX_SIZE; i++){
		if(index_list[i].key < = key && index_list[i+1].key > key ){
			break;
		}
	}
	//���� ���� �ε��� ���̺��� ���̸� 
	if(i == INDEX_SIZE){
		low = index_list[i - 1].index;
		hight = n;
	} 
	else{
		low = index_list[i].index;
		hgih = index_list[i+1].index;
	}
	//����Ǵ� ������ ���� Ž�� 
	return seq_search(key, low, high); 
} 

//���α׷� 13.7
int interpol_search(int key, int n)
{
	int low, high, j;
	
	low = 0;
	high = n - 1;
	while( (list[high] >= key) && (key > list[low]) ){
		j = ( (float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low; //��ʽ����� j�� ����
		if( key > list[j] ){
			low = j + 1;
		} 
		else if( key < list[j] ){
			high = j -1;
		}
		else {
			low = j; //��ġ �Ұ�� ���������� ���� low = j 
		}
	} 
	if( list[low] == key ){
		return low; //Ž�� ���� 
	}
	else{
		return -1;
	}
} 


QUIZ1. �Ʒ��� ���ĵ� ����Ʈ�� Ű �� '4'�� ������ ���� Ž���ϴ� ������ ���̰�, ��Ƚ���� ���϶�.
0	1	2	3	4	5	6	7
1 | 2 | 3 | 5 | 6 | 8 | 9 | 10 | 
1�ܰ�)
if list[0] == 5
	break;
else
	i++
	
2�ܰ�) 
if list[1] == 5
	break;
else
	i++

3�ܰ�) 
if list[2] == 5
	break;
else
	i++

4�ܰ�)
if list[3] == 5
	break;
else
	i++
	
5�ܰ�)
if ( i == high + 1)
	return -1;
else
	return i;
	
����� i = 3 | 5�� ���Ѵ�.

QUIZ2. �Ʒ��� ���ĵ� ����Ʈ�� Ű ��  5�� ���� Ž���ϴ� ������ ���̰�, �� Ƚ���� ���϶�. 
1�ܰ�) 0, 7���� ����Ž�� 
middle = 3
if(5 == list[middle]) 
	return middle
else if( 5 < list[middle])
	return 0���� middle-1���� ����Ž�� 
else if( 5 > list[middle])
	reuturn middle + 1���� high���� ����Ž�� 
2�ܰ�) 4���� 7���� ����Ž��
middle = 5
if(5 == list[middle]) 
	return middle
else if( 5 < list[middle])
	return 4���� middle-1���� ����Ž�� 
else if( 5 > list[middle])
	reuturn middle + 1���� high���� ����Ž��
	
3�ܰ�) 4���� 4���� ����Ž��
middle = 4
if(5 == list[middle]) 
	return middle
else if( 5 < list[middle])
	return 4���� middle-1���� ����Ž�� 
else if( 5 > list[middle])
	reuturn middle + 1���� high���� ����Ž��

����� -1 | 7�� ���Ѵ�.

QUIZ 3. �Ʒ��� ���ĵ� ����Ʈ�� Ű �� 6���� ���� Ž���ϴ� ������ ���̰� �� Ƚ���� ���϶�.
1�ܰ�)0���� 7���� ����Ž�� 
list[7] >= 6 && 6 > list[0]
j =  (6 - 1) / (10 - 1) * (7 - 0) + low = 5/9*7 =3.xx -> 3
if( 6 > list[3] )
	low = j + 1;
	
2�ܰ�) 4���� 7���� ���� Ž��
list[7] >= 6 && 6 > list[4]

3�ܰ�)
if(list[4] == 6)
else
	return -1
	
����� -1 | 4�� �� 
