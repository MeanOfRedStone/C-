/*
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
//���α׷� 14.1 ����������� ���� Part1(�ؽ� ���̺� ����) 
#define KEY_SIZE 10	//Ž��Ű�� �ִ� ���� 
#define TABLE_SIZE 13  // �ؽ� ���̺��� ũ�� = �Ҽ�

//�ؽ� ���̺�� ������ Ű 
typedef struct
{
	char key[KEY_SIZE];
	//�ٸ� �پ��� �ʵ��	
} element;

element hash_table[TABLE_SIZE];

//���α׷� 14.2 ����������� ���� Part2(�ؽ� ���̺��� �� ��ҵ��� �ʱ�ȭ ������ ���ľ��Ѵ�.�ʱ�ȭ �����̶� �� ��Ŷ���� ������·� ����� ���̴�.)
void init_table(element ht[])
{
	int i;
	for(i = 0; i < TABLE_SIZE; i++){
		//Ű�� ù ��° ���� NULL �̸� ��Ŷ�� ����ֵ� ������ ������ �� �ִ�. 
		ht[i].key[0] = NULL; 
	}
} 

//���α׷� 14.3 ����������� ���� part3(�ؽ� ���̺� Ű�� �����ϱ� ���ؼ� ���� Ű�� ������ �ٲپ��ִ� �ؽ� �Լ��� �ʿ�)
//���ڷ� �� Ű�� ���ڷ� ��ȯ
int transform(char *key)
{
	int number = 0;
	while (*key){
		number = 31 * number + *key++;
	}
	return number;
} 

//���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char *key)
{
	//Ű�� �ڿ����� ��ȯ�� ���� ���̺��� ũ�⸦ ������ �������� ��ȯ
	return transform(key) % TABLE_SIZE; 
} 

//(����) ����ȭ(clustering): �� �� �浹�� ���۵Ǹ� �� ��ġ�� �׸���� ���ߵǴ� ����. 



//���α׷� 14.4 ����������Ǳ��� part4 
//hasp_lp_add : Ű�� ���Ͽ� �ؽ� �ּ� ��� -> �� �ּҰ� ����ִ��� �˻�. 
//(1) ������� �ʴٸ�: �� �ּҿ� ����� Ű�� ���� �����Ϸ��� �ϴ� Ű�� ���������� üũ 
//-> Ű�� �����ϸ� �ߺ��Ǿ��ٴ� ���� ȭ�鿡 ����ϰ� ���� 
//-> �ߺ����� �ʾҴٸ� ���� �ּҸ� ��Ÿ���� ���� i�� �����Ͽ� ���� ��Ŷ�� ����Ű�����Ѵ�. 
//->ó������ �ǵ��ƿ´ٸ� ���̺� �� ����.

//empty �Լ�: ���� ��Ŷ�� ����մ����� �˻� 
#define empty(item) (strlen(item.key) == 0)
//equal �Լ�: �� ���� �׸��� ���������� �˻��ϴ� �Լ��̴�.(����Ǵ� �ڷ��� ������ ���� �޶�����.) 
#define equal(item1, item2) (!strcmp(item1.key, item2.key)) 
 
//���� ������� �̿��Ͽ� ���̺� Ű�� �����ϰ�,
//���̺��� ���� �� ���� ����
void hash_lp_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	//printf("hash_address =%d\n, i);
	while( !empty(ht[i]) ){
		if(equal(item, ht[i])){
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE;
		if(i == hash_value) {
			fprintf(stderr, "���̺��� ���� á���ϴ�\n");
			exit(1);
		}
	}
	ht[i] = item;
} 

//����Ǵ� �׸��� Ž���ϴ� �Լ�. Ž���� ���������� ���� Ű�� �ؽ� �Լ��� ������Ѽ� ���� �ּҿ��� �׸� ã�� ���ϸ� ��� ���ӵ� ��ŶŽ��.
//ó������ �ǵ��ƿ´ٸ� �ش� �׸��� ���̺� ���ٰ� ��� ������. 
//���α׷� 14.5 ����������� ���� part4 
//���� ������� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_lp_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])){
		if(equal(item, ht[i])){
			fprintf(stderr, "Ž�� %s: ��ġ = %d\n", item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if( i == hash_value) {
			fprintf(stderr, "ã�� ���� ���̺� ����\n");
			return;
		}
	}
	fprintf(stderr, "ã�� ���� ���̺� ����");
} 


//���α׷� 14.6 ����������� ���� part5
//�ؽ� ���̺��� ������ ���
void hash_lp_print(element ht[])
{
	int i;
	printf("\n================================\n");
	for(i = 0; i < TABLE_SIZE; i++){
		printf("[%d] %s\n", i, ht[i].key);
	}
	printf("================================\n\n");
}

//�ؽ� ���̺��� ����� ����
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

//���α׷� 14.7 ����������� ����
void hash_qp_add(element item, element ht[])
{
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	//printf("hash_address=%d\n", i);
	while(!empty(ht[i])){
		if(equal(item, ht[i])){
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
			exit(1);
		}
		i = (hash_value + inc*inc) % TABLE_SIZE;
		inc = inc + 1;
		if(i == hash_value){
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
			exit(1);
		}
	}
	ht[i] = item;
} 

//���α׷� 14.8 ���� �ؽ̹��� ����
void hash_dh_add(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function(item.key);
	//printf("hash_address=%d\n",i);
	while(!empty(ht[i])){
		if(equal(item, ht[i])){
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�.\n");
			exit(1);
		}
		i = (i + inc) % TABLE_SIZE;
		if(i == hash_value){
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
			exit(1);
		}
	}
	ht[i] = item;
} 
