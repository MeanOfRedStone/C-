/*
//10��. �迭�� ��� �ִ� ������ ������ �Ųٷ� �ϴ� ���α׷��� �ۼ��غ���. ���� ��� 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top; 
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
}

int main(void)
{
	StackType s;
	init_stack(&s);
	int n;
	element item;
	printf("���� �迭�� ũ�� : ");
	scanf("%d", &n);

	for(int i = 0; i < n; i++) 
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &item); 
		push(&s, item);
	}
	
	printf("������ ���� �迭: ");
	for(int i = 0; i < n; i++)
	{
		printf("%d ", pop(&s));

	}
	return 0;	
}
*/
/*
//11.���Ŀ� �ִ� ��ȣ�� ��ȣ�� ����ϴ� ���α׷��� �ۼ��϶�.
//	���� ��ȣ�� ���� ������ ��ȣ ��ȣ�� �ϳ��� �����Ѵ�.
//	������ ��ȣ�� ������ ��Ī�Ǵ� ���� ��ȣ ��ȣ�� ����Ѵ�.
//�׳� (�� �ִ°� �ƴ϶� ��ȣ�� cnt�� ���ÿ� �ִ´�. (����) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
}



int main(void)
{
	StackType s;
	char ch, open_ch; //ch Ȯ�� ���ڿ� open_ch ���� Ȯ�� ���ڿ� 
	init_stack(&s);

	printf("���� : ");
	char p[1001]; //�������� ���ڿ� �� ��� char�� ������ ��� 
	gets(p);
	int n = strlen(p);
	int cnt = 0;
	printf("��ȣ �� : ");
	
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		switch(ch)
		{
		case '(' :
		{
			cnt += 1;
			push(&s, cnt);
			printf("%d ", cnt);
			break;
		}
		case ')' :
		{
			printf("%d ", pop(&s));
			break;
		}
		}
	}

	return 0;
} 
*/
/*
//12.���ڿ� ���� ���α׷�. 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
}

int main() {

    char str[20] = "";
    int count = 0;
    StackType s;
    init_stack(&s);
    printf("enter a string : ");
    scanf("%s", str);
    for(int i=0;i<20;i++) {
        char chr = tolower(str[i]);
        if(is_empty(&s) || chr == peek(&s))  {
            count++;
            push(&s, chr);
        }
        else if(chr != peek(&s)) {
            printf("%d%c", count, peek(&s));
            count = 0;
            while(!is_empty(&s))
                pop(&s);
            i--;
        } 
    }
    printf("\n");
    return 0;
}


int main(void)
{	
	StackType a;
	StackType b;
	init_stack(&a);
	init_stack(&b);
	char ch, open_ch;
	
	printf("���ڿ��� �Է��Ͻÿ�  : ");
	char p[1001]; //�������� ���ڿ� �� ��� char�� ������ ��� 
	gets(p);
	
	int n = strlen(p);
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		switch(ch)
		{
		
		case 'a': case 'A':
		{
			push(&a, 'a');
			break;
		}
		case 'b': case 'B':
		{
			push(&b, 'b');
			break;
		}
		
		}
	}
	printf("%d%c%d%c",a.top+1, peek(&a), b.top+1, peek(&b));
	
	
	return 0;	
} */
/*
//13. �־��� �������� �ݺ��Ǵ� ���ڸ� �����ϴ� ���α׷��� �ۼ��غ���.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
} 

int main(void)
{
	StackType s;
	StackType l;
	init_stack(&s);
	init_stack(&l);
	char ch;
	
	char p[SIZE];
	printf("������ �Է��Ͻÿ�: ");
	gets(p);
	int n = strlen(p);
	
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		if(is_empty(&s))
		{
			push(&s, ch);
		}
		else
		{
			if(ch != peek(&s))
			{
				push(&s, ch);
			}
		}
	}
	
	while(!is_empty(&s))
	{
		char item = pop(&s);
		push(&l, item);
	}
	printf("���: ");
	while(!is_empty(&l))
	{
		printf("%c", pop(&l));	
	}	
	
	return 0;
	
}
*/
//14.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

//���� ���� Ȯ�� 
int is_empty(StackType *s)
{
	return (s->top == -1);	
} 
//���� ��ȭ Ȯ�� 
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}


//���� �Լ� 
element pop(StackType *s)
{
	if(is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[(s->top)--];
	}
}
//�����Լ� 
void push(StackType *s, element item)
{
	if(is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
	{
		s->data[++(s->top)] = item;
	}
}

//Ȯ�� �Լ� 
element peek(StackType *s)
{
	if(is_empty(s))//�Լ� ���� �����Ҷ��� �ּ� ������ �� �־��ָ� �� 
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	{
		return s->data[s->top];
	}
	
} 

int main(void)
{
	StackType s;
	init_stack(&s);
	char ch;
	char p[SIZE];
	printf("�Է�: ");
	gets(p);
	
	int n = strlen(p);
	
	for(int i = 0; i < n; i++)
	{
		ch = p[i];
		push(&s,ch);
	}
	
	printf("����� �� : %d", s.top + 1);
	
	return 0; 
}

