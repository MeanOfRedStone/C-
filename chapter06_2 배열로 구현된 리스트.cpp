//chapter 6. 2 배열로 구성된 리스트의 코드를 작성합니다.

//*리스트의 정의
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 //리스트의 최대 크기

typedef int element; //항목의 정의
typedef struct{
	element array[MAX_LIST_SIZE]; //배열의 정의
	int size; // 현재 리스트에 저장된 항목들의 개수 
} ArrayListType;


//*기초연산 : 모든 연산은 구조체 포인터로 바든다. 포인터로 받는 이유는
//함수 안에서 구조체를 변경할 필요도 있기 때문이다. 
//구조체를 변화시킬 때 포인터 사용 안하면 복사본만 전달되어 변경 불가.

//오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
} 

//리스트 초기화 함수
void init(ArrayListType *L)
{
	L->size = 0;
} 

//리스트 공백 확인 함수 
int is_empty(ArrayListType *L)
{
	return L->size == 0;
}

//리스트 포화 확인 함수
int is_full(ArrayListType *L)
{
	return L->size == MAX_LIST_SIZE; //스택, 선형 큐와 다르게 데이터가 없을 때 위치 0이다. 
}

//pos 요소 값 반환 
element get_entry(ArrayListType *L, int pos)
{
	if(pos < 0 || pos >= L->size)
	{
		error("위치 오류");
	}
	else
	{
		return L->array[pos];
	}
}

//리스트 출력
void print_list(ArrayListType *L)
{
	int i;
	for(i = 0; i < L->size; i++)
	{
		printf("%d->",L->array[i]);
	}
	printf("\n"); 
} 

//*항목 추가 연산
void insert_last(ArrayListType *L, element item)
{
	if(L->size >= MAX_LIST_SIZE)
	{
		error("리스트 오버플로우"); 
	}
	else
	{
		L->array[L->size++] = item;
	} 
} 

//pos 위치에 새로운 항목 추가할 경우
void insert(ArrayListType *L, int pos, element item)
{
	if(!is_full(L) && (pos >= 0) && (pos <= L->size))
	{
		for(int i = (L->size - 1); i >= pos; i--)
		{
			L->array[i+1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

//*항목 삭제 연산 
element delete_list(ArrayListType *L, int pos)
{
	element item;
	
	if(pos < 0 || pos >= L->size) //L->size는 공백인 위치니깐
	{
		error("위치 오류");	
	}
	else
	{
		item = L->array[pos];
		for(int i = pos; i<(L->size- 1); i++)
		{
			L->array[i] = L->array[i+1]; // 맨 마지막 위치는 가지오 오는 값이 없으니깐 
		}
		L->size--;
		return item; 
	} 
}

void replace(ArrayListType *L, int pos, element item)
{
	if(pos < 0 || pos >= L->size)
	{
		error("위치 오류");
	}
	else
	{
		L->array[pos] = item;
	} 
}

int get_length(ArrayListType *L)
{
	return L->size;
}

void insert_first(ArrayListType *L, element item)
{
	if(!is_empty(L))
	{
		for(int i = L->size; i > 0; i--)
		{
			L->array[i] = L->array[i-1];
		}
		L->array[0] = item;
		L->size ++;
	}
}

/*프로그램 6.1 배열리스트 
int main(void)
{
	//ArryListType을 정적으로 생성하고 ArrayListTypedmf
	//가리키는 포인터를 함수의 매개변수로 전달한다.
	//안의 내용을 바꾸귀 위해 
	ArrayListType list;
	
	init(&list);
	insert(&list, 0, 10);
	print_list(&list); 
	insert(&list, 0, 20);
	print_list(&list); 
	insert(&list, 0, 30);
	print_list(&list);
	insert_last(&list, 40);
	print_list(&list);
	delete_list(&list, 0);
	print_list(&list);
	
	return 0; 
	
}
*/
/* 도전 문제 '리스트'의 연산 중에서 insert_first(list,item)연산을 구현하여
테스트하라 
int main(void)
{
	ArrayListType list;
	init(&list);
	
	insert_last(&list, 10);
	print_list(&list);	
	insert_last(&list,20);
	print_list(&list);
	insert_last(&list,30);
	print_list(&list);
	insert_last(&list,40);
	print_list(&list);
	insert_first(&list, 100);
	print_list(&list);
	return 0;
}
*/
//도전 문제 malloc을 사용하여 동적으로 ArrayListType 만들기 
int main(void)
{
	ArrayListType *list;
	list = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(list);
	insert_last(list, 10);
	print_list(list);
	insert_last(list, 20);
	print_list(list);
	insert_last(list, 30);
	print_list(list);
	
	free(list);
	
	return 0;	
} 
