/* >>>>>구조체 선언은 dict 타입으로 

#include <stdio.h>

struct student{
	char name[10];
	int age;
	double gpa;
} ;

int main(void)
{
	student a = {"kim", 20, 4.3};
	
	printf("%d", a.age);
	return 0;
}

*/



#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

int get_distance(struct point p1, struct point p2)
{
	//int d = sqrt((p1.x - p2.x)^2 + (p1.y - p2.y)^2);
	int d = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return d;
}
int main(void)
{
	struct point p1;
	struct point p2;
	
	p1.x = 1;
	p1.y = 2;
	
	p2.x = 9;
	p2.y = 8; 
	
	printf("거리 : %d", get_distance(p1, p2));
	return 0;
}
