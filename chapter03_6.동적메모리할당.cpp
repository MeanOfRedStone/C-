/*
���α׷�3.8 malloc.c ���� �޸� �Ҵ��� �� 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main(void)
{
	int *p;
	
	p = (int *)malloc(SIZE * sizeof(int));
	if(p == NULL)
	{
		fprintf(stderr, "�޸� ����\n");
		exit(1);
	}
	
	for(int i =0 ; i < SIZE; i++)
	{
		p[i] = i;
	}
	for(int i = 0; i < SIZE; i++)
	{
		printf("%d ", p[i]);
	}
	
	free(p);
	return 0;
} 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[10];
	int age;
	double gpa;
} student;

int main(void)
{
	student *s;
	
	s= (student *)malloc(sizeof(student));
	
	if(s == NULL)
	{
		fprintf(stderr, "�޸� ����\n");
		exit(1);
	}
	
	strcpy(s->name, "park"); //����ü ������ ���� ��� (*s).name or s->name 
	s->age = 20;
	s->gpa = 3.7;
	printf("�̸� : %s, ���� : %d, ���� : %.1f", s->name, s->age, s->gpa);
	free(s);
	return 0;
}
