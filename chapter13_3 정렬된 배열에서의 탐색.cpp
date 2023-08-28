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
