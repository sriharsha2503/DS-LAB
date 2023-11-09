#include<stdio.h>
#include<stdlib.h>

struct dob{
	int day;
	int month;
	int year;
};
struct address{
	int hno;
	int zip;
	char state[30];
};
struct EMPLOYEE{
	char name[30];
	struct dob date;
	struct address add;
};
int main(){
	int n,i;
	printf("Enter number of employees : ");
	scanf("%d",&n);
	struct EMPLOYEE *emp = (struct EMPLOYEE*)malloc(sizeof(struct EMPLOYEE));
		for(i=0;i<n;i++){
		printf("For Employee %d\n",i+1);
		printf("Enter Name of Employee %d : ",i+1);
		scanf("%s",emp[i].name);
		printf("Enter date of birth of Employee %d in format (dd mm yyyy): ",i+1);
		scanf("%d%d%d",&emp[i].date.day,&emp[i].date.month,&emp[i].date.year);
		printf("For Address of employee %d: \n",i+1);
		printf("Enter House number : ");
		scanf("%d",&emp[i].add.hno);
		printf("Enter Zipcode : ");
		scanf("%d",&emp[i].add.zip);
		printf("Enter State : ");
		scanf("%s",emp[i].add.state);
	}
	for(i=0;i<n;i++){
		printf("Details of Employees are \n");
		printf("Name of Employye %d : %s\n",i+1,emp[i].name);
		printf("Date of Birth of employee %d : %d/%d/%d\n",i+1,emp[i].date.day,emp[i].date.month,emp[i].date.year);
		printf("Address of Employee %d : %d,%d,%s\n",i+1,emp[i].add.hno,emp[i].add.zip,emp[i].add.state);
	}
	return 0;

}