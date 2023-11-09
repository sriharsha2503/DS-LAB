#include<stdio.h>
#include<stdlib.h>
struct STUDENT{
	char *name;
	int number;
	double CGPA;
};
int main(){
	struct STUDENT *student = (struct STUDENT *)malloc(sizeof(struct STUDENT));
	student -> name = (char *)malloc(50 * sizeof(char));
	printf("Enter The name of the student : ");
	scanf("%s",student -> name);
	printf("Enter roll number of student : ");
	scanf("%d",&student -> number);
	printf("Enter CGPA of student : ");
	scanf("%f",&student -> CGPA);
	printf("Details of Student are\n");
	printf("Name of the student : %s\n",student -> name);
	printf("Roll Number of Student : %d\n",student -> number);
	printf("CGPA of Student : %f \n",student -> CGPA);

}
