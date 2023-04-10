//연습문제
//4번 문제
/*
#include <stdio.h>
#define SIZE 10

int main(void)
{
	int two[SIZE];
	
	for(int i = 0; i < SIZE; i++)
	{
		two[i] = 20 + i;
	}
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", two[i]);
	}
	
	return 0;	
}
*/
/*
5번 문제 
#include <stdioh.h>

typedef struct{
	char name[10];
	int age;
	float salary;
} person;
*/

//6번 문제 
/*
#include <stdio.h>

typedef struct{
	float real;
	float imaginary;
} complex;



int main(void)
{
	complex c1;
	complex c2;
	return 0;	
} 
*/
//7번 문제 
/*
#include <stdio.h>

typedef struct{
	float real;
	float imaginary;
} complex;

complex complex_add(complex A, complex B){
	complex C;
	C.real = A.real + B.real;
	C.imaginary = A.imaginary + B.imaginary;
	
	return C;	
} 

int main(void)
{
	complex c1 = {1, 3};
	complex c2 = {2, 4};
	complex c3;
	c3 = complex_add(c1, c2);
	printf("c3 : %.1f + %.1fi", c3.real, c3.imaginary);
	return 0;	
} 
*/

#include <stdio.h>

void insert(int array[], int loc, int value)
{
	
	int n = 5;
	for(int i = n - 1; i > loc - 1; i--)
	{
		array[i] = array[i - 1];
	}
	array[loc] = value;
	printf(">>>>>>>>결과값\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}

int main(void)
{
	int n = 5;
	int array[n];
	
	for(int i = 0; i < n; i++)
	{
		printf("배열을 입력하세요 : ");
		scanf("%d", &array[i]);
	}
	
	printf(">>>>>>>>배열 입력 확인\n");	
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("=============================\n");
	int loc;
	printf("삽입 위치를 입력하세요 : ");
	scanf("%d", &loc);
	int value; 
	printf("value를 입력하세요 : ");
	scanf("%d", &value); 
	
	insert(array, loc, value); 

	return 0; 
}
