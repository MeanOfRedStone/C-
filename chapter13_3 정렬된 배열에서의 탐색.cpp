//프로그램 13.4 순환 호출을 이용한 이진 탐색
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
	return -1; //탐색 실패 
} 

//프로그램 13.5 반복을 이용한 이진탐색( 더 효율적이다)
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

//프로그램13.6 색인 순차 탐색
#define INDEX_SIZE 256
typedef struct
{
	int key;
	int index;
} itable;
itable index_list[INDEX_SIZE];

//INDEX_SIZE는 인덱스 테이블의 크기
int search_index(int key, int n)
{
	int i, low, high;
	
	//키 값이 리스트 범위 내의 값이 아니면 종료	
	if(key < list[0] || key > list[n-1]){
		return -1;
	} 
	
	//인덱스 테이블을 조사하여 해당키의 구간 결정
	for(i = 0; i < INDEX_SIZE; i++){
		if(index_list[i].key < = key && index_list[i+1].key > key ){
			break;
		}
	}
	//나온 값이 인덱스 테이블의 끝이면 
	if(i == INDEX_SIZE){
		low = index_list[i - 1].index;
		hight = n;
	} 
	else{
		low = index_list[i].index;
		hgih = index_list[i+1].index;
	}
	//예상되는 범위만 순차 탐색 
	return seq_search(key, low, high); 
} 

//프로그램 13.7
int interpol_search(int key, int n)
{
	int low, high, j;
	
	low = 0;
	high = n - 1;
	while( (list[high] >= key) && (key > list[low]) ){
		j = ( (float)(key - list[low]) / (list[high] - list[low]) * (high - low)) + low; //비례식으로 j값 추정
		if( key > list[j] ){
			low = j + 1;
		} 
		else if( key < list[j] ){
			high = j -1;
		}
		else {
			low = j; //일치 할경우 빠져나오기 위해 low = j 
		}
	} 
	if( list[low] == key ){
		return low; //탐색 성공 
	}
	else{
		return -1;
	}
} 


QUIZ1. 아래의 정렬된 리스트를 키 값 '4'로 개선된 순차 탐색하는 순서를 보이고, 비교횟수를 답하라.
0	1	2	3	4	5	6	7
1 | 2 | 3 | 5 | 6 | 8 | 9 | 10 | 
1단계)
if list[0] == 5
	break;
else
	i++
	
2단계) 
if list[1] == 5
	break;
else
	i++

3단계) 
if list[2] == 5
	break;
else
	i++

4단계)
if list[3] == 5
	break;
else
	i++
	
5단계)
if ( i == high + 1)
	return -1;
else
	return i;
	
결과값 i = 3 | 5번 비교한다.

QUIZ2. 아래의 정렬된 리스트를 키 값  5로 이진 탐색하는 순서를 보이고, 비교 횟수를 답하라. 
1단계) 0, 7까지 이진탐색 
middle = 3
if(5 == list[middle]) 
	return middle
else if( 5 < list[middle])
	return 0부터 middle-1까지 이진탐색 
else if( 5 > list[middle])
	reuturn middle + 1부터 high까지 이진탐색 
2단계) 4부터 7까지 순차탐색
middle = 5
if(5 == list[middle]) 
	return middle
else if( 5 < list[middle])
	return 4부터 middle-1까지 이진탐색 
else if( 5 > list[middle])
	reuturn middle + 1부터 high까지 이진탐색
	
3단계) 4부터 4까지 이진탐색
middle = 4
if(5 == list[middle]) 
	return middle
else if( 5 < list[middle])
	return 4부터 middle-1까지 이진탐색 
else if( 5 > list[middle])
	reuturn middle + 1부터 high까지 이진탐색

결과값 -1 | 7번 비교한다.

QUIZ 3. 아래의 정렬된 리스트를 키 값 6으로 보간 탐색하는 순서를 보이고 비교 횟수를 답하라.
1단계)0에서 7까지 보간탐색 
list[7] >= 6 && 6 > list[0]
j =  (6 - 1) / (10 - 1) * (7 - 0) + low = 5/9*7 =3.xx -> 3
if( 6 > list[3] )
	low = j + 1;
	
2단계) 4에서 7까지 보간 탐색
list[7] >= 6 && 6 > list[4]

3단계)
if(list[4] == 6)
else
	return -1
	
결과값 -1 | 4번 비교 
