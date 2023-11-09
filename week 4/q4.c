#include<stdio.h>
#include<stdlib.h>
struct Date {
    int day;
    int *month;
    int year;
};
struct Address {
    int houseNumber;
    int zipCode;
    char *state;
};
struct STU_INFO {
    int reg_no;
    char *name;
    struct Address address;
};
struct COLLEGE {
    char *college_name;
    char *university_name;
};
struct STUDENT {
    struct Date dob;
    struct STU_INFO stu_info;
    struct COLLEGE college;
};
int main(){
	struct STUDENT *student = (struct STUDENT *)malloc(sizeof(struct STUDENT));
	student->dob.month = (int *)malloc(sizeof(int));
    student->stu_info.name = (char *)malloc(50 * sizeof(char));
    student->stu_info.address.state = (char *)malloc(20 * sizeof(char));
    student->college.college_name = (char *)malloc(50 * sizeof(char));
    student->college.university_name = (char *)malloc(50 * sizeof(char));
    printf("Enter student's date of birth (day month year): ");
    scanf("%d %d %d", &student->dob.day, student->dob.month, &student->dob.year);

    printf("Enter student's registration number: ");
    scanf("%d", &student->stu_info.reg_no);

    printf("Enter student's name: ");
    scanf(" %s", student->stu_info.name);

    printf("Enter student's address (house number zip code state): ");
    scanf("%d %d %s", &student->stu_info.address.houseNumber, &student->stu_info.address.zipCode, student->stu_info.address.state);

    printf("Enter college name: ");
    scanf(" %s", student->college.college_name);

    printf("Enter university name: ");
    scanf(" %s", student->college.university_name);

 
    printf("\nStudent information:\n");
    printf("Date of Birth: %d-%d-%d\n", student->dob.day, *student->dob.month, student->dob.year);
    printf("Registration Number: %d\n", student->stu_info.reg_no);
    printf("Name: %s\n", student->stu_info.name);
    printf("Address: %d, %d, %s\n", student->stu_info.address.houseNumber, student->stu_info.address.zipCode, student->stu_info.address.state);
    printf("College Name: %s\n", student->college.college_name);
    printf("University Name: %s\n", student->college.university_name);


    free(student->dob.month);
    free(student->stu_info.name);
    free(student->stu_info.address.state);
    free(student->college.college_name);
    free(student->college.university_name);
    free(student);

    return 0;
}