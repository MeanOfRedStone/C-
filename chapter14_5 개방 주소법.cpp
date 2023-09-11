/*
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
//프로그램 14.1 선형조사법의 구현 Part1(해시 테이블 생성) 
#define KEY_SIZE 10	//탐색키의 최대 길이 
#define TABLE_SIZE 13  // 해싱 테이블의 크기 = 소수

//해시 테이블당 가지는 키 
typedef struct
{
	char key[KEY_SIZE];
	//다른 다양한 필드들	
} element;

element hash_table[TABLE_SIZE];

//프로그램 14.2 선형조사법의 구현 Part2(해시 테이블의 각 요소들은 초기화 과정을 거쳐야한다.초기화 과정이란 각 버킷들을 공백상태로 만드는 것이다.)
void init_table(element ht[])
{
	int i;
	for(i = 0; i < TABLE_SIZE; i++){
		//키의 첫 번째 값이 NULL 이면 버킷이 비어있듣 것으로 생각할 수 있다. 
		ht[i].key[0] = NULL; 
	}
} 

//프로그램 14.3 선형조사법의 구현 part3(해시 테이블에 키를 삽입하기 위해서 먼저 키를 정수로 바꾸어주는 해시 함수가 필요)
//문자로 된 키를 숫자로 변환
int transform(char *key)
{
	int number = 0;
	while (*key){
		number = 31 * number + *key++;
	}
	return number;
} 

//제산 함수를 사용한 해싱 함수
int hash_function(char *key)
{
	//키를 자연수로 변환한 다음 테이블의 크기를 나누어 나머지를 반환
	return transform(key) % TABLE_SIZE; 
} 

//(참고) 군집화(clustering): 한 번 충돌이 시작되면 그 위치에 항목들이 집중되는 현상. 



//프로그램 14.4 선형조사법의구현 part4 
//hasp_lp_add : 키에 대하여 해시 주소 계산 -> 그 주소가 비어있는지 검사. 
//(1) 비어있지 않다면: 그 주소에 저장된 키와 현재 삽입하려고 하는 키가 동일한지를 체크 
//-> 키가 동일하면 중복되었다는 것을 화면에 출력하고 복귀 
//-> 중복되지 않았다면 현재 주소를 나타내는 변수 i를 증가하여 다음 버킷을 가리키도록한다. 
//->처음으로 되돌아온다면 테이블 다 찬것.

//empty 함수: 현재 버킷이 비어잇는지를 검사 
#define empty(item) (strlen(item.key) == 0)
//equal 함수: 두 개의 항목이 동일한지를 검사하는 함수이다.(저장되는 자료의 종류에 따라 달라진다.) 
#define equal(item1, item2) (!strcmp(item1.key, item2.key)) 
 
//선형 조사법을 이용하여 테이블에 키를 삽입하고,
//테이블이 가득 찬 경우는 종료
void hash_lp_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	//printf("hash_address =%d\n, i);
	while( !empty(ht[i]) ){
		if(equal(item, ht[i])){
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE;
		if(i == hash_value) {
			fprintf(stderr, "테이블이 가득 찼습니다\n");
			exit(1);
		}
	}
	ht[i] = item;
} 

//저장되는 항목을 탐색하는 함수. 탐색도 마찬가지로 먼저 키에 해시 함수를 적용시켜서 계산된 주소에서 항목 찾지 못하면 계속 연속된 버킷탐색.
//처음으로 되돌아온다면 해당 항목이 테이블에 없다고 결론 내린다. 
//프로그램 14.5 선형조사법의 구현 part4 
//선형 조사법을 이용하여 테이블에 저장된 키를 탐색
void hash_lp_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])){
		if(equal(item, ht[i])){
			fprintf(stderr, "탐색 %s: 위치 = %d\n", item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if( i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음");
} 


//프로그램 14.6 선형조사법의 구현 part5
//해싱 테이블의 내용을 출력
void hash_lp_print(element ht[])
{
	int i;
	printf("\n================================\n");
	for(i = 0; i < TABLE_SIZE; i++){
		printf("[%d] %s\n", i, ht[i].key);
	}
	printf("================================\n\n");
}

//해싱 테이블을 사용한 예제
int main(void)
{
	char *s[7] = {"do", "for", "if", "case", "else", "return", "function"};
	element e;
	
	for(int i = 0; i < 7; i++){
		strcpy(e.key, s[i]);
		hash_lp_add(e, hash_table);
		hash_lp_print(hash_table);
	}
	for (int i = 0; i < 7; i++){
		strcpy(e.key, s[i]);
		hash_lp_search(e, hash_table);
	}
	return 0;
} 
*/

//프로그램 14.7 이차조사법의 구현
void hash_qp_add(element item, element ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	//printf("hash_address=%d\n", i);
	while(!empty(ht[i])){
		if(equal(item, ht[i])){
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (hash_value + inc*inc) % TABLE_SIZE;
		inc = inc + 1;
		if(i == hash_value){
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
		}
	}
	ht[i] = item;
} 

//프로그램 14.8 이중 해싱법의 구현
void hash_dh_add(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function(item.key);
	//printf("hash_address=%d\n",i);
	while(!empty(ht[i])){
		if(equal(item, ht[i])){
			fprintf(stderr, "탐색키가 중복되었습니다.\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE;
		if(i == hash_value){
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
		}
	}
	ht[i] = item;
} 
