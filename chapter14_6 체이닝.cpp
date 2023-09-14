#include <stdio.h>
#include <stdlib.h> 

//체이닝 해싱의 구현을 위한 구조체 선언
#define TABLE_SIZE 7
typedef struct{
	int key;
} element;

//키값 저장하는 연결 리스트 
struct list
{
	element item;
	struct list *link;
};
struct list *hash_table[TABLE_SIZE]; 

//프로그램 14.9 체인법의 구현
int hash_function(int key)
{
	return key % TABLE_SIZE;
}

//체인법을 이용하여 테이블에 키 삽입
void hash_chain_add(element item, struct list *ht[])
{
	int hash_value = hash_function(item.key);
	struct list *ptr;
	//node_before가 필요한 이유 node 포인터가 NULL이 되면 for루프가 끝나기 때문. 하지만 우리가 필요한 포인터는 NULL 바로 앞의 포인터이다. 마지막 노드의 앞 포인터를 갖기 위해 node_before가 있는 것읻. 
	struct list *node_before = NULL, *node = ht[hash_value];
	//어떤 항목을 사용할 것인지는 두번 째 항목에서 같이 결정 됨(노드가 존재할 경우) 
	for(; node; node_before = node, node = node->link){
		if(node->item.key == item.key){
			fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
			return;
		}
	}
	ptr = (struct list *)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	
	//node_before가 존재한다면 == (즉, 해쉬 값의 충돌이 일어난 경우) 
	if(node_before){
		node_before->link = ptr;
	}
	else{
		ht[hash_value] = ptr;
	}
} 

//체인법을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_search(element item, struct list *ht[])
{
	struct list *node;
	
	int hash_value = hash_function(item.key);
	for(node = ht[hash_value]; node; node = node->link){
		if(node->item.key == item.key){
			fprintf(stderr, "탐색 %d 성공 \n", item.key);
			return;
		}
	}
	printf("키를 찾지 못햇음\n");
}
 
void hash_chain_print(struct list *ht[])
{
	struct list *node;
	int i;
	printf("\n=============================================\n");
	for(i = 0; i < TABLE_SIZE; i++){
		printf("[%d]->", i);
		for(node = ht[i]; node; node = node->link){
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("\n=============================================\n");
}

#define SIZE 5

//해싱 테이블 예제
int main(void)
{
	int data[SIZE] = {8, 1, 9, 6, 13};
	element e;
	for(int i = 0; i < SIZE; i++){
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table); 
	}
	for(int i = 0; i < SIZE; i++){
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}
	return 0;
 } 
