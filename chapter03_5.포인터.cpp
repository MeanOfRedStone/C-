/*swap.c 포인터를 함수의 매개변수로 사용하는 프로그램 
#include <stdio.h>

void swap(int *px, int *py)
{
	int tmp;
	tmp = *px;   //tmp에 포인터px로 치환(임시저장). tmp와 px는 같은 개ㅊ객 
	*px =  *py;		//px를 py로 치환.
	*py = tmp;		//py를 tmp로 치환. 즉, px로 치환하는것 
}

int main(void)
{
	int a = 1, b = 2;
	printf("swap 호출 전 a값 : %d, b값 : %d\n", a, b);
	swap(&a, &b);
	printf("swap 호출 후 a값 : %d, b값 : %d\n", a, b); 
	return 0;
}
/*
프로그램 3.7 array1.c 배열을 함수의 매개변수로 사용하는 프로그램 
#include <stdio.h>
#define SIZE 6
void get_integers(int list[]) // 리스트에 주소값을 받아 배열 숫자를 입력 
{
	printf("6개의 정수를 입력하시오 :");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &list[i]);
	} 
}

int cal_sum(int list[])
{
	int sum = 0;
	for(int i = 0; i < SIZE; i++ )
	{
		sum += *(list + i);
	}
	return sum;
}

int main(void)
{
	int list[SIZE];
	get_integers(list);
	printf("합 = %d", cal_sum(list));
	return 0;
} 
*/

