// �ؽ� �Լ�
int hash_function(int key)
{
	int hash_index = key % M;
	if(hash_index < 0) {
		hash_index += M;
	}
	return hash_index;
} 


//XOR ���� : 32��Ʈ Ű�� 2���� 16��Ʈ�� ������ ��Ʈ���� ����
hash_index = (short) (key ^ (key >> 16)) 

//Horner's method ( Ű�� �� ���ڿ��� ��� �����÷ο� ����ų ���� ����, ���� g=31 ���) 
int hash_function(char *key)
{
	int hash_index = 0;
	while (*key){
		hash_index = g * hash_index + *key++;
	}
	return hash_key;
}
 
