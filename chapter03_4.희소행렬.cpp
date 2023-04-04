/*
#include <stdio.h>
#define ROWS 3
#define COLS 3
//
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for(int r = 0; r < ROWS; r++)
	{
		for(int c = 0; c < COLS; c++)
		{
			B[c][r] = A[r][c]; 
		}
	}
}

void matrix_print(int A[ROWS][COLS])
{
	printf("========================\n");
	for(int i = 0; i < ROWS; i++)
	{
	
		for(int j = 0; j < COLS; j++)
		{
		
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
}

int main(void)
{
	int array1[ROWS][COLS] = {{2, 3, 0},
							{8, 9, 1},
							{7, 0, 5}};
	int array2[ROWS][COLS];
	
	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);
	return 0;
}

*/
/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct{
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

void matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;
	
	int bindex; //행렬 b에서 현재 저장 위치
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;
	
	if(a.terms > 0)
	{
		bindex=0;
		for(int c = 0; c < a.cols; c++) //a 열기준으로 b행이 되어야 하기 때문 
		{
			for(int i =0; i < a.terms; i++)
			{
				if(a.data[i].col == c) //a 열에 데이터가 있을 때 행,열 바꿔줌 
				{
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	} 
}

void matrix_print(SparseMatrix a)
{
	for(int i = 0; i < a.terms; i++)
		printf("(%d %d %d)\n", a.data[i].row, a.data[i].col, a.data[i].value);
}

int  main(void)
{
	SparseMatrix m = {{{0, 3, 7},{1, 0, 9},{1, 5, 8},{3, 0, 6},{3, 1, 5},{4, 5, 1},{5, 2, 2}},
	 6, 6, 7};
	
	SparseMatrix result; 
	matrix_print(m);
	 return 0;
}
*/

#include<stdio.h>
#define ROWS 3
#define COLS 3
void matrix_print(int A[ROWS][COLS])
{
	printf("========================\n");
	for(int i = 0; i < ROWS; i++)
	{
	
		for(int j = 0; j < COLS; j++)
		{
		
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
}

void matrix_add(int X[ROWS][COLS], int Y[ROWS][COLS], int Z[ROWS][COLS])
{
	for(int r = 0; r < ROWS; r++)
	{
		for(int c = 0; c < COLS; c++)
		{
			Z[r][c] = X[r][c] + Y[r][c];
		}
	}
	
}

int main(void)
{
	int A[ROWS][COLS] = {{1, 2, 3}, 
						{1, 4, 5},
						{3, 4, 2}};
			
	int B[ROWS][COLS] = {{4, 5, 3}, 
						{1, 2, 1},
						{2, 7, 3}};
	int C[ROWS][COLS];
	
	matrix_add(A, B, C);
	
	matrix_print(A);
	matrix_print(B);
	printf("------------------------------------------\n");
	matrix_print(C);
		
	
	return 0;	
} 
