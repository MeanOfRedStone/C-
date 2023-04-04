/* ���������� ���׽� ���ϱ� 
#include <stdio.h>
#define MAX_DEGREE 101
#define MAX(a, b) (((a) > (b)) ? (a) : b) // a, b�� ū ���� ��ȯ 

struct polynomial {
	int degree;
	float coef[MAX_DEGREE];
};
//����ü �Լ� ����� ����ü�� ������ָ� �ȴ�. 
polynomial poly_add1(polynomial A, polynomial B)
{
	struct polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0; //�迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);
	
	while(Apos <= A.degree && Bpos <= B.degree)
	{
		if(degree_a > degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if(degree_a == degree_b)
		{
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else // B�� > A�� 
		{
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;	
		}
	}
	return C; 
	
}

void print_poly(polynomial p)
{
	int i;
	for(i = p.degree; i > 0; i--)
	{
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
		
	}
	printf("%3.1f \n", p.coef[p.degree]); //������ for loop ���� ���� i =0 
}

int main(void)
{
	struct polynomial a = {5, {3, 6, 0, 0, 0, 10}};
	struct polynomial b = {4, {7, 0, 5, 0, 1}};
	polynomial c;
	
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("-----------------------------------------------------\n");
	print_poly(c);
	return 0;	
} 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct{
	float coef;
	int expon;
} polynomial;

polynomial terms[MAX_TERMS] = {{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1,0}};
int avail = 6;

//�Լ� ����(�� ���� ���� ��) 
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
	
}

// ���ο� ���� ���׽Ŀ� �߰�
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
	{
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1); //exit(1) : ���α׷� ���� ���� 
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++; 
	
} 

//C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail;
	while(As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon))
		{
			case '>' :
				attach(terms[As].coef, terms[As].expon);
				As++;	break;
			case '=' :
				tempcoef = terms[As].coef + terms[Bs].coef;
				if (tempcoef) //tempcoef �����  
					attach(tempcoef, terms[As].expon);
				As++; Bs++; break;
			case '<' :
				attach(terms[Bs].coef, terms[Bs].expon);
				Bs++;	break; 
		}
	*Ce = avail - 1;
}
void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}


int main(void)
{
	int As = 0, Ae = 2, Bs= 3, Be = 5, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("--------------------------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}



