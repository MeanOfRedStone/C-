//프로그램 12.4 버블 정렬 프로그램
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t))
void bubble_sort(int list[], int n)
{
	int i, j ,temp;
	for(i = n-1; i > 0; i--){
		for(j = 0; j < i; j++){
			//앞 뒤의 레코드를 비교한 후 교체
			if(list[j] > list[j+1]){
				SWAP(list[j], list[j+1], temp);
			} 
		}
	}
} 
/*
1. 버블정렬이 아래의 key를 정렬할 때 key의 자리 변화를 단계별로 보여라
1단계)
3 - 7 - 4 - 1 - 6 - 9

2단계)
3 - 4 - 1 - 6 - 7 - 9

3단계)
3 - 1 - 4 - 6 - 7 - 9

4단계)
1 - 3 - 4 - 6 - 7 - 9

5단계)
 1 - 3 - 4 - 6 - 7 - 9
 
6단계)
1 - 3 - 4 - 6 - 7 - 9

2. 버블정렬이 선택정렬에 비해 이동 연산이 많은 이유를 설명하라.
배열에서 모든 다른 요소들과 순서에 맞지 않게 교환하기 때문이다. 
*/
