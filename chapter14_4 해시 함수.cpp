// 해시 함수
int hash_function(int key)
{
	int hash_index = key % M;
	if(hash_index < 0) {
		hash_index += M;
	}
	return hash_index;
} 


//XOR 연산 : 32비트 키를 2개의 16비트로 나누어 비트별로 연산
hash_index = (short) (key ^ (key >> 16)) 

//Horner's method ( 키가 긴 문자열일 경우 오버플로우 일으킬 수도 있음, 보통 g=31 사용) 
int hash_function(char *key)
{
	int hash_index = 0;
	while (*key){
		hash_index = g * hash_index + *key++;
	}
	return hash_key;
}
 
